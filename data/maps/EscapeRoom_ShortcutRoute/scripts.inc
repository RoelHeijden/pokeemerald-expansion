EscapeRoom_ShortcutRoute_MapScripts::
# 8 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SetWallOnLoad
# 9 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ResetSmashRock1
	.byte 0


SetWallOnLoad::
# 14 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 15 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 19 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 20 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


ResetSmashRock1::
# 26 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 26 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 27 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 31 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


EscapeRoom_ShortcutRoute_EventScript_FindWhiteHerb::
# 38 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 39 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_WHITE_HERB
# 40 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 3
# 41 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 42 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

