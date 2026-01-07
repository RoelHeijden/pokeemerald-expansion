# 50 "data/maps/EscapeRoom_Main/scripts.pory"
_face_down:
# 51 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 53 "data/maps/EscapeRoom_Main/scripts.pory"
_face_up:
# 54 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 56 "data/maps/EscapeRoom_Main/scripts.pory"
_face_right:
# 57 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 59 "data/maps/EscapeRoom_Main/scripts.pory"
_face_left:
# 60 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_Main_MapScripts::
# 67 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 68 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 70 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 75 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 76 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_STICKY_BARB_RETURN, 1, EscapeRoom_MapScripts_ReturnStickyBarb
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 80 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 81 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 82 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_JUST_ESCAPED_ICE_PUZZLE, 1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROPE_EE_STATE, 1, EscapeRoom_EventScript_EscapeRopeEE_message1
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 92 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 97 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 93 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 99 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 115 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 121 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfSecretPowerObtained
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_MapScript_OnResumeScripts_13
EscapeRoom_MapScript_OnResumeScripts_12:
# 129 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_MapScript_OnResumeScripts_16
EscapeRoom_MapScript_OnResumeScripts_15:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_20
EscapeRoom_MapScript_OnResumeScripts_18:
# 139 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_24
EscapeRoom_MapScript_OnResumeScripts_23:
# 145 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_27
EscapeRoom_MapScript_OnResumeScripts_26:
# 150 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_30
EscapeRoom_MapScript_OnResumeScripts_29:
# 156 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 160 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 163 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_32
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 111 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 125 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckZeraPredamageStep
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_16:
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckRareCandyReviveStep
	goto EscapeRoom_MapScript_OnResumeScripts_15

EscapeRoom_MapScript_OnResumeScripts_19:
# 135 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_20:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_19
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_24:
# 140 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_23

EscapeRoom_MapScript_OnResumeScripts_27:
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStickyBarbStolen
	goto EscapeRoom_MapScript_OnResumeScripts_26

EscapeRoom_MapScript_OnResumeScripts_30:
# 151 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_29

EscapeRoom_MapScript_OnResumeScripts_32:
# 164 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 183 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 186 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 189 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 200 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 202 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 204 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 205 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 208 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 215 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 225 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 228 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 229 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 230 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 238 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckStickyBarbStolen::
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 244 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_2
EscapeRoom_MapScripts_CheckStickyBarbStolen_1:
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_5
EscapeRoom_MapScripts_CheckStickyBarbStolen_4:
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_8
EscapeRoom_MapScripts_CheckStickyBarbStolen_7:
# 255 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_10
	return

EscapeRoom_MapScripts_CheckStickyBarbStolen_2:
# 245 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_1

EscapeRoom_MapScripts_CheckStickyBarbStolen_5:
# 249 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_4

EscapeRoom_MapScripts_CheckStickyBarbStolen_8:
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_7

EscapeRoom_MapScripts_CheckStickyBarbStolen_10:
# 257 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 263 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 264 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 265 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_8
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_11
EscapeRoom_MapScripts_CheckIfAskPreDamage_10:
# 279 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 266 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 274 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_10


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 288 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 289 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 289 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 294 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 299 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 319 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 320 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 305 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 315 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 321 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 320 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_CheckIfAskWarpBack::
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskWarpBack_3
EscapeRoom_MapScripts_CheckIfAskWarpBack_1:
# 334 "data/maps/EscapeRoom_Main/scripts.pory"
Equal:
	return

EscapeRoom_MapScripts_CheckIfAskWarpBack_2:
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_LOCATED_AT_SECTION_X, VAR_RESPAWN_AT_SECTION_X
# 331 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_eq Equal
# 332 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 1
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1

EscapeRoom_MapScripts_CheckIfAskWarpBack_3:
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_MapScripts_CheckIfAskWarpBack_2
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1


EscapeRoom_MapScripts_CheckIfSecretPowerObtained::
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_4
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1:
# 371 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FIELD_POISON_WHITEOUT
	return

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2:
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 358 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_8:
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_THIEF
# 367 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_3:
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FIELD_POISON_WHITEOUT, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_4:
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_3
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9:
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_8


EscapeRoom_MapScripts_CheckZeraPredamageStep::
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FERROTHORN
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 19
	goto_if_le EscapeRoom_MapScripts_CheckZeraPredamageStep_3
EscapeRoom_MapScripts_CheckZeraPredamageStep_1:
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLAG_ZERA_PREDAMAGE_SUCCES, EscapeRoom_MapScripts_CheckZeraPredamageStep_8
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_2:
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLAG_ZERA_PREDAMAGE_SUCCES
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FERROTHORN
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_0x8004
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FLORGES
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_ne EscapeRoom_MapScripts_CheckZeraPredamageStep_12
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_ne EscapeRoom_MapScripts_CheckZeraPredamageStep_12
	goto EscapeRoom_MapScripts_CheckZeraPredamageStep_1

EscapeRoom_MapScripts_CheckZeraPredamageStep_3:
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLAG_ZERA_PREDAMAGE_SUCCES, EscapeRoom_MapScripts_CheckZeraPredamageStep_2
	goto EscapeRoom_MapScripts_CheckZeraPredamageStep_1

EscapeRoom_MapScripts_CheckZeraPredamageStep_6:
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_PREDAMAGE_COMPLETED
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_7:
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POKE_BALL_OBTAINED, EscapeRoom_MapScripts_CheckZeraPredamageStep_6
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_8:
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLAG_ZERA_BLOCK_SUCCES, EscapeRoom_MapScripts_CheckZeraPredamageStep_7
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_12:
# 390 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_MapScripts_CheckZeraPredamageStep_1


EscapeRoom_MapScripts_CheckRareCandyReviveStep::
# 407 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 3
	goto_if_eq EscapeRoom_MapScripts_CheckRareCandyReviveStep_3
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_1:
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_REVIVE_COMPLETED
# 413 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_LIEPARD
	goto_if_ne EscapeRoom_MapScripts_CheckRareCandyReviveStep_7
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_2:
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY1_OBTAINED, EscapeRoom_MapScripts_CheckRareCandyReviveStep_1
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_3:
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_MapScripts_CheckRareCandyReviveStep_2
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_7:
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 431 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 432 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 443 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 492 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 532 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 564 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 571 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 572 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 577 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 578 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 584 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 585 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 590 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 591 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIcePuzzleItemReturns::
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_JUST_ESCAPED_ICE_PUZZLE, 0
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_3
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1:
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_8
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6:
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2:
# 603 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11:
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21:
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM43
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31:
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_38
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_AUTOCLOSE
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37:
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_3:
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_7:
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16:
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26:
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RARE_CANDY
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_35
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_34:
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_AUTOCLOSE
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_41:
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RARE_CANDY2_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_8:
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_7
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12:
# 608 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 609 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13:
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17:
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18:
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22:
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23:
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27:
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 654 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28:
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32:
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM43
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_35:
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_RARE_CANDY
# 659 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_34

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_38:
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_DEFAULT
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoSecretPowerTeach
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42:
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_DEFAULT
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy_IcePuzzle
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_41


EscapeRoom_MapScript_GameStartScripts::
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 700 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 760 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 766 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 771 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 777 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 783 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 788 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 825 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 837 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 852 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 856 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 877 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 895 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MainSignWhatToRead, MSGBOX_MAIN_SIGN
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_3
EscapeRoom_EventScript_MainInfoSign_1:
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 909 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_MainInfoSign_6
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_MainInfoSign_7
# 917 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetGameCompletion
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessage, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_3:
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_11
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_6:
# 910 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageInitial, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_7:
# 913 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageFinal, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_11:
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 928 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_GetGameCompletion::
# 936 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 0
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_GetGameCompletion_2
EscapeRoom_EventScript_GetGameCompletion_1:
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_GetGameCompletion_5
EscapeRoom_EventScript_GetGameCompletion_4:
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_8
EscapeRoom_EventScript_GetGameCompletion_7:
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_11
EscapeRoom_EventScript_GetGameCompletion_10:
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_14
EscapeRoom_EventScript_GetGameCompletion_13:
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_17
EscapeRoom_EventScript_GetGameCompletion_16:
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_20
EscapeRoom_EventScript_GetGameCompletion_19:
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_23
EscapeRoom_EventScript_GetGameCompletion_22:
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_GetGameCompletion_26
EscapeRoom_EventScript_GetGameCompletion_25:
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_29
EscapeRoom_EventScript_GetGameCompletion_28:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_GetGameCompletion_32
EscapeRoom_EventScript_GetGameCompletion_31:
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_GetGameCompletion_35
EscapeRoom_EventScript_GetGameCompletion_34:
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_38
EscapeRoom_EventScript_GetGameCompletion_37:
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_GetGameCompletion_41
EscapeRoom_EventScript_GetGameCompletion_40:
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_GetGameCompletion_44
EscapeRoom_EventScript_GetGameCompletion_43:
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_47
EscapeRoom_EventScript_GetGameCompletion_46:
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_GetGameCompletion_50
EscapeRoom_EventScript_GetGameCompletion_49:
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_53
EscapeRoom_EventScript_GetGameCompletion_52:
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_56
EscapeRoom_EventScript_GetGameCompletion_55:
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_59
EscapeRoom_EventScript_GetGameCompletion_58:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_GetGameCompletion_62
EscapeRoom_EventScript_GetGameCompletion_61:
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_65
EscapeRoom_EventScript_GetGameCompletion_64:
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_68
EscapeRoom_EventScript_GetGameCompletion_67:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_70
	return

EscapeRoom_EventScript_GetGameCompletion_2:
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 2
	goto EscapeRoom_EventScript_GetGameCompletion_1

EscapeRoom_EventScript_GetGameCompletion_5:
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 8
	goto EscapeRoom_EventScript_GetGameCompletion_4

EscapeRoom_EventScript_GetGameCompletion_8:
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 12
	goto EscapeRoom_EventScript_GetGameCompletion_7

EscapeRoom_EventScript_GetGameCompletion_11:
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 18
	goto EscapeRoom_EventScript_GetGameCompletion_10

EscapeRoom_EventScript_GetGameCompletion_14:
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 20
	goto EscapeRoom_EventScript_GetGameCompletion_13

EscapeRoom_EventScript_GetGameCompletion_17:
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 23
	goto EscapeRoom_EventScript_GetGameCompletion_16

EscapeRoom_EventScript_GetGameCompletion_20:
# 972 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 28
	goto EscapeRoom_EventScript_GetGameCompletion_19

EscapeRoom_EventScript_GetGameCompletion_23:
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 33
	goto EscapeRoom_EventScript_GetGameCompletion_22

EscapeRoom_EventScript_GetGameCompletion_26:
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 35
	goto EscapeRoom_EventScript_GetGameCompletion_25

EscapeRoom_EventScript_GetGameCompletion_29:
# 990 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 41
	goto EscapeRoom_EventScript_GetGameCompletion_28

EscapeRoom_EventScript_GetGameCompletion_32:
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 44
	goto EscapeRoom_EventScript_GetGameCompletion_31

EscapeRoom_EventScript_GetGameCompletion_35:
# 1000 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 46
	goto EscapeRoom_EventScript_GetGameCompletion_34

EscapeRoom_EventScript_GetGameCompletion_38:
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 49
	goto EscapeRoom_EventScript_GetGameCompletion_37

EscapeRoom_EventScript_GetGameCompletion_41:
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 55
	goto EscapeRoom_EventScript_GetGameCompletion_40

EscapeRoom_EventScript_GetGameCompletion_44:
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 57
	goto EscapeRoom_EventScript_GetGameCompletion_43

EscapeRoom_EventScript_GetGameCompletion_47:
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 63
	goto EscapeRoom_EventScript_GetGameCompletion_46

EscapeRoom_EventScript_GetGameCompletion_50:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 68
	goto EscapeRoom_EventScript_GetGameCompletion_49

EscapeRoom_EventScript_GetGameCompletion_53:
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 73
	goto EscapeRoom_EventScript_GetGameCompletion_52

EscapeRoom_EventScript_GetGameCompletion_56:
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 78
	goto EscapeRoom_EventScript_GetGameCompletion_55

EscapeRoom_EventScript_GetGameCompletion_59:
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 84
	goto EscapeRoom_EventScript_GetGameCompletion_58

EscapeRoom_EventScript_GetGameCompletion_62:
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 89
	goto EscapeRoom_EventScript_GetGameCompletion_61

EscapeRoom_EventScript_GetGameCompletion_65:
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 91
	goto EscapeRoom_EventScript_GetGameCompletion_64

EscapeRoom_EventScript_GetGameCompletion_68:
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 95
	goto EscapeRoom_EventScript_GetGameCompletion_67

EscapeRoom_EventScript_GetGameCompletion_70:
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 100
	return


EscapeRoom_EventScript_MoveDeleterSign::
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
EscapeRoom_EventScript_EndSign_1:
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_END_ESCAPE_ROOM_STATE, 2
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_Heal_Pokemon_Nurse1::
# 1110 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 1128 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 1129 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_2
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_5
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage_Finale, MSGBOX_HINTNPC
EscapeRoom_EventScript_HintsNPC_4:
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_9
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_10
# 1167 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_HintsNPC_11
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_8:
# 1173 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsFinalMessage, MSGBOX_AUTOCLOSE
# 1148 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1149 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HintsNPC_5:
# 1155 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_HINTNPC
	goto EscapeRoom_EventScript_HintsNPC_4

EscapeRoom_EventScript_HintsNPC_9:
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_SmallHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_10:
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_LargeHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_11:
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_Solution
	goto EscapeRoom_EventScript_HintsNPC_8


EscapeRoom_EventScript_HintsNPC_SmallHint::
# 1181 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_SmallHint_2
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_3
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_4
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_5
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_6
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_SmallHint_7
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_8
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_9
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_10
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_11
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_12
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_SmallHint_13
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_14
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_SmallHint_15
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_16
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_17
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_18
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_SmallHint_19
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_20
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_21
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_SmallHint_22
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_23
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_24
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_25
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_26
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_SmallHint_36
EscapeRoom_EventScript_HintsNPC_SmallHint_35:
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_28
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_29
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_30
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_31
EscapeRoom_EventScript_HintsNPC_SmallHint_1:
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_69
EscapeRoom_EventScript_HintsNPC_SmallHint_68:
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_66
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_SmallHint_64:
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_SmallHint_2:
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_SmallHint
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SMALL_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_3:
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_SmallHint
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_SMALL_HINT, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_4:
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_SmallHint
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_COMPLETED_SMALL_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_5:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_SmallHint
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERAORA_CAUGHT_SMALL_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_6:
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_SmallHint
# 1202 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SMALL_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_7:
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_SmallHint
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SMALL_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_8:
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_SmallHint
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SMALL_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_9:
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_SmallHint
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SMALL_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_10:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_SmallHint
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SMALL_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_11:
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_SmallHint
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SMALL_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_12:
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_SmallHint
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SMALL_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_13:
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_SmallHint
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SMALL_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_14:
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_SmallHint
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SMALL_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_15:
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_SmallHint
# 1251 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SMALL_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_16:
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_SmallHint
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SMALL_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_17:
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_SmallHint
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SMALL_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_18:
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_SmallHint
# 1266 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SMALL_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_19:
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_SmallHint
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SMALL_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_20:
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_SmallHint
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SMALL_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_21:
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_SmallHint
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SMALL_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_22:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_SmallHint
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SMALL_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_23:
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_SmallHint
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SMALL_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_24:
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_SmallHint
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SMALL_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_25:
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_SmallHint
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SMALL_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_26:
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_SmallHint
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SMALL_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_27:
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_SmallHint
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SMALL_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_28:
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_SmallHint
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SMALL_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_29:
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_SmallHint
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SMALL_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_30:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_SmallHint
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SMALL_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_31:
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_SmallHint
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SMALL_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_36:
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_27
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_35

EscapeRoom_EventScript_HintsNPC_SmallHint_65:
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_73
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
EscapeRoom_EventScript_HintsNPC_SmallHint_72:
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SMALL_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_64

EscapeRoom_EventScript_HintsNPC_SmallHint_66:
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_64

EscapeRoom_EventScript_HintsNPC_SmallHint_69:
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_65
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_68

EscapeRoom_EventScript_HintsNPC_SmallHint_73:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 15
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC15minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_72


EscapeRoom_EventScript_HintsNPC_LargeHint::
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_LargeHint_2
# 1381 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_3
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_4
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_5
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_6
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_LargeHint_7
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_8
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_9
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_10
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_11
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_12
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_LargeHint_13
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_14
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_LargeHint_15
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_16
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_17
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_18
# 1465 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_LargeHint_19
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_20
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_21
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_LargeHint_22
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_23
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_24
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_25
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_26
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_LargeHint_36
EscapeRoom_EventScript_HintsNPC_LargeHint_35:
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_28
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_29
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_30
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_31
EscapeRoom_EventScript_HintsNPC_LargeHint_1:
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_69
EscapeRoom_EventScript_HintsNPC_LargeHint_68:
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_66
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_LargeHint_64:
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_LargeHint_2:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_LargeHint
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_LARGE_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_3:
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_LargeHint
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_LARGE_HINT, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_4:
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_LargeHint
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_LARGE_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_5:
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_LargeHint
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_LARGE_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_6:
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_LargeHint
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_LARGE_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_7:
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_LargeHint
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_LARGE_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_8:
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_LargeHint
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_LARGE_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_9:
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_LargeHint
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_LARGE_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_10:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_LargeHint
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_LARGE_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_11:
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_LargeHint
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_LARGE_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_12:
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_LargeHint
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_LARGE_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_13:
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_LargeHint
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_LARGE_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_14:
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_LargeHint
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_LARGE_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_15:
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_LargeHint
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_LARGE_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_16:
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_LargeHint
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_LARGE_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_17:
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_LargeHint
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_LARGE_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_18:
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_LargeHint
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_LARGE_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_19:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_LargeHint
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_LARGE_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_20:
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_LargeHint
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_LARGE_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_21:
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_LargeHint
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_LARGE_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_22:
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_LargeHint
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_LARGE_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_23:
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_LargeHint
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_LARGE_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_24:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_LargeHint
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_LARGE_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_25:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_LargeHint
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_LARGE_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_26:
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_LargeHint
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_LARGE_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_27:
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_LargeHint
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_LARGE_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_28:
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_LargeHint
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_LARGE_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_29:
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_LargeHint
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_LARGE_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_30:
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_LargeHint
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_LARGE_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_31:
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_LargeHint
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_LARGE_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_36:
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_27
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_35

EscapeRoom_EventScript_HintsNPC_LargeHint_65:
# 1537 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_73
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
EscapeRoom_EventScript_HintsNPC_LargeHint_72:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_LARGE_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_64

EscapeRoom_EventScript_HintsNPC_LargeHint_66:
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_64

EscapeRoom_EventScript_HintsNPC_LargeHint_69:
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_65
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_68

EscapeRoom_EventScript_HintsNPC_LargeHint_73:
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_72


EscapeRoom_EventScript_HintsNPC_Solution::
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_Solution_2
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_3
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_4
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_Solution_5
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_6
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_Solution_7
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_8
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_9
# 1623 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_10
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_11
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_12
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_Solution_13
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_14
# 1658 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_Solution_15
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_16
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_17
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_Solution_18
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_Solution_19
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_20
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_21
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_Solution_22
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_23
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_24
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_25
# 1735 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_26
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_Solution_36
EscapeRoom_EventScript_HintsNPC_Solution_35:
# 1745 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_28
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_29
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_30
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_31
EscapeRoom_EventScript_HintsNPC_Solution_1:
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_Solution_65
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_Solution_64:
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1819 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_Solution_2:
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_Solution
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SOLUTION, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_3:
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_Solution
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_SOLUTION, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_4:
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_SOLUTION, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_5:
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_Solution
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_SOLUTION, FLAG_ZERA_CATCH_SOLUTION
# 1591 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_68
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_6:
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_Solution
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SOLUTION, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_7:
# 1603 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_Solution
# 1604 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SOLUTION, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_8:
# 1608 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SOLUTION, FLAG_TRAINER1_SOLUTION
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_70
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_9:
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_Solution
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SOLUTION, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_10:
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_Solution
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SOLUTION, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_11:
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_Solution
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SOLUTION, FLAG_TRAINER3_SOLUTION
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_72
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_12:
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_Solution
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SOLUTION, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_13:
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_Solution
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SOLUTION, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_14:
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_Solution
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SOLUTION, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_15:
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_Solution
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SOLUTION, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_16:
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_Solution
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SOLUTION, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_17:
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_Solution
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SOLUTION, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_18:
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SOLUTION, FLAG_TRAINER5_SOLUTION
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_74
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_19:
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_Solution
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SOLUTION, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_20:
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_Solution
# 1691 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SOLUTION, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_21:
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SOLUTION, FLAG_TRAINER6_SOLUTION
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_76
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_22:
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_Solution
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SOLUTION, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_23:
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_Solution
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SOLUTION, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_24:
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_Solution
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SOLUTION, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_25:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SOLUTION, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AskViewExactIcePuzzleSolution, MSGBOX_YESNO
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_78
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_26:
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_Solution
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SOLUTION, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_27:
# 1741 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_Solution
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SOLUTION, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_28:
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution
# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SOLUTION, FLAG_SECRET_POWER_SOLUTION
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AskViewExactIcePuzzleSolution, MSGBOX_YESNO
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_81
EscapeRoom_EventScript_HintsNPC_Solution_80:
# 1756 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_89
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_29:
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_Solution
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SOLUTION, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_30:
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_Solution
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SOLUTION, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_31:
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SOLUTION, FLAG_TRAINER11_SOLUTION
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution_MoveSetup, MSGBOX_YESNO
# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_83
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_36:
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_27
	goto EscapeRoom_EventScript_HintsNPC_Solution_35

EscapeRoom_EventScript_HintsNPC_Solution_65:
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1798 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_86
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 120
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC120minAddedMessage
EscapeRoom_EventScript_HintsNPC_Solution_85:
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SOLUTIONS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_Solution_64

EscapeRoom_EventScript_HintsNPC_Solution_68:
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_70:
# 1614 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_72:
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox intsNPC_Trainer3_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_74:
# 1680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_76:
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_78:
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution_IcePuzzleSteps
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_81:
# 1752 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution_IcePuzzleSteps
	goto EscapeRoom_EventScript_HintsNPC_Solution_80

EscapeRoom_EventScript_HintsNPC_Solution_83:
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_91
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_86:
# 1799 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1800 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_Solution_85

EscapeRoom_EventScript_HintsNPC_Solution_89:
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_91:
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 1832 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 1847 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 1855 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_MAX_REVIVE, EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_23
EscapeRoom_EventScript_ReturnLostItems_22:
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_33
EscapeRoom_EventScript_ReturnLostItems_32:
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 1988 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_42:
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_49
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_49
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 2076 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 1899 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 1907 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MAX_REVIVE
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
# 1924 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 1914 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_28
EscapeRoom_EventScript_ReturnLostItems_26:
# 1947 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1948 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_35
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_23:
# 1961 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_22

EscapeRoom_EventScript_ReturnLostItems_25:
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_27:
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_25
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_28:
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_27
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_33:
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_32

EscapeRoom_EventScript_ReturnLostItems_35:
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_38:
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_47
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_43:
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_54:
# 1997 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_68
EscapeRoom_EventScript_ReturnLostItems_67:
# 2004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_79
EscapeRoom_EventScript_ReturnLostItems_78:
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_83
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_44:
# 1988 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_47:
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 1981 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_49:
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_63
EscapeRoom_EventScript_ReturnLostItems_61:
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_59
EscapeRoom_EventScript_ReturnLostItems_57:
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_70
	return

EscapeRoom_EventScript_ReturnLostItems_55:
# 1991 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_54

EscapeRoom_EventScript_ReturnLostItems_58:
# 2029 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_72
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_59:
# 2056 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2057 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_62:
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_58
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_63:
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_62
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_68:
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_67

EscapeRoom_EventScript_ReturnLostItems_70:
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 2069 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_72:
# 2031 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2034 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_73:
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_81
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_76:
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_79:
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_78

EscapeRoom_EventScript_ReturnLostItems_81:
# 2042 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2048 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_83:
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_42


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2138 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 2152 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_29
EscapeRoom_EventScript_UndoUsedItems_28:
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 2166 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_32
EscapeRoom_EventScript_UndoUsedItems_31:
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
EscapeRoom_EventScript_UndoUsedItems_34:
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_42
EscapeRoom_EventScript_UndoUsedItems_41:
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SECRET_POWER
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 2192 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 2193 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 2194 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 2197 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_44
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 2115 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2120 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_ANNIHILAPE
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2129 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2140 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_29:
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2160 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2161 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_28

EscapeRoom_EventScript_UndoUsedItems_32:
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_31

EscapeRoom_EventScript_UndoUsedItems_35:
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_34

EscapeRoom_EventScript_UndoUsedItems_42:
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_41

EscapeRoom_EventScript_UndoUsedItems_44:
# 2198 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38:
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21:
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 2264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 2277 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45:
# 2294 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 2308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66:
# 2322 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72:
# 2331 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 2228 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSecretPower, OptionUndoRareCandy
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 2250 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13:
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14:
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37:
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41:
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 2295 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 2288 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2289 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 2296 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 2309 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 2303 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 2316 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76
# 2320 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70:
# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73:
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79
# 2327 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76:
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79:
# 2324 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 2338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 2344 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_5
# 2351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_6
EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_10
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_11
EscapeRoom_EventScript_AskUndoMoveTeach_9:
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 2374 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2377 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 2378 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_18
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 2339 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2340 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_5:
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_14
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_6:
# 2352 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_16
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_10:
# 2359 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2360 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_20
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_11:
# 2366 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 2367 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_22
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_14:
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_16:
# 2354 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_18:
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_AskUndoMoveTeach_20:
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_22:
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9


EscapeRoom_EventScript_UndoMoveTeach::
# 2385 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 2389 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 2405 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 2413 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 2417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 2417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_10:
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 2456 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_32:
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2468 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_46
EscapeRoom_EventScript_UndoMoveTeach_45:
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2480 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_57
EscapeRoom_EventScript_UndoMoveTeach_55:
# 2505 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_53:
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 2541 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_65
EscapeRoom_EventScript_UndoMoveTeach_64:
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_74
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 2390 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2393 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 2396 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 2399 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_23
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 2394 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 2418 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, VAR_0x8008
# 2419 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, VAR_0x8008
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_23:
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_26:
# 2430 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
# 2436 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_41
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_33:
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 2460 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM43
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_35:
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_39:
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_40:
# 2439 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
# 2443 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_41:
# 2436 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_40
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_46:
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2474 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_45

EscapeRoom_EventScript_UndoMoveTeach_49:
# 2440 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 2444 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2445 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 2495 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2496 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2497 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2501 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_56:
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_57:
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_56
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_62:
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2512 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2513 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_69
EscapeRoom_EventScript_UndoMoveTeach_67:
# 2517 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2518 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_85
EscapeRoom_EventScript_UndoMoveTeach_83:
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 2525 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_94
EscapeRoom_EventScript_UndoMoveTeach_93:
# 2533 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_99
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_65:
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_80
EscapeRoom_EventScript_UndoMoveTeach_78:
# 2548 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_90
EscapeRoom_EventScript_UndoMoveTeach_88:
# 2555 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 2556 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 2557 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_97
EscapeRoom_EventScript_UndoMoveTeach_96:
# 2564 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_101
	goto EscapeRoom_EventScript_UndoMoveTeach_64

EscapeRoom_EventScript_UndoMoveTeach_68:
# 2514 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_69:
# 2513 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_68
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_72:
# 2575 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 2576 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 2578 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 2579 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_73:
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_72
	return

EscapeRoom_EventScript_UndoMoveTeach_74:
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_73
	return

EscapeRoom_EventScript_UndoMoveTeach_79:
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2546 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_80:
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_79
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_84:
# 2519 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_85:
# 2518 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_84
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_89:
# 2550 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2551 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_90:
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_89
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_94:
# 2527 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_93

EscapeRoom_EventScript_UndoMoveTeach_97:
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_96

EscapeRoom_EventScript_UndoMoveTeach_99:
# 2534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 2535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_101:
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_64


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 2585 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 2586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 2593 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 2594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 2602 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 2609 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 2616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 2628 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 2632 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 2620 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 2635 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 2644 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 2661 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_31
EscapeRoom_EventScript_UndoRareCandy_30:
# 2687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 2702 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 2705 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
EscapeRoom_EventScript_UndoRareCandy_27:
# 2791 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_36
# 2794 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_38
EscapeRoom_EventScript_UndoRareCandy_35:
# 2803 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2804 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_48
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 2636 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 2645 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 2639 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 2666 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2668 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2669 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 2670 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 2650 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_33
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2717 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_43
EscapeRoom_EventScript_UndoRareCandy_42:
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_51
EscapeRoom_EventScript_UndoRareCandy_50:
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_59
EscapeRoom_EventScript_UndoRareCandy_58:
# 2751 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 2759 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2760 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_68
EscapeRoom_EventScript_UndoRareCandy_66:
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_77
EscapeRoom_EventScript_UndoRareCandy_75:
# 2787 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_31:
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2681 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_30

EscapeRoom_EventScript_UndoRareCandy_33:
# 2652 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_36:
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_37:
# 2795 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_38:
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_43:
# 2720 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2721 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2722 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2723 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_42

EscapeRoom_EventScript_UndoRareCandy_46:
# 2689 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2691 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2692 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 2695 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_48:
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_55
EscapeRoom_EventScript_UndoRareCandy_54:
# 2840 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_64
	return

EscapeRoom_EventScript_UndoRareCandy_51:
# 2730 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2731 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2732 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2733 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_50

EscapeRoom_EventScript_UndoRareCandy_53:
# 2810 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 2811 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_61
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2832 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_73
	return

EscapeRoom_EventScript_UndoRareCandy_55:
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_53
	goto EscapeRoom_EventScript_UndoRareCandy_54

EscapeRoom_EventScript_UndoRareCandy_59:
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2744 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2745 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_58

EscapeRoom_EventScript_UndoRareCandy_61:
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2815 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_71
	return

EscapeRoom_EventScript_UndoRareCandy_64:
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005, reverse = FALSE
# 2844 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2845 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2848 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_67:
# 2762 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2766 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2767 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_68:
# 2760 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_67
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_71:
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2822 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_73:
# 2833 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return

EscapeRoom_EventScript_UndoRareCandy_76:
# 2775 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2779 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2780 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2783 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_75

EscapeRoom_EventScript_UndoRareCandy_77:
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_76
	goto EscapeRoom_EventScript_UndoRareCandy_75


EscapeRoom_EventScript_UndoExpCandy::
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 2859 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2862 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 2863 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 2871 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2872 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2874 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2878 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 2886 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 2887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 2895 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 2903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 2912 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2916 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 2889 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 2905 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 2903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 2895 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 2887 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 2887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 2890 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 2898 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 2906 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 2921 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 2922 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2925 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 2928 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 2932 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 2940 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 2944 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 2950 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 2951 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2930 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2934 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 2941 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 2945 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 2956 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2957 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 2964 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 2965 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2970 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2973 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 2958 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2960 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 2978 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 2986 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 2987 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 2988 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 2991 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 2992 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2996 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 2980 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 2981 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2982 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_LiepardNPC::
# 3003 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3007 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 3008 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 3009 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 3010 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3013 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 3014 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 3095 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 3016 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 3019 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3020 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3021 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3024 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3025 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 3026 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3027 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3028 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3031 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 3032 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3033 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 3034 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3035 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 3038 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 3039 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3040 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3043 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3044 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 3045 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3046 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3047 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 3048 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3049 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 3050 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3053 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 3054 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 3060 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3061 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 3062 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 3072 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3073 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 3074 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3075 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3076 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3077 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 3078 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 3086 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3087 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 3090 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 3093 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 3080 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3081 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 3099 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 3100 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 3100 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 3106 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3108 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 3109 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 3111 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 3112 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3114 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3120 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 3142 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3143 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 3144 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3145 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3147 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 3148 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 3159 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 3149 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3154 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 3168 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 3170 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3171 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3174 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 3175 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 3176 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3179 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 3182 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3183 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3187 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 3188 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3189 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3190 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 3198 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 3201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 3202 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 3205 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 3206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3208 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3209 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 3212 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3213 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3215 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3225 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3227 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 3228 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 3229 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3230 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 3233 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 3236 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 3237 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 3238 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 3246 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3247 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3250 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 3257 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 3260 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 3266 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 3273 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 3274 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 3251 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 3252 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3253 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 3261 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 3262 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 3268 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 3279 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 3283 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 3284 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 3289 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 3292 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 3293 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 3307 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 3308 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 3323 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 3337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 3294 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3295 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3296 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 3299 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3300 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3301 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3302 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3303 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3310 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3311 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 3314 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3315 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3316 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 3324 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3325 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3326 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 3329 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3332 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3333 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 3339 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 3345 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3346 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 3347 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3348 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 3349 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3350 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 3351 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 3390 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 3361 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 3369 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 3362 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 3363 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3364 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3365 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 3397 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3398 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 3399 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3400 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 3401 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3402 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 3409 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 3411 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3412 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 3415 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 3420 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3423 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 3424 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3427 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 3428 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3431 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 3434 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 3435 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3438 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 3439 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 3442 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3450 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3451 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3452 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3454 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3457 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 3458 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3459 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 3460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3461 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 3463 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3464 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3465 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3466 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 3471 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 3472 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3473 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 3474 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3476 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 3477 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3478 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 3480 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 3489 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 3498 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3499 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 3505 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3506 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 3512 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 3513 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 3516 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 3493 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 3494 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 3500 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 3507 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 3520 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3521 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 3523 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 3538 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 3524 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 3525 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 3526 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3527 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 3528 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3529 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3530 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3532 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SUN_STONE_SOLD
# 3534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 3535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 3547 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 3556 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 3548 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 3549 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
# 3550 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 3552 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_IronBall, MSGBOX_NPC
# 3553 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoSecretPowerTeach::
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3568 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_2
EscapeRoom_EventScript_UndoSecretPowerTeach_1:
# 3578 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3579 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_5
EscapeRoom_EventScript_UndoSecretPowerTeach_4:
# 3583 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3584 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_10
EscapeRoom_EventScript_UndoSecretPowerTeach_9:
# 3594 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 3595 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_13
EscapeRoom_EventScript_UndoSecretPowerTeach_12:
# 3602 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_SECRET_POWER
# 3603 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_SECRET_POWER, VAR_0x8004
# 3604 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_SECRET_POWER
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
EscapeRoom_EventScript_UndoSecretPowerTeach_17:
# 3611 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
# 3611 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
EscapeRoom_EventScript_UndoSecretPowerTeach_22:
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
EscapeRoom_EventScript_UndoSecretPowerTeach_27:
# 3644 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
# 3644 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
EscapeRoom_EventScript_UndoSecretPowerTeach_32:
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
EscapeRoom_EventScript_UndoSecretPowerTeach_43:
# 3667 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3668 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3669 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSecretPowerTeach_2:
# 3569 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3572 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3573 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_7
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_5:
# 3580 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_4

EscapeRoom_EventScript_UndoSecretPowerTeach_7:
# 3574 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_10:
# 3585 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 3588 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_15
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_13:
# 3596 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_12

EscapeRoom_EventScript_UndoSecretPowerTeach_15:
# 3590 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_18:
# 3608 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3609 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_17

EscapeRoom_EventScript_UndoSecretPowerTeach_23:
# 3612 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3613 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_22

EscapeRoom_EventScript_UndoSecretPowerTeach_28:
# 3620 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_37
# 3626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_39
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_33:
# 3645 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 3646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_49
EscapeRoom_EventScript_UndoSecretPowerTeach_48:
# 3649 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3650 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_59
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_37:
# 3623 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_38:
# 3629 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_52
# 3633 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_53
EscapeRoom_EventScript_UndoSecretPowerTeach_51:
# 3637 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_39:
# 3626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_38
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_44:
# 3656 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 3657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_57
EscapeRoom_EventScript_UndoSecretPowerTeach_56:
# 3660 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3661 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_61
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43

EscapeRoom_EventScript_UndoSecretPowerTeach_49:
# 3647 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_48

EscapeRoom_EventScript_UndoSecretPowerTeach_52:
# 3630 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3631 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_53:
# 3634 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3635 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_57:
# 3658 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_56

EscapeRoom_EventScript_UndoSecretPowerTeach_59:
# 3651 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_61:
# 3662 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43


EscapeRoom_EventScript_UndoRareCandy_IcePuzzle::
# 3676 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 3677 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 3680 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2
# 3684 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3685 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1:
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5:
# 3699 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8:
# 3713 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15:
# 3728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24:
# 3739 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_33
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32:
# 3749 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_AUTOCLOSE
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13:
# 3754 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 3757 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21:
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2:
# 3681 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6:
# 3691 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3692 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9:
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3701 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11:
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14:
# 3718 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 3719 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3720 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3721 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_AUTOCLOSE
# 3722 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16:
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19:
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22:
# 3768 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3769 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_30
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29:
# 3778 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3779 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_36
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35:
# 3790 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3791 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_38:
# 3803 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 3811 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3812 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41:
# 3824 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_48
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46:
# 3839 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25:
# 3730 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3731 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3732 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3733 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 3736 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27:
# 3707 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_30:
# 3772 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3773 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3774 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3775 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3776 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_33:
# 3741 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3742 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3744 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_36:
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3783 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3784 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3785 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3786 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39:
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3797 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_38

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42:
# 3814 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3815 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3819 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3820 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3821 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3822 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43:
# 3812 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47:
# 3827 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3828 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3831 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3832 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3834 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3835 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_48:
# 3825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46


EscapeRoom_EventScript_CheckRareCandy2Stolen::
# 3847 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 3848 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_EventScript_CheckRareCandy2Stolen_2
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_1:
# 3849 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_COMPLETED
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_2:
# 3848 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_CheckRareCandy2Stolen_1
	return


EscapeRoom_AnnihilapeHintNPC::
# 3857 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3860 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 3872 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 3873 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 3861 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 3862 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3863 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3864 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3865 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 3866 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3867 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 3868 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 3879 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3880 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 3883 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 3887 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 3889 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 3881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 3884 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer0::
# 3896 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 3903 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 3904 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer1::
# 3909 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3910 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 3919 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 3923 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 3924 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 3920 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 3929 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 3935 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 3936 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 3941 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3942 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 3949 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 3955 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 3961 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 3962 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 3969 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 3970 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 3978 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 3987 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 3994 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 3995 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 3971 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3972 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 3973 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 3970 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 3979 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 3980 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 3981 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 3982 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 3983 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 4000 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 4007 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 4008 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 4013 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 4020 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 4021 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 4026 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 4033 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 4034 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 4039 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 4047 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4048 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_Trainer8_2
EscapeRoom_EventScript_Trainer8_1:
# 4052 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4053 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer8_2:
# 4049 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4050 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8_1


EscapeRoom_EventScript_Trainer9::
# 4058 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 4065 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 4066 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 4071 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 4078 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 4079 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 4085 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_Trainer11_2
EscapeRoom_EventScript_Trainer11_1:
# 4091 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 4099 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4100 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_Trainer11_5
# 4106 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FINAL_MESSAGE_READ, EscapeRoom_EventScript_Trainer11_9
EscapeRoom_EventScript_Trainer11_8:
# 4112 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_EndTheGame, MSGBOX_YESNO
# 4113 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_Trainer11_11
EscapeRoom_EventScript_Trainer11_4:
# 4118 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer11_2:
# 4086 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4087 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
	goto EscapeRoom_EventScript_Trainer11_1

EscapeRoom_EventScript_Trainer11_5:
# 4102 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_A, MSGBOX_AUTOCLOSE
# 4103 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer11_4

EscapeRoom_EventScript_Trainer11_9:
# 4107 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FINAL_MESSAGE_READ
# 4108 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_B, MSGBOX_AUTOCLOSE
# 4109 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4110 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
	goto EscapeRoom_EventScript_Trainer11_8

EscapeRoom_EventScript_Trainer11_11:
# 4114 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4115 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame
	goto EscapeRoom_EventScript_Trainer11_4


EscapeRoom_EventScript_PostMatchHeal::
# 4125 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 4130 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 4148 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 4149 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 4134 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4135 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 4138 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4139 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 4142 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4143 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 4136 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 4140 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 4144 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 4154 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4157 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4158 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4159 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 4167 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 4170 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 4176 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4177 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4178 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4179 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4180 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4181 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 4182 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4183 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 4184 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 4185 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 4194 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4195 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 4197 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 4160 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4161 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 4187 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4188 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4189 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 4184 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 4184 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 4162 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4163 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 4204 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4207 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4208 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4209 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 4216 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 4217 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4220 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 4227 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4228 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 4229 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4231 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 4237 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 4210 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 4233 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4235 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 4212 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4213 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 4243 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4246 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 4249 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4250 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 4253 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 4258 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 4260 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 4262 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4263 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4266 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 4269 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 4272 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4279 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4280 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 4281 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4282 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4283 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 4289 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 4251 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4286 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4287 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 4293 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 4295 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4295 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4296 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 4300 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 4301 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4306 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4307 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4308 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4309 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4310 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 4311 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 4312 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 4318 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 4321 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 4314 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4315 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4316 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 4312 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 4326 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4329 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 4341 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 4353 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 4365 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 4377 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 4388 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 4389 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 4330 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4331 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 4334 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4335 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 4342 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4343 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 4346 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4347 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 4332 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 4354 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4355 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_IRON_BALL
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 4358 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_IRON_BALL
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 4344 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 4336 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 4366 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4367 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 4370 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4371 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 4356 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 4348 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 4378 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4379 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 4382 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4383 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 4368 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 4360 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 4380 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 4372 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 4384 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 4394 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4397 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 4400 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 4401 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4402 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 4410 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 4411 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4412 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 4420 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 4422 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4425 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 4432 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4433 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4434 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4435 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4437 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 4438 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4439 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 4440 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 4442 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 4443 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 4444 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 4445 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 4447 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 4448 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4449 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 4450 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4451 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_IRON_BALL
# 4452 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 4453 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 4454 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 4456 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 4457 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 4458 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 4459 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 4461 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4463 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4464 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4466 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4467 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4468 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4471 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4472 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4473 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4474 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4475 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4476 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 4403 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4404 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 4413 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 4405 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 4478 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4479 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4480 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4481 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 4415 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4416 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 4486 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 4487 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4492 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 4493 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 4494 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 4500 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 4496 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4497 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4498 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 4504 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 4505 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4507 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4508 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4509 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4510 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 4515 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 4516 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4523 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4524 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4525 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 4526 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4527 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4528 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 4529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 4537 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_CUT
# 4540 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4541 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4542 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4544 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 4531 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4532 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4533 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 4548 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 4549 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4552 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 4560 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4561 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4562 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4563 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4564 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4565 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4566 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4567 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 4573 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 4569 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4571 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 4577 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 4578 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4581 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4591 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4592 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4593 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4594 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 35
# 4595 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4595 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_BAGON
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 4596 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4598 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4599 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4600 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 4606 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 4602 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4603 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4604 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 4610 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 4611 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4613 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4616 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4619 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_FINAL_BATTLE_REACHED, 1
# 4620 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_END_ESCAPE_ROOM_STATE, 1
# 4623 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer11End
# 4624 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4627 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxy 5, 3, 34
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4629 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 5
# 4630 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_CHAMPION
# 4632 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 4636 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer11End:
# 4637 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
	step_end

EscapeRoom_EventScript_TradeZeraForHMCut::
# 4645 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4646 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 4647 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 4674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 4676 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 4651 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4652 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4653 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 4662 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 4665 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4666 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4667 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4670 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 4671 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 4655 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4656 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4657 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 4680 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4681 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4684 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 4709 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 4710 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 4767 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 4768 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 4771 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 4687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 4703 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 4704 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 4688 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 4689 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4690 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 4697 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 4698 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 4713 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 4714 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 4724 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 4727 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 4728 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4729 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4731 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4734 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4735 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4736 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4739 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 4740 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 4762 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 4691 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 4693 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 4694 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 4717 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4718 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4719 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 4776 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4777 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4780 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 4805 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 4806 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 4840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 4841 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 4844 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 4783 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 4800 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 4784 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 4785 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4786 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 4793 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 4794 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 4809 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4810 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4811 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 4820 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 4823 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 4824 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4825 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4826 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4829 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4830 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4831 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4834 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 4835 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 4836 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 4787 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 4789 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 4790 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 4813 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4814 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4815 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 4848 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4849 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4852 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 4858 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 4859 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 4888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 4889 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 4892 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 4853 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 4854 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 4862 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 4863 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4864 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 4873 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 4874 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4875 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 4878 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4879 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4880 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4883 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 4884 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 4866 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4867 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4868 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_GetChoiceItem::
# 4900 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetChoiceItem_1
# 4945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsNoLongerAvailable, MSGBOX_DEFAULT
# 4946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_1:
# 4903 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsWhichOne, MSGBOX_DEFAULT
# 4904 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4907 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionChoiceBand, OptionChoiceSpecs, OptionChoiceScarf
# 4910 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_5
# 4913 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_6
# 4916 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_7
# 4920 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsComeAgain, MSGBOX_DEFAULT
# 4921 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_4:
# 4926 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem
# 4929 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RemoveChoiceItem
# 4932 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem VAR_0x8006
# 4935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_GetChoiceItem_12
# 4940 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CHOICE_ITEM_OBTAINED
	return

EscapeRoom_EventScript_GetChoiceItem_5:
# 4911 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_BAND
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_6:
# 4914 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SPECS
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_7:
# 4917 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SCARF
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_12:
# 4936 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsSwapped, MSGBOX_DEFAULT
# 4937 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem::
# 4951 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 4954 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem VAR_0x8006
# 4955 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1:
# 4959 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4960 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4:
# 4967 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4968 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7:
# 4977 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10
	return

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2:
# 4956 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5:
# 4961 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4962 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual1
# 4963 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4965 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual1:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8:
# 4969 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4970 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual2
# 4971 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4973 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual2:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10:
# 4978 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsAlreadyHaveThis, MSGBOX_DEFAULT
# 4979 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4980 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_RemoveChoiceItem::
# 4986 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_BAND
# 4987 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SPECS
# 4988 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SCARF
# 4990 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4991 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_3
EscapeRoom_EventScript_RemoveChoiceItem_1:
# 4998 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4999 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_11
	return

EscapeRoom_EventScript_RemoveChoiceItem_2:
# 4995 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_3:
# 4992 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 4993 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 4994 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_10:
# 5003 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	return

EscapeRoom_EventScript_RemoveChoiceItem_11:
# 5000 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 5001 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 5002 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 5011 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5012 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 5013 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 5014 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 5015 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 5019 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5020 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 5021 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 5022 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 5023 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 5027 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5028 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 5029 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 5030 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 5031 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindTMSecretPower::
# 5035 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5036 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_TM43
# 5037 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 5038 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_OBTAINED
# 5039 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy2::
# 5043 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5044 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 5045 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 5046 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 19
# 5049 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 1
# 5051 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRescueBell::
# 5055 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5056 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SOOTHE_BELL
# 5057 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RESCUE_BELL_OBTAINED
# 5058 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 5060 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RescueBellExplainMessage, MSGBOX_AUTOCLOSE
# 5061 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5063 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 5071 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5074 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 5082 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet1_Onix, MSGBOX_DEFAULT
# 5085 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 5088 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 5091 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 5094 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 5099 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 5114 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 5075 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5076 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5077 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 5086 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 5089 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 5092 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 5095 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 5100 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5101 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 5102 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5103 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5106 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 5111 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 5107 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 5118 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5121 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 5129 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet2_Toedscruel, MSGBOX_DEFAULT
# 5132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 5135 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 5138 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 5141 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 5146 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 5160 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 5122 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5123 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5124 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 5133 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 5136 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 5139 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 5142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 5147 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5148 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 5149 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5150 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5153 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 5158 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 5154 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 5164 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5167 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 5175 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet3_Dusknoir, MSGBOX_DEFAULT
# 5178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 5181 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 5184 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 5187 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 5192 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 5206 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 5168 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5169 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5170 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 5179 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 5182 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 5188 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 5193 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5194 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 5195 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5196 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5199 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 5204 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 5200 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 5210 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5213 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 5221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 5226 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet4_Dunsparce, MSGBOX_DEFAULT
# 5229 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 5232 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 5235 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 5238 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 5243 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 5257 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 5214 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5215 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5216 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 5222 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 5230 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 5233 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 5236 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 5239 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 5244 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5245 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 5246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5247 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5250 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 5255 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 5251 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 5262 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 5267 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5268 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 5269 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 5264 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 5263 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 5265 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 5274 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5275 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 5276 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 5277 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5278 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5279 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5280 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5281 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 5282 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5283 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 5284 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5285 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5286 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 5293 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5296 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 5299 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 5304 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 5327 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 5328 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 5300 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 5332 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5333 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5334 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 5341 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 5351 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5352 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5353 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 5357 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5358 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5361 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 5344 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 5345 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5347 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 5343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 5342 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 5365 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5367 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5370 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 5373 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 5374 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 5375 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 5382 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5383 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5384 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5386 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 5377 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5378 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 5390 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5391 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5392 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5395 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 5399 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 5406 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 5407 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 5414 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 5417 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5418 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5420 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 5401 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 5402 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5404 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 5409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5411 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 5424 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5425 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5426 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5429 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 5432 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 5433 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 5434 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 5441 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5442 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5443 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5445 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 5436 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5437 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 5449 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5450 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5451 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5454 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 5457 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 5458 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 5459 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 5466 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5467 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5468 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5470 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 5461 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5462 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 5474 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5475 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5476 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5479 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 5482 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 5483 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 5484 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 5491 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5492 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5493 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5495 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 5486 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5487 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 5499 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5501 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5504 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 5508 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 5515 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 5516 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 5527 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5528 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5529 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 5531 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 5512 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 5513 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 5518 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5519 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5521 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5522 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5523 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 5535 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5536 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5537 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5540 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 5544 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 5551 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 5552 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 5559 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 5562 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5563 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5565 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 5546 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 5547 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5549 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 5554 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5555 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5556 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 5569 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5571 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5574 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 5577 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 5578 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 5579 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 5586 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5587 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5588 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5590 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 5581 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5582 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 5594 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5595 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5596 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5599 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 5602 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 5603 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 5604 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 5611 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5612 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5613 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5615 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 5606 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5607 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 5619 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5620 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 5622 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 5623 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5624 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5625 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5626 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5627 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5628 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5629 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 5632 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 5633 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5634 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5636 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_SPAWNED
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 5640 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5643 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 5679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 5680 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 5683 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 5645 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 5646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 5673 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 5674 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 5649 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5650 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 5651 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 5654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 5655 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 5646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 5658 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 5659 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 5664 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5665 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5666 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 5667 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 5660 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 5661 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 5688 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5689 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5690 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5691 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 5692 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5693 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5694 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 5697 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 5698 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 5699 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 5700 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 5701 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_NIGHTMARE
# 5702 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5703 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5704 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5705 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 5706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 5707 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5708 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5711 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5712 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 5713 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 5714 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_NONE
# 5715 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 5719 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5720 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 5721 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5722 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndGame::
# 5729 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5730 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 5733 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 5734 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq EscapeRoom_EventScript_EndGame_2
# 5738 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq EscapeRoom_EventScript_EndGame_3
EscapeRoom_EventScript_EndGame_1:
# 5742 "data/maps/EscapeRoom_Main/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ESCAPE_ROOM_MAIN
# 5743 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 5745 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, ChampionEnterBoat
# 5746 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 5747 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 34
# 5748 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 35
# 5751 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 35, BoatSailAway
# 5754 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5755 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 5758 "data/maps/EscapeRoom_Main/scripts.pory"
	special GameClear
# 5759 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5760 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_EndGame_2:
# 5735 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EnterBoat2
# 5736 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_EndGame_1

EscapeRoom_EventScript_EndGame_3:
# 5739 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EnterBoat1
# 5740 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_EndGame_1


# 5764 "data/maps/EscapeRoom_Main/scripts.pory"
EnterBoat1:
# 5765 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5766 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 5768 "data/maps/EscapeRoom_Main/scripts.pory"
EnterBoat2:
# 5769 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 5770 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 5771 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5772 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 5772 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 5774 "data/maps/EscapeRoom_Main/scripts.pory"
ChampionEnterBoat:
# 5775 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 5776 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 5777 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5778 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 5780 "data/maps/EscapeRoom_Main/scripts.pory"
BoatSailAway:
# 5781 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
	step_end

EscapeRoom_EventScript_EscapeRopeEE_message1::
# 5789 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5790 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 2
# 5791 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 5792 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 5793 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 5794 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5795 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EscapeRopeEE_message2andwarp::
# 5799 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 3
# 5800 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRopeEEMessage2, MSGBOX_AUTOCLOSE
# 5801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5802 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 47, 17
# 5803 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


SomethingsGoneWrongMessage::
# 5811 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 5818 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 5822 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 5828 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1) The game's mechanics reflect GEN 9\n"
	.string "where possible; overworld mechanics\l"
	.string "are the main exception.\p"
	.string "2) Moves & learnsets are mostly vanilla.\n"
	.string "Move PP may be reduced (e.g. 5 PP Mimic)\l"
	.string "to suit puzzle design.\p"
	.string "3) Battle RNG has been disabled.\n"
	.string "Outcomes are deterministic (0% or 100%)\l"
	.string "with Assist as sole exception.\p"
	.string "4) There are no hidden items.\p"
	.string "5) EXP gain from battling has been\n"
	.string "disabled.\p"
	.string "6) Any Pokémon could have custom IVs or\n"
	.string "EVs, including wild Pokémon.\p"
	.string "Keep reading?$"

SignMessage1_part2::
# 5852 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "7) Your party is fully healed each time\n"
	.string "you beat a trainer.\p"
	.string "8) You'll never get softlocked.\n"
	.string "The game has an anti-softlock system\l"
	.string "to undo any mistake you could make.\l"
	.string "This may have side effects (such as\l"
	.string "healing your party) to prevent gaining\l"
	.string "an advantage via the system.\p"
	.string "9) There are QOL features that further\n"
	.string "reduce any need for save states, like\l"
	.string "the option to restore a pre-damaged\l"
	.string "state after losing.\p"
	.string "They're strictly QOL and not required to\n"
	.string "solve any of the puzzles.$"

MainSignWhatToRead::
# 5883 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to check?$"

GameCompletionMessage::
# 5887 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed roughly {STR_VAR_1}% of the\n"
	.string "game so far.$"

GameCompletionMessageInitial::
# 5892 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed 0% of the game so far.$"

GameCompletionMessageFinal::
# 5896 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've fully completed the game!$"

SignMessageReadInfoAgain::
# 5900 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

MoveDeleterSignMessage::
# 5906 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP after your\l"
	.string "Pokémon used Struggle.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 5923 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 5929 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 5933 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 5937 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 5942 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 5947 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 5951 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 5955 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 5964 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 5972 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 5977 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 5982 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 5989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 5998 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 6002 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something just opened...$"

MApSwitchesAlreadySolved::
# 6006 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchTablet1_Onix::
# 6011 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 95.$"

MapSwitchTablet2_Toedscruel::
# 6018 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 949.$"

MapSwitchTablet3_Dusknoir::
# 6025 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 477.$"

MapSwitchTablet4_Dunsparce::
# 6032 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 206.$"

MapSwitchPointedNorth::
# 6040 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEast::
# 6045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouth::
# 6050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWest::
# 6055 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 6062 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 6066 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 6070 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 6078 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "What kind of hint would you like to get?$"

HintsIntroMessage_Finale::
# 6087 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Please note: for this final challenge,\n"
	.string "hint costs are doubled.\p"
	.string "What kind of hint would you like to get?$"

HintsNPCNoHintMessage::
# 6098 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsFinalMessage::
# 6102 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed the escape room.\n"
	.string "I'm no longer needed!$"

HintsNPCHintAlreadyReceivedMessage::
# 6107 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received this hint so\n"
	.string "no time was added to your clock.$"

HintsNPCSolutionAlreadyReceivedMessage::
# 6112 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received the solution\n"
	.string "so no time was added to your clock.$"

HintsNPC_ReviewPreviousStep::
# 6117 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to review the previous step?\n"
	.string "This won't add any extra time.$"

HintsNPC_ReviewExactSequence::
# 6122 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact move sequence?$"

HintsNPC_AskViewExactIcePuzzleSolution::
# 6126 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact ice puzzle\n"
	.string "steps?$"

HintsNPC15minAddedMessage::
# 6132 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "15 minutes were added to your clock.$"

HintsNPC30minAddedMessage::
# 6136 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "30 minutes were added to your clock.$"

HintsNPC60minAddedMessage::
# 6140 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1 hour was added to your clock.$"

HintsNPC120minAddedMessage::
# 6144 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "2 hours were added to your clock.$"

HintsNPC_AnnihilapeSpawn_SmallHint::
# 6151 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Those gravestones seem to be placed in\n"
	.string "an interesting pattern...$"

HintsNPC_ZeraCatchPredamage_SmallHint::
# 6156 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block is what you need,\n"
	.string "but how to get the speed?\p"
	.string "At the graveyard fight the ape.\n"
	.string "Do ghosts always escape?$"

HintsNPC_ZeraoraCatch_SmallHint::
# 6163 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sometimes Zeraora blends in a little too\n"
	.string "well with its environment.\p"
	.string "Can Ferrothorn take advantage?$"

HintsNPC_Trainer0_SmallHint::
# 6169 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sticky Barbs are so annoying.\n"
	.string "If only you had an item.$"

HintsNPC_SafetyGoggles_SmallHint::
# 6174 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An item you're missing may finally be\n"
	.string "within reach.$"

HintsNPC_Trainer1_SmallHint::
# 6179 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora can take out Marowak but needs\n"
	.string "to absorb some additional HP.\p"
	.string "Can both Pokémon carry the Goggles?$"

HintsNPC_MarangaBerry_SmallHint::
# 6185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Double battles can be difficult.\n"
	.string "Is there a way to avoid them?$"

HintsNPC_Trainer2_SmallHint::
# 6190 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use Cut?$"

HintsNPC_Trainer3_SmallHint::
# 6194 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala is asleep?\n"
	.string "There's gotta be a way to use that.$"

HintsNPC_EggSkip_SmallHint::
# 6199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Why would you need an egg?$"

HintsNPC_SunStone_SmallHint::
# 6205 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have the ability to progress!$"

HintsNPC_UltraBall_SmallHint::
# 6209 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Someone's got something for you.$"

HintsNPC_Trainer4_SmallHint::
# 6213 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Trump Trump Trump, I feel depleted.\n"
	.string "Assistable moves should be deleted.$"

HintsNPC_TauntHerb_SmallHint::
# 6218 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One new move, your path will unlock.\n"
	.string "Where was that first Rock Smash rock?$"

HintsNPC_MoonStone_SmallHint::
# 6223 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I wonder what the carrier birds are\n"
	.string "carrying today.$"

HintsNPC_BerryJuice_SmallHint::
# 6228 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Are you a Rock Smash rock?\n"
	.string "Because I can't move past you.\p"
	.string "Such a juicy pickup line.$"

HintsNPC_Trainer5_SmallHint::
# 6234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An Onix so sturdy, I admire.\n"
	.string "The Berry Juice, her true desire.\p"
	.string "That's how Liepard hits her twice.\n"
	.string "Pay Day your partner? That's not nice.$"

HintsNPC_TrapinchRun_SmallHint::
# 6241 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Run!!$"

HintsNPC_RareCandyRevive_SmallHint::
# 6245 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find your way back once more?\n"
	.string "Too bad Liepard will be fainted.$"

HintsNPC_Trainer6_SmallHint::
# 6250 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ring Target Annihilape?\n"
	.string "Yeah, that makes sense.$"

HintsNPC_MapSwitches_SmallHint::
# 6255 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet numbers may have something\n"
	.string "to do with Pokémon...$"

HintsNPC_Trainer7A_SmallHint::
# 6262 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sore eyes?\n"
	.string "Hindsight is 20/20.$"

HintsNPC_Trainer8_SmallHint::
# 6267 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hidden Power Normal does not exist!$"

HintsNPC_IcePuzzleRareCandy_SmallHint::
# 6271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try taking just one item from the ice\n"
	.string "puzzle.\p"
	.string "Don't be greedy.$"

HintsNPC_Trainer9_SmallHint::
# 6277 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need an extra ¥500?\n"
	.string "Annihilape might help you out.$"

HintsNPC_ToxicOrbSteal_SmallHint::
# 6282 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Muk.$"

HintsNPC_SecretPower_SmallHint::
# 6286 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Make the right choice, revive, and\n"
	.string "you'll have poison.\p"
	.string "That's how you can unlock your Secret\n"
	.string "Power.$"

HintsNPC_RareCandy3_SmallHint::
# 6293 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There are two Secret Bases!$"

HintsNPC_Trainer10_SmallHint::
# 6297 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Kecleon was hit by Flamethrower!\n"
	.string "Huh? Its type didn't change.$"

HintsNPC_Trainer11_SmallHint::
# 6302 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Both of your items are very important!\p"
	.string "Can Heatran be poisoned?\n"
	.string "It's a real struggle.$"

HintsNPC_AnnihilapeSpawn_LargeHint::
# 6313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones represent a numpad.\n"
	.string "Maybe there's a code written somewhere\l"
	.string "for you to enter.$"

HintsNPC_UltraBall_LargeHint::
# 6319 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's an NPC you still haven't\n"
	.string "interacted with!$"

HintsNPC_ZeraCatchPredamage_LargeHint::
# 6324 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You should pre-damage Ferrothorn for\n"
	.string "Custap Berry Block against Zeraora.\p"
	.string "Grass Knot is great, but Florges is so\n"
	.string "heavy...\p"
	.string "Florges can run?\n"
	.string "That's so spooky!$"

HintsNPC_ZeraoraCatch_LargeHint::
# 6333 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block, Ingrain, Zeraora will stay.\n"
	.string "The Electric type stands in your way.\p"
	.string "One PP, its type will change.\n"
	.string "Which move brings the catch in range?$"

HintsNPC_Trainer0_LargeHint::
# 6340 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Struggling against Rhyperior?\n"
	.string "Skill Swap is really useful!\p"
	.string "Wait, no...\n"
	.string "TM Skill Swap is really useful!$"

HintsNPC_SafetyGoggles_LargeHint::
# 6347 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One of the gravestones is a little\n"
	.string "mysterious.\p"
	.string "Can Zeraora help you out?$"

HintsNPC_Trainer1_LargeHint::
# 6353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Cut Guy is very tough!\p"
	.string "Zeraora can beat the Marowak, but you\n"
	.string "must use Volt Absorb to keep it alive.\p"
	.string "Start the fight with Grassy Terrain,\n"
	.string "then share the Goggles with Zeraora\l"
	.string "once Lightningrod is removed.$"

HintsNPC_MarangaBerry_LargeHint::
# 6364 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.$"

HintsNPC_Trainer2_LargeHint::
# 6370 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Nature Power won't cut it?\n"
	.string "Just remove the grass.$"

HintsNPC_Trainer3_LargeHint::
# 6375 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala's type keeps Hex from landing.\n"
	.string "Maybe it needs a different held item.\p"
	.string "Magicians never reveal their secret,\n"
	.string "but a little sharing doesn't hurt.\p"
	.string "Why is Komala holding a Snowball?$"

HintsNPC_EggSkip_LargeHint::
# 6383 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.\p"
	.string "...\p"
	.string "Or if you only have one Pokémon.$"

HintsNPC_SunStone_LargeHint::
# 6393 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You should fight some Dusknoir.\n"
	.string "A certain ability might help you out.$"

HintsNPC_Trainer4_LargeHint::
# 6398 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Beating Iron Bundle will require some\n"
	.string "preparation at the Dusknoir.\p"
	.string "Can Thief be used with Assist?\n"
	.string "Don't you worry, there's no pressure if\l"
	.string "you fail.$"

HintsNPC_TauntHerb_LargeHint::
# 6407 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Taunted Dusknoirs Struggle twice,\n"
	.string "but a single hit would be paradise.\p"
	.string "You'd skip the Twins and not disturb.\n"
	.string "Dusknoir just needs a soothing herb.$"

HintsNPC_MoonStone_LargeHint::
# 6414 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You may not be a thief, but you've got\n"
	.string "a new Trick.\p"
	.string "Is it possible to steal the moon?$"

HintsNPC_BerryJuice_LargeHint::
# 6420 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know Pickup has an in-battle\n"
	.string "effect as well?\p"
	.string "It might come in handy at the Rock\n"
	.string "Smash rocks.\p"
	.string "Make sure you're not too quick!$"

HintsNPC_Trainer5_LargeHint::
# 6428 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Insane Money Hack You Won't Believe:\p"
	.string "Step 1: Give Onix some Berry Juice.\n"
	.string "Step 2: Delete the cat.\l"
	.string "Step 3: Break. That. Sub!\l"
	.string "Step 4: Taunt.\l"
	.string "...\l"
	.string "Step 8: Profit.\p"
	.string "Still not enough?\n"
	.string "Just Pay Day yourself!$"

HintsNPC_TrapinchRun_LargeHint::
# 6442 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Trapped? Just Run Away!$"

HintsNPC_RareCandyRevive_LargeHint::
# 6446 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Taunt a Dusknoir, now you can run.\n"
	.string "The other side holds all the fun!\p"
	.string "Want Liepard and the Ape to meet?\n"
	.string "Give your cat get a special treat.$"

HintsNPC_Trainer6_LargeHint::
# 6453 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You'll need to set up for Aipom to use\n"
	.string "Custap Endeavor vs Rayquaza.\p"
	.string "Oh... You want to use Endeavor against\n"
	.string "a Ghost type?\p"
	.string "It's tricky, but with the right item, it\n"
	.string "might just work.\p"
	.string "Endeavor for you, Endeavor for me.$"

HintsNPC_MapSwitches_LargeHint::
# 6466 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Four stone tablets, have you seen?\n"
	.string "The numbers Mason, what do they mean!\p"
	.string "Every Pokémon has their own.\n"
	.string "In numerical order they are shown.\p"
	.string "Where can the Pokémon be found?$"

HintsNPC_Trainer7A_LargeHint::
# 6476 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What if Peepers means it litterally?\n"
	.string "Perhaps her eyes really are sore.\p"
	.string "It wouldn't be strange for someone her\n"
	.string "age to be a little short-sighted.\p"
	.string "And Caesar... I totally understand his\n"
	.string "struggle.$"

HintsNPC_Trainer8_LargeHint::
# 6486 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dusclops is sus...\n"
	.string "Is there any move you haven't used?$"

HintsNPC_IcePuzzleRareCandy_LargeHint::
# 6491 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right now, TM Secret Power can't be\n"
	.string "taken out of the ice puzzle.\p"
	.string "Escaping with the Rare Candy is\n"
	.string "possible, but you'll need to find a new\l"
	.string "angle.\p"
	.string "Try to avoid instant gratification.$"

HintsNPC_Trainer9_LargeHint::
# 6502 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use twenty harmless Rage Fists, you'll\n"
	.string "have everything you need.\p"
	.string "Are there any trainers you could never\n"
	.string "defeat?$"

HintsNPC_ToxicOrbSteal_LargeHint::
# 6509 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My MUK ate a Moon Stone\n"
	.string "and I can't get it out!\p"
	.string "...\p"
	.string "Sorry, that's the wrong escape room.\n"
	.string "This Muk ate something else.$"

HintsNPC_SecretPower_LargeHint::
# 6517 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Compared to a Choice Scarf, the\n"
	.string "Dusknoir are slower.\p"
	.string "Stall and revive, its PP will get lower.\p"
	.string "The Toxic Orb triggers, let the poison\n"
	.string "run its course.\p"
	.string "Head to the ice, Secret Power is yours.$"

HintsNPC_RareCandy3_LargeHint::
# 6527 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find the Secret Bases?\p"
	.string "There's a wall indent and a tree.\n"
	.string "Wait, where's the nurse NPC?$"

HintsNPC_Trainer10_LargeHint::
# 6533 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sheer Force has an interesting\n"
	.string "interaction with Color Change.\p"
	.string "Do you have a Pokémon with Sheer Force?$"

HintsNPC_Trainer11_LargeHint::
# 6539 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This battle is very tricky.\p"
	.string "You'll need to find a way to take out\n"
	.string "Heatran with the Toxic Orb.\p"
	.string "Wandering Spirit can be used to give\n"
	.string "Heatran a new ability, but none of its\l"
	.string "moves make any contact.\p"
	.string "Try giving Heatran a Choice Specs and\n"
	.string "see if you can force it to Struggle.\p"
	.string "Did anyone say Disable Annihilape?\p"
	.string "PS: The trainer will avoid attacking\n"
	.string "into Destiny Bond.$"

HintsNPC_AnnihilapeSpawn_Solution::
# 6561 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones form a numpad pattern:\n"
	.string "1 2 3, 4 5 6, 7 8 9, 0.\p"
	.string "Interact with them in the following\n"
	.string "order: 1 8 3 7.$"

HintsNPC_UltraBall_Solution::
# 6568 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Talk to the NPC with the green hat to\n"
	.string "obtain an Ultra Ball.$"

HintsNPC_ZeraCatchPredamage_Solution::
# 6573 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1. Give Florges a Float Stone and fight\n"
	.string "the Annihilape.\p"
	.string "2. Let it Mimic Grass Knot, switch to\n"
	.string "Ferrothorn, then back to Florges.\p"
	.string "3. Use Camouflage to turn into a Ghost\n"
	.string "type and run from the battle.\p"
	.string "4. Sell the Float Stone, buy a Custap\n"
	.string "Berry, and give it to Ferrothorn.\p"
	.string "You can now use Block against Zeraora.$"

HintsNPC_ZeraCatchPredamage_Solution_Refresher::
# 6585 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pre-damage Ferrothorn by letting the\n"
	.string "Annihilape use Grass Knot.\p"
	.string "Have Florges hold a Float Stone and use\n"
	.string "Camouflage to run away.$"

HintsNPC_ZeraoraCatch_Solution::
# 6592 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1. Use Custap Berry Block vs Zeraora\n"
	.string "and let it Snatch Ingrain.\p"
	.string "2. Switch to Florges, use the Ether on\n"
	.string "Camouflage, and let Zeraora copy both\l"
	.string "Grassy Terrain and Camouflage.\p"
	.string "3. Switch to Ferrothorn and use Steel\n"
	.string "Roller.\p"
	.string "You can now catch Zeraora.$"

HintsNPC_Trainer0_Solution::
# 6603 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have to beat the Pincurchin\n"
	.string "trainer.\p"
	.string "1. Give TM Skill Swap to Florges as\n"
	.string "held item.\p"
	.string "2. Sack Ferrothorn and Zeraora to the\n"
	.string "Selfdestructing Pincurchin.\p"
	.string "3. Use Grass Knot.$"

HintsNPC_SafetyGoggles_Solution::
# 6613 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Exp Candy on Zeraora to reach\n"
	.string "level 43.\p"
	.string "Go to the graveyard and interact with\n"
	.string "the bottom-left gravestone to obtain\l"
	.string "the Safety Goggles.$"

HintsNPC_Trainer1_Solution::
# 6621 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have to defeat the Toedscruel and\n"
	.string "Marowak trainer.\p"
	.string "Replace Grass Knot with Skill Swap,\n"
	.string "give Florges the Safety Goggles and\l"
	.string "Zeraora the Electric Seed.\p"
	.string "To win the battle, do the following:\p"
	.string "1. Get rid of Lightningrod by using\n"
	.string "Skill Swap and switching out.\p"
	.string "2. Pass the goggles to Zeraora via\n"
	.string "Symbiosis (activate Electric Seed).\p"
	.string "3. Turn Florges into a Grass type with\n"
	.string "Camouflage.\p"
	.string "4. Heal Zeraora with Electric type\n"
	.string "Nature Power.$"

HintsNPC_Trainer1_Solution_ExactSequence::
# 6644 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Florges (Safety Goggles) and\n"
	.string "Zeroara (Electric Seed).\p"
	.string "Turn 1: Grassy Terrain + Plasma Fists.\n"
	.string "Turn 2: Skill Swap (Marowak) + Plasma\l"
	.string "Fists.\p"
	.string "Turn 3: Switch to Ferrothorn + Plasma\n"
	.string "Fists.\p"
	.string "Turn 4: Camouflage + Plasma Fists.\n"
	.string "Turn 5: Nature Power (Zeraora) +\l"
	.string "Electric Terrain.\p"
	.string "Turn 6: Nature Power (Zeraora) +\n"
	.string "Plasma Fists (Marowak).\p"
	.string "Turn 7: X + Plasma Fists (Marowak).\n"
	.string "Repeat untill Marowak faints.$"

HintsNPC_MarangaBerry_Solution::
# 6666 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fight the Annihilape and let it copy\n"
	.string "Steel Roller.\p"
	.string "Set up Grassy Terrain, switch out and\n"
	.string "sack Ferrothorn, use Camouflage, and\l"
	.string "run from battle.\p"
	.string "You can now walk past the Twins and\n"
	.string "pick the Maranga Berry.$"

HintsNPC_Trainer2_Solution::
# 6676 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Florges the Maranga Berry, then\n"
	.string "use Cut to remove the Grass tiles next\l"
	.string "to the Dracozolt trainer.\p"
	.string "Start the battle on a regular tile and\n"
	.string "use Nature Power to win.$"

HintsNPC_Trainer3_Solution::
# 6684 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let Klefki steal your Ring Target with\n"
	.string "Magician, give it Symbiosis, activate\l"
	.string "Komala's Snowball, and you're now able\l"
	.string "to beat it with Trump Card and Hex.$"

intsNPC_Trainer3_Solution_ExactSequence::
# 6691 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Florges (Ring Target) and\n"
	.string "Dunsparce.\p"
	.string "Turn 1: Grassy Terrain + Trump Card.\n"
	.string "Turn 2: Skill Swap + Trump Card.\l"
	.string "Turn 3: Ice Beam (Komala).\l"
	.string "Turn 4-6: Trump Card.\l"
	.string "Turn 7: Hex.\l"
	.string "Repeat untill Komala faints.$"

HintsNPC_EggSkip_Solution::
# 6702 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins cannot fight you when one of\n"
	.string "your Pokémon is an egg.\p"
	.string "Buy an Escape Rope, exit and re-enter\n"
	.string "the cave from where the Liepard Collar\l"
	.string "was located.\p"
	.string "Trade your Florges for the Pokémon egg,\n"
	.string "use the Escape Rope, and you can now\l"
	.string "walk past the Twins again.$"

HintsNPC_SunStone_Solution::
# 6715 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pickup will activate once you've fought\n"
	.string "a few wild Dusknoir.\p"
	.string "You'll get a Sun Stone which can be\n"
	.string "sold to an NPC up north.$"

HintsNPC_Trainer4_Solution::
# 6722 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Iron Bundle can be defeated with two\n"
	.string "200 BP Trump Cards from Dunsparce and\l"
	.string "Liepard.\p"
	.string "1. Fight the Dusknoir and bring Trump\n"
	.string "Card's PP down to 1.\p"
	.string "2. Bring Assist's PP down to 2.\p"
	.string "3. Buy and teach TM Thief to Dunsparce.\p"
	.string "4. Delete every move from Aipom and\n"
	.string "Dunsparce except for Mimic and Thief.\p"
	.string "5. Use Assist against Dusknoir.\n"
	.string "Neither Mimic nor Thief can be called\l"
	.string "by Assist, so the move will fail and\l"
	.string "Pressure will have no effect.\p"
	.string "6. Restore your movesets, then remove\n"
	.string "everything again except for Mimic and\l"
	.string "Trump Card.\p"
	.string "You can now use Trump Card and Assist\n"
	.string "(Trump Card) to beat the Iron Bundle.$"

HintsNPC_TauntHerb_Solution::
# 6750 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1. Talk to the NPC below the Iron Bundle\n"
	.string "trainer and trade your Dunsparce for\l"
	.string "TM Taunt.\p"
	.string "2. Teach Taunt to Aipom and delete\n"
	.string "Endeavor via the Move Deleter.\p"
	.string "3. Buy a Mental Herb and give it to\n"
	.string "Liepard.\p"
	.string "4. Fight Dusknoir and use Assist until\n"
	.string "it selects Taunt, then use it again to\l"
	.string "Fling the Mental Herb.\p"
	.string "Your Liepard will be fainted and you\n"
	.string "can now walk past the Twins again.$"

HintsNPC_MoonStone_Solution::
# 6769 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rayquaza carries a Moon Stone.\p"
	.string "Use Trick to steal the Moon Stone and\n"
	.string "sell it to the NPC up north.$"

HintsNPC_BerryJuice_Solution::
# 6775 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Aipom the Iron Ball and fight a\n"
	.string "Shuckle at the Rock Smash rocks.\p"
	.string "Use Endeavor to trigger Shuckle's Berry\n"
	.string "Juice, then Aipom's Pickup activates\l"
	.string "to recover the consumed item.\p"
	.string "Run from the battle and you've now got\n"
	.string "a Berry Juice.$"

HintsNPC_Trainer5_Solution::
# 6787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your goal is to earn an additional ¥525\n"
	.string "during battle to purchase the Ability\l"
	.string "Capsule from the NPC in the cave.\p"
	.string "Each successful Pay Day yields ¥5 per\n"
	.string "level. This means you'll need five Pay\l"
	.string "Days from Aipom and two from Liepard to\l"
	.string "earn enough money.\p"
	.string "Aipom can simply use five Pay Days into\n"
	.string "its partner, but Liepard's setup is\l"
	.string "slightly trickier.\p"
	.string "Use Berry Juice, Pickup, Taunt, and\n"
	.string "Rock Smash to get Onix back to full HP\l"
	.string "without a Substitute up.\p"
	.string "You can then Copycat Pay Day the Onix\n"
	.string "twice, who'll hang on by 1 HP after the\l"
	.string "first hit due to Sturdy.$"

HintsNPC_Trainer5_Solution_ExactSequence::
# 6810 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Liepard (Berry Juice) and Aipom.\p"
	.string "Turn 1: Trick (Onix) + Mimic (Meowth).\n"
	.string "Turn 2: Rock Smash (Meowth) + Pay Day\l"
	.string "(Liepard).\p"
	.string "Turn 3: Rock Smash + Pay Day (Liepard).\n"
	.string "Turn 4: Rock Smash + Taunt.\l"
	.string "Turn 5: Trick (Aipom) + Pay Day\l"
	.string "(Liepard).\p"
	.string "Turn 6: Rock Smash + X (not Pay Day).\n"
	.string "Turn 7: Trick + Pay Day (Liepard).\l"
	.string "Turn 8: Copycat + Pay Day (Liepard).\l"
	.string "Turn 9: Copycat + X.$"

HintsNPC_TrapinchRun_Solution::
# 6828 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Ability Capsule on Aipom to get\n"
	.string "Run Away.\p"
	.string "Fight the Trapinch and run away.$"

HintsNPC_RareCandyRevive_Solution::
# 6834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fight Dusknoir and use Assist until it\n"
	.string "selects Taunt, sack Liepard, and use\l"
	.string "Aipom's Run Away to escape.\p"
	.string "Walk past the Twins again and revive\n"
	.string "Liepard with the Rare Candy.\p"
	.string "You can now revisit Annihilape and set\n"
	.string "up for the Rayquaza trainer.\p"
	.string "(A new hint/solution will be available\n"
	.string "once Liepard is succesfully revived.)$"

HintsNPC_Trainer6_Solution_Refresher::
# 6849 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Assist Taunt against a Dusknoir, sack\n"
	.string "Liepard, then run away.\p"
	.string "Walk past the Twins and Revive Liepard\n"
	.string "with the Rare Candy.$"

HintsNPC_Trainer6_Solution::
# 6856 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You can beat the Rayquaza with Custap\n"
	.string "Berry Endeavor + Assist Fling, which\l"
	.string "will require Aipom to be at <25% HP.\p"
	.string "Give Liepard a Ring Target and fight\n"
	.string "the Annihilape to pre-damage Aipom\l"
	.string "with the following sequence:\p"
	.string "Lead: Aipom.\n"
	.string "Turn 1: Endeavor.\l"
	.string "Turn 2: X (let Ape Mimic Endeavor).\l"
	.string "Turn 3: Switch to Liepard.\l"
	.string "Turn 4: Trick (give Ring Target).\l"
	.string "Turn 5: Copycat (Endeavor).\l"
	.string "Turn 6: Trick (take Ring Target).\l"
	.string "Turn 7: Switch to Aipom.\l"
	.string "Turn 8: Run.\p"
	.string "Sell the Ring Target, buy a Custap for\n"
	.string "Aipom, and give Liepard the Safety\l"
	.string "Goggles.\p"
	.string "Return to the other area via the tunnel\n"
	.string "and delete Aipom's Taunt.\p"
	.string "Start the trainer battle leading with\n"
	.string "Aipom, then:\l"
	.string "1. Use Endeavor (Custap activates).\l"
	.string "2. Use Assist (Fling Safety Goggles).$"

HintsNPC_MapSwitches_Solution::
# 6888 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Each of the four tablets is engraved\n"
	.string "with the Pokédex entry number of a\l"
	.string "Pokémon you've encountered.\p"
	.string "For each tablet, open the matching\n"
	.string "Pokédex entry and check the Pokémon's\l"
	.string "encounter area.\p"
	.string "Align the tablet to the highlighted\n"
	.string "part of the map (north, east, south, or\l"
	.string "west).$"

HintsNPC_Trainer7A_Solution::
# 6904 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Muk trainer's sight radius is only\n"
	.string "three tiles, so you can isolate the\l"
	.string "Shedinja trainer by hugging the\l"
	.string "northern wall.\p"
	.string "Before the battle, visit the Move\n"
	.string "Deleter and remove all of Liepard's\l"
	.string "moves except for Trick or Assist.\p"
	.string "Fight the Shedinja, use up all your PP,\n"
	.string "and Struggle will get the KO.$"

HintsNPC_Trainer8_Solution::
# 6918 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teach Cut to Bagon and fight the\n"
	.string "Dusclops trainer.\p"
	.string "Use Cut.$"

HintsNPC_IcePuzzleRareCandy_Solution::
# 6924 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "At this point, only the Rare Candy can\n"
	.string "be taken out of the ice puzzle.\p"
	.string "To do so, the item ball must be used as\n"
	.string "an obstacle within the puzzle itself.$"

HintsNPC_IcePuzzleRareCandy_Solution_IcePuzzleSteps::
# 6932 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW} (ignore the\n"
	.string "item) {LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{LEFT_ARROW} "
	.string "(take the item) {DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}.$"

HintsNPC_Trainer9_Solution::
# 6940 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have Primeape use Rage Fist 20 times\n"
	.string "(Sentret is the easiest target), then\l"
	.string "give it the Rare Candy to evolve into\l"
	.string "Annihilape.\p"
	.string "Now you're finally able to defeat the\n"
	.string "Twins.\p"
	.string "Keep using Rage Fist (start with the\n"
	.string "Urshifu-Rapid-Strike) to win.$"

HintsNPC_ToxicOrbSteal_Solution::
# 6953 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Muk is holding a Toxic Orb.\p"
	.string "Buy TM Thief, teach it to Annihilape,\n"
	.string "and steal the Toxic Orb from Muk.$"

HintsNPC_SecretPower_Solution_Refresher::
# 6960 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Buy TM Thief, teach it to Annihilape,\n"
	.string "and steal the Toxic Orb from Muk.$"

HintsNPC_SecretPower_Solution::
# 6965 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You can smuggle TM Secret Power out of\n"
	.string "the ice puzzle by whiting out due to\l"
	.string "poison in the overworld.\p"
	.string "To do this, first activate the stolen\n"
	.string "Toxic Orb by battling a Dusknoir.\p"
	.string "This requires the following setup:\p"
	.string "1. Give Annihilape a Choice Scarf,\n"
	.string "fight a Dusknoir and use Taunt until\l"
	.string "Annihilape faints.\p"
	.string "Don't send out another Pokémon, but use\n"
	.string "the flee option instead.\p"
	.string "2. Give Annihilape the Toxic Orb, give\n"
	.string "Bagon the Choice Scarf, then fight\l"
	.string "another Dusknoir and use Substitute\l"
	.string "repeatedly.\p"
	.string "3. Use the Max Revive on Annihilape to\n"
	.string "burn a turn without using any PP.\p"
	.string "Dusknoir should now be out of Memento\n"
	.string "PP by the time Annihilape comes in.\p"
	.string "4. Let Bagon faint from Struggle, send\n"
	.string "out Annihilape, use any move, then run\l"
	.string "from battle.\p"
	.string "Annihilape should now be poisoned.\p"
	.string "Return to the ice puzzle, grab TM\n"
	.string "Secret Power, and run around until\l"
	.string "Annihilape faints from poison.$"

HintsNPC_SecretPower_Solution_IcePuzzleSteps::
# 7002 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{DOWN_ARROW}"
	.string "{LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW}.$"

HintsNPC_RareCandy3_Solution::
# 7008 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There are two Secret Bases hidden\n"
	.string "throughout the map.\p"
	.string "1. There's a tree entrance in the first\n"
	.string "area behind the Mart NPC.\p"
	.string "2. There's a wall entrance southwest,\n"
	.string "outside the cave of the 4th tablet.\p"
	.string "Enter the first base to find a Solid\n"
	.string "Board, then use it in the second base\l"
	.string "to get a Rare Candy.$"

HintsNPC_Trainer10_Solution::
# 7023 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Color Change won't trigger when hit by\n"
	.string "a Sheer Force-boosted move.\p"
	.string "Use the Rare Candy on Bagon to learn\n"
	.string "Flamethrower, but cancel the evolution\l"
	.string "to keep Sheer Force.\p"
	.string "Give Bagon a Choice Specs and start the\n"
	.string "trainer battle leading with Annihilape.\p"
	.string "1. Use Taunt, then Secret Power or Thief\n"
	.string "until Taunt wears off, and repeat.\p"
	.string "2. Send out Bagon and lock into\n"
	.string "Flamethrower to win the battle.$"

HintsNPC_Trainer11_Solution_MoveSetup::
# 7041 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokémon will need the following\n"
	.string "setup:\p"
	.string "Annihilape (Choice Specs)\n"
	.string "Rage Fist / Role Play / Mimic / Taunt.\p"
	.string "Yamask (Toxic Orb)\n"
	.string "Trick / Disable / Destiny Bond / X.\p"
	.string "Want to continue?$"

HintsNPC_Trainer11_Solution::
# 7054 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your only way to win is to take out\n"
	.string "Heatran with the Toxic Orb.\p"
	.string "The key is to use Wandering Spirit and\n"
	.string "Role Play to give Heatran Protean and\l"
	.string "change its typing.\p"
	.string "1. Heatran can only make contact with\n"
	.string "Wandering Spirit via Struggle, which\l"
	.string "you can force by using Disable after\l"
	.string "giving it the Choice Specs.\p"
	.string "2. Use Destiny Bond on the Disable turn\n"
	.string "so Heatran's Struggle has to target\l"
	.string "Annihilape, keeping Yamask alive.\p"
	.string "This means Annihilape needs to be the\n"
	.string "one using Disable, which requires\l"
	.string "Mimicking it earlier in the fight.\p"
	.string "3. Use Trick on the Struggle turn to\n"
	.string "take back the Choice Specs and prevent\l"
	.string "Heatran from Struggling twice.$"

HintsNPC_Trainer11_Solution_ExactSequence::
# 7080 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Annihilape (Choice Specs) and\n"
	.string "Yamask (Toxic Orb).\p"
	.string "Turn 1: Role Play (any target) + Trick\n"
	.string "(Kecleon, give Toxic Orb).\p"
	.string "Turn 2: Role Play (any target) + Trick\n"
	.string "(Annihilape, take Choice Specs).\p"
	.string "Turn 3: Role Play (Yamask) + Trick\n"
	.string "(Heatran, give Choice Specs).\p"
	.string "Turn 4: Taunt (Heatran) + Disable\n"
	.string "(Annihilape).\p"
	.string "Turn 5: Mimic (Yamask) + Disable\n"
	.string "(Annihilape).\p"
	.string "Turn 6: Disable (Heatran) + Destiny\n"
	.string "Bond.\p"
	.string "Turn 7: Role Play (Kecleon) + Trick\n"
	.string "(Heatran, take Choice Specs).\p"
	.string "Turn 8: Rage Fist (Heatran) + Trick\n"
	.string "(Kecleon, take Toxic Orb).\p"
	.string "Turn 9: X + Trick (Heatran, give Toxic\n"
	.string "Orb).\p"
	.string "Turn 10: Taunt (Kecleon) + X.\n"
	.string "Turn 11: X.\l"
	.string "Turn 12: X.\l"
	.string "Turn 13: Taunt (Kecleon).\l"
	.string "Turn 14: X.\l"
	.string "Turn 15: X.\l"
	.string "Turn 16: Rage Fist.\p"
	.string "Other variations may also be possible.$"

AntiSoftlockIntroMessage::
# 7124 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 7134 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 7138 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 7144 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 7149 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 7153 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 7157 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 7163 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 7168 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 7172 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoSecretPower::
# 7175 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Secret Power$"

OptionUndoCut::
# 7178 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 7181 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 7184 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 7187 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 7191 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 7196 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "used on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 7201 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 7206 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 7210 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 7215 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 7220 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 7224 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 7228 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 7232 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 7238 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 7243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 7250 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 7254 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 7259 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 7266 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 7276 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 7283 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 7294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 7298 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 7305 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 7309 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 7313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your energy trying to catch\n"
	.string "or beat her.$"

FourTabletsHintMessage1::
# 7325 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 7331 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?$"

FourTabletsHintMessage3::
# 7336 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake???$"

StonesBuyNPCInitialMessage_no_item::
# 7343 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 7351 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 7357 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for an Iron Ball?$"

StonesBuyNPCSellAcceptedMessage::
# 7365 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_IronBall::
# 7369 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the ball will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 7373 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 7377 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 7381 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 7388 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 7392 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 7396 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 7400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 7407 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 7411 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretPowerTmReturned::
# 7418 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TM43 Secret Power was returned to its\n"
	.string "previous location.$"

RareCandy2Returned::
# 7423 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Rare Candy was returned to its\n"
	.string "previous location.$"

MonForgotSecretPower::
# 7428 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MartNPC_AskToShop::
# 7434 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 7440 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

ChoiceItemsFirstMessage::
# 7446 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Impressive, you saw right through my\n"
	.string "facade!\p"
	.string "I think you've earned a reward!\n"
	.string "Take your pick of my Choice items.\p"
	.string "You can always return if you'd like to\n"
	.string "try a different one.$"

ChoiceItemsNoLongerAvailable::
# 7455 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It seems you've made the right choice.$"

ChoiceItemsWhichOne::
# 7459 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Which item would you like to have?$"

ChoiceItemsComeAgain::
# 7463 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back anytime.$"

ChoiceItemsSwapped::
# 7467 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You returned the other Choice item.$"

ChoiceItemsAlreadyHaveThis::
# 7471 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You already have this one.$"

OptionChoiceBand::
# 7475 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Band$"

OptionChoiceSpecs::
# 7479 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Specs$"

OptionChoiceScarf::
# 7483 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Scarf$"

PrimeapeObtainMessage::
# 7489 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 7493 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

RescueBellExplainMessage::
# 7499 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Rescue Bell to teleport out of\n"
	.string "the ice puzzle if you're stuck.\p"
	.string "When used, any obtained items will be\n"
	.string "placed back inside the ice puzzle.$"

AskDeleteMove::
# 7508 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 7514 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 7520 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 7524 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 7528 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 7534 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 7538 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 7542 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 7549 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 7554 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 7559 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 7565 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 7571 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 7576 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 7580 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 7584 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 7588 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 7592 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 7597 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 7602 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 7607 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 7613 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 7617 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 7621 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 7625 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 7629 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 7634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 7638 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 7643 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 7649 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 7655 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 7659 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 7665 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 7672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You think you are ready?\n"
	.string "You really need three.\l"
	.string "One of them might hold the key.$"

Trainer0_Outro::
# 7678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "But sharing is caring...$"

Trainer0_PostBattle::
# 7682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go.$"

Trainer1_Intro::
# 7688 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 7694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 7698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 7703 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 7710 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 7716 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 7721 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love writing in 686578!$"

Trainer2_PostBattle::
# 7725 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 7731 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 7736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 7740 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 7745 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 7751 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 7756 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 7760 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know 5(A->L) + 2(L->O) = 525?$"

Trainer5_Intro::
# 7767 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 7772 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 7776 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 7780 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 7787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 7794 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 7798 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My birds have traveled through all\n"
	.string "sorts of areas.\p"
	.string "Your Pokédex would be full by now if\n"
	.string "you'd done the same!$"

Trainer7A_Intro::
# 7807 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 7814 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 7818 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "bsqajmnq? qsq.$"

Trainer7B_Intro::
# 7826 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 7831 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 7835 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 7842 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Ghost type mons are everywhere,\n"
	.string "you still haven't seen mine.$"

Trainer8_Outro::
# 7854 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 7858 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "$"

Trainer9_Intro::
# 7864 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 7869 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try hard in every fight!$"

Trainer9_PostBattle::
# 7873 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is this your last time passing through?$"

Trainer10_Intro::
# 7879 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Darwinism?\n"
	.string "More like Schmarminism...\p"
	.string "Kecleon doesn't need any changes!$"

Trainer10_Outro::
# 7885 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a struggle!$"

Trainer10_PostBattle::
# 7889 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So Kecleon isn't the only Pokémon with\n"
	.string "the ability to change?$"

Trainer11_Intro::
# 7896 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So you've finally made it to the end...\p"
	.string "No more hints.\p"
	.string "No more clues.\p"
	.string "It's time for your final test.$"

Trainer11_Outro::
# 7903 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

Trainer11_PostBattle_A::
# 7907 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please read the sign first.$"

Trainer11_PostBattle_B::
# 7911 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This game has been a true passion\n"
	.string "project of mine.\p"
	.string "An absurd amount of time, effort, and\n"
	.string "care was put into every small detail.\p"
	.string "If you enjoyed the experience, please\n"
	.string "let me know by commenting on the game's\l"
	.string "PokéCommunity forum post.\p"
	.string "It really does mean lot to me.\p"
	.string "Thank you so much for playing.\n"
	.string " - Ketch.$"

Trainer11_EndTheGame::
# 7928 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wanna get out of here?$"

EscapeRoomEndCongratz::
# 7934 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have completed\n"
	.string "the escape room!$"

EndEscapeRoomSignMessage::
# 7939 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your final time: {STR_VAR_1}.\p"
	.string "Small hints used: {STR_VAR_2}.\n"
	.string "Large hints used: {STR_VAR_3}.\l"
	.string "Solutions used: {STR_VAR_5}.$"

EscapeRopeEEMessage2::
# 7948 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just kidding.$"
