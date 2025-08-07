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
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts::
# 22 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1
	return

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1:
# 23 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 11, 4, 8
# 24 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	return


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 29 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 30 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 31 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 32 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained
# 33 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained
	return


EscapeRoom_HiddenDungeon_DisableBagUse::
# 38 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_HiddenDungeon_DisableBagUse_1
	return

EscapeRoom_HiddenDungeon_DisableBagUse_1:
# 39 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_HiddenDungeon_SetLostItemVars::
# 45 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_HiddenDungeon_SetLostItemVars_1
	return

EscapeRoom_HiddenDungeon_SetLostItemVars_1:
# 47 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained::
# 52 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1:
# 53 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 62 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 63 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 64 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 65 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 66 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 67 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 68 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 69 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 70 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 71 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 72 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5:
# 78 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
# 81 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removetaughtmove SPECIES_CACNEA, MOVE_THIEF
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2:
# 52 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6:
# 74 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 75 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 76 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5


EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained::
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 87 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 91 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 92 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 95 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 96 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 101 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 89 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 93 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 92 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 97 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 110 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 111 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 112 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 113 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 114 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 115 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19
# 116 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19
# 118 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19
# 119 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19
# 120 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 126 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_19:
# 122 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 123 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 124 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18


EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea::
# 138 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 139 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_2
# 157 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskCacneaTrade, MSGBOX_YESNO
# 158 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_5
# 229 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox CacneaTradeDeclined, MSGBOX_AUTOCLOSE
# 230 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1:
# 233 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_2:
# 143 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox CacneaTradePostTrade, MSGBOX_NPC
# 144 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 147 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 148 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 149 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 150 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 151 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_CACNEA_TRADER
# 152 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 153 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_5:
# 161 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 162 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 163 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_9
# 170 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 171 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 172 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_12
# 181 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message CacneaReceivedMessage
# 182 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 183 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 184 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 187 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 188 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 189 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 190 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 193 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 194 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 195 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 196 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 199 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 200 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 201 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 202 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_CACNEA, 41, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = 18, gender = MON_FEMALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 31, atkIv = 30, defIv = 31, speedIv = 30, spAtkIv = 31, spDefIv = 31
# 225 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_9:
# 165 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 166 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 167 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_12:
# 174 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 175 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 176 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 239 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 240 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 242 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 249 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 250 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 253 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 254 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
# 273 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 274 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 277 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 244 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 245 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 257 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 258 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 261 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 262 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 266 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 267 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 269 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 280 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 281 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 282 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 283 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

AskCacneaTrade::
# 291 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Cacnea so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

CacneaReceivedMessage::
# 306 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Cacnea!$"

CacneaTradeDeclined::
# 310 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

CacneaTradePostTrade::
# 314 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 321 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 327 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 332 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 342 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're not very normal, are you?\n"
	.string "Just don't cause any trouble$"
