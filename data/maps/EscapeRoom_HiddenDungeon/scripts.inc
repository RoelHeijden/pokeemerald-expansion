EscapeRoom_HiddenDungeon_MapScripts::
# 7 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts
# 9 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 11 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 12 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 19 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 20 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 21 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
	return


EscapeRoom_HiddenDungeon_DisableBagUse::
# 27 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_HiddenDungeon_DisableBagUse_1
	return

EscapeRoom_HiddenDungeon_DisableBagUse_1:
# 28 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_HiddenDungeon_SetLostItemVars::
# 34 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_HiddenDungeon_SetLostItemVars_1
	return

EscapeRoom_HiddenDungeon_SetLostItemVars_1:
# 36 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_HiddenDungeon_FindPrimeape::
# 47 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 48 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_POKE_BALL, item = ITEM_RARE_CANDY, abilityNum = 2, nature = 15, gender = MON_FEMALE, move1 = MOVE_ENCORE, move2 = MOVE_RAGE_FIST, move3 = MOVE_COUNTER, move4 = MOVE_NONE, atkEv = 0, spAtkEv = 0, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 73 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 74 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message PrimeapeObtainMessage
# 75 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 76 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 78 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 9
# 79 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 80 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


PrimeapeObtainMessage::
# 84 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Primeape!$"
