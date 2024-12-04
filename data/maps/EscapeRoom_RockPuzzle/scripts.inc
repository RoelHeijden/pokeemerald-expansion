EscapeRoom_RockPuzzle_MapScripts::
# 5 "data/maps/EscapeRoom_RockPuzzle/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_RockPuzzle_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

EscapeRoom_RockPuzzle_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/EscapeRoom_RockPuzzle/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_setObjectUnloadFlag
	.2byte 0


EscapeRoom_MapScript_setObjectUnloadFlag::
# 12 "data/maps/EscapeRoom_RockPuzzle/scripts.pory"
	setflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	return

