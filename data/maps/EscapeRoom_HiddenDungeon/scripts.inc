EscapeRoom_HiddenDungeon_MapScripts::
# 14 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts
# 15 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts
# 17 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 19 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 20 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 21 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 22 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_DO_SOMETHING_WRONG_MESSAGE, 1, EscapeRoom_MapScripts_SomethingWrongMessage
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts::
# 29 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_2
EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1:
# 35 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_4
	return

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_2:
# 30 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 11, 4, 8
# 31 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	goto EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_4:
# 36 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 5, 59, 8
# 37 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	return


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 42 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 43 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 44 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained
# 45 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained
# 49 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 53 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 56 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts_1
	return

EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts_1:
# 57 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_HiddenDungeon_DisableBagUse::
# 63 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_HiddenDungeon_DisableBagUse_1
	return

EscapeRoom_HiddenDungeon_DisableBagUse_1:
# 64 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_HiddenDungeon_SetLostItemVars::
# 70 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_HiddenDungeon_SetLostItemVars_1
	return

EscapeRoom_HiddenDungeon_SetLostItemVars_1:
# 72 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained::
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1:
# 78 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 87 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 89 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 90 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 91 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 92 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 93 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 94 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 95 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 96 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 97 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5:
# 103 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_THIEF
# 106 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2:
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6:
# 99 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5


EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained::
# 111 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 112 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 113 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 116 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 120 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 121 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 126 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 113 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 118 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 122 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 135 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 136 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 137 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 138 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 139 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 140 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 141 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 143 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 144 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 145 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 147 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	return


EscapeRoom_MapScripts_SomethingWrongMessage::
# 154 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 155 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 0
# 156 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 157 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 158 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_FindPrimeape::
# 167 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 170 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_MAX_REVIVE, abilityNum = 2, nature = NATURE_CALM, gender = MON_FEMALE, move1 = MOVE_RAGE_FIST, move2 = MOVE_TAUNT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 252, defEv = 0, spDefEv = 8 hpIv = 31, atkIv = 0, defIv = 0, spAtkIv = 31, spDefIv = 31, speedIv = 10
# 196 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 15
# 197 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 200 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_MAX_REVIVE_OBTAINED
# 203 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 204 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message PrimeapeObtainMessage
# 205 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 206 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 209 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 210 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_FindPrimeape_2
EscapeRoom_HiddenDungeon_FindPrimeape_1:
# 214 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	closemessage
# 215 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FindPrimeape_2:
# 211 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 212 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_HiddenDungeon_FindPrimeape_1


EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon::
# 221 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 222 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 225 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2
# 240 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskBagonTrade, MSGBOX_YESNO
# 241 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5
# 311 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradeDeclined, MSGBOX_AUTOCLOSE
# 312 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1:
# 315 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2:
# 226 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradePostTrade, MSGBOX_NPC
# 227 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 230 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 231 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 232 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 233 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 234 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_BAGON_TRADER
# 235 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 236 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5:
# 244 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 245 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 246 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9
# 253 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 254 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 255 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12
# 264 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message BagonReceivedMessage
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 266 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 267 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 270 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 271 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 272 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 273 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 276 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 277 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 278 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 279 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 282 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 283 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 284 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 285 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_BAGON, 34, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = NATURE_MODEST, gender = MON_MALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_SUBSTITUTE, move3 = MOVE_NONE, move4 = MOVE_NONE, spAtkEv = 252, speedEv = 252, hpIv = 1, atkIv = 0, defIv = 1, spAtkIv = 31, spDefIv = 31, speedIv = 30
# 307 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9:
# 248 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 249 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 250 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12:
# 257 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 258 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 259 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 321 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 322 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 324 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 331 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 332 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 335 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 336 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 354 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 326 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 327 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 339 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 340 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 343 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 344 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 347 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 348 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 349 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 351 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 357 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 358 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 359 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 360 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

EscapeRoom_HiddenDungeon_FinaleReachedTrigger::
# 366 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 368 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_YAMASK_OBTAINED, EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2
# 407 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 408 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 411 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 412 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 415 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 416 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 419 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 420 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1:
# 422 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2:
# 371 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 372 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 373 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_PIN
# 374 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 375 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 376 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 30
# 379 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 380 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 383 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_FINAL_BATTLE
# 384 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 385 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 388 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyMainMessage, MSGBOX_DEFAULT
# 389 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 392 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_BagonYamaskTrade
# 395 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 396 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 399 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 400 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 403 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_RemoveTMSecretPower
	goto EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1


# 425 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
PlayerMoveUp:
# 426 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_up
# 427 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_up
	step_end

EscapeRoom_HiddenDungeon_BagonYamaskTrade::
# 432 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_BAGON
# 433 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 434 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_BagonYamaskTrade_2
EscapeRoom_HiddenDungeon_BagonYamaskTrade_1:
# 443 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message YamaskReceivedMessage
# 444 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 445 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 446 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 449 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 450 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 451 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 452 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 455 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_BAGON
# 456 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_SHELGON
# 457 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_YAMASK_GALAR, 5, abilityNum = 0, nature = NATURE_HASTY, gender = MON_MALE, move1 = MOVE_ASTONISH, move2 = MOVE_HAZE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 479 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_YAMASK_OBTAINED
	return

EscapeRoom_HiddenDungeon_BagonYamaskTrade_2:
# 436 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 437 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_BagonYamaskTrade_1


EscapeRoom_HiddenDungeon_RemoveTMSecretPower::
# 484 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 485 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1:
# 488 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 489 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6:
# 492 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TM43
# 493 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11
	return

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2:
# 486 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3:
# 485 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7:
# 490 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8:
# 489 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11:
# 494 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeitem ITEM_TM43
	return


EscapeRoom_HiddenDungeon_YamaskGuy::
# 500 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 503 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_YamaskGuy_2
# 508 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyFinalMessage, MSGBOX_NPC
# 509 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_YamaskGuy_1:
# 512 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_YamaskGuy_2:
# 504 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_NPC
# 505 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_YamaskGuy_1


EscapeRoom_HiddenDungeon_MoveRelearner::
# 518 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 519 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 522 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerMainMessage, MSGBOX_DEFAULT
# 523 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 526 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special ChooseMonForMoveRelearner
# 527 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitstate
# 536 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerEndMessage, MSGBOX_DEFAULT
# 537 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 540 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


AskBagonTrade::
# 549 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Bagon so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

BagonReceivedMessage::
# 564 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Bagon!$"

BagonTradeDeclined::
# 568 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

BagonTradePostTrade::
# 572 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 579 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 585 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 590 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 600 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hm... Cute entry card though.$"

YamaskReceivedMessage::
# 608 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Yamask!$"

YamaskGuyPostTradeMessage::
# 612 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "The trainer you're about to face can be\n"
	.string "a bit of a cheater.\p"
	.string "The Kecleon uses an illegal move and\n"
	.string "their Struggle always seems to find\l"
	.string "the optimal target.\p"
	.string "Don't worry, you've got everything you\n"
	.string "need to come out victorious!\p"
	.string "Your Choice Specs can no longer be\n"
	.string "exchanged, and Secret Power will be\l"
	.string "added to the Move Tutor moves.\p"
	.string "You're all set.\n"
	.string "Good luck!$"

YamaskGuyFinalMessage::
# 631 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Wow... Well done!$"

YamaskGuyMainMessage::
# 635 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're almost there!\n"
	.string "Only one more challenge remains.\p"
	.string "It's a tough one though...\p"
	.string "Allow me to take your Bagon and provide\n"
	.string "you with something more suitable.\p"
	.string "You wouldn't stand a chance otherwise.$"

MoveRelearnerMainMessage::
# 646 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hi, I'm your Move Tutor.\p"
	.string "Which of your Pokémon should I teach a\n"
	.string "new move?$"

MoveRelearnerEndMessage::
# 652 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "I'll be here if you need me.$"
