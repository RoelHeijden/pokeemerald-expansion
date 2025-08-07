#include "global.h"
#include "frontier_util.h"
#include "battle_setup.h"
#include "berry.h"
#include "clock.h"
#include "coins.h"
#include "contest.h"
#include "contest_util.h"
#include "contest_painting.h"
#include "data.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "field_door.h"
#include "field_effect.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "item.h"
#include "lilycove_lady.h"
#include "main.h"
#include "menu.h"
#include "money.h"
#include "mystery_event_script.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "overworld.h"
#include "rotating_tile_puzzle.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "script_movement.h"
#include "script_pokemon_util.h"
#include "shop.h"
#include "slot_machine.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "trainer_see.h"
#include "tv.h"
#include "window.h"
#include "list_menu.h"
#include "malloc.h"
#include "constants/event_objects.h"

// added
#include "pokedex.h"


typedef u16 (*SpecialFunc)(void);
typedef void (*NativeFunc)(struct ScriptContext *ctx);

EWRAM_DATA const u8 *gRamScriptRetAddr = NULL;
static EWRAM_DATA u32 sAddressOffset = 0; // For relative addressing in vgoto etc., used by saved scripts (e.g. Mystery Event)
static EWRAM_DATA u16 sPauseCounter = 0;
static EWRAM_DATA u16 sMovingNpcId = 0;
static EWRAM_DATA u16 sMovingNpcMapGroup = 0;
static EWRAM_DATA u16 sMovingNpcMapNum = 0;
static EWRAM_DATA u16 sFieldEffectScriptId = 0;

static u8 sBrailleWindowId;
static bool8 sIsScriptedWildDouble;

extern const SpecialFunc gSpecials[];
extern const u8 *gStdScripts[];
extern const u8 *gStdScripts_End[];

static void CloseBrailleWindow(void);
static void DynamicMultichoiceSortList(struct ListMenuItem *items, u32 count);

// ADDED
static void ShiftMoveSlot(struct Pokemon *mon, u8 slotTo, u8 slotFrom);

// ADDED
void MonToBoxMon(const struct Pokemon *src, struct BoxPokemon *dest);



// This is defined in here so the optimizer can't see its value when compiling
// script.c.
void * const gNullScriptPtr = NULL;

static const u8 sScriptConditionTable[6][3] =
{
//  <  =  >
    {1, 0, 0}, // <
    {0, 1, 0}, // =
    {0, 0, 1}, // >
    {1, 1, 0}, // <=
    {0, 1, 1}, // >=
    {1, 0, 1}, // !=
};

static u8 *const sScriptStringVars[] =
{
    gStringVar1,
    gStringVar2,
    gStringVar3,
};

bool8 ScrCmd_nop(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 ScrCmd_nop1(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 ScrCmd_end(struct ScriptContext *ctx)
{
    FlagClear(FLAG_SAFE_FOLLOWER_MOVEMENT);
    StopScript(ctx);
    return FALSE;
}

bool8 ScrCmd_gotonative(struct ScriptContext *ctx)
{
    bool8 (*addr)(void) = (bool8 (*)(void))ScriptReadWord(ctx);

    SetupNativeScript(ctx, addr);
    return TRUE;
}

bool8 ScrCmd_special(struct ScriptContext *ctx)
{
    u16 index = ScriptReadHalfword(ctx);

    gSpecials[index]();
    return FALSE;
}

bool8 ScrCmd_specialvar(struct ScriptContext *ctx)
{
    u16 *var = GetVarPointer(ScriptReadHalfword(ctx));

    *var = gSpecials[ScriptReadHalfword(ctx)]();
    return FALSE;
}

bool8 ScrCmd_callnative(struct ScriptContext *ctx)
{
    NativeFunc func = (NativeFunc)ScriptReadWord(ctx);

    func(ctx);
    return FALSE;
}

bool8 ScrCmd_waitstate(struct ScriptContext *ctx)
{
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_goto(struct ScriptContext *ctx)
{
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_return(struct ScriptContext *ctx)
{
    ScriptReturn(ctx);
    return FALSE;
}

bool8 ScrCmd_call(struct ScriptContext *ctx)
{
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_goto_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_call_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_setvaddress(struct ScriptContext *ctx)
{
    u32 addr1 = (u32)ctx->scriptPtr - 1;
    u32 addr2 = ScriptReadWord(ctx);

    sAddressOffset = addr2 - addr1;
    return FALSE;
}

bool8 ScrCmd_vgoto(struct ScriptContext *ctx)
{
    u32 addr = ScriptReadWord(ctx);

    ScriptJump(ctx, (u8 *)(addr - sAddressOffset));
    return FALSE;
}

bool8 ScrCmd_vcall(struct ScriptContext *ctx)
{
    u32 addr = ScriptReadWord(ctx);

    ScriptCall(ctx, (u8 *)(addr - sAddressOffset));
    return FALSE;
}

bool8 ScrCmd_vgoto_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)(ScriptReadWord(ctx) - sAddressOffset);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_vcall_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)(ScriptReadWord(ctx) - sAddressOffset);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_gotostd(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);
    const u8 **ptr = &gStdScripts[index];

    if (ptr < gStdScripts_End)
        ScriptJump(ctx, *ptr);
    return FALSE;
}

bool8 ScrCmd_callstd(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);
    const u8 **ptr = &gStdScripts[index];

    if (ptr < gStdScripts_End)
        ScriptCall(ctx, *ptr);
    return FALSE;
}

bool8 ScrCmd_gotostd_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    u8 index = ScriptReadByte(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
    {
        const u8 **ptr = &gStdScripts[index];
        if (ptr < gStdScripts_End)
            ScriptJump(ctx, *ptr);
    }
    return FALSE;
}

bool8 ScrCmd_callstd_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    u8 index = ScriptReadByte(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
    {
        const u8 **ptr = &gStdScripts[index];
        if (ptr < gStdScripts_End)
            ScriptCall(ctx, *ptr);
    }
    return FALSE;
}

bool8 ScrCmd_returnram(struct ScriptContext *ctx)
{
    ScriptJump(ctx, gRamScriptRetAddr);
    return FALSE;
}

bool8 ScrCmd_endram(struct ScriptContext *ctx)
{
    FlagClear(FLAG_SAFE_FOLLOWER_MOVEMENT);
    ClearRamScript();
    StopScript(ctx);
    return TRUE;
}

bool8 ScrCmd_setmysteryeventstatus(struct ScriptContext *ctx)
{
    u8 status = ScriptReadByte(ctx);

    SetMysteryEventScriptStatus(status);
    return FALSE;
}

bool8 ScrCmd_loadword(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    ctx->data[index] = ScriptReadWord(ctx);
    return FALSE;
}

bool8 ScrCmd_loadbytefromptr(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    ctx->data[index] = *(const u8 *)ScriptReadWord(ctx);
    return FALSE;
}

bool8 ScrCmd_setptr(struct ScriptContext *ctx)
{
    u8 value = ScriptReadByte(ctx);

    *(u8 *)ScriptReadWord(ctx) = value;
    return FALSE;
}

bool8 ScrCmd_loadbyte(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    ctx->data[index] = ScriptReadByte(ctx);
    return FALSE;
}

bool8 ScrCmd_setptrbyte(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    *(u8 *)ScriptReadWord(ctx) = ctx->data[index];
    return FALSE;
}

bool8 ScrCmd_copylocal(struct ScriptContext *ctx)
{
    u8 destIndex = ScriptReadByte(ctx);
    u8 srcIndex = ScriptReadByte(ctx);

    ctx->data[destIndex] = ctx->data[srcIndex];
    return FALSE;
}

bool8 ScrCmd_copybyte(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)ScriptReadWord(ctx);
    *ptr = *(const u8 *)ScriptReadWord(ctx);
    return FALSE;
}

bool8 ScrCmd_setvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = ScriptReadHalfword(ctx);
    return FALSE;
}

bool8 ScrCmd_copyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = *GetVarPointer(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_setorcopyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

u8 Compare(u16 a, u16 b)
{
    if (a < b)
        return 0;
    if (a == b)
        return 1;
    return 2;
}

bool8 ScrCmd_compare_local_to_local(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_local_to_value(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = ScriptReadByte(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_local_to_ptr(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = *(const u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_ptr_to_local(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_ptr_to_value(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = ScriptReadByte(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_ptr_to_ptr(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = *(const u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_var_to_value(struct ScriptContext *ctx)
{
    const u16 value1 = *GetVarPointer(ScriptReadHalfword(ctx));
    const u16 value2 = ScriptReadHalfword(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_var_to_var(struct ScriptContext *ctx)
{
    const u16 *ptr1 = GetVarPointer(ScriptReadHalfword(ctx));
    const u16 *ptr2 = GetVarPointer(ScriptReadHalfword(ctx));

    ctx->comparisonResult = Compare(*ptr1, *ptr2);
    return FALSE;
}

// Note: addvar doesn't support adding from a variable in vanilla. If you were to
// add a VarGet() to the above, make sure you change the `addvar VAR_*, -1`
// in the contest scripts to `subvar VAR_*, 1`, else contests will break.
bool8 ScrCmd_addvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr += ScriptReadHalfword(ctx);
    return FALSE;
}

bool8 ScrCmd_subvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr -= VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_random(struct ScriptContext *ctx)
{
    u16 max = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = Random() % max;
    return FALSE;
}

bool8 ScrCmd_additem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = AddBagItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_removeitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = RemoveBagItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_checkitemspace(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckBagHasSpace(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_checkitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckBagHasItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_checkitemtype(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = GetPocketByItemId(itemId);
    return FALSE;
}

bool8 ScrCmd_addpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = AddPCItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_checkpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckPCHasItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_adddecoration(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationAdd(decorId);
    return FALSE;
}

bool8 ScrCmd_removedecoration(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationRemove(decorId);
    return FALSE;
}

bool8 ScrCmd_checkdecorspace(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationCheckSpace(decorId);
    return FALSE;
}

bool8 ScrCmd_checkdecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckHasDecoration(decorId);
    return FALSE;
}

bool8 ScrCmd_setflag(struct ScriptContext *ctx)
{
    FlagSet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_clearflag(struct ScriptContext *ctx)
{
    FlagClear(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_checkflag(struct ScriptContext *ctx)
{
    ctx->comparisonResult = FlagGet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_incrementgamestat(struct ScriptContext *ctx)
{
    IncrementGameStat(ScriptReadByte(ctx));
    return FALSE;
}

bool8 ScrCmd_animateflash(struct ScriptContext *ctx)
{
    AnimateFlash(ScriptReadByte(ctx));
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_setflashlevel(struct ScriptContext *ctx)
{
    SetFlashLevel(VarGet(ScriptReadHalfword(ctx)));
    return FALSE;
}

static bool8 IsPaletteNotActive(void)
{
    if (!gPaletteFade.active)
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_fadescreen(struct ScriptContext *ctx)
{
    FadeScreen(ScriptReadByte(ctx), 0);
    SetupNativeScript(ctx, IsPaletteNotActive);
    return TRUE;
}

bool8 ScrCmd_fadescreenspeed(struct ScriptContext *ctx)
{
    u8 mode = ScriptReadByte(ctx);
    u8 speed = ScriptReadByte(ctx);

    FadeScreen(mode, speed);
    SetupNativeScript(ctx, IsPaletteNotActive);
    return TRUE;
}

bool8 ScrCmd_fadescreenswapbuffers(struct ScriptContext *ctx)
{
    u8 mode = ScriptReadByte(ctx);

    switch (mode)
    {
    case FADE_TO_BLACK:
    case FADE_TO_WHITE:
    default:
        CpuCopy32(gPlttBufferUnfaded, gPaletteDecompressionBuffer, PLTT_SIZE);
        FadeScreen(mode, 0);
        break;
    case FADE_FROM_BLACK:
    case FADE_FROM_WHITE:
        CpuCopy32(gPaletteDecompressionBuffer, gPlttBufferUnfaded, PLTT_SIZE);
        FadeScreen(mode, 0);
        break;
    }

    SetupNativeScript(ctx, IsPaletteNotActive);
    return TRUE;
}

static bool8 RunPauseTimer(void)
{
    if (--sPauseCounter == 0)
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_delay(struct ScriptContext *ctx)
{
    sPauseCounter = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, RunPauseTimer);
    return TRUE;
}

bool8 ScrCmd_initclock(struct ScriptContext *ctx)
{
    u8 hour = VarGet(ScriptReadHalfword(ctx));
    u8 minute = VarGet(ScriptReadHalfword(ctx));

    RtcInitLocalTimeOffset(hour, minute);
    return FALSE;
}

bool8 ScrCmd_dotimebasedevents(struct ScriptContext *ctx)
{
    DoTimeBasedEvents();
    return FALSE;
}

bool8 ScrCmd_gettime(struct ScriptContext *ctx)
{
    RtcCalcLocalTime();
    gSpecialVar_0x8000 = gLocalTime.hours;
    gSpecialVar_0x8001 = gLocalTime.minutes;
    gSpecialVar_0x8002 = gLocalTime.seconds;
    return FALSE;
}

bool8 ScrCmd_setweather(struct ScriptContext *ctx)
{
    u16 weather = VarGet(ScriptReadHalfword(ctx));

    SetSavedWeather(weather);
    return FALSE;
}

bool8 ScrCmd_resetweather(struct ScriptContext *ctx)
{
    SetSavedWeatherFromCurrMapHeader();
    return FALSE;
}

bool8 ScrCmd_doweather(struct ScriptContext *ctx)
{
    DoCurrentWeather();
    return FALSE;
}

bool8 ScrCmd_setstepcallback(struct ScriptContext *ctx)
{
    ActivatePerStepCallback(ScriptReadByte(ctx));
    return FALSE;
}

bool8 ScrCmd_setmaplayoutindex(struct ScriptContext *ctx)
{
    u16 value = VarGet(ScriptReadHalfword(ctx));

    SetCurrentMapLayout(value);
    return FALSE;
}

bool8 ScrCmd_warp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warpsilent(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoDiveWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warpdoor(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoDoorWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warphole(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    s16 x;
    s16 y;

    PlayerGetDestCoords(&x, &y);
    if (mapGroup == MAP_GROUP(UNDEFINED) && mapNum == MAP_NUM(UNDEFINED))
        SetWarpDestinationToFixedHoleWarp(x - MAP_OFFSET, y - MAP_OFFSET);
    else
        SetWarpDestination(mapGroup, mapNum, WARP_ID_NONE, x - MAP_OFFSET, y - MAP_OFFSET);
    DoFallWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

// RS mossdeep gym warp, unused in Emerald
bool8 ScrCmd_warpteleport(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoTeleportTileWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warpmossdeepgym(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoMossdeepGymWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_setwarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setdynamicwarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetDynamicWarpWithCoords(0, mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setdivewarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetFixedDiveWarp(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setholewarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetFixedHoleWarp(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setescapewarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetEscapeWarp(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_getplayerxy(struct ScriptContext *ctx)
{
    u16 *pX = GetVarPointer(ScriptReadHalfword(ctx));
    u16 *pY = GetVarPointer(ScriptReadHalfword(ctx));

    *pX = gSaveBlock1Ptr->pos.x;
    *pY = gSaveBlock1Ptr->pos.y;
    return FALSE;
}

bool8 ScrCmd_getpartysize(struct ScriptContext *ctx)
{
    gSpecialVar_Result = CalculatePlayerPartyCount();
    return FALSE;
}

bool8 ScrCmd_playse(struct ScriptContext *ctx)
{
    PlaySE(ScriptReadHalfword(ctx));
    return FALSE;
}

static bool8 WaitForSoundEffectFinish(void)
{
    if (!IsSEPlaying())
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_waitse(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForSoundEffectFinish);
    return TRUE;
}

bool8 ScrCmd_playfanfare(struct ScriptContext *ctx)
{
    PlayFanfare(ScriptReadHalfword(ctx));
    return FALSE;
}

static bool8 WaitForFanfareFinish(void)
{
    return IsFanfareTaskInactive();
}

bool8 ScrCmd_waitfanfare(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForFanfareFinish);
    return TRUE;
}

bool8 ScrCmd_playbgm(struct ScriptContext *ctx)
{
    u16 songId = ScriptReadHalfword(ctx);
    bool8 save = ScriptReadByte(ctx);

    if (save == TRUE)
        Overworld_SetSavedMusic(songId);
    PlayNewMapMusic(songId);
    return FALSE;
}

bool8 ScrCmd_savebgm(struct ScriptContext *ctx)
{
    Overworld_SetSavedMusic(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_fadedefaultbgm(struct ScriptContext *ctx)
{
    Overworld_ChangeMusicToDefault();
    return FALSE;
}

bool8 ScrCmd_fadenewbgm(struct ScriptContext *ctx)
{
    Overworld_ChangeMusicTo(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_fadeoutbgm(struct ScriptContext *ctx)
{
    u8 speed = ScriptReadByte(ctx);

    if (speed != 0)
        FadeOutBGMTemporarily(4 * speed);
    else
        FadeOutBGMTemporarily(4);
    SetupNativeScript(ctx, IsBGMPausedOrStopped);
    return TRUE;
}

bool8 ScrCmd_fadeinbgm(struct ScriptContext *ctx)
{
    u8 speed = ScriptReadByte(ctx);

    if (speed != 0)
        FadeInBGM(4 * speed);
    else
        FadeInBGM(4);
    return FALSE;
}

bool8 ScrCmd_applymovement(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    const u8 *movementScript = (const u8 *)ScriptReadWord(ctx);
    struct ObjectEvent *objEvent;

    // When applying script movements to follower, it may have frozen animation that must be cleared
    if (localId == OBJ_EVENT_ID_FOLLOWER && (objEvent = GetFollowerObject()) && objEvent->frozen)
    {
        ClearObjectEventMovement(objEvent, &gSprites[objEvent->spriteId]);
        gSprites[objEvent->spriteId].animCmdIndex = 0; // Reset start frame of animation
    }
    ScriptMovement_StartObjectMovementScript(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, movementScript);
    sMovingNpcId = localId;
    objEvent = GetFollowerObject();
    // Force follower into pokeball
    if (localId != OBJ_EVENT_ID_FOLLOWER
        && !FlagGet(FLAG_SAFE_FOLLOWER_MOVEMENT)
        && (movementScript < Common_Movement_FollowerSafeStart || movementScript > Common_Movement_FollowerSafeEnd)
        && (objEvent = GetFollowerObject())
        && !objEvent->invisible)
    {
        ClearObjectEventMovement(objEvent, &gSprites[objEvent->spriteId]);
        gSprites[objEvent->spriteId].animCmdIndex = 0; // Reset start frame of animation
        ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_FOLLOWER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, EnterPokeballMovement);
    }
    return FALSE;
}

bool8 ScrCmd_applymovementat(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    const void *movementScript = (const void *)ScriptReadWord(ctx);
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    ScriptMovement_StartObjectMovementScript(localId, mapNum, mapGroup, movementScript);
    sMovingNpcId = localId;
    return FALSE;
}

static bool8 WaitForMovementFinish(void)
{
    if (ScriptMovement_IsObjectMovementFinished(sMovingNpcId, sMovingNpcMapNum, sMovingNpcMapGroup))
    {
        struct ObjectEvent *objEvent = GetFollowerObject();
        // If the follower is still entering the pokeball, wait for it to finish too
        // This prevents a `release` after this script command from getting the follower stuck in an intermediate state
        if (sMovingNpcId != OBJ_EVENT_ID_FOLLOWER && objEvent && ObjectEventGetHeldMovementActionId(objEvent) == MOVEMENT_ACTION_ENTER_POKEBALL)
            return ScriptMovement_IsObjectMovementFinished(objEvent->localId, objEvent->mapNum, objEvent->mapGroup);
        return TRUE;
    }
    return FALSE;
}

bool8 ScrCmd_waitmovement(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));

    if (localId != 0)
        sMovingNpcId = localId;
    sMovingNpcMapGroup = gSaveBlock1Ptr->location.mapGroup;
    sMovingNpcMapNum = gSaveBlock1Ptr->location.mapNum;
    SetupNativeScript(ctx, WaitForMovementFinish);
    return TRUE;
}

bool8 ScrCmd_waitmovementat(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup;
    u8 mapNum;

    if (localId != 0)
        sMovingNpcId = localId;
    mapGroup = ScriptReadByte(ctx);
    mapNum = ScriptReadByte(ctx);
    sMovingNpcMapGroup = mapGroup;
    sMovingNpcMapNum = mapNum;
    SetupNativeScript(ctx, WaitForMovementFinish);
    return TRUE;
}

bool8 ScrCmd_removeobject(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));

    RemoveObjectEventByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_removeobjectat(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    RemoveObjectEventByLocalIdAndMap(objectId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_addobject(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(ScriptReadHalfword(ctx));

    TrySpawnObjectEvent(objectId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_addobjectat(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    TrySpawnObjectEvent(objectId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_setobjectxy(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    TryMoveObjectEventToMapCoords(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, x, y);
    return FALSE;
}

bool8 ScrCmd_setobjectxyperm(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetObjEventTemplateCoords(localId, x, y);
    return FALSE;
}

bool8 ScrCmd_copyobjectxytoperm(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));

    TryOverrideObjectEventTemplateCoords(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_showobjectat(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    SetObjectInvisibility(localId, mapNum, mapGroup, FALSE);
    return FALSE;
}

bool8 ScrCmd_hideobjectat(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    SetObjectInvisibility(localId, mapNum, mapGroup, TRUE);
    return FALSE;
}

bool8 ScrCmd_setobjectsubpriority(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 priority = ScriptReadByte(ctx);

    SetObjectSubpriority(localId, mapNum, mapGroup, priority + 83);
    return FALSE;
}

bool8 ScrCmd_resetobjectsubpriority(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    ResetObjectSubpriority(localId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_faceplayer(struct ScriptContext *ctx)
{
    if (gObjectEvents[gSelectedObjectEvent].active)
        ObjectEventFaceOppositeDirection(&gObjectEvents[gSelectedObjectEvent], GetPlayerFacingDirection());
    return FALSE;
}

bool8 ScrCmd_turnobject(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 direction = ScriptReadByte(ctx);

    ObjectEventTurnByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, direction);
    return FALSE;
}

bool8 ScrCmd_setobjectmovementtype(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 movementType = ScriptReadByte(ctx);

    SetObjEventTemplateMovementType(localId, movementType);
    return FALSE;
}

bool8 ScrCmd_createvobject(struct ScriptContext *ctx)
{
    u16 graphicsId = ScriptReadHalfword(ctx);
    u8 virtualObjId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));
    u8 elevation = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);

    CreateVirtualObject(graphicsId, virtualObjId, x, y, elevation, direction);
    return FALSE;
}

bool8 ScrCmd_turnvobject(struct ScriptContext *ctx)
{
    u8 virtualObjId = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);

    TurnVirtualObject(virtualObjId, direction);
    return FALSE;
}

// lockall freezes all object events except the player immediately.
// The player is frozen after waiting for their current movement to finish.
bool8 ScrCmd_lockall(struct ScriptContext *ctx)
{
    if (IsOverworldLinkActive())
    {
        return FALSE;
    }
    else
    {
        FreezeObjects_WaitForPlayer();
        SetupNativeScript(ctx, IsFreezePlayerFinished);
        return TRUE;
    }
}

// lock freezes all object events except the player, follower, and the selected object immediately.
// The player and selected object are frozen after waiting for their current movement to finish.
bool8 ScrCmd_lock(struct ScriptContext *ctx)
{
    if (IsOverworldLinkActive())
    {
        return FALSE;
    }
    else
    {
        struct ObjectEvent *followerObj = GetFollowerObject();
        if (gObjectEvents[gSelectedObjectEvent].active)
        {
            FreezeObjects_WaitForPlayerAndSelected();
            SetupNativeScript(ctx, IsFreezeSelectedObjectAndPlayerFinished);
            // follower is being talked to; keep it frozen
            if (gObjectEvents[gSelectedObjectEvent].localId == OBJ_EVENT_ID_FOLLOWER)
                followerObj = NULL;
        }
        else
        {
            FreezeObjects_WaitForPlayer();
            SetupNativeScript(ctx, IsFreezePlayerFinished);
        }
        if (followerObj) // Unfreeze follower object
            UnfreezeObjectEvent(followerObj);
        return TRUE;
    }
}

bool8 ScrCmd_releaseall(struct ScriptContext *ctx)
{
    u8 playerObjectId;
    struct ObjectEvent *followerObject = GetFollowerObject();
    // Release follower from movement iff it exists and is in the shadowing state
    if (followerObject && gSprites[followerObject->spriteId].data[1] == 0)
        ClearObjectEventMovement(followerObject, &gSprites[followerObject->spriteId]);

    HideFieldMessageBox();
    playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
    return FALSE;
}

bool8 ScrCmd_release(struct ScriptContext *ctx)
{
    u8 playerObjectId;
    struct ObjectEvent *followerObject = GetFollowerObject();
    // Release follower from movement iff it exists and is in the shadowing state
    if (followerObject && gSprites[followerObject->spriteId].data[1] == 0)
        ClearObjectEventMovement(followerObject, &gSprites[followerObject->spriteId]);

    HideFieldMessageBox();
    if (gObjectEvents[gSelectedObjectEvent].active)
        ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gSelectedObjectEvent]);
    playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
    return FALSE;
}

bool8 ScrCmd_message(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    ShowFieldMessage(msg);
    return FALSE;
}

bool8 ScrCmd_pokenavcall(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    ShowPokenavFieldMessage(msg);
    return FALSE;
}

bool8 ScrCmd_messageautoscroll(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    gTextFlags.autoScroll = TRUE;
    gTextFlags.forceMidTextSpeed = TRUE;
    ShowFieldAutoScrollMessage(msg);
    return FALSE;
}

// Prints all at once. Skips waiting for player input. Only used by link contests
bool8 ScrCmd_messageinstant(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, TRUE);
    AddTextPrinterParameterized(0, FONT_NORMAL, msg, 0, 1, 0, NULL);
    return FALSE;
}

bool8 ScrCmd_waitmessage(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, IsFieldMessageBoxHidden);
    return TRUE;
}

bool8 ScrCmd_closemessage(struct ScriptContext *ctx)
{
    HideFieldMessageBox();
    return FALSE;
}

static bool8 WaitForAorBPress(void)
{
    if (JOY_NEW(A_BUTTON))
        return TRUE;
    if (JOY_NEW(B_BUTTON))
        return TRUE;
    return FALSE;
}

bool8 ScrCmd_waitbuttonpress(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForAorBPress);
    return TRUE;
}

bool8 ScrCmd_yesnobox(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);

    if (ScriptMenu_YesNo(left, top) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// ADDED
bool8 ScrCmd_softlockguymovebox(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    u8 multichoiceId = MULTI_SOFTLOCK_GUY;

    if (ScriptMenu_Multichoice(left, top, multichoiceId, ignoreBPress) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// ADDED
bool8 ScrCmd_movedeleterbox(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    u8 multichoiceId = MULTI_MOVE_DELETER;

    if (ScriptMenu_Multichoice(left, top, multichoiceId, ignoreBPress) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



static void DynamicMultichoiceSortList(struct ListMenuItem *items, u32 count)
{
    u32 i,j;
    struct ListMenuItem tmp;
    for (i = 0; i < count - 1; ++i)
    {
        for (j = 0; j < count - i - 1; ++j)
        {
            if (items[j].id > items[j+1].id)
            {
                tmp = items[j];
                items[j] = items[j+1];
                items[j+1] = tmp;
            }
        }
    }
}

#define DYN_MULTICHOICE_DEFAULT_MAX_BEFORE_SCROLL 6

bool8 ScrCmd_dynmultichoice(struct ScriptContext *ctx)
{
    u32 i;
    u32 left = VarGet(ScriptReadHalfword(ctx));
    u32 top = VarGet(ScriptReadHalfword(ctx));
    bool32 ignoreBPress = ScriptReadByte(ctx);
    u32 maxBeforeScroll = ScriptReadByte(ctx);
    bool32 shouldSort = ScriptReadByte(ctx);
    u32 initialSelected = VarGet(ScriptReadHalfword(ctx));
    u32 callbackSet = ScriptReadByte(ctx);
    u32 initialRow = 0;
    // Read vararg
    u32 argc = ScriptReadByte(ctx);
    struct ListMenuItem *items;

    if (argc == 0)
        return FALSE;

    if (maxBeforeScroll == 0xFF)
        maxBeforeScroll = DYN_MULTICHOICE_DEFAULT_MAX_BEFORE_SCROLL;

    if ((const u8*) ScriptPeekWord(ctx) != NULL)
    {
        items = AllocZeroed(sizeof(struct ListMenuItem) * argc);
        for (i = 0; i < argc; ++i)
        {
            u8 *nameBuffer = Alloc(100);
            const u8 *arg = (const u8 *) ScriptReadWord(ctx);
            StringExpandPlaceholders(nameBuffer, arg);
            items[i].name = nameBuffer;
            items[i].id = i;
            if (i == initialSelected)
                initialRow = i;
        }
    }
    else
    {
        argc = MultichoiceDynamic_StackSize();
        items = AllocZeroed(sizeof(struct ListMenuItem) * argc);
        for (i = 0; i < argc; ++i)
        {
            struct ListMenuItem *currentItem = MultichoiceDynamic_PeekElementAt(i);
            items[i] = *currentItem;
            if (currentItem->id == initialSelected)
                initialRow = i;
        }
        if (shouldSort)
            DynamicMultichoiceSortList(items, argc);
        MultichoiceDynamic_DestroyStack();
    }

    if (ScriptMenu_MultichoiceDynamic(left, top, argc, items, ignoreBPress, maxBeforeScroll, initialRow, callbackSet))
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_dynmultipush(struct ScriptContext *ctx)
{
    u8 *nameBuffer = Alloc(100);
    const u8 *name = (const u8*) ScriptReadWord(ctx);
    u32 id = VarGet(ScriptReadHalfword(ctx));
    struct ListMenuItem item;
    StringExpandPlaceholders(nameBuffer, name);
    item.name = nameBuffer;
    item.id = id;
    MultichoiceDynamic_PushElement(item);
    return FALSE;
}

bool8 ScrCmd_multichoice(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    if (ScriptMenu_Multichoice(left, top, multichoiceId, ignoreBPress) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_multichoicedefault(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    u8 defaultChoice = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    if (ScriptMenu_MultichoiceWithDefault(left, top, multichoiceId, ignoreBPress, defaultChoice) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_drawbox(struct ScriptContext *ctx)
{
    /*u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 right = ScriptReadByte(ctx);
    u8 bottom = ScriptReadByte(ctx);

    MenuDrawTextWindow(left, top, right, bottom);*/
    return FALSE;
}

bool8 ScrCmd_multichoicegrid(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    u8 numColumns = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    if (ScriptMenu_MultichoiceGrid(left, top, multichoiceId, ignoreBPress, numColumns) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_erasebox(struct ScriptContext *ctx)
{
    u8 UNUSED left = ScriptReadByte(ctx);
    u8 UNUSED top = ScriptReadByte(ctx);
    u8 UNUSED right = ScriptReadByte(ctx);
    u8 UNUSED bottom = ScriptReadByte(ctx);

    // Menu_EraseWindowRect(left, top, right, bottom);
    return FALSE;
}

bool8 ScrCmd_drawboxtext(struct ScriptContext *ctx)
{
    u8 UNUSED left = ScriptReadByte(ctx);
    u8 UNUSED top = ScriptReadByte(ctx);
    u8 UNUSED multichoiceId = ScriptReadByte(ctx);
    bool8 UNUSED ignoreBPress = ScriptReadByte(ctx);

    /*if (Multichoice(left, top, multichoiceId, ignoreBPress) == TRUE)
    {
        ScriptContext_Stop();
        return TRUE;
    }*/
    return FALSE;
}

bool8 ScrCmd_showmonpic(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    ScriptMenu_ShowPokemonPic(species, x, y);
    return FALSE;
}

bool8 ScrCmd_hidemonpic(struct ScriptContext *ctx)
{
    // The hide function returns a pointer to a function
    // that returns true once the pic is hidden
    bool8 (*func)(void) = ScriptMenu_HidePokemonPic();

    if (func == NULL)
        return FALSE;
    SetupNativeScript(ctx, func);
    return TRUE;
}

bool8 ScrCmd_showcontestpainting(struct ScriptContext *ctx)
{
    u8 contestWinnerId = ScriptReadByte(ctx);

    // Artist's painting is temporary and already has its data loaded
    if (contestWinnerId != CONTEST_WINNER_ARTIST)
        SetContestWinnerForPainting(contestWinnerId);

    ShowContestPainting();
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_braillemessage(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)ScriptReadWord(ctx);
    struct WindowTemplate winTemplate;
    s32 i;
    u8 width, height;
    u8 xWindow, yWindow, xText, yText;
    u8 temp;

    // + 6 for the 6 bytes at the start of a braille message (brailleformat macro)
    // In RS these bytes are used to position the text and window, but
    // in Emerald they are unused and position is calculated below instead
    StringExpandPlaceholders(gStringVar4, ptr + 6);

    width = GetStringWidth(FONT_BRAILLE, gStringVar4, -1) / 8u;

    if (width > 28)
        width = 28;

    for (i = 0, height = 4; gStringVar4[i] != EOS;)
    {
        if (gStringVar4[i++] == CHAR_NEWLINE)
            height += 3;
    }

    if (height > 18)
        height = 18;

    temp = width + 2;
    xWindow = (30 - temp) / 2;

    temp = height + 2;
    yText = (20 - temp) / 2;

    xText = xWindow;
    xWindow += 1;

    yWindow = yText;
    yText += 2;

    xText = (xWindow - xText - 1) * 8 + 3;
    yText = (yText - yWindow - 1) * 8;

    winTemplate = CreateWindowTemplate(0, xWindow, yWindow + 1, width, height, 0xF, 0x1);
    sBrailleWindowId = AddWindow(&winTemplate);
    LoadUserWindowBorderGfx(sBrailleWindowId, 0x214, BG_PLTT_ID(14));
    DrawStdWindowFrame(sBrailleWindowId, FALSE);
    PutWindowTilemap(sBrailleWindowId);
    FillWindowPixelBuffer(sBrailleWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(sBrailleWindowId, FONT_BRAILLE, gStringVar4, xText, yText, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sBrailleWindowId, COPYWIN_FULL);
    return FALSE;
}

bool8 ScrCmd_closebraillemessage(struct ScriptContext *ctx)
{
    CloseBrailleWindow();
    return FALSE;
}

bool8 ScrCmd_vmessage(struct ScriptContext *ctx)
{
    u32 msg = ScriptReadWord(ctx);

    ShowFieldMessage((u8 *)(msg - sAddressOffset));
    return FALSE;
}

bool8 ScrCmd_bufferspeciesname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 species = VarGet(ScriptReadHalfword(ctx)) & OBJ_EVENT_GFX_SPECIES_MASK; // ignore possible shiny / form bits

    StringCopy(sScriptStringVars[stringVarIndex], GetSpeciesName(species));
    return FALSE;
}

bool8 ScrCmd_bufferleadmonspeciesname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);

    u8 *dest = sScriptStringVars[stringVarIndex];
    u8 partyIndex = GetLeadMonIndex();
    u32 species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES, NULL);
    StringCopy(dest, GetSpeciesName(species));
    return FALSE;
}

void BufferFirstLiveMonNickname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);

    GetMonData(GetFirstLiveMon(), MON_DATA_NICKNAME, sScriptStringVars[stringVarIndex]);
    StringGet_Nickname(sScriptStringVars[stringVarIndex]);
}

bool8 ScrCmd_bufferpartymonnick(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));

    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, sScriptStringVars[stringVarIndex]);
    StringGet_Nickname(sScriptStringVars[stringVarIndex]);
    return FALSE;
}

bool8 ScrCmd_bufferitemname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 itemId = VarGet(ScriptReadHalfword(ctx));

    CopyItemName(itemId, sScriptStringVars[stringVarIndex]);
    return FALSE;
}

bool8 ScrCmd_bufferitemnameplural(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    CopyItemNameHandlePlural(itemId, sScriptStringVars[stringVarIndex], quantity);
    return FALSE;
}

bool8 ScrCmd_bufferdecorationname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 decorId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], gDecorations[decorId].name);
    return FALSE;
}

bool8 ScrCmd_buffermovename(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 moveId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetMoveName(moveId));
    return FALSE;
}

bool8 ScrCmd_buffernumberstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 num = VarGet(ScriptReadHalfword(ctx));
    u8 numDigits = CountDigits(num);

    ConvertIntToDecimalStringN(sScriptStringVars[stringVarIndex], num, STR_CONV_MODE_LEFT_ALIGN, numDigits);
    return FALSE;
}

bool8 ScrCmd_bufferstdstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 index = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], gStdStrings[index]);
    return FALSE;
}

bool8 ScrCmd_buffercontestname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 category = VarGet(ScriptReadHalfword(ctx));

    BufferContestName(sScriptStringVars[stringVarIndex], category);
    return FALSE;
}

bool8 ScrCmd_bufferstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    const u8 *text = (u8 *)ScriptReadWord(ctx);

    StringCopy(sScriptStringVars[stringVarIndex], text);
    return FALSE;
}

bool8 ScrCmd_vbuffermessage(struct ScriptContext *ctx)
{
    const u8 *ptr = (u8 *)(ScriptReadWord(ctx) - sAddressOffset);

    StringExpandPlaceholders(gStringVar4, ptr);
    return FALSE;
}

bool8 ScrCmd_vbufferstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u32 addr = ScriptReadWord(ctx);

    const u8 *src = (u8 *)(addr - sAddressOffset);
    u8 *dest = sScriptStringVars[stringVarIndex];
    StringCopy(dest, src);
    return FALSE;
}

bool8 ScrCmd_bufferboxname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 boxId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetBoxNamePtr(boxId));
    return FALSE;
}

bool8 ScrCmd_giveegg(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = ScriptGiveEgg(species);
    return FALSE;
}


// ADDED
bool8 SrcCmd_giveaipomegg(struct ScriptContext *ctx)
{
    gSpecialVar_Result = ScriptGiveAipomEgg();
    return FALSE;
}

bool8 ScrCmd_setmonmove(struct ScriptContext *ctx)
{
    u8 partyIndex = ScriptReadByte(ctx);
    u8 slot = ScriptReadByte(ctx);
    u16 move = ScriptReadHalfword(ctx);

    ScriptSetMonMoveSlot(partyIndex, move, slot);
    return FALSE;
}

// ADDED
// add move to nearest free slot
bool8 SrcCmd_addmonmove(struct ScriptContext *ctx)
{
    u16 partymonspecies = ScriptReadHalfword(ctx);
    u16 move = ScriptReadHalfword(ctx);
    struct Pokemon *mon;
    u16 species;

    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        species = GetMonData(mon, MON_DATA_SPECIES);

        if (species == partymonspecies)
        {
            for (u8 j = 0; j < MAX_MON_MOVES; j++)
            {
                if (GetMonData(mon, MON_DATA_MOVE1 + j) == MOVE_NONE)
                {
                    SetMonMoveSlot(mon, move, j);
                    gSpecialVar_Result = TRUE;
                    return FALSE;
                }
            }

            // Species found, but no empty slots
            gSpecialVar_Result = FALSE;
            return FALSE;
        }
    }

    // Species not found
    gSpecialVar_Result = FALSE;
    return FALSE;
}

// ADDED
bool8 ScrCmd_checkmonmove0pp(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    u16 moveId = ScriptReadHalfword(ctx);
    struct Pokemon *mon;

    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        if (species == GetMonData(mon, MON_DATA_SPECIES))
        {
            for (u8 j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 move = GetMonData(mon, MON_DATA_MOVE1 + j);
                u8 pp = GetMonData(mon, MON_DATA_PP1 + j);

                if (move == moveId)
                {
                    gSpecialVar_Result = (pp == 0);
                    return FALSE;
                }
            }
            // move not found on this mon
            gSpecialVar_Result = FALSE;
            return FALSE;
        }
    }

    // species not found in party
    gSpecialVar_Result = FALSE;
    return FALSE;
}

// ADDED
bool8 ScrCmd_backupplayerparty(struct ScriptContext *ctx)
{
    for (int i = 0; i < PARTY_SIZE; i++)
        gPlayerPartyBackup[i] = gPlayerParty[i];

    gPartyBackupInUse = TRUE;
    return FALSE;
}

// ADDED
bool8 ScrCmd_restoreplayerparty(struct ScriptContext *ctx)
{
    if (gPartyBackupInUse)
    {
        for (int i = 0; i < PARTY_SIZE; i++)
            gPlayerParty[i] = gPlayerPartyBackup[i];

        gPartyBackupInUse = FALSE;
    }
    return FALSE;
}

// ADDED
bool8 ScrCmd_partybackupisdifferent(struct ScriptContext *ctx)
{
    gSpecialVar_Result = FALSE;

    if (!gPartyBackupInUse)
        return FALSE; // no backup to compare with
    
    for (int i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *curMon = &gPlayerParty[i];
        struct Pokemon *backupMon = &gPlayerPartyBackup[i];

        // check if species in slots match
        if (GetMonData(curMon, MON_DATA_SPECIES) != GetMonData(backupMon, MON_DATA_SPECIES)){
            gSpecialVar_Result = TRUE;
            return FALSE;
        }

        // skip next steps if slot has no pokemon
        if (GetMonData(curMon, MON_DATA_SPECIES) == SPECIES_NONE)
            continue;

        // check if HP matches
        if (GetMonData(curMon, MON_DATA_HP) != GetMonData(backupMon, MON_DATA_HP)){
            gSpecialVar_Result = TRUE;
            return FALSE;
        }

        // check if moves and PP matches
        for (int j = 0; j < MAX_MON_MOVES; j++)
        {
            if (GetMonData(curMon, MON_DATA_MOVE1 + j) != GetMonData(backupMon, MON_DATA_MOVE1 + j)){
                gSpecialVar_Result = TRUE;
                return FALSE;
            }

            if (GetMonData(curMon, MON_DATA_PP1 + j) != GetMonData(backupMon, MON_DATA_PP1 + j)){
                gSpecialVar_Result = TRUE;
                return FALSE;
            }
        }
    }

    // no changes found
    gSpecialVar_Result = FALSE;
    return FALSE; 
}

// ADDED
bool8 ScrCmd_backupmonmoveset(struct ScriptContext *ctx)
{
    u16 partyslot = VarGet(ScriptReadHalfword(ctx));
    gSpecialVar_Result = FALSE;

    if (partyslot >= PARTY_SIZE)
        return FALSE;

    u16 species = GetMonData(&gPlayerParty[partyslot], MON_DATA_SPECIES);

    // check if backup already exists
    for (int i = 0; i < MAX_BACKUP_SLOTS; i++)
    {
        if (gSaveBlock3Ptr->movesetBackupData.slots[i].valid &&
            gSaveBlock3Ptr->movesetBackupData.slots[i].species == species)
        {
            // backup exists — update PP for matching moves
            for (int j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 move = GetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE1 + j);
                if (move == MOVE_NONE)
                    continue;

                // search for the move in backup
                for (int k = 0; k < MAX_MON_MOVES; k++)
                {
                    if (gSaveBlock3Ptr->movesetBackupData.slots[i].moves[k] == move)
                    {
                        gSaveBlock3Ptr->movesetBackupData.slots[i].pp[k] = GetMonData(&gPlayerParty[partyslot], MON_DATA_PP1 + j);
                        break;
                    }
                }
            }

            gSpecialVar_Result = TRUE;
            return FALSE;
        }
    }

    // no backup — create new one
    for (int i = 0; i < MAX_BACKUP_SLOTS; i++)
    {
        if (!gSaveBlock3Ptr->movesetBackupData.slots[i].valid)
        {
            gSaveBlock3Ptr->movesetBackupData.slots[i].species = species;

            for (int j = 0; j < MAX_MON_MOVES; j++)
            {
                gSaveBlock3Ptr->movesetBackupData.slots[i].moves[j] = GetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE1 + j);
                gSaveBlock3Ptr->movesetBackupData.slots[i].pp[j] = GetMonData(&gPlayerParty[partyslot], MON_DATA_PP1 + j);
            }

            gSaveBlock3Ptr->movesetBackupData.slots[i].valid = TRUE;
            gSpecialVar_Result = TRUE;
            break;
        }
    }

    return FALSE;
}

// ADDED
bool8 ScrCmd_restoremonmoveset(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    gSpecialVar_Result = FALSE;

    // find party slot matching the species
    int partyslot = -1;
    for (int i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == species)
        {
            partyslot = i;
            break;
        }
    }
    if (partyslot == -1)
        return FALSE; // species not found in party

    // find matching backup entry
    for (int i = 0; i < MAX_BACKUP_SLOTS; i++)
    {
        if (gSaveBlock3Ptr->movesetBackupData.slots[i].valid &&
            gSaveBlock3Ptr->movesetBackupData.slots[i].species == species)
        {
            // check if current total PP is 0
            u32 totalCurrentPP = 0;
            for (int j = 0; j < MAX_MON_MOVES; j++)
                totalCurrentPP += GetMonData(&gPlayerParty[i], MON_DATA_PP1 + j);

            // restore only deleted moves
            for (int j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 backupMove = gSaveBlock3Ptr->movesetBackupData.slots[i].moves[j];
                if (backupMove == MOVE_NONE)
                    continue;

                bool8 moveStillExists = FALSE;
                for (int k = 0; k < MAX_MON_MOVES; k++)
                {
                    u16 currentMove = GetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE1 + k);
                    if (currentMove == backupMove)
                    {
                        moveStillExists = TRUE;
                        break;
                    }
                }

                // only restore move if it's missing
                if (!moveStillExists)
                {
                    // find first empty slot to write into
                    for (int k = 0; k < MAX_MON_MOVES; k++)
                    {
                        u16 currentMove = GetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE1 + k);
                        if (currentMove == MOVE_NONE)
                        {
                            SetMonData(&gPlayerParty[partyslot], MON_DATA_MOVE1 + k, &backupMove);
                            SetMonData(&gPlayerParty[partyslot], MON_DATA_PP1 + k, &gSaveBlock3Ptr->movesetBackupData.slots[i].pp[j]);

                            if (totalCurrentPP == 0)
                            {
                                u8 zero = 0;
                                SetMonData(&gPlayerParty[partyslot], MON_DATA_PP1 + k, &zero);
                            }
                            break;
                        }
                    }
                }
            }
            
            gSaveBlock3Ptr->movesetBackupData.slots[i].valid = FALSE;
            gSpecialVar_Result = TRUE;
            break;
        }
    }
    return FALSE;
}

// ADDED
bool8 ScrCmd_checkpartymove(struct ScriptContext *ctx)
{
    u8 i;
    u16 moveId = ScriptReadHalfword(ctx);

    gSpecialVar_Result = PARTY_SIZE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (!species)
            break;
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) && MonKnowsMove(&gPlayerParty[i], moveId) == TRUE)
        {
            gSpecialVar_Result = i;
            gSpecialVar_0x8004 = species;
            break;
        }
    }
    // ADDED
    if (gSpecialVar_Result == PARTY_SIZE && PlayerHasMove(moveId)){  // If no mon have the move, but the player has the HM in bag, use the first mon
        gSpecialVar_Result = 0;
        gSpecialVar_0x8004 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    }
    return FALSE;
}

// ADDED
// takes VARs
bool8 ScrCmd_checkpartymonmove(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 moveId = VarGet(ScriptReadHalfword(ctx)); 
    u16 i, j;

    gSpecialVar_Result = PARTY_SIZE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == species &&
            !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL) == moveId)
                {
                    gSpecialVar_Result = i; // party slot of match
                    return FALSE;
                }
            }
        }
    }

    return FALSE;
}

// ADDED
// check what item is held by a pokemon -- takes VAR as slot
bool8 ScrCmd_checkpartyitem(struct ScriptContext *ctx)
{
    // u8 slot = ScriptReadByte(ctx); 
    u8 slot = VarGet(ScriptReadHalfword(ctx));
    u16 item;

    gSpecialVar_Result = 0; 
    gSpecialVar_0x8005 = ITEM_NONE; 

    if (slot < PARTY_SIZE)
    {
        u16 species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES, NULL);
        if (species && !GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
        {
            item = GetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM, NULL);
            if (item != ITEM_NONE) 
            {
                gSpecialVar_Result = 1; 
                gSpecialVar_0x8005 = item; 
            }
        }
    }
    return FALSE;
}

// ADDED
// removes the held item of a Pokémon in the specified party slot -- takes VAR as slot
bool8 ScrCmd_removepartyitem(struct ScriptContext *ctx)
{
    // u8 slot = ScriptReadByte(ctx);
    u8 slot = VarGet(ScriptReadHalfword(ctx));
    gSpecialVar_Result = 0; // Default to failure
    
    if (slot < PARTY_SIZE)
    {
        u16 species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES, NULL);
        if (species && !GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
        {
            u16 item = GetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM, NULL);
            if (item != ITEM_NONE)
            {
                SetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM, &gSpecialVar_Result); // set held item to ITEM_NONE
                gSpecialVar_Result = 1;
            }
        }
    }
    return FALSE;
}

// ADDED
// gives a held item to a Pokémon in the specified party slot -- takes VAR as slot, constant as item
bool8 ScrCmd_givepartyitem(struct ScriptContext *ctx)
{
    u16 item = ScriptReadHalfword(ctx);                    // item is passed directly as a constant
    u8 slot = VarGet(ScriptReadHalfword(ctx));             // slot is passed as a variable
    gSpecialVar_Result = 0;                                

    if (slot < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[slot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            if (GetMonData(mon, MON_DATA_HELD_ITEM, NULL) == ITEM_NONE) // only give if no item held
            {
                SetMonData(mon, MON_DATA_HELD_ITEM, &item);
                gSpecialVar_Result = 1;
            }
        }
    }
    return FALSE;
}

// ADDED
bool8 ScrCmd_isitemlost(struct ScriptContext *ctx)
{
    u16 itemId = ScriptReadHalfword(ctx);
    gSpecialVar_Result = FALSE;

    for (int i = 0; i < MAX_LOST_ITEMS; i++)
    {
        if (gSaveBlock3Ptr->lostItemsTracker.lostItems[i] == itemId){
            gSpecialVar_Result = TRUE;
            break;
        }
    }
    return FALSE;
}

// ADDED
bool8 ScrCmd_removelostitem(struct ScriptContext *ctx)
{
    u16 itemId = ScriptReadHalfword(ctx);
    gSpecialVar_Result = FALSE;

    for (int i = 0; i < MAX_LOST_ITEMS; i++)
    {
        if (gSaveBlock3Ptr->lostItemsTracker.lostItems[i] == itemId)
        {
            gSaveBlock3Ptr->lostItemsTracker.lostItems[i] = ITEM_NONE;
            gSpecialVar_Result = TRUE;
            break;
        }
    }
    return FALSE;
}

// ADDED
bool8 ScrCmd_healpartymon(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    u8 i;
    struct Pokemon *mon;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES, NULL) == species &&
            GetMonData(mon, MON_DATA_IS_EGG, NULL) == FALSE)
        {
            HealPokemon(mon);
            gSpecialVar_Result = i; // return slot index
            return FALSE;
        }
    }

    gSpecialVar_Result = PARTY_SIZE; // not found
    return FALSE;
}

// ADDED
bool8 ScrCmd_partymonhasfainted(struct ScriptContext *ctx)
{
    s32 i;

    gSpecialVar_Result = PARTY_SIZE; 
    gSpecialVar_0x8004 = SPECIES_NONE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
        {
            u8 hp = GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL);
            if (hp == 0) 
            {
                gSpecialVar_Result = i; 
                gSpecialVar_0x8004 = species; 
                break;
            }
        }
    }

    return FALSE;
}

// ADDED
bool8 ScrCmd_checkpartymonfullhp(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    s32 i;

    gSpecialVar_Result = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == species
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
        {
            u16 hp = GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL);
            u16 maxHp = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP, NULL);

            if (hp == maxHp)
            {
                gSpecialVar_Result = TRUE;
                break;
            }
        }
    }

    return FALSE;
}

// ADDED
bool8 ScrCmd_checkpartymon(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx)); 
    u8 i;

    gSpecialVar_Result = PARTY_SIZE; 

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 monSpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (monSpecies == species)
        {
            gSpecialVar_Result = i; // set the slot where species is found
            break; 
        }
    }
    return FALSE;
}

// ADDED
// remove a move from a party Pokémon, with VARs as arguments
bool8 ScrCmd_replacemove(struct ScriptContext *ctx)
{
    u8 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u16 moveId_old = VarGet(ScriptReadHalfword(ctx));
    u16 moveId_new = VarGet(ScriptReadHalfword(ctx));
    u8 slot, i, j;

    gSpecialVar_Result = MAX_MON_MOVES;

    if (partyIndex < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[partyIndex];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);

        if (species && !GetMonData(mon, MON_DATA_IS_EGG))
        {
            // Replace move
            for (slot = 0; slot < MAX_MON_MOVES; slot++)
            {
                if (GetMonData(mon, MON_DATA_MOVE1 + slot) == moveId_old)
                {
                    ScriptSetMonMoveSlot(partyIndex, moveId_new, slot);
                    gSpecialVar_Result = slot;
                    break;
                }
            }

            // Reorder: move all MOVE_NONE to the end
            for (i = 0; i < MAX_MON_MOVES - 1; i++)
            {
                for (j = 0; j < MAX_MON_MOVES - 1 - i; j++)
                {
                    u16 move1 = GetMonData(mon, MON_DATA_MOVE1 + j, NULL);
                    u16 move2 = GetMonData(mon, MON_DATA_MOVE1 + j + 1, NULL);

                    if (move1 == MOVE_NONE && move2 != MOVE_NONE)
                        ShiftMoveSlot(mon, j, j + 1);
                }
            }
        }
    }

    return FALSE;
}

// ADDED
// replace a move via species, with VARs as arguments
bool8 ScrCmd_replacemove2(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 moveId_old = VarGet(ScriptReadHalfword(ctx));
    u16 moveId_new = VarGet(ScriptReadHalfword(ctx));
    u8 slot, i, j;

    gSpecialVar_Result = MAX_MON_MOVES; // default: not replaced

    // find first matching species in party
    for (u8 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
    {
        struct Pokemon *mon = &gPlayerParty[partyIndex];
        u16 monSpecies = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (monSpecies != SPECIES_NONE && monSpecies == species && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            // Replace move
            for (slot = 0; slot < MAX_MON_MOVES; slot++)
            {
                if (GetMonData(mon, MON_DATA_MOVE1 + slot) == moveId_old)
                {
                    ScriptSetMonMoveSlot(partyIndex, moveId_new, slot);
                    gSpecialVar_Result = slot;
                    break;
                }
            }

            // Reorder: move all MOVE_NONE to the end
            for (i = 0; i < MAX_MON_MOVES - 1; i++)
            {
                for (j = 0; j < MAX_MON_MOVES - 1 - i; j++)
                {
                    u16 move1 = GetMonData(mon, MON_DATA_MOVE1 + j, NULL);
                    u16 move2 = GetMonData(mon, MON_DATA_MOVE1 + j + 1, NULL);

                    if (move1 == MOVE_NONE && move2 != MOVE_NONE)
                        ShiftMoveSlot(mon, j, j + 1);
                }
            }

            break; // done with first matching species
        }
    }

    return FALSE;
}

// ADDED
bool8 ScrCmd_checkpartymonlevel(struct ScriptContext *ctx)
{
    u8 i;
    u16 level = ScriptReadHalfword(ctx);

    gSpecialVar_Result = PARTY_SIZE;  
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (!species)
            break;  
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) && GetMonData(&gPlayerParty[i], MON_DATA_LEVEL, NULL) == level)
        {
            gSpecialVar_Result = i; 
            gSpecialVar_0x8004 = species; 
            break;
        }
    }
    return FALSE;
}

// ADDED
bool8 ScrCmd_levelDownMon(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);  

    gSpecialVar_Result = PARTY_SIZE;  

    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        u16 currentSpecies = GetMonData(mon, MON_DATA_SPECIES, NULL);
        u8 currentLevel = GetMonData(mon, MON_DATA_LEVEL, NULL);

        if (currentSpecies == SPECIES_NONE || currentSpecies == SPECIES_EGG) // skip invalid entries
            continue;

        if (currentSpecies == species)
        {
            if (currentLevel > 1)
            {
                u8 targetLevel = currentLevel - 1;
                u8 growthRate = gSpeciesInfo[currentSpecies].growthRate;
                u32 newExp = gExperienceTables[growthRate][targetLevel];

                // set new exp amount
                SetMonData(mon, MON_DATA_EXP, &newExp);

                // recalculate stats for the Pokémon
                CalculateMonStats(mon);

                // // check if the Pokémon learned any move at the undone level
                // const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
                // u16 moveLearned = MOVE_NONE;
                // for (u8 j = 0; learnset[j].level != LEVEL_UP_MOVE_END; j++)
                // {
                //     if (learnset[j].level == currentLevel)
                //         moveLearned = learnset[j].move; 
                // }

                // remove move Sketch
                for (u8 j = 0; j < MAX_MON_MOVES; j++)
                {
                    u16 move = GetMonData(mon, MON_DATA_MOVE1 + j, NULL);
                    if (move == MOVE_SKETCH)
                    {
                        // remove the move
                        SetMonMoveSlot(mon, MOVE_NONE, j);
                        RemoveMonPPBonus(mon, j);

                        // shift the remaining moves
                        for (u8 k = j; k < MAX_MON_MOVES - 1; k++)
                            ShiftMoveSlot(mon, k, k + 1);
                        break;
                    }
                }

                // set result to the party slot of the Pokémon
                gSpecialVar_Result = i;
            }
            else
            {
                gSpecialVar_Result = PARTY_SIZE;
            }
            break;
        }
    }
    return FALSE; 
}

// ADDED
static void ShiftMoveSlot(struct Pokemon *mon, u8 slotTo, u8 slotFrom)
{
    u16 moveFrom = GetMonData(mon, MON_DATA_MOVE1 + slotFrom, NULL);
    u16 moveTo = GetMonData(mon, MON_DATA_MOVE1 + slotTo, NULL);
    u8 ppFrom = GetMonData(mon, MON_DATA_PP1 + slotFrom, NULL);
    u8 ppTo = GetMonData(mon, MON_DATA_PP1 + slotTo, NULL);
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    
    // shift PP bonuses
    u8 ppBonusMaskFrom = gPPUpGetMask[slotFrom];
    u8 ppBonusMaskTo = gPPUpGetMask[slotTo];
    u8 ppBonusFrom = (ppBonuses & ppBonusMaskFrom) >> (slotFrom * 2);
    u8 ppBonusTo = (ppBonuses & ppBonusMaskTo) >> (slotTo * 2);

    ppBonuses &= ~ppBonusMaskTo;
    ppBonuses &= ~ppBonusMaskFrom;
    ppBonuses |= (ppBonusFrom << (slotTo * 2)) + (ppBonusTo << (slotFrom * 2));

    // set new move and PP data
    SetMonData(mon, MON_DATA_MOVE1 + slotTo, &moveFrom);
    SetMonData(mon, MON_DATA_MOVE1 + slotFrom, &moveTo);
    SetMonData(mon, MON_DATA_PP1 + slotTo, &ppFrom);
    SetMonData(mon, MON_DATA_PP1 + slotFrom, &ppTo);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

// ADDED
bool8 ScrCmd_getpartymonmove(struct ScriptContext *ctx)
{
    u8 partyIndex = VarGet(ScriptReadHalfword(ctx)); 
    u8 moveSlot = VarGet(ScriptReadHalfword(ctx)); 
    struct Pokemon *mon;
    u16 move = MOVE_NONE;

    if (partyIndex >= PARTY_SIZE)
    {
        gSpecialVar_Result = MOVE_NONE; // invalid party index
        return FALSE;
    }

    mon = &gPlayerParty[partyIndex];
    if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_NONE || GetMonData(mon, MON_DATA_IS_EGG, NULL))
    {
        gSpecialVar_Result = MOVE_NONE; // no valid Pokémon in the slot
        return FALSE;
    }

    if (moveSlot < MAX_MON_MOVES)
        move = GetMonData(mon, MON_DATA_MOVE1 + moveSlot, NULL);

    gSpecialVar_Result = move;

    return FALSE;
}

// ADDED
bool8 ScrCmd_bufferplaytimeandhints(struct ScriptContext *ctx)
{
    u8 *dest = gStringVar1;

    // buffer the playtime hours
    dest = ConvertIntToDecimalStringN(dest, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *(dest++) = CHAR_COLON;
    ConvertIntToDecimalStringN(dest, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);

    // buffer VAR_HINTS_USED_COUNTER into gStringVar2
    u16 hintsUsed = VarGet(VAR_HINTS_USED_COUNTER); 
    if (hintsUsed < 10)
        ConvertIntToDecimalStringN(gStringVar2, hintsUsed, STR_CONV_MODE_LEFT_ALIGN, 1);
    else
        ConvertIntToDecimalStringN(gStringVar2, hintsUsed, STR_CONV_MODE_LEFT_ALIGN, 2);

    return FALSE;
}

// ADDED
bool8 ScrCmd_addgametime(struct ScriptContext *ctx)
{
    u16 time = ScriptReadHalfword(ctx); 

    // Convert current play time to total minutes
    u32 totalMinutes = (gSaveBlock2Ptr->playTimeHours * 60) + gSaveBlock2Ptr->playTimeMinutes;

    // Add the provided time to the total minutes
    totalMinutes += time;

    // Recalculate hours and minutes from the new total
    gSaveBlock2Ptr->playTimeHours = totalMinutes / 60;
    gSaveBlock2Ptr->playTimeMinutes = totalMinutes % 60;

    // Handle overflow: if playtime exceeds 999 hours, cap it
    if (gSaveBlock2Ptr->playTimeHours > 999)
    {
        gSaveBlock2Ptr->playTimeHours = 999;
        gSaveBlock2Ptr->playTimeMinutes = 59; // Cap at the max allowable time
    }

    return FALSE;
}

// ADDED
// backup first matching party mon of species to PC Box 0 Slot 0
bool8 ScrCmd_backupmontopc(struct ScriptContext *ctx)                               
{                                                                       
    u16 species = ScriptReadHalfword(ctx);
    u8 i;

    gSpecialVar_Result = FALSE;
                                  
    for (i = 0; i < PARTY_SIZE; i++)                                
    {                                                                   
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == species) 
        {                                                           
            // send to PC    
            MonToBoxMon(&gPlayerParty[i], &gPokemonStoragePtr->boxes[0][0]); 

            // remove held item from backup
            SetBoxMonData(&gPokemonStoragePtr->boxes[0][0], MON_DATA_HELD_ITEM, &(u16){ITEM_NONE});

            gSpecialVar_Result = TRUE;                             
            break;                                                      
        }
    } 
    return FALSE;
}

// ADDED
// copy mon to pc
void MonToBoxMon(const struct Pokemon *src, struct BoxPokemon *dest)
{
    *dest = src->box;
}

// ADDED
// restore backup from PC Box 0 Slot 0 to first empty party slot
bool8 ScrCmd_restoremonfrompc(struct ScriptContext *ctx)
{  
    u16 species = ScriptReadHalfword(ctx);
    u8 i;

    gSpecialVar_Result = FALSE;

    struct BoxPokemon *backup = &gPokemonStoragePtr->boxes[0][0]; 
    if (GetBoxMonData(backup, MON_DATA_SPECIES) == species) 
    {       
        for (i = 0; i < PARTY_SIZE; i++) 
        {    
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE)
            {  
                // restore from PC
                BoxMonToMon(backup, &gPlayerParty[i]);  

                gSpecialVar_Result = TRUE; 
                break;  
            }   
        } 
    }  
    return FALSE;
}

// ADDED
bool8 ScrCmd_checkexactmoney(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);

    gSpecialVar_Result = GetMoney(&gSaveBlock1Ptr->money) == amount;
    return FALSE;
}


// ADDED
// can take VARs as arguments
bool8 ScrCmd_removetaughtmove(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 newMove = VarGet(ScriptReadHalfword(ctx));
    gSpecialVar_Result = FALSE;

    for (int i = 0; i < MAX_TAUGHT_MOVES; i++)
    {
        struct TaughtMoveEntry *e = &gSaveBlock3Ptr->taughtMoveLog.entries[i];
        if (e->species == species && e->newMove == newMove)
        {
            e->species = SPECIES_NONE;
            e->oldMove = MOVE_NONE;
            e->newMove = MOVE_NONE;
            gSpecialVar_Result = TRUE;
            break;
        }
    }

    return FALSE;
}

// ADDED
// can take VARs as arguments
bool8 ScrCmd_istaughtmovepresent(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 newMove = VarGet(ScriptReadHalfword(ctx));
    gSpecialVar_Result = FALSE;

    for (int i = 0; i < MAX_TAUGHT_MOVES; i++)
    {
        struct TaughtMoveEntry *e = &gSaveBlock3Ptr->taughtMoveLog.entries[i];
        if (e->species == species && e->newMove == newMove)
        {
            gSpecialVar_Result = TRUE;
            gSpecialVar_0x8004 = e->oldMove;
            break;
        }
    }
    return FALSE;
}







bool8 ScrCmd_addmoney(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        AddMoney(&gSaveBlock1Ptr->money, amount);
    return FALSE;
}

bool8 ScrCmd_removemoney(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        RemoveMoney(&gSaveBlock1Ptr->money, amount);
    return FALSE;
}

bool8 ScrCmd_checkmoney(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        gSpecialVar_Result = IsEnoughMoney(&gSaveBlock1Ptr->money, amount);
    return FALSE;
}

bool8 ScrCmd_showmoneybox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        DrawMoneyBox(GetMoney(&gSaveBlock1Ptr->money), x, y);
    return FALSE;
}

bool8 ScrCmd_hidemoneybox(struct ScriptContext *ctx)
{
    /*u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);*/

    HideMoneyBox();
    return FALSE;
}

bool8 ScrCmd_updatemoneybox(struct ScriptContext *ctx)
{
    u8 UNUSED x = ScriptReadByte(ctx);
    u8 UNUSED y = ScriptReadByte(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        ChangeAmountInMoneyBox(GetMoney(&gSaveBlock1Ptr->money));
    return FALSE;
}

bool8 ScrCmd_showcoinsbox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    ShowCoinsWindow(GetCoins(), x, y);
    return FALSE;
}

bool8 ScrCmd_hidecoinsbox(struct ScriptContext *ctx)
{
    u8 UNUSED x = ScriptReadByte(ctx);
    u8 UNUSED y = ScriptReadByte(ctx);

    HideCoinsWindow();
    return FALSE;
}

bool8 ScrCmd_updatecoinsbox(struct ScriptContext *ctx)
{
    u8 UNUSED x = ScriptReadByte(ctx);
    u8 UNUSED y = ScriptReadByte(ctx);

    PrintCoinsString(GetCoins());
    return FALSE;
}

bool8 ScrCmd_trainerbattle(struct ScriptContext *ctx)
{
    // ADDED
    // first backup player party
    BackupPlayerParty();

    ctx->scriptPtr = BattleSetup_ConfigureTrainerBattle(ctx->scriptPtr);
    return FALSE;
}

bool8 ScrCmd_dotrainerbattle(struct ScriptContext *ctx)
{
    BattleSetup_StartTrainerBattle();
    return TRUE;
}

bool8 ScrCmd_gotopostbattlescript(struct ScriptContext *ctx)
{
    ctx->scriptPtr = BattleSetup_GetScriptAddrAfterBattle();
    return FALSE;
}

bool8 ScrCmd_gotobeatenscript(struct ScriptContext *ctx)
{
    ctx->scriptPtr = BattleSetup_GetTrainerPostBattleScript();
    return FALSE;
}

bool8 ScrCmd_checktrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));

    ctx->comparisonResult = HasTrainerBeenFought(index);
    return FALSE;
}

bool8 ScrCmd_settrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));

    SetTrainerFlag(index);
    return FALSE;
}

bool8 ScrCmd_cleartrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));

    ClearTrainerFlag(index);
    return FALSE;
}

bool8 ScrCmd_setwildbattle(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    u8 level = ScriptReadByte(ctx);
    u16 item = ScriptReadHalfword(ctx);
    u16 species2 = ScriptReadHalfword(ctx);
    u8 level2 = ScriptReadByte(ctx);
    u16 item2 = ScriptReadHalfword(ctx);

    if(species2 == SPECIES_NONE)
    {
        CreateScriptedWildMon(species, level, item);
        sIsScriptedWildDouble = FALSE;
    }
    else
    {
        CreateScriptedDoubleWildMon(species, level, item, species2, level2, item2);
        sIsScriptedWildDouble = TRUE;
    }

    return FALSE;
}

bool8 ScrCmd_dowildbattle(struct ScriptContext *ctx)
{
    if (sIsScriptedWildDouble == FALSE)
        BattleSetup_StartScriptedWildBattle();
    else
        BattleSetup_StartScriptedDoubleWildBattle();

    ScriptContext_Stop();

    return TRUE;
}

bool8 ScrCmd_pokemart(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);

    CreatePokemartMenu(ptr);
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_pokemartdecoration(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);

    CreateDecorationShop1Menu(ptr);
    ScriptContext_Stop();
    return TRUE;
}

// Changes clerk dialogue slightly from above. See MART_TYPE_DECOR2
bool8 ScrCmd_pokemartdecoration2(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);

    CreateDecorationShop2Menu(ptr);
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_playslotmachine(struct ScriptContext *ctx)
{
    u8 machineId = VarGet(ScriptReadHalfword(ctx));

    PlaySlotMachine(machineId, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_setberrytree(struct ScriptContext *ctx)
{
    u8 treeId = ScriptReadByte(ctx);
    u8 berry = ScriptReadByte(ctx);
    u8 growthStage = ScriptReadByte(ctx);

    if (berry == 0)
        PlantBerryTree(treeId, berry, growthStage, FALSE);
    else
        PlantBerryTree(treeId, berry, growthStage, FALSE);
    return FALSE;
}

bool8 ScrCmd_getpokenewsactive(struct ScriptContext *ctx)
{
    u16 newsKind = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = IsPokeNewsActive(newsKind);
    return FALSE;
}

bool8 ScrCmd_choosecontestmon(struct ScriptContext *ctx)
{
    ChooseContestMon();
    ScriptContext_Stop();
    return TRUE;
}


bool8 ScrCmd_startcontest(struct ScriptContext *ctx)
{
    StartContest();
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_showcontestresults(struct ScriptContext *ctx)
{
    ShowContestResults();
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_contestlinktransfer(struct ScriptContext *ctx)
{
    ContestLinkTransfer(gSpecialVar_ContestCategory);
    ScriptContext_Stop();
    return TRUE;
}

bool8 ScrCmd_dofieldeffect(struct ScriptContext *ctx)
{
    u16 effectId = VarGet(ScriptReadHalfword(ctx));

    sFieldEffectScriptId = effectId;
    FieldEffectStart(sFieldEffectScriptId);
    return FALSE;
}

bool8 ScrCmd_setfieldeffectargument(struct ScriptContext *ctx)
{
    u8 argNum = ScriptReadByte(ctx);

    gFieldEffectArguments[argNum] = (s16)VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

static bool8 WaitForFieldEffectFinish(void)
{
    if (!FieldEffectActiveListContains(sFieldEffectScriptId))
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_waitfieldeffect(struct ScriptContext *ctx)
{
    sFieldEffectScriptId = VarGet(ScriptReadHalfword(ctx));
    SetupNativeScript(ctx, WaitForFieldEffectFinish);
    return TRUE;
}

bool8 ScrCmd_setrespawn(struct ScriptContext *ctx)
{
    u16 healLocationId = VarGet(ScriptReadHalfword(ctx));

    SetLastHealLocationWarp(healLocationId);
    return FALSE;
}

bool8 ScrCmd_checkplayergender(struct ScriptContext *ctx)
{
    gSpecialVar_Result = gSaveBlock2Ptr->playerGender;
    return FALSE;
}

bool8 ScrCmd_playmoncry(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 mode = VarGet(ScriptReadHalfword(ctx));

    PlayCry_Script(species, mode);
    return FALSE;
}

void PlayFirstMonCry(struct ScriptContext *ctx)
{
    PlayCry_Script(GetMonData(GetFirstLiveMon(), MON_DATA_SPECIES), CRY_MODE_NORMAL);
}

bool8 ScrCmd_waitmoncry(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, IsCryFinished);
    return TRUE;
}

bool8 ScrCmd_setmetatile(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));
    u16 metatileId = VarGet(ScriptReadHalfword(ctx));
    bool16 isImpassable = VarGet(ScriptReadHalfword(ctx));

    x += MAP_OFFSET;
    y += MAP_OFFSET;
    if (!isImpassable)
        MapGridSetMetatileIdAt(x, y, metatileId);
    else
        MapGridSetMetatileIdAt(x, y, metatileId | MAPGRID_COLLISION_MASK);
    return FALSE;
}

bool8 ScrCmd_opendoor(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += MAP_OFFSET;
    y += MAP_OFFSET;
    PlaySE(GetDoorSoundEffect(x, y));
    FieldAnimateDoorOpen(x, y);
    return FALSE;
}

bool8 ScrCmd_closedoor(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += MAP_OFFSET;
    y += MAP_OFFSET;
    FieldAnimateDoorClose(x, y);
    return FALSE;
}

static bool8 IsDoorAnimationStopped(void)
{
    if (!FieldIsDoorAnimationRunning())
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_waitdooranim(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, IsDoorAnimationStopped);
    return TRUE;
}

bool8 ScrCmd_setdooropen(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += MAP_OFFSET;
    y += MAP_OFFSET;
    FieldSetDoorOpened(x, y);
    return FALSE;
}

bool8 ScrCmd_setdoorclosed(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += MAP_OFFSET;
    y += MAP_OFFSET;
    FieldSetDoorClosed(x, y);
    return FALSE;
}

// Below two are functions for elevators in RS, do nothing in Emerald
bool8 ScrCmd_addelevmenuitem(struct ScriptContext *ctx)
{
    u8 UNUSED v3 = ScriptReadByte(ctx);
    u16 UNUSED v5 = VarGet(ScriptReadHalfword(ctx));
    u16 UNUSED v7 = VarGet(ScriptReadHalfword(ctx));
    u16 UNUSED v9 = VarGet(ScriptReadHalfword(ctx));

    //ScriptAddElevatorMenuItem(v3, v5, v7, v9);
    return FALSE;
}

bool8 ScrCmd_showelevmenu(struct ScriptContext *ctx)
{
    /*ScriptShowElevatorMenu();
    ScriptContext_Stop();
    return TRUE;*/
    return FALSE;
}

bool8 ScrCmd_checkcoins(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = GetCoins();
    return FALSE;
}

bool8 ScrCmd_addcoins(struct ScriptContext *ctx)
{
    u16 coins = VarGet(ScriptReadHalfword(ctx));

    if (AddCoins(coins) == TRUE)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
    return FALSE;
}

bool8 ScrCmd_removecoins(struct ScriptContext *ctx)
{
    u16 coins = VarGet(ScriptReadHalfword(ctx));

    if (RemoveCoins(coins) == TRUE)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
    return FALSE;
}

bool8 ScrCmd_moverotatingtileobjects(struct ScriptContext *ctx)
{
    u16 puzzleNumber = VarGet(ScriptReadHalfword(ctx));

    sMovingNpcId = MoveRotatingTileObjects(puzzleNumber);
    return FALSE;
}

bool8 ScrCmd_turnrotatingtileobjects(struct ScriptContext *ctx)
{
    TurnRotatingTileObjects();
    return FALSE;
}

bool8 ScrCmd_initrotatingtilepuzzle(struct ScriptContext *ctx)
{
    u16 isTrickHouse = VarGet(ScriptReadHalfword(ctx));

    InitRotatingTilePuzzle(isTrickHouse);
    return FALSE;
}

bool8 ScrCmd_freerotatingtilepuzzle(struct ScriptContext *ctx)
{
    FreeRotatingTilePuzzle();
    return FALSE;
}

bool8 ScrCmd_selectapproachingtrainer(struct ScriptContext *ctx)
{
    gSelectedObjectEvent = GetCurrentApproachingTrainerObjectEventId();
    return FALSE;
}

bool8 ScrCmd_lockfortrainer(struct ScriptContext *ctx)
{
    if (IsOverworldLinkActive())
    {
        return FALSE;
    }
    else
    {
        if (gObjectEvents[gSelectedObjectEvent].active)
        {
            FreezeForApproachingTrainers();
            SetupNativeScript(ctx, IsFreezeObjectAndPlayerFinished);
        }
        return TRUE;
    }
}

// This command will set a Pokémon's modernFatefulEncounter bit; there is no similar command to clear it.
bool8 ScrCmd_setmodernfatefulencounter(struct ScriptContext *ctx)
{
    bool8 isModernFatefulEncounter = TRUE;
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));

    SetMonData(&gPlayerParty[partyIndex], MON_DATA_MODERN_FATEFUL_ENCOUNTER, &isModernFatefulEncounter);
    return FALSE;
}

bool8 ScrCmd_checkmodernfatefulencounter(struct ScriptContext *ctx)
{
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MODERN_FATEFUL_ENCOUNTER, NULL);
    return FALSE;
}

bool8 ScrCmd_trywondercardscript(struct ScriptContext *ctx)
{
    const u8 *script = GetSavedRamScriptIfValid();

    if (script)
    {
        gRamScriptRetAddr = ctx->scriptPtr;
        ScriptJump(ctx, script);
    }
    return FALSE;
}

// This warp is only used by the Union Room.
// For the warp used by the Aqua Hideout, see DoTeleportTileWarp
bool8 ScrCmd_warpspinenter(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    SetSpinStartFacingDir(GetPlayerFacingDirection());
    DoSpinEnterWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_setmonmetlocation(struct ScriptContext *ctx)
{
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u8 location = ScriptReadByte(ctx);

    if (partyIndex < PARTY_SIZE)
        SetMonData(&gPlayerParty[partyIndex], MON_DATA_MET_LOCATION, &location);
    return FALSE;
}

static void CloseBrailleWindow(void)
{
    ClearStdWindowAndFrame(sBrailleWindowId, TRUE);
    RemoveWindow(sBrailleWindowId);
}

bool8 ScrCmd_buffertrainerclassname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 trainerClassId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetTrainerClassNameFromId(trainerClassId));
    return FALSE;
}

bool8 ScrCmd_buffertrainername(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 trainerClassId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetTrainerNameFromId(trainerClassId));
    return FALSE;
}

void SetMovingNpcId(u16 npcId)
{
    sMovingNpcId = npcId;
}

bool8 ScrCmd_warpwhitefade(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoWhiteFadeWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

void ScriptSetDoubleBattleFlag(struct ScriptContext *ctx)
{
    sIsScriptedWildDouble = TRUE;
}
