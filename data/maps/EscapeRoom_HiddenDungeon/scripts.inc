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


EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained::
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_4
EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1:
# 110 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	clearflag FLAG_FIELD_POISON_WHITEOUT
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2:
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
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9
# 93 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9
# 94 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9
# 95 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9
# 96 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9
# 97 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9
EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_8:
# 103 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_THIEF
# 106 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_3:
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_FIELD_POISON_WHITEOUT, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_4:
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_3
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_9:
# 99 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_8


EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained::
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 115 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 116 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 119 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 120 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 123 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 124 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 129 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 116 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 121 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 120 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 125 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 138 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 139 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 140 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 141 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 143 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 144 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 145 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 146 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 147 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 148 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 150 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	return


EscapeRoom_MapScripts_SomethingWrongMessage::
# 157 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 158 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 0
# 159 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 160 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 161 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon::
# 171 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 172 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 175 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2
# 190 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskBagonTrade, MSGBOX_YESNO
# 191 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5
# 261 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradeDeclined, MSGBOX_AUTOCLOSE
# 262 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1:
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_2:
# 176 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox BagonTradePostTrade, MSGBOX_NPC
# 177 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 180 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 181 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 182 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 183 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 184 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_BAGON_TRADER
# 185 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 186 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_5:
# 194 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 195 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 196 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9
# 203 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 204 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 205 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12
# 214 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message BagonReceivedMessage
# 215 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 216 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 217 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 220 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 221 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 222 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 223 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 226 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 227 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 228 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 229 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 232 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 233 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 234 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 235 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_BAGON, 34, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = NATURE_MODEST, gender = MON_MALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_SUBSTITUTE, move3 = MOVE_NONE, move4 = MOVE_NONE, spAtkEv = 252, speedEv = 252, hpIv = 1, atkIv = 0, defIv = 1, spAtkIv = 31, spDefIv = 31, speedIv = 30
# 257 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_9:
# 198 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 199 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 200 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForBagon_12:
# 207 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 208 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 209 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 271 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 272 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 274 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 281 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 282 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 285 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 286 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 304 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 276 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 277 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 289 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 290 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 293 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 294 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 297 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 298 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 299 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 301 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 307 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 308 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 309 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 310 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

EscapeRoom_HiddenDungeon_FinaleReachedTrigger::
# 316 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 318 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_YAMASK_OBTAINED, EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2
# 357 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 358 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 361 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 362 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 365 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 366 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 369 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 370 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1:
# 372 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_FinaleReachedTrigger_2:
# 321 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, _face_right
# 322 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 323 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_PIN
# 324 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 325 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 14
# 326 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 30
# 329 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_left
# 330 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 333 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_FINAL_BATTLE
# 334 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 335 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 338 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyMainMessage, MSGBOX_DEFAULT
# 339 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 342 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_BagonYamaskTrade
# 345 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_AUTOCLOSE
# 346 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 349 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveUp
# 350 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 353 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_RemoveTMSecretPower
	goto EscapeRoom_HiddenDungeon_FinaleReachedTrigger_1


# 375 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
PlayerMoveUp:
# 376 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_up
# 377 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_up
	step_end

EscapeRoom_HiddenDungeon_BagonYamaskTrade::
# 382 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_BAGON
# 383 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 384 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_BagonYamaskTrade_2
EscapeRoom_HiddenDungeon_BagonYamaskTrade_1:
# 393 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message YamaskReceivedMessage
# 394 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 395 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 396 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 399 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 400 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 401 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 402 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 405 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_BAGON
# 406 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_SHELGON
# 407 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_YAMASK_GALAR, 5, abilityNum = 0, nature = NATURE_HASTY, gender = MON_MALE, move1 = MOVE_ASTONISH, move2 = MOVE_HAZE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 429 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_YAMASK_OBTAINED
	return

EscapeRoom_HiddenDungeon_BagonYamaskTrade_2:
# 386 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 387 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_BagonYamaskTrade_1


EscapeRoom_HiddenDungeon_RemoveTMSecretPower::
# 434 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 435 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1:
# 438 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 439 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8
EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6:
# 442 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TM43
# 443 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11
	return

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2:
# 436 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_3:
# 435 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_2
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_1

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7:
# 440 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_8:
# 439 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_HiddenDungeon_RemoveTMSecretPower_7
	goto EscapeRoom_HiddenDungeon_RemoveTMSecretPower_6

EscapeRoom_HiddenDungeon_RemoveTMSecretPower_11:
# 444 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeitem ITEM_TM43
	return


EscapeRoom_HiddenDungeon_YamaskGuy::
# 450 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 453 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_HiddenDungeon_YamaskGuy_2
# 458 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyFinalMessage, MSGBOX_NPC
# 459 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_YamaskGuy_1:
# 462 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_YamaskGuy_2:
# 454 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox YamaskGuyPostTradeMessage, MSGBOX_NPC
# 455 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_YamaskGuy_1


EscapeRoom_HiddenDungeon_MoveRelearner::
# 468 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 469 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 472 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerMainMessage, MSGBOX_DEFAULT
# 473 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 476 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special ChooseMonForMoveRelearner
# 477 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitstate
# 486 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox MoveRelearnerEndMessage, MSGBOX_DEFAULT
# 487 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 490 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


AskBagonTrade::
# 499 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Bagon so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

BagonReceivedMessage::
# 514 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Bagon!$"

BagonTradeDeclined::
# 518 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

BagonTradePostTrade::
# 522 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 529 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 535 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 540 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 550 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hm... Cute entry card though.$"

YamaskReceivedMessage::
# 558 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Yamask!$"

YamaskGuyPostTradeMessage::
# 562 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
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
# 581 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Wow... Well done!$"

YamaskGuyMainMessage::
# 585 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're almost there!\n"
	.string "Only one more challenge remains.\p"
	.string "It's a tough one though...\p"
	.string "Allow me to take your Bagon and provide\n"
	.string "you with something more suitable.\p"
	.string "You wouldn't stand a chance otherwise.$"

MoveRelearnerMainMessage::
# 596 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hi, I'm your Move Tutor.\p"
	.string "Which of your Pokémon should I teach a\n"
	.string "new move?$"

MoveRelearnerEndMessage::
# 602 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "I'll be here if you need me.$"
