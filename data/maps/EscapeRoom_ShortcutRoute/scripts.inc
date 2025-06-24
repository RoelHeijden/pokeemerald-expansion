EscapeRoom_ShortcutRoute_MapScripts::
# 9 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheckResetRocks
# 10 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CheckIfBerryJuiceObtained
	.byte 0


SetWallOnLoad::
# 16 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 19 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 20 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 21 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 22 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


CheckResetRocks::
# 27 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetSmashRock1
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetShuckleSmashRocks
	return


ResetSmashRock1::
# 33 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 33 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 34 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 38 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 35 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


ResetShuckleSmashRocks::
# 45 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, ResetShuckleSmashRocks_1
	return

ResetShuckleSmashRocks_1:
# 46 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK1
# 47 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK2
# 48 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK3
# 49 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK4
	return


CheckIfBerryJuiceObtained::
# 54 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_1
	return

CheckIfBerryJuiceObtained_1:
# 56 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 57 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_4
CheckIfBerryJuiceObtained_3:
# 60 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 61 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_7
CheckIfBerryJuiceObtained_6:
# 66 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 67 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_9
	return

CheckIfBerryJuiceObtained_4:
# 58 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_3

CheckIfBerryJuiceObtained_7:
# 62 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_6

CheckIfBerryJuiceObtained_9:
# 68 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	return


EscapeRoom_ShortcutRoute_EventScript_FindWhiteHerb::
# 78 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 79 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_WHITE_HERB
# 80 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 3
# 81 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 82 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

