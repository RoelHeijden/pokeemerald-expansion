EscapeRoom_IcePuzzle_MapScripts::
# 5 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_IcePuzzle_MapScript_OnResumeScripts
# 7 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_IcePuzzle_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_IcePuzzle_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindGreatBallAferUse
# 9 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1, EscapeRoom_MapScripts_FindPechaBerryAferUse
	.2byte 0


EscapeRoom_IcePuzzle_MapScript_OnResumeScripts::
# 16 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 19 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 22 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattlePecha
# 25 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleHeal
# 28 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_IcePuzzle_MapScript_OnResumeScripts_1
	return

EscapeRoom_IcePuzzle_MapScript_OnResumeScripts_1:
# 29 "data/maps/EscapeRoom_IcePuzzle/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

