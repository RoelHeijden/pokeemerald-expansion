EscapeRoom_HiddenDungeon_MapScripts::
# 9 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts
# 10 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts
# 12 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 14 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 15 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 16 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_DO_SOMETHING_WRONG_MESSAGE, 1, EscapeRoom_MapScripts_SomethingWrongMessage
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts::
# 23 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1
	return

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1:
# 24 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 11, 4, 8
# 25 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	return


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 30 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 31 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 32 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 33 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained
# 34 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained
	return


EscapeRoom_HiddenDungeon_DisableBagUse::
# 39 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_HiddenDungeon_DisableBagUse_1
	return

EscapeRoom_HiddenDungeon_DisableBagUse_1:
# 40 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_HiddenDungeon_SetLostItemVars::
# 46 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_HiddenDungeon_SetLostItemVars_1
	return

EscapeRoom_HiddenDungeon_SetLostItemVars_1:
# 48 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained::
# 53 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1:
# 54 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 63 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 64 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 65 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 66 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 67 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 68 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 69 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 70 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 71 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 72 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 73 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5:
# 79 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removetaughtmove SPECIES_CACNEA, MOVE_THIEF
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2:
# 53 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6:
# 75 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5


EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained::
# 84 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 85 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 89 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 90 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 93 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 94 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 99 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 87 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 91 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 90 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 95 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 108 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 109 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 110 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 111 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 112 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 113 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 115 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 116 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 118 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 120 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	return


EscapeRoom_MapScripts_SomethingWrongMessage::
# 127 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 128 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 0
# 129 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 130 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 131 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea::
# 141 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 145 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_2
# 160 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskCacneaTrade, MSGBOX_YESNO
# 161 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_5
# 232 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox CacneaTradeDeclined, MSGBOX_AUTOCLOSE
# 233 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1:
# 236 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_2:
# 146 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox CacneaTradePostTrade, MSGBOX_NPC
# 147 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 150 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 151 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 152 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 153 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 154 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_CACNEA_TRADER
# 155 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 156 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_5:
# 164 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 165 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 166 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_9
# 173 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 174 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 175 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_12
# 184 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message CacneaReceivedMessage
# 185 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 186 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 187 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 190 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 191 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 192 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 193 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 196 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 197 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 198 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 199 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 202 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 203 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 204 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 205 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_CACNEA, 41, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = 18, gender = MON_FEMALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 31, atkIv = 30, defIv = 31, speedIv = 30, spAtkIv = 31, spDefIv = 31
# 228 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_9:
# 168 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 169 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 170 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_12:
# 177 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 178 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 179 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 242 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 243 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 245 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 252 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 253 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 256 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 257 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 275 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 247 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 248 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 260 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 261 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 264 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 268 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 269 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 270 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 272 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 278 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 279 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 280 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 281 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

AskCacneaTrade::
# 289 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Cacnea so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

CacneaReceivedMessage::
# 304 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Cacnea!$"

CacneaTradeDeclined::
# 308 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

CacneaTradePostTrade::
# 312 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 319 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 325 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 330 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 340 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're not very normal, are you?\n"
	.string "Just don't cause any trouble$"
