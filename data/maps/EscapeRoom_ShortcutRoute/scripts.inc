EscapeRoom_ShortcutRoute_MapScripts::
# 2 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SetWallOnLoad
	.byte 0


SetWallOnLoad::
# 7 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 8 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 9 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 10 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 11 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 12 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 13 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

