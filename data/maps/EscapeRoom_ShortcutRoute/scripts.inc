EscapeRoom_ShortcutRoute_MapScripts::
# 10 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SetWallOnLoad
	.byte 0


SetWallOnLoad::
# 15 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 16 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 19 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 20 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 21 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


EscapeRoom_ShortcutRoute_EventScript_FindChoiceSpecs::
# 27 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_CHOICE_SCARF
# 29 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 3
# 30 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_CHOICE_SPECS_OBTAINED
# 31 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


EscapeRoom_ShortcutRoute_EventScript_FindRareCandy::
# 35 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 36 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_RARE_CANDY
# 37 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 4
# 38 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 39 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


EscapeRoom_ShortcutRoute_EventScript_FindWhiteHerb::
# 43 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 44 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_WHITE_HERB
# 45 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 5
# 46 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 47 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

