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
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 17 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_DO_SOMETHING_WRONG_MESSAGE, 1, EscapeRoom_MapScripts_SomethingWrongMessage
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts::
# 24 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1
	return

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1:
# 25 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 11, 4, 8
# 26 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	return


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 31 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 32 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 33 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained
# 34 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained
# 38 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 42 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 45 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts_1
	return

EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts_1:
# 46 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_HiddenDungeon_DisableBagUse::
# 52 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_HiddenDungeon_DisableBagUse_1
	return

EscapeRoom_HiddenDungeon_DisableBagUse_1:
# 53 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_HiddenDungeon_SetLostItemVars::
# 59 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_HiddenDungeon_SetLostItemVars_1
	return

EscapeRoom_HiddenDungeon_SetLostItemVars_1:
# 61 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained::
# 66 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1:
# 67 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 76 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 77 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 78 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 79 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 80 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 81 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 82 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 83 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 84 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 85 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6
EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5:
# 92 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removetaughtmove SPECIES_CACNEA, MOVE_THIEF
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2:
# 66 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_6:
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_5


EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained::
# 97 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_1:
# 98 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 0
# 99 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3:
# 102 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartyitem 1
# 103 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8:
# 106 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 107 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14
EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13:
# 112 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4:
# 100 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_5:
# 99 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_4
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_3

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9:
# 104 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_10:
# 103 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_9
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_8

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_14:
# 108 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_13

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_16:
# 121 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkexactmoney 0
# 122 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 123 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 124 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 125 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 126 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 127 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 128 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 129 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 130 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
# 131 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18
	return

EscapeRoom_HiddenDungeon_CheckIfToxicOrbObtained_18:
# 133 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	return


EscapeRoom_MapScripts_SomethingWrongMessage::
# 140 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 141 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 0
# 142 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 143 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 144 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return


EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea::
# 154 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lock
# 155 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 158 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_2
# 173 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox AskCacneaTrade, MSGBOX_YESNO
# 174 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_5
# 245 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox CacneaTradeDeclined, MSGBOX_AUTOCLOSE
# 246 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1:
# 249 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_2:
# 159 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox CacneaTradePostTrade, MSGBOX_NPC
# 160 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 163 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_TO_BLACK
# 164 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playse SE_EXIT
# 165 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	delay 15
# 166 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removeobject 6
# 167 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_HIDE_CACNEA_TRADER
# 168 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 169 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitse
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_5:
# 177 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 178 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 179 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_9
# 186 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 187 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 188 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_12
# 197 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	message CacneaReceivedMessage
# 198 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 199 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 200 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitfanfare
# 203 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 204 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 205 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 206 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 209 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 210 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	special BufferMonNickname
# 211 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_DEFAULT
# 212 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 215 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_AIPOM
# 216 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	removemon SPECIES_LIEPARD
# 217 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 218 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	givemon SPECIES_CACNEA, 41, item = ITEM_RAINBOW_PASS, abilityNum = 2, nature = 18, gender = MON_FEMALE, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 31, atkIv = 30, defIv = 31, speedIv = 30, spAtkIv = 31, spDefIv = 31
# 241 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
	goto EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_1

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_9:
# 181 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 182 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 183 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end

EscapeRoom_HiddenDungeon_TradeAipomLiepardForCacnea_12:
# 190 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 191 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 192 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	end


EscapeRoom_HiddenDungeon_DungeonGuard::
# 255 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 256 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 258 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 265 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_DEFAULT
# 266 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 269 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_RAINBOW_PASS
# 270 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 288 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 260 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_DEFAULT
# 261 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 273 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowsCard, MSGBOX_DEFAULT
# 274 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 277 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardGivesEntry, MSGBOX_AUTOCLOSE
# 278 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 281 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 282 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 283 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 285 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 291 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 292 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 293 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 294 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

AskCacneaTrade::
# 302 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Trying to get past the guard?\p"
	.string "I might be able to help you out.\n"
	.string "How badly do you want in?\p"
	.string "Give me your Pokémon and I'll get you\n"
	.string "in that restricted area.\p"
	.string "You can have my Cacnea so you won't be\n"
	.string "stuck without a partner.\p"
	.string "Do we have a deal?$"

CacneaReceivedMessage::
# 317 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "{PLAYER} received a Cacnea!$"

CacneaTradeDeclined::
# 321 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Suit yourself.$"

CacneaTradePostTrade::
# 325 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hehehehe!$"

DungeonGuardIntro::
# 332 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "I'll need to see an entry card, or you\n"
	.string "are not getting through.$"

DungeonGuardShowsCard::
# 338 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "(You hesitantly hold up your rainbow-\n"
	.string "colored entry card.)$"

DungeonGuardGivesEntry::
# 343 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Hmmm...\p"
	.string "This doesn't look like one of our usual\n"
	.string "entry cards.\p"
	.string "...\p"
	.string "Honestly, I've seen stranger cards make\n"
	.string "it through.\p"
	.string "You're clear to enter.$"

DungeonGuardPostEntry::
# 353 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're not very normal, are you?\n"
	.string "Just don't cause any trouble$"
