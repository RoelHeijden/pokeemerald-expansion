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
# 22 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ESCAPE_ROPE_EE_STATE, 1, EscapeRoom_HiddenDungeon_EscapeRopeEE_message1
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
	call EscapeRoom_MapScripts_CheckIfSecretPowerObtained
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


EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon::
# 137 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 138 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 141 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2
# 156 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskBagonTrade, MSGBOX_YESNO
# 157 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5
# 227 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradeDeclined, MSGBOX_AUTOCLOSE
# 228 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1:
# 231 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2:
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradePostTrade, MSGBOX_NPC
# 143 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 146 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 147 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 148 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 149 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 150 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_BAGON_TRADER
# 151 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 152 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5:
# 160 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 161 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 162 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9
# 169 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 170 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 171 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12
# 180 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message BagonReceivedMessage
# 181 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 182 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 183 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 186 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 187 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 188 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 189 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 192 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 193 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 194 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 195 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 198 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 199 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 200 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 201 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_BAGON, 34, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = NATURE_MODEST, gender = MON_MALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_SUBSTITUTE, move3 = MOVE_NONE, move4 = MOVE_NONE, spAtkEv = 252, speedEv = 252, hpIv = 1, atkIv = 0, defIv = 1, spAtkIv = 31, spDefIv = 31, speedIv = 30
# 223 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9:
# 164 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 165 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 166 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12:
# 173 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 174 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 175 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 237 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 238 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 240 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 247 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 248 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 251 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 252 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 270 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 242 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 243 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 255 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 256 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 259 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 260 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 263 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 264 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 267 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 273 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 274 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 275 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 276 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

EscapeRoom_HiddenDungeon_FinaleReachedTrigger::
# 282 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 284 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_YAMASK_OBTAINED, EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2
# 323 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 324 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 327 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 328 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 331 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 332 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 335 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 336 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1:
# 338 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2:
# 287 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 288 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 289 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_PIN
# 290 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 291 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 292 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 30
# 295 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 296 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 299 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_FINAL_BATTLE
# 300 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 301 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 304 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyMainMessage, MSGBOX_DEFAULT
# 305 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 308 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_BagonYamaskTrade
# 311 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 312 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 315 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 316 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 319 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_RemoveTMSecretPower
	goto EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1


# 341 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
PlayerMoveUp:
# 342 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_up
# 343 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_up
	step_end

EscapeRoom_HiddenDungeon_BagonYamaskTrade::
# 348 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_BAGON
# 349 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 350 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_BagonYamaskTrade_2
EscapeRoom_HiddenDungeon_BagonYamaskTrade_1:
# 359 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message YamaskReceivedMessage
# 360 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 361 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 362 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 365 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 366 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 367 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 368 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 371 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_BAGON
# 372 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_SHELGON
# 373 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_YAMASK_GALAR, 5, abilityNum = 0, nature = NATURE_HASTY, gender = MON_MALE, move1 = MOVE_ASTONISH, move2 = MOVE_HAZE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 395 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_YAMASK_OBTAINED
	return

EscapeRoom_HiddenDungeon_BagonYamaskTrade_2:
# 352 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 353 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_BagonYamaskTrade_1


EscapeRoom_HiddenDungeon_RemoveTMSecretPower::
# 400 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 401 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1:
# 404 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 405 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6:
# 408 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TM43
# 409 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11
	return

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2:
# 402 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3:
# 401 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7:
# 406 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8:
# 405 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11:
# 410 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeitem ITEM_TM43
	return


EscapeRoom_HiddenDungeon_YamaskGuy::
# 416 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 419 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_YamaskGuy_2
# 424 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyFinalMessage, MSGBOX_NPC
# 425 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_YamaskGuy_1:
# 428 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_YamaskGuy_2:
# 420 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_NPC
# 421 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_YamaskGuy_1


EscapeRoom_HiddenDungeon_MoveRelearner::
# 434 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 435 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 438 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerMainMessage, MSGBOX_DEFAULT
# 439 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 442 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special ChooseMonForMoveRelearner
# 443 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitstate
# 452 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerEndMessage, MSGBOX_DEFAULT
# 453 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 456 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_EscapeRopeEE_message1::
# 462 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 2
# 463 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 464 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox EscapeRopeEEMessage1, MSGBOX_AUTOCLOSE
# 465 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
	return


EscapeRoom_HiddenDungeon_EscapeRopeEE_message2andwarp::
# 469 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 3
# 470 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox EscapeRopeEEMessage2, MSGBOX_AUTOCLOSE
# 471 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 472 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 47, 17
# 473 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitstate
	return


AskBagonTrade::
# 481 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Bagon so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

BagonReceivedMessage::
# 496 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Bagon!$"

BagonTradeDeclined::
# 500 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

BagonTradePostTrade::
# 504 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 511 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 517 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 522 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 532 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hm... Cute entry card though.$"

YamaskReceivedMessage::
# 540 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Yamask!$"

YamaskGuyPostTradeMessage::
# 544 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "The trainer you're about to face can be\n"
	.string "a bit of a cheater.\p"
	.string "The Kecleon uses an illegal move and\n"
	.string "their Struggle always seems to find\l"
	.string "the optimal target.\p"
	.string "Don't worry, you've got everything you\n"
	.string "need to come out on top.\p"
	.string "Good luck!$"

YamaskGuyFinalMessage::
# 563 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Wow... Well done!$"

YamaskGuyMainMessage::
# 567 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're almost there!\n"
	.string "Just one more challenge remains.\p"
	.string "It's a tough one though...\p"
	.string "Allow me to take your Bagon and provide\n"
	.string "you with something more suitable.\p"
	.string "You wouldn't stand a chance otherwise.$"

MoveRelearnerMainMessage::
# 578 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hi, I'm your Move Tutor.\p"
	.string "Which of your Pokémon should I teach a\n"
	.string "new move?$"

MoveRelearnerEndMessage::
# 584 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "I'll be here if you need me.$"

EscapeRopeEEMessage1::
# 589 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EscapeRopeEEMessage2::
# 594 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Just kidding.$"
