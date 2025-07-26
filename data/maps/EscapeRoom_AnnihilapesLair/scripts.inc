EscapeRoom_AnnihilapesLair_MapScripts::
# 6 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpawnDungeonEntranceOnLoad
# 7 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts
# 9 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 11 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


SpawnDungeonEntranceOnLoad::
# 17 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, SpawnDungeonEntranceOnLoad_1
	return

SpawnDungeonEntranceOnLoad_1:
# 18 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 6, 0, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
# 19 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 5, 1, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
# 20 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 6, 1, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
# 21 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 7, 1, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return


EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts::
# 27 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_ReturnBall
# 28 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_DisableBagUse
# 29 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_SetLostItemVars
	return


EscapeRoom_AnnihilapesLair_ReturnBall::
# 34 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_AnnihilapesLair_ReturnBall_2
	return

EscapeRoom_AnnihilapesLair_ReturnBall_1:
# 35 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_AnnihilapesLair_ReturnBall_2:
# 34 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_AnnihilapesLair_ReturnBall_1
	return


EscapeRoom_AnnihilapesLair_DisableBagUse::
# 41 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_AnnihilapesLair_DisableBagUse_1
	return

EscapeRoom_AnnihilapesLair_DisableBagUse_1:
# 42 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_AnnihilapesLair_SetLostItemVars::
# 48 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_AnnihilapesLair_SetLostItemVars_1
	return

EscapeRoom_AnnihilapesLair_SetLostItemVars_1:
# 50 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return

