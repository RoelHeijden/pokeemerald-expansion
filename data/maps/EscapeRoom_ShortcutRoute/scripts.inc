EscapeRoom_ShortcutRoute_MapScripts::
# 8 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SetWallOnLoad
	.byte 0


SetWallOnLoad::
# 13 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 14 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 19 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


EscapeRoom_ShortcutRoute_EventScript_FindChoiceSpecs::
# 25 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 26 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_CHOICE_SPECS
# 27 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 3
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_CHOICE_SPECS_OBTAINED
# 29 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

