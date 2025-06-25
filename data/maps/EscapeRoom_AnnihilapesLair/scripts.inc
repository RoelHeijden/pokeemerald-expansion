EscapeRoom_AnnihilapesLair_MapScripts::
# 6 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts
# 8 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 10 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts::
# 16 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_ReturnBall
# 17 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_DisableBagUse
# 18 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_SetLostItemVars
	return


EscapeRoom_AnnihilapesLair_ReturnBall::
# 23 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_AnnihilapesLair_ReturnBall_2
	return

EscapeRoom_AnnihilapesLair_ReturnBall_1:
# 24 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_AnnihilapesLair_ReturnBall_2:
# 23 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_AnnihilapesLair_ReturnBall_1
	return


EscapeRoom_AnnihilapesLair_DisableBagUse::
# 30 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_AnnihilapesLair_DisableBagUse_1
	return

EscapeRoom_AnnihilapesLair_DisableBagUse_1:
# 31 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_AnnihilapesLair_SetLostItemVars::
# 37 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_AnnihilapesLair_SetLostItemVars_1
	return

EscapeRoom_AnnihilapesLair_SetLostItemVars_1:
# 39 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return

