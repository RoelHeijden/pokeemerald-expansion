EscapeRoom_IcePuzzle_MapScripts::
# 5 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_IcePuzzle_MapScript_OnResumeScripts
# 7 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_IcePuzzle_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 11 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_IcePuzzle_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_IcePuzzle_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_IcePuzzle_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_IcePuzzle_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindGreatBallAferUse
# 13 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1, EscapeRoom_MapScripts_FindPechaBerryAferUse
	.2byte 0


EscapeRoom_IcePuzzle_MapScript_OnResumeScripts::
# 20 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 23 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 26 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattlePecha
# 29 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleHeal
# 32 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_IcePuzzle_MapScript_OnResumeScripts_1
	return

EscapeRoom_IcePuzzle_MapScript_OnResumeScripts_1:
# 33 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_IcePuzzle_MapScript_OnWarpIntoScripts::
# 39 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_IcePuzzle_MapScript_setNPCfacing
	return


EscapeRoom_IcePuzzle_MapScript_setNPCfacing::
# 43 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	turnobject 3, DIR_EAST
# 44 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	turnobject 4, DIR_SOUTH
	return

