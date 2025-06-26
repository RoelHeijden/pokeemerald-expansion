EscapeRoom_ShortcutRoute_MapScripts::
# 14 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheckResetRocks
# 15 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_ShortcutRoute_OnResumeMapScripts
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


EscapeRoom_ShortcutRoute_OnResumeMapScripts::
# 24 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call CheckIfBerryJuiceObtained
# 25 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_DisableBagUse
# 26 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_SetLostItemVars
	return


EscapeRoom_ShortcutRoute_DisableBagUse::
# 31 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_ShortcutRoute_DisableBagUse_1
	return

EscapeRoom_ShortcutRoute_DisableBagUse_1:
# 32 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_ShortcutRoute_SetLostItemVars::
# 38 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_ShortcutRoute_SetLostItemVars_1
	return

EscapeRoom_ShortcutRoute_SetLostItemVars_1:
# 40 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


SetWallOnLoad::
# 47 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 48 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 49 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 50 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 51 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 52 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 53 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


CheckResetRocks::
# 58 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetSmashRock1
# 59 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetShuckleSmashRocks
	return


ResetSmashRock1::
# 64 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 64 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 65 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 69 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 66 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


ResetShuckleSmashRocks::
# 76 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, ResetShuckleSmashRocks_1
	return

ResetShuckleSmashRocks_1:
# 77 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK1
# 78 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK2
# 79 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK3
# 80 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK4
	return


CheckIfBerryJuiceObtained::
# 85 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_1
	return

CheckIfBerryJuiceObtained_1:
# 87 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 88 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_4
CheckIfBerryJuiceObtained_3:
# 91 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 92 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_7
CheckIfBerryJuiceObtained_6:
# 97 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 98 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_9
	return

CheckIfBerryJuiceObtained_4:
# 89 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_3

CheckIfBerryJuiceObtained_7:
# 93 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_6

CheckIfBerryJuiceObtained_9:
# 99 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	return

