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
# 108 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 109 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 110 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 113 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 118 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 123 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 111 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 110 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 115 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 119 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 132 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 133 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 134 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 135 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 136 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 137 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 138 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 139 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 140 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 141 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 144 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	return


EscapeRoom_MapScripts_SomethingWrongMessage::
# 151 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 152 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 0
# 153 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 154 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 155 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon::
# 165 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 166 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 169 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2
# 184 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskBagonTrade, MSGBOX_YESNO
# 185 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5
# 255 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradeDeclined, MSGBOX_AUTOCLOSE
# 256 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1:
# 259 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2:
# 170 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradePostTrade, MSGBOX_NPC
# 171 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 174 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 175 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 176 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 177 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 178 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_BAGON_TRADER
# 179 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 180 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5:
# 188 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 189 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 190 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9
# 197 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 198 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 199 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12
# 208 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message BagonReceivedMessage
# 209 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 210 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 211 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 214 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 215 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 216 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 217 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 220 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 221 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 222 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 223 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 226 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 227 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 228 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 229 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_BAGON, 34, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = NATURE_MODEST, gender = MON_MALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_SUBSTITUTE, move3 = MOVE_NONE, move4 = MOVE_NONE, spAtkEv = 252, speedEv = 252, hpIv = 1, atkIv = 0, defIv = 1, spAtkIv = 31, spDefIv = 31, speedIv = 30
# 251 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9:
# 192 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 193 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 194 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12:
# 201 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 202 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 203 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 266 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 268 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 275 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 276 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 279 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 280 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 298 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 270 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 271 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 283 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 284 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 287 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 288 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 291 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 292 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 293 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 295 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 301 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 302 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 303 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 304 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

EscapeRoom_HiddenDungeon_FinaleReachedTrigger::
# 310 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 312 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_YAMASK_OBTAINED, EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2
# 351 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 352 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 355 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 356 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 359 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 360 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 363 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 364 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1:
# 366 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2:
# 315 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 316 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 317 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_PIN
# 318 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 319 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 320 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 30
# 323 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 324 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 327 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_FINAL_BATTLE
# 328 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 329 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 332 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyMainMessage, MSGBOX_DEFAULT
# 333 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 336 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_BagonYamaskTrade
# 339 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 340 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 343 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 344 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 347 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_RemoveTMSecretPower
	goto EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1


# 369 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
PlayerMoveUp:
# 370 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_up
# 371 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_up
	step_end

EscapeRoom_HiddenDungeon_BagonYamaskTrade::
# 376 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_BAGON
# 377 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 378 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_BagonYamaskTrade_2
EscapeRoom_HiddenDungeon_BagonYamaskTrade_1:
# 387 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message YamaskReceivedMessage
# 388 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 389 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 390 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 393 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 394 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 395 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 396 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 399 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_BAGON
# 400 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_SHELGON
# 401 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_YAMASK_GALAR, 5, abilityNum = 0, nature = NATURE_HASTY, gender = MON_MALE, move1 = MOVE_ASTONISH, move2 = MOVE_HAZE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 423 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_YAMASK_OBTAINED
	return

EscapeRoom_HiddenDungeon_BagonYamaskTrade_2:
# 380 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 381 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_BagonYamaskTrade_1


EscapeRoom_HiddenDungeon_RemoveTMSecretPower::
# 428 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 429 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1:
# 432 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 433 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6:
# 436 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TM43
# 437 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11
	return

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2:
# 430 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3:
# 429 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7:
# 434 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8:
# 433 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11:
# 438 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeitem ITEM_TM43
	return


EscapeRoom_HiddenDungeon_YamaskGuy::
# 444 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 447 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_YamaskGuy_2
# 452 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyFinalMessage, MSGBOX_NPC
# 453 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_YamaskGuy_1:
# 456 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_YamaskGuy_2:
# 448 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_NPC
# 449 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_YamaskGuy_1


EscapeRoom_HiddenDungeon_MoveRelearner::
# 462 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 463 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 466 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerMainMessage, MSGBOX_DEFAULT
# 467 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 470 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special ChooseMonForMoveRelearner
# 471 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitstate
# 480 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerEndMessage, MSGBOX_DEFAULT
# 481 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 484 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


AskBagonTrade::
# 493 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Bagon so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

BagonReceivedMessage::
# 508 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Bagon!$"

BagonTradeDeclined::
# 512 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

BagonTradePostTrade::
# 516 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 523 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 529 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 534 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 544 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hm... Cute entry card though.$"

YamaskReceivedMessage::
# 552 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Yamask!$"

YamaskGuyPostTradeMessage::
# 556 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
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
# 575 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Wow... Well done!$"

YamaskGuyMainMessage::
# 579 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're almost there!\n"
	.string "Only one more challenge remains.\p"
	.string "It's a tough one though...\p"
	.string "Allow me to take your Bagon and provide\n"
	.string "you with something more suitable.\p"
	.string "You wouldn't stand a chance otherwise.$"

MoveRelearnerMainMessage::
# 590 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hi, I'm your Move Tutor.\p"
	.string "Which of your Pokémon should I teach a\n"
	.string "new move?$"

MoveRelearnerEndMessage::
# 596 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "I'll be here if you need me.$"
