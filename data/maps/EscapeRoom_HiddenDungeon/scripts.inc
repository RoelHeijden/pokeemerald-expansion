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
# 50 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox PrimeapePokeballMessage, MSGBOX_YESNO
# 51 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne EscapeRoom_HiddenDungeon_FindPrimeape_2
# 57 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_POKE_BALL, abilityNum = 2, nature = 15, gender = MON_FEMALE, move1 = MOVE_TAUNT, move2 = MOVE_RAGE_FIST, move3 = MOVE_COUNTER, move4 = MOVE_NONE, atkEv = 0, spAtkEv = 0, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 82 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 8
# 83 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 87 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message PrimeapeObtainMessage
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 89 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 92 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 93 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_FindPrimeape_5
EscapeRoom_HiddenDungeon_FindPrimeape_4:
# 97 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	closemessage
# 98 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FindPrimeape_2:
# 52 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_FindPrimeape_5:
# 94 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 95 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_HiddenDungeon_FindPrimeape_4


NicknameThisPokemonMessage2::
# 101 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

PrimeapePokeballMessage::
# 106 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "There's a Pokémon inside the Poke Ball.\p"
	.string "Do you want to pick it up?$"

PrimeapeObtainMessage::
# 111 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Primeape!$"
