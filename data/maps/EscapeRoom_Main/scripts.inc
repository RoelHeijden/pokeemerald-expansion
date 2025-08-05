# 47 "data/maps/EscapeRoom_Main/scripts.pory"
_face_down:
# 48 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 50 "data/maps/EscapeRoom_Main/scripts.pory"
_face_up:
# 51 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 53 "data/maps/EscapeRoom_Main/scripts.pory"
_face_right:
# 54 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 56 "data/maps/EscapeRoom_Main/scripts.pory"
_face_left:
# 57 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_Main_MapScripts::
# 64 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 65 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 67 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 68 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 75 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 76 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 85 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 90 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 92 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 103 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_14
EscapeRoom_MapScript_OnResumeScripts_12:
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_18
EscapeRoom_MapScript_OnResumeScripts_17:
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_21
EscapeRoom_MapScript_OnResumeScripts_20:
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 99 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 103 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 115 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_14:
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_13
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_18:
# 120 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_17

EscapeRoom_MapScript_OnResumeScripts_21:
# 125 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_20


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 151 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 157 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 164 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 165 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 166 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 167 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 173 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 176 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 177 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 177 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 183 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 189 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 202 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_9
EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 219 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_12
EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_9:
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_8

EscapeRoom_MapScripts_CheckIfAskPreDamage_12:
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_11


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 241 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 242 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 246 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 250 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 255 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 266 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 267 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 242 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 262 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 268 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 267 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 279 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 280 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 281 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 289 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 292 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_AskResetPredamage::
# 300 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 306 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_MapScripts_AskResetPredamage_5
EscapeRoom_MapScripts_AskResetPredamage_3:
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_12
EscapeRoom_MapScripts_AskResetPredamage_1:
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 307 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_9
# 319 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 320 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 321 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_4:
# 306 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
	goto EscapeRoom_MapScripts_AskResetPredamage_3

EscapeRoom_MapScripts_AskResetPredamage_5:
# 306 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScripts_AskResetPredamage_4
	goto EscapeRoom_MapScripts_AskResetPredamage_3

EscapeRoom_MapScripts_AskResetPredamage_9:
# 310 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 311 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 312 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 315 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_12:
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_14
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_14:
# 334 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 344 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 358 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScript_GameStartScripts::
# 374 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 375 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 381 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 383 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 390 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SLEEP_TALK, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_EXP_CANDY_S, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 452 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 466 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 471 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawn1
	return


EscapeRoom_MapScripts_GetItems::
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_SetRespawn1::
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 1
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 0
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	return


EscapeRoom_EventScript_SetRespawn2::
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_SetRespawn2_1
	return

EscapeRoom_EventScript_SetRespawn2_1:
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawn3::
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 0
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 1
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_MainInfoSign::
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 533 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 562 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 563 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 584 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 585 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 586 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 596 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 604 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 600 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 627 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 628 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_SOFTLOCK_GUY
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1


EscapeRoom_EventScript_ReturnLostItems::
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 672 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 686 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 732 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_30
EscapeRoom_EventScript_ReturnLostItems_29:
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUSK_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_37
EscapeRoom_EventScript_ReturnLostItems_34:
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_41:
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_51
EscapeRoom_EventScript_ReturnLostItems_48:
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_55
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_55
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 820 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmonmove0pp SPECIES_FLORGES, MOVE_CAMOUFLAGE
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_13
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_13:
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_17:
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_25
EscapeRoom_EventScript_ReturnLostItems_23:
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_32
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_22:
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_24:
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_22
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_25:
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_24
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_30:
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_29

EscapeRoom_EventScript_ReturnLostItems_32:
# 726 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_35:
# 752 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUSK_STONE_CONSUMED
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_DUSK_STONE
# 754 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_36:
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_35
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_37:
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_36
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_42:
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 760 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 761 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_41

EscapeRoom_EventScript_ReturnLostItems_43:
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_42
	goto EscapeRoom_EventScript_ReturnLostItems_41

EscapeRoom_EventScript_ReturnLostItems_44:
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_41

EscapeRoom_EventScript_ReturnLostItems_49:
# 766 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_48

EscapeRoom_EventScript_ReturnLostItems_50:
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_49
	goto EscapeRoom_EventScript_ReturnLostItems_48

EscapeRoom_EventScript_ReturnLostItems_51:
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_50
	goto EscapeRoom_EventScript_ReturnLostItems_48

EscapeRoom_EventScript_ReturnLostItems_55:
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_65
EscapeRoom_EventScript_ReturnLostItems_63:
# 805 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_61
	return

EscapeRoom_EventScript_ReturnLostItems_60:
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_69
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_61:
# 806 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_64:
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_60
	goto EscapeRoom_EventScript_ReturnLostItems_63

EscapeRoom_EventScript_ReturnLostItems_65:
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_64
	goto EscapeRoom_EventScript_ReturnLostItems_63

EscapeRoom_EventScript_ReturnLostItems_69:
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 788 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 23, 11
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_UndoUsedItems::
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_AUTOCLOSE
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoOtherActions::
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_0x8005
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 837 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8005
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, ITEM_ETHER
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, ITEM_ETHER
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
EscapeRoom_EventScript_UndoOtherActions_13:
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_10:
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_9
EscapeRoom_EventScript_UndoOtherActions_7:
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_6
EscapeRoom_EventScript_UndoOtherActions_5:
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_AUTOCLOSE
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoEtherPurchase, MSGBOX_YESNO
# 846 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_24
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 856 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_26
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 864 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_28
	return

EscapeRoom_EventScript_UndoOtherActions_4:
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_30
	return

EscapeRoom_EventScript_UndoOtherActions_6:
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_4
	goto EscapeRoom_EventScript_UndoOtherActions_5

EscapeRoom_EventScript_UndoOtherActions_9:
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_7

EscapeRoom_EventScript_UndoOtherActions_12:
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_10

EscapeRoom_EventScript_UndoOtherActions_15:
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_13

EscapeRoom_EventScript_UndoOtherActions_16:
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ETHER_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_15
	goto EscapeRoom_EventScript_UndoOtherActions_13

EscapeRoom_EventScript_UndoOtherActions_24:
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoEtherPurchase
	return

EscapeRoom_EventScript_UndoOtherActions_26:
# 857 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_28:
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_30:
# 875 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_UndoEtherPurchase::
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoEtherPurchase_2
EscapeRoom_EventScript_UndoEtherPurchase_1:
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 895 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ETHER
	goto_if_eq EscapeRoom_EventScript_UndoEtherPurchase_5
EscapeRoom_EventScript_UndoEtherPurchase_4:
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ETHER
	goto_if_eq EscapeRoom_EventScript_UndoEtherPurchase_8
EscapeRoom_EventScript_UndoEtherPurchase_7:
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 500
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived500
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockEtherPurchaseUndone, MSGBOX_AUTOCLOSE
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ETHER_BOUGHT
	return

EscapeRoom_EventScript_UndoEtherPurchase_2:
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_ETHER
	goto EscapeRoom_EventScript_UndoEtherPurchase_1

EscapeRoom_EventScript_UndoEtherPurchase_5:
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoEtherPurchase_4

EscapeRoom_EventScript_UndoEtherPurchase_8:
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoEtherPurchase_7


EscapeRoom_EventScript_SetTrainer5Rematch::
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_AUTOCLOSE
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUSK_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUSK_STONE_CONSUMED
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_DUSK_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 935 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10


EscapeRoom_EventScript_UndoFerroTrade::
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 955 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return


EscapeRoom_EventScript_UndoFlorgesTrade::
# 964 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return


EscapeRoom_EventScript_LiepardNPC::
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 990 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1000 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 1001 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 1016 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1017 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1023 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 1027 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1028 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1031 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 1036 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 1060 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1069 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 1075 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 1087 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 1088 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 1096 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1102 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_COPYCAT, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 1124 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1129 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 1166 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 1180 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 1181 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	return


# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 1193 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1208 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1209 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 1213 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 1218 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 1223 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1234 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 1266 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1277 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1278 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1282 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 1291 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1292 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1297 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 1321 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 1322 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1331 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 1356 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_OBTAINED, EscapeRoom_ZeraoraHintNPC_8
# 1366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage3, MSGBOX_NPC
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1347 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_8:
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 1362 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage2, MSGBOX_NPC
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1381 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1400 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1414 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1415 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1419 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 1479 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_DUSK_STONE
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_12
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end

EscapeRoom_TryBuyStonesPC_12:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyDuskStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 1513 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 1500
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived1500
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 1533 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 1500
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1537 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived1500
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1542 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyDuskStone::
# 1552 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_DuskStone, MSGBOX_YESNO
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyDuskStone_1
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyDuskStone_1:
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_DUSK_STONE
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 1561 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_SecretGarden_SecretPowerNPC::
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_SecretGarden_SecretPowerNPC_2
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_AskLovePlants, MSGBOX_YESNO
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_5
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_THIEF
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_8
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes, MSGBOX_AUTOCLOSE
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1608 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1611 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes_Thief, MSGBOX_YESNO
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_11
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_TeachDeclinedMessage, MSGBOX_AUTOCLOSE
# 1621 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_SecretGarden_SecretPowerNPC_4:
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_SecretPowerNPC_2:
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_EndOfScriptMessage, MSGBOX_AUTOCLOSE
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_SecretGarden_SecretPowerNPC_5:
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_No, MSGBOX_AUTOCLOSE
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_4

EscapeRoom_SecretGarden_SecretPowerNPC_8:
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes, MSGBOX_AUTOCLOSE
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_SecretGarden_TeachSecretPower
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PostTeachMessage, MSGBOX_AUTOCLOSE
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_4

EscapeRoom_SecretGarden_SecretPowerNPC_11:
# 1614 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_SecretGarden_TeachSecretPower
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PostTeachMessage, MSGBOX_AUTOCLOSE
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_4


EscapeRoom_SecretGarden_TeachSecretPower::
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_THIEF
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_2
EscapeRoom_SecretGarden_TeachSecretPower_1:
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACNEA
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_5
EscapeRoom_SecretGarden_TeachSecretPower_4:
# 1647 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_13
EscapeRoom_SecretGarden_TeachSecretPower_12:
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonLearnedSecretPower, MSGBOX_AUTOCLOSE
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_LEARNED
	return

EscapeRoom_SecretGarden_TeachSecretPower_2:
# 1632 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_SecretGarden_TeachSecretPower_8
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_SecretGarden_TeachSecretPower_9
EscapeRoom_SecretGarden_TeachSecretPower_7:
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_THIEF_REPLACED
	goto EscapeRoom_SecretGarden_TeachSecretPower_1

EscapeRoom_SecretGarden_TeachSecretPower_5:
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACNEA, MOVE_SECRET_POWER
	goto EscapeRoom_SecretGarden_TeachSecretPower_4

EscapeRoom_SecretGarden_TeachSecretPower_8:
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 0, MOVE_THIEF, MOVE_NONE
	goto EscapeRoom_SecretGarden_TeachSecretPower_7

EscapeRoom_SecretGarden_TeachSecretPower_9:
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 1, MOVE_THIEF, MOVE_NONE
	goto EscapeRoom_SecretGarden_TeachSecretPower_7

EscapeRoom_SecretGarden_TeachSecretPower_13:
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACTURNE, MOVE_SECRET_POWER
	goto EscapeRoom_SecretGarden_TeachSecretPower_12


EscapeRoom_SecretGarden_GateEntryNPC_KeepOut::
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, _face_left
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 25
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardKeepOut, MSGBOX_AUTOCLOSE
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_SecretGarden_GateEntryNPC_KickOut::
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1691 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1692 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, _face_down
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1698 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, SecretGarden_NPC_move_down
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardSpotted, MSGBOX_AUTOCLOSE
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, SecretGarden_NPC_move_up
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveUp
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_LEARNED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1:
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2:
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardStayOut, MSGBOX_AUTOCLOSE
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3:
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardRemoveSecretPower, MSGBOX_AUTOCLOSE
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SECRET_POWER
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_7
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_6:
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_LEARNED
# 1735 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_THIEF_REPLACED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_12
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_11:
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACNEA
# 1745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_GateEntryNPC_KickOut_15
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14:
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_GateEntryNPC_KickOut_18
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_17:
# 1753 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1756 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_20
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_7:
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 0, MOVE_SECRET_POWER, MOVE_NONE
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_6

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8:
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 1, MOVE_SECRET_POWER, MOVE_NONE
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_6

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_12:
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACNEA, MOVE_THIEF
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACTURNE, MOVE_THIEF
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_THIEF_REPLACED
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_11

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_15:
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_18:
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_17

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_20:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonThiefRestored, MSGBOX_AUTOCLOSE
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1


# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_down:
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_up:
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveUp:
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveLeft:
# 1790 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
# 1791 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_AnnihilapeHintNPC::
# 1798 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1801 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 1820 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 1822 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 1825 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_DusknoirStoleMyMailNPC::
# 1834 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DusknoirStoleMyMailMsg, MSGBOX_NPC
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EtherSellNPC::
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ETHER_BOUGHT, EscapeRoom_EtherSellNPC_2
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EtherNPCpostSellMessage, MSGBOX_AUTOCLOSE
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EtherSellNPC_1:
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EtherSellNPC_2:
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EtherNPCbuyEther, MSGBOX_YESNO
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EtherSellNPC_5
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EtherNPCsellDeclined, MSGBOX_AUTOCLOSE
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EtherSellNPC_1

EscapeRoom_EtherSellNPC_5:
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 500
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EtherSellNPC_9
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 500
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EtherNPCsellAcceptedMessage, MSGBOX_AUTOCLOSE
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ETHER_BOUGHT
	goto EscapeRoom_EtherSellNPC_1

EscapeRoom_EtherSellNPC_9:
# 1852 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EtherNPCnotEnoughMoney, MSGBOX_AUTOCLOSE
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1854 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_Trainer1::
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 1897 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 1913 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 1946 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 1947 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 1955 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 1948 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 1947 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 1956 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUSK_STONE_CONSUMED
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 1976 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 1983 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 1984 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 1997 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer8_PostBattle, MSGBOX_AUTOCLOSE
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer9::
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 2048 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle, MSGBOX_AUTOCLOSE
# 2062 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2080 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 2088 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2096 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2097 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 2081 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2084 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 2123 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 2136 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 2129 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2130 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2166 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 2182 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2196 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 2197 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 2198 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 2210 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_3
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2230 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_3:
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUSK_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 2268 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 2291 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2250 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 2257 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2258 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_DUSK_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2262 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_DUSK_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 2273 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_29
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 2251 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 2281 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_31
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 2271 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 2263 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_29:
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_31:
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18


EscapeRoom_EventScript_Trainer6PostBattle::
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2300 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 2303 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 2304 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2335 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2336 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2338 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 2339 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2340 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 2343 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 2344 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_DUSK_STONE
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 2351 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 2352 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 2354 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 2355 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 2359 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 2360 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 2362 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2363 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2364 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 2366 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 2367 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2371 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2372 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2374 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2375 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2376 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2377 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 2316 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 2308 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2380 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2381 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2382 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 2387 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer7BPostBattle::
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 2393 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 2398 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer9PostBattle::
# 2402 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 2403 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer10PostBattle::
# 2407 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer11PostBattle::
# 2412 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 2413 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 2420 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 2449 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 2451 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2428 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 2440 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 2442 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2445 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 2430 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 2455 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2456 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 2484 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 2546 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 2478 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 2464 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 2488 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 2489 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2490 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 2499 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 2502 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 2503 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2509 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2514 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 2537 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 2468 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 2492 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 2551 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2552 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2555 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 2580 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 2581 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 2615 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 2616 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 2575 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2585 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 2595 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2600 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2605 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 2606 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2609 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 2611 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 2564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2624 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2627 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 2663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 2664 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 2628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 2629 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 2638 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2639 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 2648 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2650 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 2653 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 2655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2642 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2643 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindLiepardCollar::
# 2674 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 2677 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy2::
# 2682 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2683 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 2685 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 2686 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPrimeape::
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2700 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_RARE_CANDY, abilityNum = 2, nature = 15, gender = MON_FEMALE, move1 = MOVE_TAUNT, move2 = MOVE_RAGE_FIST, move3 = MOVE_COUNTER, move4 = MOVE_NONE, atkEv = 0, spAtkEv = 0, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 2730 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2731 "data/maps/EscapeRoom_Main/scripts.pory"
	message PrimeapeObtainMessage
# 2732 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2733 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2736 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 2737 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_FindPrimeape_2
EscapeRoom_EventScript_FindPrimeape_1:
# 2741 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2742 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_FindPrimeape_2:
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_FindPrimeape_1


EscapeRoom_EventScript_MapSwitch1::
# 2749 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2752 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 2760 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 2766 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 2774 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 2789 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 2753 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2754 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2755 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 2761 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 2764 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 2767 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 2775 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 2777 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2778 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 2786 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2796 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 2804 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 2810 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 2813 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 2832 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2799 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 2805 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 2811 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 2819 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2822 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 2836 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 2847 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 2850 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 2853 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 2856 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 2861 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 2840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 2848 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 2851 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 2854 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 2857 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 2862 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2863 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 2879 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 2890 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 2895 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 2898 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 2923 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 2883 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2884 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 2902 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 2905 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 2910 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2911 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 2912 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2916 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 2921 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 2917 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 2928 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 2934 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 2930 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 2931 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 2939 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2940 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 2941 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2944 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2945 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2948 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 2949 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2950 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 2951 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 2958 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2961 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 2964 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 2992 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 2965 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2999 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3002 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 3006 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 3016 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 3022 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3023 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3026 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 3009 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 3010 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3012 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 3008 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 3007 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 3030 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3031 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3032 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3035 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 3038 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 3039 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 3040 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 3047 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3048 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3049 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3043 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3057 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3060 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 3064 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 3071 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 3072 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 3079 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 3082 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3083 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3085 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 3066 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 3067 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3069 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 3074 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3075 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3076 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 3089 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3090 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3091 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3094 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 3097 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 3098 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 3099 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 3106 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3107 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3108 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 3101 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 3114 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3116 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 3122 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 3123 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 3124 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 3131 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3132 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3133 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3135 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 3126 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3127 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 3139 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3140 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3141 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3144 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 3147 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 3148 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 3149 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 3156 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3160 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 3151 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 3164 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3165 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3166 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 3173 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 3192 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 3196 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 3177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 3178 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 3183 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3186 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3187 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3188 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 3200 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3202 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 3209 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 3227 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3228 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3230 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 3212 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3214 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3220 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3221 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3236 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 3242 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 3243 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 3244 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 3251 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3252 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3253 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3255 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 3246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3247 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 3259 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3260 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3261 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 3268 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 3269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 3276 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3277 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3278 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3272 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 3284 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3285 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 3287 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 3288 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3289 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3290 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3291 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3292 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3293 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3294 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3296 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 3297 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 3298 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3299 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 3303 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3306 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 3332 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 3335 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 3308 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 3325 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 3326 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 3312 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3313 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3314 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 3319 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 3320 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3341 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3342 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3343 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 3344 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3345 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3346 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 3349 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3350 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 3351 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3352 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 3353 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_SWEET_SCENT
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3355 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3356 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 3359 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 3363 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3364 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 3365 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 3367 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


SomethingsGoneWrongMessage::
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 3385 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1::
# 3390 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 3394 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 3399 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 3404 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MoveDeleterSignMessage::
# 3411 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 3427 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 3446 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 3451 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 3459 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 3468 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 3476 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 3486 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Something happened to\n"
	.string "{STR_VAR_1}'s moves.$"

RotatedSwitchSoundMessage::
# 3494 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 3498 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 3502 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 3507 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 3513 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 3519 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 3525 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 3532 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 3538 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 3550 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 3569 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 3575 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 3582 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 3588 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 3594 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 3608 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 3612 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 3616 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 3622 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 3631 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 3635 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 3642 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.\p"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 3658 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 3663 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 3667 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockNoItemToUndo::
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockNoActionsToUndo::
# 3676 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoEtherPurchase::
# 3681 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your Ether\n"
	.string "purchase?$"

MoneyReceived500::
# 3686 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥500!$"

AntiSoftlockEtherPurchaseUndone::
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Ether purchase has been undone.$"

AntiSoftlockAskUndoTrainer5::
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 3701 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love seeing rare Pokémon up close!\p"
	.string "If you ever manage to catch something\n"
	.string "special, be sure to show me.$"

ZeraoraHintMessage2::
# 3723 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 3728 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to catch a Zeraora!?\p"
	.string "Unbelievable... I've always dreamed of\n"
	.string "seeing one up close!\p"
	.string "This means a lot to me.\n"
	.string "Please, take this.$"

ZeraoraHintPostCatchMessage2::
# 3736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 3740 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 3755 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.\p"
	.string "She'll always be back.$"

FourTabletsHintMessage1::
# 3765 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 3771 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to go through the menus.$"

FourTabletsHintMessage3::
# 3780 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake!?$"

DusknoirStoleMyMailMsg::
# 3787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A Dusknoir stole my mail!\p"
	.string "To be honest, I don't really mind.\n"
	.string "It's just a bit strange.$"

StonesBuyNPCInitialMessage_no_item::
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 3804 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥1500?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 3810 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "Would you sell it to me for ¥1500?$"

StonesBuyNPCInitialMessage_has_DuskStone::
# 3816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Dusk Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 3824 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 3828 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 3832 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 3836 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived1500::
# 3840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥1500!$"

LiepardObtainMessage::
# 3847 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 3851 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 3855 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 3866 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 3870 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretGardenNPC_AskLovePlants::
# 3877 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love plants!\p"
	.string "Do you love plants?$"

SecretGardenNPC_PlantLove_No::
# 3882 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Aw, that's too bad.$"

SecretGardenNPC_PlantLove_Yes::
# 3886 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Of course you do!\p"
	.string "Let me teach your cactus how to use\n"
	.string "the power of its surroundings.\p"
	.string "It's a gift from the secret garden.$"

SecretGardenNPC_PlantLove_Yes_Thief::
# 3895 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh... your Pokémon knows Thief.\p"
	.string "The garden usually doesn't share its\n"
	.string "secrets with those who steal.\p"
	.string "I could make an exception, but Thief\n"
	.string "will be forgotten.\p"
	.string "Is that alright?$"

SecretGardenNPC_TeachDeclinedMessage::
# 3908 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's up to you.$"

SecretGardenNPC_PostTeachMessage::
# 3912 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't tell anyone I shared this move\n"
	.string "with you!$"

SecretGardenNPC_EndOfScriptMessage::
# 3917 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's our little secret.$"

MonLearnedSecretPower::
# 3921 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} learned Secret Power!$"

SecretGardenGuardKeepOut::
# 3926 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found our secret garden!\p"
	.string "I cannot let you enter, sorry.$"

SecretGardenGuardSpotted::
# 3931 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "How did you get in there!?$"

SecretGardenGuardStayOut::
# 3935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Stay out of our garden!$"

SecretGardenGuardRemoveSecretPower::
# 3939 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I cannot let you leave with that what\n"
	.string "belongs to the garden.\p"
	.string "I will have to take Secret Power away\n"
	.string "from your Pokémon.$"

MonForgotSecretPower::
# 3946 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MonThiefRestored::
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Thief was restored.$"

MartNPC_AskToShop::
# 3956 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 3962 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

PrimeapePokeballMessage::
# 3968 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a Primeape inside the Poke Ball.\p"
	.string "Do you want to take it?$"

PrimeapeObtainMessage::
# 3973 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 3977 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

EtherNPCbuyEther::
# 3985 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi there! Would you like to buy an Ether\n"
	.string "for the great price of ¥500?$"

EtherNPCnotEnoughMoney::
# 3990 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh, it looks like you don't have enough\n"
	.string "money.$"

EtherNPCsellAcceptedMessage::
# 3995 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go!$"

EtherNPCsellDeclined::
# 3999 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "No worries, perhaps next time.$"

EtherNPCpostSellMessage::
# 4003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't waste it all at once!$"

AskDeleteMove::
# 4009 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 4015 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 4021 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 4025 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 4029 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 4035 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 4039 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

AskResetPredamageMessage::
# 4045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 4050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 4056 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 4062 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 4067 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 4071 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 4075 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 4079 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 4083 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 4088 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 4093 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 4098 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 4104 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 4108 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 4112 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 4116 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 4120 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 4125 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 4129 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 4134 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 4140 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 4146 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 4150 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 4156 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer1_Intro::
# 4163 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\p"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 4169 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 4173 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 4178 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 4185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 4191 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 4196 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer2_PostBattle::
# 4200 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Call me a maniac, but I love writing\n"
	.string "things in 68 65 78.$"

Trainer3_Intro::
# 4207 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 4212 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 4216 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 4221 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 4227 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 4231 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 4235 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know that 5A + 2L = 525?$"

Trainer5_Intro::
# 4241 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 4246 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 4250 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They always find their way back.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tables have turned.$"

Trainer6_PostBattle::
# 4272 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you know where I can find a cook?\n"
	.string "My birds deliver letters, not lunch.$"

Trainer7A_Intro::
# 4279 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 4286 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 4290 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "fwuenqru? uwu.$"

Trainer7B_Intro::
# 4297 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 4302 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 4306 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 4313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Everyone's got ghost-type mons,\n"
	.string "but you haven't yet fought mine.$"

Trainer8_Outro::
# 4320 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 4324 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you been to the secret garden?\p"
	.string "There's an easy way in, but is there an\n"
	.string "easy way out as well?$"

Trainer9_Intro::
# 4332 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 4337 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks. Only real battles.$"

Trainer9_PostBattle::
# 4341 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Somehow I doubt this was your last time\n"
	.string "passing through.$"

Trainer10_Intro::
# 4348 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've decided to let my anger run free\n"
	.string "and have it push me toward change.\p"
	.string "I call it character development, but\n"
	.string "perhaps it's not for everyone.$"

Trainer10_Outro::
# 4355 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Whatever happened to Cacturne?$"

Trainer10_PostBattle::
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't stop now.\n"
	.string "You're almost there!$"

Trainer11_Intro::
# 4366 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_Outro::
# 4370 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_PostBattle::
# 4374 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"
