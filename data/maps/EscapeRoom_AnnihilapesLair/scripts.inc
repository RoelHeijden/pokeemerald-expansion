EscapeRoom_AnnihilapesLair_MapScripts::
# 8 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpawnDungeonEntranceOnLoad
# 9 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts
# 11 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 13 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


SpawnDungeonEntranceOnLoad::
# 19 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, SpawnDungeonEntranceOnLoad_1
	return

SpawnDungeonEntranceOnLoad_1:
# 20 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 6, 0, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
# 21 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 5, 1, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
# 22 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 6, 1, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
# 23 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 7, 1, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return


EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts::
# 29 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_ReturnBall
# 30 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_DisableBagUse
# 31 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_SetLostItemVars
	return


EscapeRoom_AnnihilapesLair_ReturnBall::
# 36 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_AnnihilapesLair_ReturnBall_2
	return

EscapeRoom_AnnihilapesLair_ReturnBall_1:
# 37 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_AnnihilapesLair_ReturnBall_2:
# 36 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_AnnihilapesLair_ReturnBall_1
	return


EscapeRoom_AnnihilapesLair_DisableBagUse::
# 43 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_AnnihilapesLair_DisableBagUse_1
	return

EscapeRoom_AnnihilapesLair_DisableBagUse_1:
# 44 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_AnnihilapesLair_SetLostItemVars::
# 50 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_AnnihilapesLair_SetLostItemVars_1
	return

EscapeRoom_AnnihilapesLair_SetLostItemVars_1:
# 52 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_AnnihilapesLair_FindPrimeape::
# 61 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 64 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_MAX_REVIVE, abilityNum = 2, nature = NATURE_CALM, gender = MON_FEMALE, move1 = MOVE_RAGE_FIST, move2 = MOVE_TAUNT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 252, defEv = 0, spDefEv = 8 hpIv = 31, atkIv = 0, defIv = 0, spAtkIv = 31, spDefIv = 31, speedIv = 10
# 90 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	removeobject 14
# 91 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 94 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_MAX_REVIVE_OBTAINED
# 97 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 98 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	message PrimeapeObtainMessage
# 99 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitfanfare
# 100 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 103 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 104 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_FindPrimeape_2
EscapeRoom_AnnihilapesLair_FindPrimeape_1:
# 108 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	closemessage
# 109 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapesLair_FindPrimeape_2:
# 105 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 106 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_AnnihilapesLair_FindPrimeape_1


EscapeRoom_AnnihilapesLair_PrimeapeGrave1::
# 113 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 114 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGraveNothing, MSGBOX_AUTOCLOSE
# 115 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 116 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return


EscapeRoom_AnnihilapesLair_PrimeapeGrave2::
# 120 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 121 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGraveNothing, MSGBOX_AUTOCLOSE
# 122 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 123 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return


PrimeapeGraveNothing::
# 126 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "...$"
