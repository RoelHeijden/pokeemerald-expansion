EscapeRoom_HiddenDungeon_MapScripts::
# 13 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts
# 14 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts
# 16 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 17 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 18 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 19 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 20 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 21 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_DO_SOMETHING_WRONG_MESSAGE, 1, EscapeRoom_MapScripts_SomethingWrongMessage
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts::
# 28 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_2
EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1:
# 34 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_4
	return

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_2:
# 29 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 11, 4, 8
# 30 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	goto EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_4:
# 35 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 5, 59, 8
# 36 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	return


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 41 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 42 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 43 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfSecretPowerObtained
# 44 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained
# 45 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfSSTicketObtained
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


EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained::
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 78 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 79 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 82 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 83 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 87 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 92 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 80 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 79 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 84 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 83 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 95 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT
# 104 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 105 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 106 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 107 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 108 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 109 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 110 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 111 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 112 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 113 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 116 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	return


EscapeRoom_MapScripts_SomethingWrongMessage::
# 123 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 124 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 0
# 125 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 126 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 127 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_CheckIfSSTicketObtained::
# 132 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SS_TICKET_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSSTicketObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfSSTicketObtained_1:
# 133 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_SS_TICKET
# 134 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSSTicketObtained_3
	return

EscapeRoom_HiddenDungeon_CheckIfSSTicketObtained_3:
# 135 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_SS_TICKET_OBTAINED
	return


EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon::
# 146 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 147 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 150 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2
# 165 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskBagonTrade, MSGBOX_YESNO
# 166 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5
# 236 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradeDeclined, MSGBOX_AUTOCLOSE
# 237 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1:
# 240 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2:
# 151 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradePostTrade, MSGBOX_NPC
# 152 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 155 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 156 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 157 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 158 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 159 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_BAGON_TRADER
# 160 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 161 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5:
# 169 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 170 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 171 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9
# 178 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 179 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 180 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12
# 189 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message BagonReceivedMessage
# 190 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 191 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 192 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 195 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 196 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 197 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 198 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 201 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 202 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 203 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 204 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 207 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 208 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 209 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 210 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_BAGON, 34, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = NATURE_MODEST, gender = MON_MALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_SUBSTITUTE, move3 = MOVE_NONE, move4 = MOVE_NONE, spAtkEv = 252, speedEv = 252, hpIv = 1, atkIv = 0, defIv = 1, spAtkIv = 31, spDefIv = 31, speedIv = 30
# 232 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9:
# 173 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 174 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 175 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12:
# 182 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 183 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 184 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 246 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 247 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 249 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 256 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 257 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 260 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 261 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 279 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 251 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 252 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 264 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 268 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 269 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 272 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 273 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 274 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 276 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 282 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 283 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 284 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 285 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

EscapeRoom_HiddenDungeon_FinaleReachedTrigger::
# 291 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 293 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_YAMASK_OBTAINED, EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2
# 332 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 333 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 336 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 337 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 340 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 341 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 344 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 345 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1:
# 347 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2:
# 296 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 297 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 298 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_PIN
# 299 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 300 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 301 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 30
# 304 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 305 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 308 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_FINAL_BATTLE
# 309 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 310 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 313 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyMainMessage, MSGBOX_DEFAULT
# 314 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 317 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_BagonYamaskTrade
# 320 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 321 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 324 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 325 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 328 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_RemoveTMSecretPower
	goto EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1


# 350 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
PlayerMoveUp:
# 351 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_up
# 352 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_up
	step_end

EscapeRoom_HiddenDungeon_BagonYamaskTrade::
# 357 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_BAGON
# 358 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 359 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_BagonYamaskTrade_2
EscapeRoom_HiddenDungeon_BagonYamaskTrade_1:
# 368 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message YamaskReceivedMessage
# 369 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 370 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 371 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 374 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 375 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 376 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 377 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 380 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_BAGON
# 381 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_SHELGON
# 382 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_YAMASK_GALAR, 5, abilityNum = 0, nature = NATURE_HASTY, gender = MON_MALE, move1 = MOVE_ASTONISH, move2 = MOVE_HAZE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 404 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_YAMASK_OBTAINED
	return

EscapeRoom_HiddenDungeon_BagonYamaskTrade_2:
# 361 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 362 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_BagonYamaskTrade_1


EscapeRoom_HiddenDungeon_RemoveTMSecretPower::
# 409 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 410 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1:
# 413 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 414 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6:
# 417 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TM43
# 418 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11
	return

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2:
# 411 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3:
# 410 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7:
# 415 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8:
# 414 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11:
# 419 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeitem ITEM_TM43
	return


EscapeRoom_HiddenDungeon_YamaskGuy::
# 425 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 428 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_YamaskGuy_2
# 433 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyFinalMessage, MSGBOX_NPC
# 434 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_YamaskGuy_1:
# 437 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_YamaskGuy_2:
# 429 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_NPC
# 430 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_YamaskGuy_1


EscapeRoom_HiddenDungeon_MoveRelearner::
# 443 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 444 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 447 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerMainMessage, MSGBOX_DEFAULT
# 448 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 451 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special ChooseMonForMoveRelearner
# 452 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitstate
# 461 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerEndMessage, MSGBOX_DEFAULT
# 462 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 465 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


AskBagonTrade::
# 474 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Bagon so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

BagonReceivedMessage::
# 489 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Bagon!$"

BagonTradeDeclined::
# 493 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

BagonTradePostTrade::
# 497 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 504 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 510 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 515 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 525 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hm... Cute entry card though.$"

YamaskReceivedMessage::
# 533 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Yamask!$"

YamaskGuyPostTradeMessage::
# 537 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "The trainer you're about to face can be\n"
	.string "a bit of a cheater.\p"
	.string "The Kecleon uses an illegal move and\n"
	.string "their Struggle always seems to find\l"
	.string "the optimal target.\p"
	.string "Don't worry, you've got everything you\n"
	.string "need to come out on top.\p"
	.string "Good luck!$"

YamaskGuyFinalMessage::
# 556 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Wow... Well done!$"

YamaskGuyMainMessage::
# 560 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're almost there!\n"
	.string "Just one more challenge remains.\p"
	.string "It's a tough one though...\p"
	.string "Allow me to take your Bagon and provide\n"
	.string "you with something more suitable.\p"
	.string "You wouldn't stand a chance otherwise.$"

MoveRelearnerMainMessage::
# 571 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hi, I'm your Move Tutor.\p"
	.string "Which of your Pokémon should I teach a\n"
	.string "new move?$"

MoveRelearnerEndMessage::
# 577 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "I'll be here if you need me.$"
