EscapeRoom_AnnihilapesLair_MapScripts::
# 4 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_AnnihilapesLair_MapScript_OnTransitionScripts
# 5 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts
# 7 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 11 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_AnnihilapesLair_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_AnnihilapesLair_MapScripts_FindBallAferUse
# 13 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage
	.2byte 0


EscapeRoom_AnnihilapesLair_MapScript_OnTransitionScripts::
	return


EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts::
# 25 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_3
EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_1:
# 30 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_7
# 30 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_7
# 30 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_7
EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_6:
# 35 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_13
	return

EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_2:
# 26 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_1

EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_3:
# 25 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_2
	goto EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_1

EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_7:
# 31 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_6

EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts_13:
# 36 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_AnnihilapesLair_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_AnnihilapesLair_MapScripts_FindBallAferUse::
# 45 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 46 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 47 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 48 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 49 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	clearflag FLAG_BALL_USED
# 50 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 51 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return


EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage::
# 55 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 58 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_2
EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_1:
# 65 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_5
EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_4:
# 72 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_8
EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_7:
# 78 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 79 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_2:
# 59 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox WhiteHerbRecoveredMessage, MSGBOX_AUTOCLOSE
# 60 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 61 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
	goto EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_1

EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_5:
# 66 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox CustapBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 67 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 68 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
	goto EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_4

EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_8:
# 73 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox MarangaBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 74 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 75 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
	goto EscapeRoom_AnnihilapesLair_MapScripts_RetrievedItemMessage_7

