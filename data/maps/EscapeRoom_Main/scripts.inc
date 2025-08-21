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
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_12
EscapeRoom_MapScripts_AskResetPredamage_1:
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 307 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_9
# 321 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 322 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
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
	call EscapeRoom_EventScript_SetRespawn1
# 316 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_12:
# 331 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 332 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_14
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_14:
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 359 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 367 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 368 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScript_GameStartScripts::
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 381 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 383 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 395 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 396 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SLEEP_TALK, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_EXP_CANDY_S, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 466 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 467 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 472 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawn1
	return


EscapeRoom_MapScripts_GetItems::
# 477 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_HM01
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_MOON_STONE
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 492 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_SetRespawn1::
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 1
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 0
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	return


EscapeRoom_EventScript_SetRespawn2::
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_SetRespawn2_1
	return

EscapeRoom_EventScript_SetRespawn2_1:
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawn3::
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 524 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 0
# 525 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 1
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_MainInfoSign::
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 562 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 571 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 572 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 577 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 578 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 590 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 591 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 595 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 596 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 608 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 609 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 622 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 628 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 669 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 701 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 727 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 747 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_30
EscapeRoom_EventScript_ReturnLostItems_29:
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_35
EscapeRoom_EventScript_ReturnLostItems_34:
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_42
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_42
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 857 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmonmove0pp SPECIES_FLORGES, MOVE_CAMOUFLAGE
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_13
# 711 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_13:
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_17:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_25
EscapeRoom_EventScript_ReturnLostItems_23:
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 737 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_32
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 749 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_22:
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_24:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_22
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_25:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_24
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_30:
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_29

EscapeRoom_EventScript_ReturnLostItems_32:
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_35:
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 766 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_38:
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_48
EscapeRoom_EventScript_ReturnLostItems_47:
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_60
EscapeRoom_EventScript_ReturnLostItems_59:
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_69
EscapeRoom_EventScript_ReturnLostItems_68:
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_42:
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_53:
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_51
	return

EscapeRoom_EventScript_ReturnLostItems_48:
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 777 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_47

EscapeRoom_EventScript_ReturnLostItems_50:
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_62
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_63
	return

EscapeRoom_EventScript_ReturnLostItems_51:
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_66
	return

EscapeRoom_EventScript_ReturnLostItems_54:
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_50
	goto EscapeRoom_EventScript_ReturnLostItems_53

EscapeRoom_EventScript_ReturnLostItems_55:
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_54
	goto EscapeRoom_EventScript_ReturnLostItems_53

EscapeRoom_EventScript_ReturnLostItems_60:
# 783 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 785 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_59

EscapeRoom_EventScript_ReturnLostItems_62:
# 816 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_ReturnLostItems_63:
# 825 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_71
	return

EscapeRoom_EventScript_ReturnLostItems_66:
# 843 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	return

EscapeRoom_EventScript_ReturnLostItems_69:
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_68

EscapeRoom_EventScript_ReturnLostItems_71:
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 829 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_73:
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 864 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 868 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_WarpToSection2::
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawn2
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 23, 11
# 875 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_UndoUsedItems::
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 895 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 902 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 909 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FERROTHORN, MOVE_CUT
# 910 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 916 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 921 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_CUT
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_26
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_26
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 944 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_33
EscapeRoom_EventScript_UndoUsedItems_32:
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 954 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 955 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_35
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 885 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 887 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 891 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 892 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 903 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_CACNEA
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FERROTHORN
# 913 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 917 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_CACNEA
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_33:
# 945 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_32

EscapeRoom_EventScript_UndoUsedItems_35:
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_20:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_19
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_18:
# 1001 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 1017 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_39:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_43
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_42:
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 1061 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 990 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 1018 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 1023 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_19:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_18

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_20

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
# 1045 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_39

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_43:
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_42

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 1049 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 1066 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 1069 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_UndoMoveTeach::
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 1095 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_4
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1086 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_4:
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_7
EscapeRoom_EventScript_UndoMoveTeach_6:
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 1106 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 1107 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_10
# 1117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_9:
# 1122 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1123 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1124 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_15
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_15
EscapeRoom_EventScript_UndoMoveTeach_14:
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_20
EscapeRoom_EventScript_UndoMoveTeach_19:
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_30
EscapeRoom_EventScript_UndoMoveTeach_29:
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
	return

EscapeRoom_EventScript_UndoMoveTeach_7:
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_6

EscapeRoom_EventScript_UndoMoveTeach_10:
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_9

EscapeRoom_EventScript_UndoMoveTeach_11:
# 1118 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_9

EscapeRoom_EventScript_UndoMoveTeach_15:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_25
EscapeRoom_EventScript_UndoMoveTeach_23:
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_UndoMoveTeach_14

EscapeRoom_EventScript_UndoMoveTeach_20:
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
EscapeRoom_EventScript_UndoMoveTeach_32:
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 1166 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 1167 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_59
EscapeRoom_EventScript_UndoMoveTeach_58:
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_64
	goto EscapeRoom_EventScript_UndoMoveTeach_19

EscapeRoom_EventScript_UndoMoveTeach_22:
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1140 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_14

EscapeRoom_EventScript_UndoMoveTeach_24:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_22
	goto EscapeRoom_EventScript_UndoMoveTeach_23

EscapeRoom_EventScript_UndoMoveTeach_25:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_24
	goto EscapeRoom_EventScript_UndoMoveTeach_23

EscapeRoom_EventScript_UndoMoveTeach_30:
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_45
EscapeRoom_EventScript_UndoMoveTeach_43:
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_55
EscapeRoom_EventScript_UndoMoveTeach_53:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_66
	goto EscapeRoom_EventScript_UndoMoveTeach_29

EscapeRoom_EventScript_UndoMoveTeach_33:
# 1155 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_37:
# 1218 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_38:
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_37
	return

EscapeRoom_EventScript_UndoMoveTeach_39:
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_38
	return

EscapeRoom_EventScript_UndoMoveTeach_44:
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_43

EscapeRoom_EventScript_UndoMoveTeach_45:
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_44
	goto EscapeRoom_EventScript_UndoMoveTeach_43

EscapeRoom_EventScript_UndoMoveTeach_49:
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_55:
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_59:
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_58

EscapeRoom_EventScript_UndoMoveTeach_62:
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_64:
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_19

EscapeRoom_EventScript_UndoMoveTeach_66:
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_29


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 1233 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 1234 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_CACNEA
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_35
EscapeRoom_EventScript_UndoRareCandy_34:
# 1327 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_42
EscapeRoom_EventScript_UndoRareCandy_41:
# 1337 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_29
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_30
EscapeRoom_EventScript_UndoRareCandy_27:
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_39
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_29:
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_30:
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_35:
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1321 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_CACNEA
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_CACTURNE, SPECIES_CACNEA
	goto EscapeRoom_EventScript_UndoRareCandy_34

EscapeRoom_EventScript_UndoRareCandy_37:
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_39:
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_52
	return

EscapeRoom_EventScript_UndoRareCandy_42:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1331 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_41

EscapeRoom_EventScript_UndoRareCandy_44:
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_49
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_56
	return

EscapeRoom_EventScript_UndoRareCandy_46:
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_44
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_49:
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_54
	return

EscapeRoom_EventScript_UndoRareCandy_52:
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_54:
# 1370 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_56:
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return


EscapeRoom_EventScript_UndoExpCandy::
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 1419 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 1449 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 1449 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1479 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 1483 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 1513 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return


EscapeRoom_EventScript_UndoFlorgesTrade::
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 1527 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1533 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return


EscapeRoom_EventScript_LiepardNPC::
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1561 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 1566 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1567 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1568 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1571 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 1600 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 1614 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1615 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1621 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 1646 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1683 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1687 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 1722 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1723 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	return


# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 1753 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 1788 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 1799 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 1815 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 1822 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 1825 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 1831 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 1834 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1837 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1852 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 1881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_OBTAINED, EscapeRoom_ZeraoraHintNPC_8
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage3, MSGBOX_NPC
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1907 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_8:
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage2, MSGBOX_NPC
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1951 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1956 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 1961 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1972 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1974 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1975 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 1976 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 1983 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1991 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 2004 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 2018 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2019 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2021 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 2030 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 2057 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 2034 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 2048 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2062 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 2064 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 2065 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 2067 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 2069 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 2074 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2084 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2096 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 2088 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 2092 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_SecretGarden_SecretPowerNPC::
# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_SecretGarden_SecretPowerNPC_2
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_SecretPowerNPC_2
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_AskLovePlants, MSGBOX_YESNO
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_7
# 2123 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_THIEF
# 2124 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_10
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes, MSGBOX_DEFAULT
# 2138 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes_Thief, MSGBOX_YESNO
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_13
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_TeachDeclinedMessage, MSGBOX_AUTOCLOSE
# 2152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_SecretGarden_SecretPowerNPC_6:
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_SecretPowerNPC_2:
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_EndOfScriptMessage, MSGBOX_AUTOCLOSE
# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_SecretGarden_SecretPowerNPC_7:
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_No, MSGBOX_DEFAULT
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_6

EscapeRoom_SecretGarden_SecretPowerNPC_10:
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes, MSGBOX_DEFAULT
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2130 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_SecretGarden_TeachSecretPower
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PostTeachMessage, MSGBOX_AUTOCLOSE
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_6

EscapeRoom_SecretGarden_SecretPowerNPC_13:
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_SecretGarden_TeachSecretPower
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PostTeachMessage, MSGBOX_AUTOCLOSE
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_6


EscapeRoom_SecretGarden_TeachSecretPower::
# 2161 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_THIEF
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_2
EscapeRoom_SecretGarden_TeachSecretPower_1:
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACNEA
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_5
EscapeRoom_SecretGarden_TeachSecretPower_4:
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_13
EscapeRoom_SecretGarden_TeachSecretPower_12:
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonLearnedSecretPower, MSGBOX_DEFAULT
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_LEARNED
	return

EscapeRoom_SecretGarden_TeachSecretPower_2:
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_SecretGarden_TeachSecretPower_8
# 2166 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_SecretGarden_TeachSecretPower_9
EscapeRoom_SecretGarden_TeachSecretPower_7:
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_THIEF_REPLACED
	goto EscapeRoom_SecretGarden_TeachSecretPower_1

EscapeRoom_SecretGarden_TeachSecretPower_5:
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACNEA, MOVE_SECRET_POWER
	goto EscapeRoom_SecretGarden_TeachSecretPower_4

EscapeRoom_SecretGarden_TeachSecretPower_8:
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 0, MOVE_THIEF, MOVE_NONE
	goto EscapeRoom_SecretGarden_TeachSecretPower_7

EscapeRoom_SecretGarden_TeachSecretPower_9:
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 1, MOVE_THIEF, MOVE_NONE
	goto EscapeRoom_SecretGarden_TeachSecretPower_7

EscapeRoom_SecretGarden_TeachSecretPower_13:
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACTURNE, MOVE_SECRET_POWER
	goto EscapeRoom_SecretGarden_TeachSecretPower_12


EscapeRoom_SecretGarden_GateEntryNPC_KeepOut::
# 2197 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2200 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_left
# 2204 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 25
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardKeepOut, MSGBOX_AUTOCLOSE
# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_SecretGarden_GateEntryNPC_KickOut::
# 2219 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_down
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_down
# 2230 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardSpotted, MSGBOX_AUTOCLOSE
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_up
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveUp
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2242 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_LEARNED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1:
# 2300 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2303 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2:
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardStayOut, MSGBOX_AUTOCLOSE
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3:
# 2250 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardRemoveSecretPower, MSGBOX_AUTOCLOSE
# 2251 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2252 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SECRET_POWER
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8:
# 2262 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_LEARNED
# 2266 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 2267 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_THIEF_REPLACED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13:
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACNEA
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_GateEntryNPC_KickOut_17
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_16:
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_GateEntryNPC_KickOut_20
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19:
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_DEFAULT
# 2288 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2289 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9:
# 2257 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 0, MOVE_SECRET_POWER, MOVE_NONE
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 1, MOVE_SECRET_POWER, MOVE_NONE
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14:
# 2268 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACNEA, MOVE_THIEF
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACTURNE, MOVE_THIEF
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_THIEF_REPLACED
# 2271 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_17:
# 2277 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_16

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_20:
# 2281 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22:
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonThiefRestored, MSGBOX_AUTOCLOSE
# 2294 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2295 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1


# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_down:
# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2308 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_up:
# 2311 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2312 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2312 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveUp:
# 2316 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2320 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveLeft:
# 2321 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
# 2322 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_AnnihilapeHintNPC::
# 2329 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2332 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 2344 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2335 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2336 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2337 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 2338 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2339 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 2340 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 2351 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2352 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 2355 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 2359 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 2356 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 2378 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 2382 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 2383 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 2394 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 2395 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2401 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 2420 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 2428 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 2429 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 2430 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 2429 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 2438 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2439 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2440 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2442 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 2480 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 2492 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 2498 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 2505 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer8_PostBattle, MSGBOX_AUTOCLOSE
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer9::
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 2518 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 2519 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 2531 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 2532 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 2537 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle, MSGBOX_AUTOCLOSE
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2563 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 2571 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 2580 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2581 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2582 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2583 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 2585 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 2586 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 2587 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 2564 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2593 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2567 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 2608 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2611 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2612 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 2620 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 2621 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2624 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 2631 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 2632 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 2635 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2615 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2639 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 2616 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 2647 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2650 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 2653 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2654 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 2657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 2664 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 2666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 2670 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 2673 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2683 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 2685 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 2686 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 2687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 2693 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 2655 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 2689 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2691 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 2699 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2699 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2700 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 2704 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 2705 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2710 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2711 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 2714 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 2722 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2719 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2720 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 2730 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2733 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 2745 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 2757 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2747 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2751 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 2736 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 2758 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2759 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 2762 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 2748 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 2740 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2771 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 2774 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2775 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 2760 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 2752 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 2786 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2787 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 2764 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 2784 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 2788 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 2804 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 2805 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2806 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 2815 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 2824 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 2836 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2837 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2838 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 2844 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 2846 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 2847 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 2848 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 2851 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 2852 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2853 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 2854 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 2856 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 2857 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 2860 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 2861 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 2862 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 2863 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2866 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2867 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 2870 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 2871 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2872 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2874 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2876 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2877 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2878 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2879 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2880 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 2809 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2883 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2884 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 2819 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 2890 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 2898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2902 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 2908 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2911 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2912 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 2919 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 2920 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2927 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 2928 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_CUT
# 2930 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 2931 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 2932 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 2939 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_CACNEA, MOVE_CUT
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2950 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 2958 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2960 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2961 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 2962 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 2963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 2964 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 2965 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 2971 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 2967 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 2975 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 2976 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 2988 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2989 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2990 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2991 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 2992 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 42
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_CACNEA
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 2994 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 2995 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 2996 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 3000 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3001 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3002 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 3008 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 3009 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 3016 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 3045 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 3047 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 3022 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3023 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 3033 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 3036 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3038 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 3026 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3027 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3028 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3052 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 3080 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 3081 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 3138 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 3139 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 3142 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 3058 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 3074 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 3075 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 3060 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3061 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 3068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3069 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 3084 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 3085 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3086 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 3095 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 3098 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 3099 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3100 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3106 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3107 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 3111 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 3133 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 3062 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 3064 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3065 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 3088 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3089 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3090 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 3147 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3148 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3151 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 3176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 3177 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 3212 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 3215 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 3154 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 3170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 3171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 3155 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 3156 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 3164 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3165 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3182 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 3191 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 3195 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3196 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3200 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3202 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3205 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 3206 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 3160 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3161 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3185 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3186 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3220 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 3229 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 3230 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 3259 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 3260 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 3225 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 3233 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 3244 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 3245 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3246 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 3249 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3250 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3251 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3254 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 3255 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 3237 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3238 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindLiepardCollar::
# 3270 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 3272 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 3273 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 3274 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 3278 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3279 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 3281 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 3282 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPrimeape::
# 3286 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3296 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_RARE_CANDY, abilityNum = 2, nature = 15, gender = MON_FEMALE, move1 = MOVE_TAUNT, move2 = MOVE_RAGE_FIST, move3 = MOVE_COUNTER, move4 = MOVE_NONE, atkEv = 0, spAtkEv = 0, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 3323 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 3326 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 3329 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	message PrimeapeObtainMessage
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3332 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3335 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 3336 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_FindPrimeape_2
EscapeRoom_EventScript_FindPrimeape_1:
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3341 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_FindPrimeape_2:
# 3337 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3338 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_FindPrimeape_1


EscapeRoom_EventScript_MapSwitch1::
# 3348 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3351 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 3359 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 3362 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 3365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 3368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 3388 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 3352 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3353 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 3363 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 3369 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3375 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3377 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3380 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 3385 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 3392 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3395 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 3403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 3406 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 3409 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 3412 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 3417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 3431 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 3396 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3397 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3398 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 3404 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 3407 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 3413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 3418 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 3420 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3424 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 3429 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 3425 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 3435 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3438 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 3446 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 3452 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 3460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 3474 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 3439 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3440 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 3447 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 3450 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 3453 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 3456 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 3461 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3462 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 3463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3464 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3467 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 3472 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 3468 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 3478 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 3489 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 3494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 3497 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 3500 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 3508 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 3522 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3483 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3484 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 3490 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 3495 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 3498 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 3501 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 3504 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 3509 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3510 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 3511 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3512 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3515 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 3520 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 3516 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 3527 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 3532 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 3529 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 3528 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 3530 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 3538 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 3540 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 3541 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 3542 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3543 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 3545 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 3546 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3547 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 3548 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3549 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 3550 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3560 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 3568 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 3591 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 3592 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 3564 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 3596 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3597 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3598 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3601 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 3605 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 3615 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3616 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3622 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3625 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 3608 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 3609 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3611 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 3606 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 3629 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3630 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3631 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3634 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 3637 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 3638 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 3639 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 3646 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3647 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3648 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3650 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 3641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3642 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3656 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3659 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 3663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 3678 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 3681 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3682 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3684 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 3666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3668 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 3673 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3674 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3675 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 3688 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3689 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3693 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 3696 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 3697 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 3698 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3706 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3707 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3709 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3701 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 3713 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3715 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3718 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 3721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 3722 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 3723 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 3730 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3731 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3732 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3734 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 3725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3726 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 3738 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3740 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 3746 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 3748 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 3755 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3756 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3757 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3759 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 3763 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3764 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3765 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3768 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 3772 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 3779 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 3780 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 3791 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3792 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3793 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 3776 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 3777 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3783 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3785 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3786 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3787 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 3799 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3800 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3804 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 3808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 3815 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 3816 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 3823 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 3826 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3827 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3829 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 3810 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 3811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3813 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3819 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3820 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3834 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3835 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3838 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 3841 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 3842 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 3850 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3851 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3852 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3854 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 3845 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3846 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 3858 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3860 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3863 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 3866 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 3867 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 3868 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3876 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3877 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3879 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 3870 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3871 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 3883 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3884 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 3886 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 3887 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3888 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3889 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3890 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3891 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3892 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3893 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3895 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 3896 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 3897 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3898 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 3902 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3905 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 3930 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 3931 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 3934 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 3907 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 3908 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 3924 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 3925 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 3911 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3912 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3913 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3916 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 3917 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 3908 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 3918 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 3919 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 3939 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3940 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3941 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3942 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 3943 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3944 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3945 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 3948 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3949 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 3952 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_SWEET_SCENT
# 3953 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3954 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3955 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3956 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3957 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 3958 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3959 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 3962 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3963 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 3964 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 3965 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 3966 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


SomethingsGoneWrongMessage::
# 3973 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 3980 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 3984 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1::
# 3989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 3993 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 3998 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 4003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MoveDeleterSignMessage::
# 4010 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 4026 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 4032 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 4036 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 4040 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 4045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 4050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 4054 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 4058 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 4067 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 4075 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 4080 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 4085 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Something happened to\n"
	.string "{STR_VAR_1}'s moves.$"

RotatedSwitchSoundMessage::
# 4093 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 4097 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 4106 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 4112 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 4118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 4124 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 4131 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 4137 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 4143 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 4149 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 4156 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 4162 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 4168 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 4174 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 4181 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 4187 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 4193 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 4199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 4207 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 4211 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 4215 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 4221 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 4230 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 4241 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 4251 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 4255 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 4266 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 4270 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockNoItemToUndo::
# 4276 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 4281 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoCut::
# 4288 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 4291 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 4297 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 4301 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 4306 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moveset was restored.$"

AskUndoRareCandyDynamic::
# 4310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "use on {STR_VAR_1}?$"

RareCandyUndoneMessage::
# 4315 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 4319 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 4324 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 4329 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 4333 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 4337 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 4342 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 4348 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 4353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 4360 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 4364 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 4369 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 4376 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love seeing rare Pokémon up close!\p"
	.string "If you ever manage to catch something\n"
	.string "special, be sure to show me.$"

ZeraoraHintMessage2::
# 4382 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 4387 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to catch a Zeraora!?\p"
	.string "Unbelievable... I've always dreamed of\n"
	.string "seeing one up close!\p"
	.string "This means a lot to me.\n"
	.string "Please, take this.$"

ZeraoraHintPostCatchMessage2::
# 4395 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 4399 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 4406 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 4410 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.\p"
	.string "She'll always be back.$"

FourTabletsHintMessage1::
# 4424 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 4430 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to go through the menus.$"

FourTabletsHintMessage3::
# 4439 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake!?$"

StonesBuyNPCInitialMessage_no_item::
# 4446 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 4454 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 4460 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 4468 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 4472 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 4476 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 4480 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 4484 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 4491 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 4495 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 4499 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 4503 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 4510 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 4514 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretGardenNPC_AskLovePlants::
# 4521 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love plants!\p"
	.string "Do you love plants?$"

SecretGardenNPC_PlantLove_No::
# 4526 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Aw, that's too bad.$"

SecretGardenNPC_PlantLove_Yes::
# 4530 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Of course you do!\p"
	.string "Let me teach your cactus how to use\n"
	.string "the power of its surroundings.\p"
	.string "It's a gift from the secret garden.$"

SecretGardenNPC_PlantLove_Yes_Thief::
# 4539 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh... your Pokémon knows Thief.\p"
	.string "The garden usually doesn't share its\n"
	.string "secrets with those who steal.\p"
	.string "I could make an exception, but Thief\n"
	.string "will be forgotten.\p"
	.string "Is that alright?$"

SecretGardenNPC_TeachDeclinedMessage::
# 4552 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's up to you.$"

SecretGardenNPC_PostTeachMessage::
# 4556 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't tell anyone I taught you this\n"
	.string "move!$"

SecretGardenNPC_EndOfScriptMessage::
# 4561 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's our little secret.$"

MonLearnedSecretPower::
# 4565 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} learned Secret Power!$"

SecretGardenGuardKeepOut::
# 4570 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found our secret garden!\p"
	.string "I cannot let you enter, sorry.$"

SecretGardenGuardSpotted::
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "How did you get in there!?$"

SecretGardenGuardStayOut::
# 4579 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Stay out of our garden!$"

SecretGardenGuardRemoveSecretPower::
# 4583 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I cannot let you leave with that what\n"
	.string "belongs to the garden.\p"
	.string "I will have to take Secret Power away\n"
	.string "from your Pokémon.$"

MonForgotSecretPower::
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MonThiefRestored::
# 4594 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Thief was restored.$"

MartNPC_AskToShop::
# 4600 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 4606 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

PrimeapePokeballMessage::
# 4612 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a Primeape inside the Poke Ball.\p"
	.string "Do you want to take it?$"

PrimeapeObtainMessage::
# 4617 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 4621 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

AskDeleteMove::
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 4634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 4640 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 4644 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 4648 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 4654 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 4658 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

AskResetPredamageMessage::
# 4664 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 4669 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 4675 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 4681 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 4686 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 4690 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 4694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 4698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 4702 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 4707 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 4712 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 4717 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 4723 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 4727 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 4731 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 4735 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 4739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 4744 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 4748 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 4753 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 4759 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 4765 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 4769 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 4775 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer1_Intro::
# 4782 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\p"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 4788 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 4792 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 4797 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 4804 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 4810 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 4815 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Call me a maniac, but I love writing in\n"
	.string "68 65 78.$"

Trainer2_PostBattle::
# 4820 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 4826 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 4831 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 4835 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 4840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 4846 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 4850 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 4854 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know that 5A + 2L = 525?$"

Trainer5_Intro::
# 4860 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 4865 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 4869 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 4873 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 4880 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They always find their way back.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 4887 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tables have turned.$"

Trainer6_PostBattle::
# 4891 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you know where I can find a cook?\n"
	.string "My birds deliver letters, not lunch.$"

Trainer7A_Intro::
# 4898 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 4905 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 4909 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "fwuenqru? uwu.$"

Trainer7B_Intro::
# 4916 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 4921 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 4925 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 4932 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Everyone's got ghost-type mons,\n"
	.string "but you haven't yet fought mine.$"

Trainer8_Outro::
# 4939 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 4943 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you been to the secret garden?\p"
	.string "There's an easy way in, but what's the\n"
	.string "easy way out?$"

Trainer9_Intro::
# 4951 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 4956 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks. Only real battles.$"

Trainer9_PostBattle::
# 4960 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Somehow I doubt this was your last time\n"
	.string "passing through.$"

Trainer10_Intro::
# 4967 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've decided to let my anger run free\n"
	.string "and have it push me toward change.\p"
	.string "I call it character development, but\n"
	.string "perhaps it's not for everyone.$"

Trainer10_Outro::
# 4974 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Whatever happened to Cacturne?$"

Trainer10_PostBattle::
# 4978 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't stop now.\n"
	.string "You're almost there!$"

Trainer11_Intro::
# 4985 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_Outro::
# 4989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_PostBattle::
# 4993 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"
