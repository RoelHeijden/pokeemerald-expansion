EscapeRoom_Main_MapScripts::
# 46 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 47 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 49 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 53 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 50 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 54 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 55 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 56 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 57 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_REMOVE_HELD_ITEM, 1, EscapeRoom_MapScripts_RemoveHeldItem
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 64 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_1
	return

EscapeRoom_MapScript_OnTransitionScripts_1:
# 65 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	return


EscapeRoom_MapScript_OnResumeScripts::
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScript_OnResumeScripts_3
EscapeRoom_MapScript_OnResumeScripts_1:
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_8
EscapeRoom_MapScript_OnResumeScripts_6:
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScript_OnResumeScripts_12
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScript_OnResumeScripts_12
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScript_OnResumeScripts_12
EscapeRoom_MapScript_OnResumeScripts_11:
# 93 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_STARDUST_STOLEN, EscapeRoom_MapScript_OnResumeScripts_19
EscapeRoom_MapScript_OnResumeScripts_18:
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_21
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_FERRO_CUSTAP
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_3:
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_7:
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_8:
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_7
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_12:
# 89 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_11

EscapeRoom_MapScript_OnResumeScripts_19:
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStardustStolen
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_21:
# 99 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 111 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 112 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 118 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 121 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScripts_RetrievedItemMessage_5
EscapeRoom_MapScripts_RetrievedItemMessage_4:
# 135 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScripts_RetrievedItemMessage_8
EscapeRoom_MapScripts_RetrievedItemMessage_7:
# 141 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox WhiteHerbRecoveredMessage, MSGBOX_AUTOCLOSE
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1

EscapeRoom_MapScripts_RetrievedItemMessage_5:
# 129 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CustapBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 131 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
	goto EscapeRoom_MapScripts_RetrievedItemMessage_4

EscapeRoom_MapScripts_RetrievedItemMessage_8:
# 136 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MarangaBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 137 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
	goto EscapeRoom_MapScripts_RetrievedItemMessage_7


EscapeRoom_MapScripts_RemoveHeldItem::
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_FERRO_CUSTAP, EscapeRoom_MapScripts_RemoveHeldItem_2
EscapeRoom_MapScripts_RemoveHeldItem_1:
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 0
	return

EscapeRoom_MapScripts_RemoveHeldItem_2:
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_FERRO_CUSTAP
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveFerroCustap
	goto EscapeRoom_MapScripts_RemoveHeldItem_1


EscapeRoom_MapScripts_RemoveFerroCustap::
# 156 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 157 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveFerroCustap_1
	return

EscapeRoom_MapScripts_RemoveFerroCustap_1:
# 159 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveFerroCustap_3
	return

EscapeRoom_MapScripts_RemoveFerroCustap_3:
# 161 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_CheckStardustStolen::
# 167 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STARDUST
# 168 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_2
EscapeRoom_MapScripts_CheckStardustStolen_1:
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_5
EscapeRoom_MapScripts_CheckStardustStolen_4:
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 176 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_8
EscapeRoom_MapScripts_CheckStardustStolen_7:
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_10
	return

EscapeRoom_MapScripts_CheckStardustStolen_2:
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_1

EscapeRoom_MapScripts_CheckStardustStolen_5:
# 173 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_4

EscapeRoom_MapScripts_CheckStardustStolen_8:
# 177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_7

EscapeRoom_MapScripts_CheckStardustStolen_10:
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	return


EscapeRoom_MapScript_GameStartScripts::
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 204 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 205 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_WHITE_HERB, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 1, defIv = 3, speedIv = 31, spAtkIv = 0, spDefIv = 30
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SLEEP_TALK, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 284 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 285 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 289 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 292 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 293 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 294 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 298 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 299 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 300 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 301 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
	return


EscapeRoom_MapScripts_GetItems::
# 312 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_EXP_CANDY_S
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 316 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_MainInfoSign::
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 332 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_EndSign::
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndSignMessage, MSGBOX_AUTOCLOSE
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 371 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 372 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 374 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 375 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 404 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LostGlassesNPC::
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCmainMessage, MSGBOX_AUTOCLOSE
# 413 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_WISE_GLASSES
# 414 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_2
EscapeRoom_EventScript_LostGlassesNPC_1:
# 452 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LostGlassesNPC_2:
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_5
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 432 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCGlassesFoundMessage, MSGBOX_AUTOCLOSE
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_WISE_GLASSES
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCendMessage, MSGBOX_AUTOCLOSE
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, EscapeRoom_Movement_LostGlassesNPC
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 443 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 444 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LostGlassesNPC_1

EscapeRoom_EventScript_LostGlassesNPC_5:
# 420 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_ObtainLiepard::
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 50, abilityNum = 2, nature = 17, gender = 0, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_ECHOED_VOICE, atkEv = 140, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 18, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	return


# 485 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_LostGlassesNPC:
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_EventScript_RelocateNurseNPC::
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 522 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 526 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_up
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 533 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 538 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 543 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 559 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 564 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 565 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

	.align 2
# 572 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM12
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_DEFAULT
# 585 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_MoveDeleterNPC_Text_0, EscapeRoom_MoveDeleterNPC_Text_1
# 590 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_2
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_3
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
EscapeRoom_MoveDeleterNPC_1:
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 591 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_1

EscapeRoom_MoveDeleterNPC_3:
# 595 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
	goto EscapeRoom_MoveDeleterNPC_1


EscapeRoom_ChooseMoveToDelete::
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 609 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EscapeRoom_ChooseMoveToDelete_2
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	special GetNumMovesSelectedMonHas
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_ChooseMoveToDelete_5
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
	goto_if_eq EscapeRoom_ChooseMoveToDelete_8
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_MOVE_DELETER_CHOSEN_SLOT
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	special MoveDeleterForgetMove
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterMoveDeleted, MSGBOX_AUTOCLOSE
	end

EscapeRoom_ChooseMoveToDelete_2:
# 610 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_5:
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOnlyOneMove, MSGBOX_AUTOCLOSE
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_8:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_RestoreMoveset::
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_3
EscapeRoom_RestoreMoveset_1:
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_6:
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_16
EscapeRoom_RestoreMoveset_14:
# 737 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_27
EscapeRoom_RestoreMoveset_25:
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_39
	return

EscapeRoom_RestoreMoveset_2:
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ICE_FANG_DELETED, EscapeRoom_RestoreMoveset_12
EscapeRoom_RestoreMoveset_11:
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SLEEP_TALK_DELETED, EscapeRoom_RestoreMoveset_23
EscapeRoom_RestoreMoveset_22:
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ENDEAVOR_DELETED, EscapeRoom_RestoreMoveset_37
EscapeRoom_RestoreMoveset_36:
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TAUNT_DELETED, EscapeRoom_RestoreMoveset_51
EscapeRoom_RestoreMoveset_50:
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 672 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_POOCH_MOVE_DELETED
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_3:
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_MOVE_DELETED, EscapeRoom_RestoreMoveset_2
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_7:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ASSIST_DELETED, EscapeRoom_RestoreMoveset_20
EscapeRoom_RestoreMoveset_19:
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_DELETED, EscapeRoom_RestoreMoveset_34
EscapeRoom_RestoreMoveset_33:
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ECHOED_VOICE_DELETED, EscapeRoom_RestoreMoveset_48
EscapeRoom_RestoreMoveset_47:
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRICK_DELETED, EscapeRoom_RestoreMoveset_60
EscapeRoom_RestoreMoveset_59:
# 701 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_6

EscapeRoom_RestoreMoveset_8:
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_MOVE_DELETED, EscapeRoom_RestoreMoveset_7
	goto EscapeRoom_RestoreMoveset_6

EscapeRoom_RestoreMoveset_12:
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_ICE_FANG
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ICE_FANG_DELETED
	goto EscapeRoom_RestoreMoveset_11

EscapeRoom_RestoreMoveset_15:
# 710 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRUMP_CARD_DELETED, EscapeRoom_RestoreMoveset_31
EscapeRoom_RestoreMoveset_30:
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HEX_DELETED, EscapeRoom_RestoreMoveset_45
EscapeRoom_RestoreMoveset_44:
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_COUNTER_DELETED, EscapeRoom_RestoreMoveset_57
EscapeRoom_RestoreMoveset_56:
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIR_SLASH_DELETED, EscapeRoom_RestoreMoveset_66
EscapeRoom_RestoreMoveset_65:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 732 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_14

EscapeRoom_RestoreMoveset_16:
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_MOVE_DELETED, EscapeRoom_RestoreMoveset_15
	goto EscapeRoom_RestoreMoveset_14

EscapeRoom_RestoreMoveset_20:
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ASSIST
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ASSIST_DELETED
	goto EscapeRoom_RestoreMoveset_19

EscapeRoom_RestoreMoveset_23:
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_SLEEP_TALK
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SLEEP_TALK_DELETED
	goto EscapeRoom_RestoreMoveset_22

EscapeRoom_RestoreMoveset_26:
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SURF_DELETED, EscapeRoom_RestoreMoveset_42
EscapeRoom_RestoreMoveset_41:
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SWITCHEROO_DELETED, EscapeRoom_RestoreMoveset_54
EscapeRoom_RestoreMoveset_53:
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UPROAR_DELETED, EscapeRoom_RestoreMoveset_63
EscapeRoom_RestoreMoveset_62:
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CONVERSION_2_DELETED, EscapeRoom_RestoreMoveset_69
EscapeRoom_RestoreMoveset_68:
# 761 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SmeargleMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SMEARGLE_MOVE_DELETED
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_25

EscapeRoom_RestoreMoveset_27:
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SMEARGLE_MOVE_DELETED, EscapeRoom_RestoreMoveset_26
	goto EscapeRoom_RestoreMoveset_25

EscapeRoom_RestoreMoveset_31:
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_TRUMP_CARD
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRUMP_CARD_DELETED
	goto EscapeRoom_RestoreMoveset_30

EscapeRoom_RestoreMoveset_34:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ROCK_SMASH
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ROCK_SMASH_DELETED
	goto EscapeRoom_RestoreMoveset_33

EscapeRoom_RestoreMoveset_37:
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_ENDEAVOR
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ENDEAVOR_DELETED
	goto EscapeRoom_RestoreMoveset_36

EscapeRoom_RestoreMoveset_39:
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return

EscapeRoom_RestoreMoveset_42:
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_SURF
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SURF_DELETED
	goto EscapeRoom_RestoreMoveset_41

EscapeRoom_RestoreMoveset_45:
# 717 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_HEX
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HEX_DELETED
	goto EscapeRoom_RestoreMoveset_44

EscapeRoom_RestoreMoveset_48:
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ECHOED_VOICE
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ECHOED_VOICE_DELETED
	goto EscapeRoom_RestoreMoveset_47

EscapeRoom_RestoreMoveset_51:
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_TAUNT
# 668 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TAUNT_DELETED
	goto EscapeRoom_RestoreMoveset_50

EscapeRoom_RestoreMoveset_54:
# 747 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_SWITCHEROO
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SWITCHEROO_DELETED
	goto EscapeRoom_RestoreMoveset_53

EscapeRoom_RestoreMoveset_57:
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_COUNTER
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_COUNTER_DELETED
	goto EscapeRoom_RestoreMoveset_56

EscapeRoom_RestoreMoveset_60:
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_TRICK
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRICK_DELETED
	goto EscapeRoom_RestoreMoveset_59

EscapeRoom_RestoreMoveset_63:
# 752 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_UPROAR
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UPROAR_DELETED
	goto EscapeRoom_RestoreMoveset_62

EscapeRoom_RestoreMoveset_66:
# 727 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_AIR_SLASH
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIR_SLASH_DELETED
	goto EscapeRoom_RestoreMoveset_65

EscapeRoom_RestoreMoveset_69:
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_CONVERSION_2
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CONVERSION_2_DELETED
	goto EscapeRoom_RestoreMoveset_68


EscapeRoom_UltraBallNPC::
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 777 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_NPC
EscapeRoom_UltraBallNPC_1:
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 786 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_AnnihilapeHintNPC::
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 804 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessagePostScript, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 806 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 838 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 843 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage, MSGBOX_NPC
EscapeRoom_ZeraoraHintNPC_1:
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_SPECS_OBTAINED, EscapeRoom_TabletsHintNPC_4
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage4, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 856 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_4:
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 875 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 885 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer6::
# 944 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7::
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7, Trainer7_Intro, Trainer7_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 963 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7_PostBattle, MSGBOX_AUTOCLOSE
# 964 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 972 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 988 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 982 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 993 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 997 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1011 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 1018 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_TradeZeraForHMCut::
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 1027 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 1049 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1031 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 1064 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 50, abilityNum = 2, nature = 8, gender = 0, move1 = MOVE_TRUMP_CARD, move2 = MOVE_AIR_SLASH, move3 = MOVE_HEX, move4 = MOVE_COUNTER, hpEv = 0, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 10, spDefIv = 31
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 1102 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1106 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 1107 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1124 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	givepoochegg
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 1148 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 1149 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1139 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1166 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 1202 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_NPC
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1180 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 6000
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 1193 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceivedMessage
# 1194 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeAccepted, MSGBOX_AUTOCLOSE
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradePoochForSmeargle::
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_TRADE_ACCEPTED, EscapeRoom_EventScript_TradePoochForSmeargle_2
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskPoochSmeargleTrade, MSGBOX_YESNO
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_5
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeDeclined, MSGBOX_AUTOCLOSE
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradePoochForSmeargle_1:
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradePoochForSmeargle_2:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradePostTrade, MSGBOX_NPC
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_5:
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_9
# 1234 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TradePoochForSmeargle_12
EscapeRoom_EventScript_TradePoochForSmeargle_11:
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_POOCHYENA
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1251 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 30, abilityNum = 0, nature = 15, gender = 0, move1 = MOVE_SWITCHEROO, move2 = MOVE_UPROAR, move3 = MOVE_SURF, move4 = MOVE_CONVERSION_2, hpEv = 0, spAtkEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 28
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1273 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POOCH_TRADE_ACCEPTED
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1277 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1278 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeAccepted, MSGBOX_AUTOCLOSE
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_9:
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradePoochForSmeargle_12:
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_14
	goto EscapeRoom_EventScript_TradePoochForSmeargle_11

EscapeRoom_EventScript_TradePoochForSmeargle_14:
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HealBeforeTradeMessage, MSGBOX_DEFAULT
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HealedBeforeTradeMessage, MSGBOX_AUTOCLOSE
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_11


EscapeRoom_EventScript_FindRareCandy::
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 1297 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindLostGlasses::
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_WISE_GLASSES
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LOST_GLASSES_OBTAINED
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1317 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1331 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1385 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1419 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1424 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1414 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1464 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1473 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 1478 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1542 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GraveStone1::
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1552 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1566 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1567 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1568 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1562 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1610 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1614 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1621 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1632 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1647 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1658 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1683 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1676 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1691 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 1697 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 1698 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1702 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 1723 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1752 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 1801 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1797 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 1819 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1822 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 1834 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 1837 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1839 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 1847 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 1848 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 1880 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 1862 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 1863 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1897 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_HAZE
# 1899 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_MoveDeleterNPC_Text_0:
# 586 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete a move$"

EscapeRoom_MoveDeleterNPC_Text_1:
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Restore deleted moves$"

SomethingsGoneWrongMessage::
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EndSignMessage::
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The end.\p"
	.string "...\p"
	.string "For now.$"

MysteriousWallSign::
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice paralysis?$"

AnnihilapeStatueMessage::
# 1955 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 1961 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A spirit stirs.\nYou sense a presence.$"

GravestoneClick3Message::
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void.$"

GravestoneAnnihilapesRoar::
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 2008 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 2045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 2064 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 2076 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 2120 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello, should I heal your Pokémon?$"

Nurse_Heal_End::
# 2138 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2161 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Thanks for playing)$"

ZeraoraHintMessage::
# 2194 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people trying to catch it\n"
	.string "but no one's been able to get its HP\l"
	.string "below 50%.\p"
	.string "It kind of just gives up after a while.$"

ZeraoraHintPostCatchMessage::
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!$"

AnnihilapeHintNoMessage1::
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Defeating her won't do much good,\n"
	.string "she always comes back.\p"
	.string "I also wouldn't waste any Poké Balls on\n"
	.string "her if I were you.$"

AnnihilapeHintMessagePostScript::
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Defeating Annihilape won't do much\n"
	.string "good, she always comes back.\p"
	.string "I also wouldn't waste any Poké Balls on\n"
	.string "her if I were you.$"

FourTabletsHintMessage1::
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\p"
	.string "You've found all four!$"

FourTabletsHintMessage3::
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did something just open?$"

FourTabletsHintMessage4::
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Enjoy your Choice Scarf I guess...$"

LostGlassesNPCmainMessage::
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen my glasses?\n"
	.string "I can't see without them!$"

LostGlassesNPCGlassesFoundMessage::
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found them!\p"
	.string "I guess I no longer need this\n"
	.string "seeing-eye leopard...\p"
	.string "...$"

LiepardObtainMessage::
# 2266 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LostGlassesNPCendMessage::
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See you around!$"

MartNPC_AskToShop::
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, welcome to my shop.\p"
	.string "Don't worry, each item can be sold back\n"
	.string "for same price.$"

MartNPC_SayGoodbye::
# 2282 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2288 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello, I can temporarily delete one of\n"
	.string "your Pokémon's moves.\p"
	.string "What would you like to do?$"

MoveDeleterComeAgain::
# 2294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MoveDeleterMoveDeleted::
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s {STR_VAR_2} was removed!$"

MoveDeleterOnlyOneMove::
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That Pokémon only has one move left.$"

PoochMovesRestoredMessage::
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Poochyena's moves were restored!$"

LiepardMovesRestoredMessage::
# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Liepard's moves were restored!$"

DunsparceMovesRestoredMessage::
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce's moves were restored!$"

SmeargleMovesRestoredMessage::
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Smeargle's moves were restored!$"

NoMovesRestoredMessage::
# 2322 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There are no moves to restore.$"

NewBallMessage::
# 2330 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

WhiteHerbRecoveredMessage::
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your White Herb was restored.$"

CustapBerryRecoveredMessage::
# 2338 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Custap Berry was restored.$"

MarangaBerryRecoveredMessage::
# 2342 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Maranga Berry was restored.$"

AskFerroDunsparceTrade::
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\n"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright. Some other time maybe.$"

FerroTradePostTrade::
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2371 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges. Do you want to\n"
	.string "trade it for my Pokémon egg?$"

EggReceivedMessage::
# 2376 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2380 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2384 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD - allow to retrade Florges$"

AskDunsparceMoneyTrade::
# 2394 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I collect rare Pokémon as a hobby.\p"
	.string "Your Dunsparce looks quite valuable,\n"
	.string "would you sell it to me for ¥6.000?$"

MoneyReceivedMessage::
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥6.000!$"

DunsparceTradeAccepted::
# 2404 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Dunsparce.$"

DunsparceTradeDeclined::
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2412 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My collection grows bigger and bigger!$"

AskPoochSmeargleTrade::
# 2418 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to trade dogs?$"

SmeargleReceivedMessage::
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

PoochTradeAccepted::
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Poochyena.$"

PoochTradeDeclined::
# 2430 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

PoochTradePostTrade::
# 2434 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks a lot.$"

HealBeforeTradeMessage::
# 2438 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "First let me heal your Pokémon.$"

HealedBeforeTradeMessage::
# 2442 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, let's trade!$"

DoubleBattle_NotEnoughMons::
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something something I've got HM Cut!$"

Trainer1_Outro::
# 2458 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2477 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2483 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I hate grass.$"

Trainer2_Outro::
# 2487 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2491 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2497 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2502 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer4_Intro::
# 2512 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 2516 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Back for more?\n"
	.string "Thought you'd escaped your ghosts.$"

Trainer5_Outro::
# 2532 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer5_PostBattle::
# 2536 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer6_Intro::
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You can't steal our item.\p"
	.string "Wanna borrow it?$"

Trainer6_Outro::
# 2547 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2551 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7_Intro::
# 2557 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Too many options?\n"
	.string "Be careful or you might freeze up.$"

Trainer7_Outro::
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7_PostBattle::
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
