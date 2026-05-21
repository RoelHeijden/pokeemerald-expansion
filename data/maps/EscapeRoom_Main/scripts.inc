# 52 "data/maps/EscapeRoom_Main/scripts.pory"
_face_down:
# 53 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 55 "data/maps/EscapeRoom_Main/scripts.pory"
_face_up:
# 56 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 58 "data/maps/EscapeRoom_Main/scripts.pory"
_face_right:
# 59 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 61 "data/maps/EscapeRoom_Main/scripts.pory"
_face_left:
# 62 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_Main_MapScripts::
# 69 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EscapeRoom_MapScript_SetIcePuzzleRockOnLoad
# 70 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 80 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 81 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_STICKY_BARB_RETURN, 1, EscapeRoom_MapScripts_ReturnStickyBarb
# 82 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 85 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_JUST_ESCAPED_ICE_PUZZLE, 1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns
# 87 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROPE_EE_STATE, 1, EscapeRoom_EventScript_EscapeRopeEE_message1
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_MAIN_EASTER_EGG_STEP3_COMPLETE_MSG, 1, EscapeRoom_EventScript_MainEasterEggStep3Complete
	.2byte 0


EscapeRoom_MapScript_SetIcePuzzleRockOnLoad::
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 3
	goto_if_ge EscapeRoom_MapScript_SetIcePuzzleRockOnLoad_1
	return

EscapeRoom_MapScript_SetIcePuzzleRockOnLoad_1:
# 95 "data/maps/EscapeRoom_Main/scripts.pory"
	setmetatile 80, 19, METATILE_EscapeRoomIceRock, TRUE
	return


EscapeRoom_MapScript_OnTransitionScripts::
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 102 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfSecretPowerObtained
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_MapScript_OnResumeScripts_13
EscapeRoom_MapScript_OnResumeScripts_12:
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_MapScript_OnResumeScripts_16
EscapeRoom_MapScript_OnResumeScripts_15:
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_20
EscapeRoom_MapScript_OnResumeScripts_18:
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_24
EscapeRoom_MapScript_OnResumeScripts_23:
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_27
EscapeRoom_MapScript_OnResumeScripts_26:
# 159 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_30
EscapeRoom_MapScript_OnResumeScripts_29:
# 165 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_32
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 115 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 120 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 126 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckZeraPredamageStep
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_16:
# 139 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckRareCandyReviveStep
	goto EscapeRoom_MapScript_OnResumeScripts_15

EscapeRoom_MapScript_OnResumeScripts_19:
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_20:
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_19
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_24:
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_23

EscapeRoom_MapScript_OnResumeScripts_27:
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStickyBarbStolen
	goto EscapeRoom_MapScript_OnResumeScripts_26

EscapeRoom_MapScript_OnResumeScripts_30:
# 160 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_29

EscapeRoom_MapScript_OnResumeScripts_32:
# 173 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 208 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 216 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 217 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 219 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 223 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 227 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 238 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 241 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 242 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 245 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 246 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 239 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckStickyBarbStolen::
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_2
EscapeRoom_MapScripts_CheckStickyBarbStolen_1:
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 257 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_5
EscapeRoom_MapScripts_CheckStickyBarbStolen_4:
# 260 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_8
EscapeRoom_MapScripts_CheckStickyBarbStolen_7:
# 264 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 265 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_10
	return

EscapeRoom_MapScripts_CheckStickyBarbStolen_2:
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_1

EscapeRoom_MapScripts_CheckStickyBarbStolen_5:
# 258 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_4

EscapeRoom_MapScripts_CheckStickyBarbStolen_8:
# 262 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_7

EscapeRoom_MapScripts_CheckStickyBarbStolen_10:
# 266 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 280 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 274 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_8
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 281 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_11
EscapeRoom_MapScripts_CheckIfAskPreDamage_10:
# 288 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 280 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 275 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 283 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_10


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 298 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 298 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 312 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 299 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 305 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 324 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_CheckIfAskWarpBack::
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskWarpBack_3
EscapeRoom_MapScripts_CheckIfAskWarpBack_1:
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
Equal:
	return

EscapeRoom_MapScripts_CheckIfAskWarpBack_2:
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_LOCATED_AT_SECTION_X, VAR_RESPAWN_AT_SECTION_X
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_eq Equal
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 1
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1

EscapeRoom_MapScripts_CheckIfAskWarpBack_3:
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_MapScripts_CheckIfAskWarpBack_2
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1


EscapeRoom_MapScripts_CheckIfSecretPowerObtained::
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_4
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1:
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FIELD_POISON_WHITEOUT
	return

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2:
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 358 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 359 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 367 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_8:
# 373 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_THIEF
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_3:
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FIELD_POISON_WHITEOUT, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_4:
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_3
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9:
# 369 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_8


EscapeRoom_MapScripts_CheckZeraPredamageStep::
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FERROTHORN
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 19
	goto_if_le EscapeRoom_MapScripts_CheckZeraPredamageStep_3
EscapeRoom_MapScripts_CheckZeraPredamageStep_1:
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLAG_ZERA_PREDAMAGE_SUCCES, EscapeRoom_MapScripts_CheckZeraPredamageStep_8
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_2:
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLAG_ZERA_PREDAMAGE_SUCCES
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FERROTHORN
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_0x8004
# 395 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FLORGES
# 396 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_ne EscapeRoom_MapScripts_CheckZeraPredamageStep_12
# 397 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_ne EscapeRoom_MapScripts_CheckZeraPredamageStep_12
	goto EscapeRoom_MapScripts_CheckZeraPredamageStep_1

EscapeRoom_MapScripts_CheckZeraPredamageStep_3:
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLAG_ZERA_PREDAMAGE_SUCCES, EscapeRoom_MapScripts_CheckZeraPredamageStep_2
	goto EscapeRoom_MapScripts_CheckZeraPredamageStep_1

EscapeRoom_MapScripts_CheckZeraPredamageStep_6:
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_PREDAMAGE_COMPLETED
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_7:
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POKE_BALL_OBTAINED, EscapeRoom_MapScripts_CheckZeraPredamageStep_6
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_8:
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLAG_ZERA_BLOCK_SUCCES, EscapeRoom_MapScripts_CheckZeraPredamageStep_7
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_12:
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_MapScripts_CheckZeraPredamageStep_1


EscapeRoom_MapScripts_CheckRareCandyReviveStep::
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 3
	goto_if_eq EscapeRoom_MapScripts_CheckRareCandyReviveStep_3
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_1:
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_REVIVE_COMPLETED
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_LIEPARD
	goto_if_ne EscapeRoom_MapScripts_CheckRareCandyReviveStep_7
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_2:
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY1_OBTAINED, EscapeRoom_MapScripts_CheckRareCandyReviveStep_1
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_3:
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_MapScripts_CheckRareCandyReviveStep_2
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_7:
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 425 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 426 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 466 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 467 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 471 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 472 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 476 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 477 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 559 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 562 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 565 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 572 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 585 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 600 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIcePuzzleItemReturns::
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_JUST_ESCAPED_ICE_PUZZLE, 0
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SS_TICKET_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_4:
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11:
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2:
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SS_TICKET
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_9
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_5:
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 629 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16:
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26:
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM43
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_36:
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_43
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_AUTOCLOSE
# 654 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42:
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_4

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_5
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_4

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_9:
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SS_TICKET
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_EASTER_EGG_SS_TICKET
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SSTicketReturned, MSGBOX_AUTOCLOSE
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12:
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21:
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_33
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RARE_CANDY
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_40
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_39:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_47
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_AUTOCLOSE
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_46:
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RARE_CANDY2_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13:
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17:
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18:
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22:
# 672 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23:
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27:
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28:
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32:
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_33:
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37:
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM43
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_36

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_40:
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_RARE_CANDY
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_39

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_43:
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_DEFAULT
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoSecretPowerTeach
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_47:
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_DEFAULT
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy_IcePuzzle
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_46


EscapeRoom_MapScript_GameStartScripts::
# 711 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 724 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
# 729 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_SS_TICKET
# 730 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_WALL_SIGN
	return


EscapeRoom_MapScript_GetPokedex::
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 737 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 803 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 804 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 805 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 806 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 857 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 852 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 864 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 870 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 868 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 878 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 902 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 913 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 935 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MainSignWhatToRead, MSGBOX_MAIN_SIGN
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_3
EscapeRoom_EventScript_MainInfoSign_1:
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_MainInfoSign_6
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_MainInfoSign_7
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetGameCompletion
# 948 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessage, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_3:
# 954 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 955 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_11
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_6:
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageInitial, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_7:
# 943 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageFinal, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_11:
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 958 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_GetGameCompletion::
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 0
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_GetGameCompletion_2
EscapeRoom_EventScript_GetGameCompletion_1:
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_GetGameCompletion_5
EscapeRoom_EventScript_GetGameCompletion_4:
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_8
EscapeRoom_EventScript_GetGameCompletion_7:
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_11
EscapeRoom_EventScript_GetGameCompletion_10:
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_14
EscapeRoom_EventScript_GetGameCompletion_13:
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_17
EscapeRoom_EventScript_GetGameCompletion_16:
# 1001 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_20
EscapeRoom_EventScript_GetGameCompletion_19:
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_23
EscapeRoom_EventScript_GetGameCompletion_22:
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_GetGameCompletion_26
EscapeRoom_EventScript_GetGameCompletion_25:
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_29
EscapeRoom_EventScript_GetGameCompletion_28:
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_GetGameCompletion_32
EscapeRoom_EventScript_GetGameCompletion_31:
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_GetGameCompletion_35
EscapeRoom_EventScript_GetGameCompletion_34:
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_38
EscapeRoom_EventScript_GetGameCompletion_37:
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_GetGameCompletion_41
EscapeRoom_EventScript_GetGameCompletion_40:
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_GetGameCompletion_44
EscapeRoom_EventScript_GetGameCompletion_43:
# 1049 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_47
EscapeRoom_EventScript_GetGameCompletion_46:
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_GetGameCompletion_50
EscapeRoom_EventScript_GetGameCompletion_49:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_53
EscapeRoom_EventScript_GetGameCompletion_52:
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_56
EscapeRoom_EventScript_GetGameCompletion_55:
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_59
EscapeRoom_EventScript_GetGameCompletion_58:
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_GetGameCompletion_62
EscapeRoom_EventScript_GetGameCompletion_61:
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_65
EscapeRoom_EventScript_GetGameCompletion_64:
# 1087 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_68
EscapeRoom_EventScript_GetGameCompletion_67:
# 1092 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_70
	return

EscapeRoom_EventScript_GetGameCompletion_2:
# 972 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 2
	goto EscapeRoom_EventScript_GetGameCompletion_1

EscapeRoom_EventScript_GetGameCompletion_5:
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 8
	goto EscapeRoom_EventScript_GetGameCompletion_4

EscapeRoom_EventScript_GetGameCompletion_8:
# 982 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 12
	goto EscapeRoom_EventScript_GetGameCompletion_7

EscapeRoom_EventScript_GetGameCompletion_11:
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 18
	goto EscapeRoom_EventScript_GetGameCompletion_10

EscapeRoom_EventScript_GetGameCompletion_14:
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 20
	goto EscapeRoom_EventScript_GetGameCompletion_13

EscapeRoom_EventScript_GetGameCompletion_17:
# 997 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 23
	goto EscapeRoom_EventScript_GetGameCompletion_16

EscapeRoom_EventScript_GetGameCompletion_20:
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 28
	goto EscapeRoom_EventScript_GetGameCompletion_19

EscapeRoom_EventScript_GetGameCompletion_23:
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 33
	goto EscapeRoom_EventScript_GetGameCompletion_22

EscapeRoom_EventScript_GetGameCompletion_26:
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 35
	goto EscapeRoom_EventScript_GetGameCompletion_25

EscapeRoom_EventScript_GetGameCompletion_29:
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 41
	goto EscapeRoom_EventScript_GetGameCompletion_28

EscapeRoom_EventScript_GetGameCompletion_32:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 44
	goto EscapeRoom_EventScript_GetGameCompletion_31

EscapeRoom_EventScript_GetGameCompletion_35:
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 46
	goto EscapeRoom_EventScript_GetGameCompletion_34

EscapeRoom_EventScript_GetGameCompletion_38:
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 49
	goto EscapeRoom_EventScript_GetGameCompletion_37

EscapeRoom_EventScript_GetGameCompletion_41:
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 55
	goto EscapeRoom_EventScript_GetGameCompletion_40

EscapeRoom_EventScript_GetGameCompletion_44:
# 1045 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 57
	goto EscapeRoom_EventScript_GetGameCompletion_43

EscapeRoom_EventScript_GetGameCompletion_47:
# 1050 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 63
	goto EscapeRoom_EventScript_GetGameCompletion_46

EscapeRoom_EventScript_GetGameCompletion_50:
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 68
	goto EscapeRoom_EventScript_GetGameCompletion_49

EscapeRoom_EventScript_GetGameCompletion_53:
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 73
	goto EscapeRoom_EventScript_GetGameCompletion_52

EscapeRoom_EventScript_GetGameCompletion_56:
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 78
	goto EscapeRoom_EventScript_GetGameCompletion_55

EscapeRoom_EventScript_GetGameCompletion_59:
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 84
	goto EscapeRoom_EventScript_GetGameCompletion_58

EscapeRoom_EventScript_GetGameCompletion_62:
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 89
	goto EscapeRoom_EventScript_GetGameCompletion_61

EscapeRoom_EventScript_GetGameCompletion_65:
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 91
	goto EscapeRoom_EventScript_GetGameCompletion_64

EscapeRoom_EventScript_GetGameCompletion_68:
# 1088 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 95
	goto EscapeRoom_EventScript_GetGameCompletion_67

EscapeRoom_EventScript_GetGameCompletion_70:
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 100
	return


EscapeRoom_EventScript_MoveDeleterSign::
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 1102 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 1109 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
EscapeRoom_EventScript_EndSign_1:
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 1129 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_END_ESCAPE_ROOM_STATE, 2
# 1113 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_Heal_Pokemon_Nurse1::
# 1140 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 1155 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1173 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_2
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_5
# 1188 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage_Finale, MSGBOX_HINTNPC
EscapeRoom_EventScript_HintsNPC_4:
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_9
# 1194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_10
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_HintsNPC_11
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_8:
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsFinalMessage, MSGBOX_AUTOCLOSE
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HintsNPC_5:
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_HINTNPC
	goto EscapeRoom_EventScript_HintsNPC_4

EscapeRoom_EventScript_HintsNPC_9:
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_SmallHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_10:
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_LargeHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_11:
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_Solution
	goto EscapeRoom_EventScript_HintsNPC_8


EscapeRoom_EventScript_HintsNPC_SmallHint::
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_SmallHint_2
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_3
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_4
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_5
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_6
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_SmallHint_7
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_8
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_9
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_10
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_11
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_12
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_SmallHint_13
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_14
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_SmallHint_15
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_16
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_17
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_18
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_SmallHint_19
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_20
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_21
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_SmallHint_22
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_23
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_24
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_25
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_EVOLUTION_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_26
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_27
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_SmallHint_37
EscapeRoom_EventScript_HintsNPC_SmallHint_36:
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_29
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_30
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_31
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_32
EscapeRoom_EventScript_HintsNPC_SmallHint_1:
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_71
EscapeRoom_EventScript_HintsNPC_SmallHint_70:
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_68
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_SmallHint_66:
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_SmallHint_2:
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_SmallHint
# 1213 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SMALL_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_3:
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_SmallHint
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_SMALL_HINT, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_4:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_SmallHint
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_COMPLETED_SMALL_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_5:
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_SmallHint
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERAORA_CAUGHT_SMALL_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_6:
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_SmallHint
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SMALL_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_7:
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_SmallHint
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SMALL_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_8:
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_SmallHint
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SMALL_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_9:
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_SmallHint
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SMALL_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_10:
# 1251 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_SmallHint
# 1252 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SMALL_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_11:
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_SmallHint
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SMALL_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_12:
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_SmallHint
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SMALL_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_13:
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_SmallHint
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SMALL_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_14:
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_SmallHint
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SMALL_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_15:
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_SmallHint
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SMALL_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_16:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_SmallHint
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SMALL_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_17:
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_SmallHint
# 1291 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SMALL_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_18:
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_SmallHint
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SMALL_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_19:
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_SmallHint
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SMALL_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_20:
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_SmallHint
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SMALL_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_21:
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_SmallHint
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SMALL_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_22:
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_SmallHint
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SMALL_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_23:
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_SmallHint
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SMALL_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_24:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_SmallHint
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SMALL_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_25:
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_SmallHint
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SMALL_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_26:
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ApeEvolution_SmallHint
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_APE_EVOLUTION_SMALL_HINT, FLAG_APE_EVOLUTION_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_27:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_SmallHint
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SMALL_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_28:
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_SmallHint
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SMALL_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_29:
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_SmallHint
# 1355 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SMALL_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_30:
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_SmallHint
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SMALL_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_31:
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_SmallHint
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SMALL_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_32:
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_SmallHint
# 1370 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SMALL_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_37:
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_28
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_36

EscapeRoom_EventScript_HintsNPC_SmallHint_67:
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_75
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
EscapeRoom_EventScript_HintsNPC_SmallHint_74:
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SMALL_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_66

EscapeRoom_EventScript_HintsNPC_SmallHint_68:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_66

EscapeRoom_EventScript_HintsNPC_SmallHint_71:
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_67
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_70

EscapeRoom_EventScript_HintsNPC_SmallHint_75:
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 15
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC15minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_74


EscapeRoom_EventScript_HintsNPC_LargeHint::
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_LargeHint_2
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_3
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_4
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_5
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_6
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_LargeHint_7
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_8
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_9
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_10
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_11
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_12
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_LargeHint_13
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_14
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_LargeHint_15
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_16
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_17
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_18
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_LargeHint_19
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_20
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_21
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_LargeHint_22
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_23
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_24
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_25
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_EVOLUTION_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_26
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_27
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_LargeHint_37
EscapeRoom_EventScript_HintsNPC_LargeHint_36:
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_29
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_30
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_31
# 1569 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_32
EscapeRoom_EventScript_HintsNPC_LargeHint_1:
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_71
EscapeRoom_EventScript_HintsNPC_LargeHint_70:
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_68
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1600 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_LargeHint_66:
# 1604 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_LargeHint_2:
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_LargeHint
# 1414 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_LARGE_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_3:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_LargeHint
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_LARGE_HINT, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_4:
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_LargeHint
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_LARGE_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_5:
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_LargeHint
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_LARGE_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_6:
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_LargeHint
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_LARGE_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_7:
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_LargeHint
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_LARGE_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_8:
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_LargeHint
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_LARGE_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_9:
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_LargeHint
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_LARGE_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_10:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_LargeHint
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_LARGE_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_11:
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_LargeHint
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_LARGE_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_12:
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_LargeHint
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_LARGE_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_13:
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_LargeHint
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_LARGE_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_14:
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_LargeHint
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_LARGE_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_15:
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_LargeHint
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_LARGE_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_16:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_LargeHint
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_LARGE_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_17:
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_LargeHint
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_LARGE_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_18:
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_LargeHint
# 1497 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_LARGE_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_19:
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_LargeHint
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_LARGE_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_20:
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_LargeHint
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_LARGE_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_21:
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_LargeHint
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_LARGE_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_22:
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_LargeHint
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_LARGE_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_23:
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_LargeHint
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_LARGE_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_24:
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_LargeHint
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_LARGE_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_25:
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_LargeHint
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_LARGE_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_26:
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ApeEvolution_LargeHint
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_APE_EVOLUTION_LARGE_HINT, FLAG_APE_EVOLUTION_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_27:
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_LargeHint
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_LARGE_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_28:
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_LargeHint
# 1551 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_LARGE_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_29:
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_LargeHint
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_LARGE_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_30:
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_LargeHint
# 1561 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_LARGE_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_31:
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_LargeHint
# 1566 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_LARGE_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_32:
# 1570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_LargeHint
# 1571 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_LARGE_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_37:
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_28
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_36

EscapeRoom_EventScript_HintsNPC_LargeHint_67:
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_75
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
EscapeRoom_EventScript_HintsNPC_LargeHint_74:
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_LARGE_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_66

EscapeRoom_EventScript_HintsNPC_LargeHint_68:
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_66

EscapeRoom_EventScript_HintsNPC_LargeHint_71:
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_67
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_70

EscapeRoom_EventScript_HintsNPC_LargeHint_75:
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_74


EscapeRoom_EventScript_HintsNPC_Solution::
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_Solution_2
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_3
# 1621 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_4
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_Solution_5
# 1637 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_6
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_Solution_7
# 1647 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_8
# 1658 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_9
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_10
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_11
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_12
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_Solution_13
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_14
# 1698 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_Solution_15
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_16
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_17
# 1713 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_Solution_18
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_Solution_19
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_20
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_21
# 1745 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_Solution_22
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_23
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_24
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_25
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_EVOLUTION_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_26
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_27
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_Solution_37
EscapeRoom_EventScript_HintsNPC_Solution_36:
# 1790 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_29
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_30
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_31
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_32
EscapeRoom_EventScript_HintsNPC_Solution_1:
# 1839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_Solution_67
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_Solution_66:
# 1863 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_Solution_2:
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_Solution
# 1614 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SOLUTION, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_3:
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_Solution
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_SOLUTION, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_4:
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution
# 1623 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_SOLUTION, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_5:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_Solution
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_SOLUTION, FLAG_ZERA_CATCH_SOLUTION
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1632 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_70
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_6:
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_Solution
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SOLUTION, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_7:
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_Solution
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SOLUTION, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_8:
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SOLUTION, FLAG_TRAINER1_SOLUTION
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_72
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_9:
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_Solution
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SOLUTION, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_10:
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_Solution
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SOLUTION, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_11:
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_Solution
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SOLUTION, FLAG_TRAINER3_SOLUTION
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_74
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_12:
# 1680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_Solution
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SOLUTION, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_13:
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_Solution
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SOLUTION, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_14:
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_Solution
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SOLUTION, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_15:
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_Solution
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SOLUTION, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_16:
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_Solution
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SOLUTION, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_17:
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_Solution
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SOLUTION, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_18:
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SOLUTION, FLAG_TRAINER5_SOLUTION
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_76
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_19:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_Solution
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SOLUTION, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_20:
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_Solution
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SOLUTION, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_21:
# 1735 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SOLUTION, FLAG_TRAINER6_SOLUTION
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_78
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_22:
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_Solution
# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SOLUTION, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_23:
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_Solution
# 1756 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SOLUTION, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_24:
# 1760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_Solution
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SOLUTION, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_25:
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SOLUTION, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AskViewExactIcePuzzleSolution, MSGBOX_YESNO
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_80
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_26:
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ApeEvolution_Solution
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_APE_EVOLUTION_SOLUTION, FLAG_APE_EVOLUTION_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_27:
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_Solution
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SOLUTION, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_28:
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_Solution
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SOLUTION, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_29:
# 1791 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SOLUTION, FLAG_SECRET_POWER_SOLUTION
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AskViewExactIcePuzzleSolution, MSGBOX_YESNO
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_83
EscapeRoom_EventScript_HintsNPC_Solution_82:
# 1801 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_91
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_30:
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_Solution
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SOLUTION, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_31:
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_Solution
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SOLUTION, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_32:
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SOLUTION, FLAG_TRAINER11_SOLUTION
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution_MoveSetup, MSGBOX_YESNO
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_85
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_37:
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_28
	goto EscapeRoom_EventScript_HintsNPC_Solution_36

EscapeRoom_EventScript_HintsNPC_Solution_67:
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_88
# 1848 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 120
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC120minAddedMessage
EscapeRoom_EventScript_HintsNPC_Solution_87:
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1854 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SOLUTIONS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_Solution_66

EscapeRoom_EventScript_HintsNPC_Solution_70:
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_72:
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_74:
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox intsNPC_Trainer3_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_76:
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_78:
# 1741 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_80:
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution_IcePuzzleSteps
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_83:
# 1797 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution_IcePuzzleSteps
	goto EscapeRoom_EventScript_HintsNPC_Solution_82

EscapeRoom_EventScript_HintsNPC_Solution_85:
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_93
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_88:
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_Solution_87

EscapeRoom_EventScript_HintsNPC_Solution_91:
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_93:
# 1831 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 1881 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1913 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 1944 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 1951 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_MAX_REVIVE, EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_23
EscapeRoom_EventScript_ReturnLostItems_22:
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_33
EscapeRoom_EventScript_ReturnLostItems_32:
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_42:
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_49
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_49
# 2123 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 2124 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 1946 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 1947 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 1956 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MAX_REVIVE
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 1981 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_28
EscapeRoom_EventScript_ReturnLostItems_26:
# 1994 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_35
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_23:
# 2008 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_22

EscapeRoom_EventScript_ReturnLostItems_25:
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_27:
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_25
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_28:
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_27
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_33:
# 2016 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 2018 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_32

EscapeRoom_EventScript_ReturnLostItems_35:
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_38:
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_47
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_43:
# 2037 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_54:
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_68
EscapeRoom_EventScript_ReturnLostItems_67:
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_81
EscapeRoom_EventScript_ReturnLostItems_80:
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_85
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_44:
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_47:
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 2029 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_49:
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_63
EscapeRoom_EventScript_ReturnLostItems_61:
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_59
EscapeRoom_EventScript_ReturnLostItems_57:
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_70
	return

EscapeRoom_EventScript_ReturnLostItems_55:
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_54

EscapeRoom_EventScript_ReturnLostItems_58:
# 2076 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_72
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_59:
# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_76
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_62:
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_58
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_63:
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_62
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_68:
# 2045 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_67

EscapeRoom_EventScript_ReturnLostItems_70:
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_72:
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2081 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_73:
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2088 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_83
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_76:
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_81:
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_80

EscapeRoom_EventScript_ReturnLostItems_83:
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2094 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_85:
# 2059 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_42


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2138 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 2160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 2166 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 2192 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 2200 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_29
EscapeRoom_EventScript_UndoUsedItems_28:
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 2214 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_32
EscapeRoom_EventScript_UndoUsedItems_31:
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
EscapeRoom_EventScript_UndoUsedItems_34:
# 2228 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_42
EscapeRoom_EventScript_UndoUsedItems_41:
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SECRET_POWER
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 2242 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_44
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 2161 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_ANNIHILAPE
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2182 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 2193 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2194 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_29:
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_28

EscapeRoom_EventScript_UndoUsedItems_32:
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_31

EscapeRoom_EventScript_UndoUsedItems_35:
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_34

EscapeRoom_EventScript_UndoUsedItems_42:
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_41

EscapeRoom_EventScript_UndoUsedItems_44:
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38:
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 2264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21:
# 2291 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 2312 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14
# 2324 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2328 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45:
# 2342 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 2349 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 2356 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 2363 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66:
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72:
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 2381 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 2266 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 2271 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 2281 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSecretPower, OptionUndoRareCandy
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 2303 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 2308 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13:
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14:
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 2264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37:
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41:
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 2335 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 2340 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 2343 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 2336 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2337 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 2350 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 2354 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 2344 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 2351 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 2364 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70:
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73:
# 2371 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79
# 2375 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76:
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79:
# 2372 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 2386 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_5
# 2399 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_6
EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_10
# 2413 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_11
EscapeRoom_EventScript_AskUndoMoveTeach_9:
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2425 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_18
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 2387 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_5:
# 2393 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2394 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_14
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_6:
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 2401 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_16
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_10:
# 2407 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_20
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_11:
# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_22
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_14:
# 2395 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_16:
# 2402 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_18:
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_AskUndoMoveTeach_20:
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_22:
# 2416 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9


EscapeRoom_EventScript_UndoMoveTeach::
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2436 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 2458 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 2461 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_10:
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 2501 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
# 2507 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_32:
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2516 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2517 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_46
EscapeRoom_EventScript_UndoMoveTeach_45:
# 2527 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_57
EscapeRoom_EventScript_UndoMoveTeach_55:
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_53:
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_65
EscapeRoom_EventScript_UndoMoveTeach_64:
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_74
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 2438 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 2444 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_23
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 2442 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, VAR_0x8008
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 2445 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, VAR_0x8008
# 2471 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_23:
# 2448 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_26:
# 2478 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
# 2484 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_41
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_33:
# 2505 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 2508 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM43
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_35:
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_39:
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_40:
# 2487 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
# 2491 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 2495 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_41:
# 2484 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_40
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_46:
# 2521 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_45

EscapeRoom_EventScript_UndoMoveTeach_49:
# 2488 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2489 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 2492 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_56:
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_57:
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_56
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_62:
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_69
EscapeRoom_EventScript_UndoMoveTeach_67:
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_85
EscapeRoom_EventScript_UndoMoveTeach_83:
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 2573 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_94
EscapeRoom_EventScript_UndoMoveTeach_93:
# 2581 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_99
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_65:
# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_80
EscapeRoom_EventScript_UndoMoveTeach_78:
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_90
EscapeRoom_EventScript_UndoMoveTeach_88:
# 2603 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 2605 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_97
EscapeRoom_EventScript_UndoMoveTeach_96:
# 2612 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_101
	goto EscapeRoom_EventScript_UndoMoveTeach_64

EscapeRoom_EventScript_UndoMoveTeach_68:
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2563 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_69:
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_68
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_72:
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 2624 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 2626 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 2627 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_73:
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_72
	return

EscapeRoom_EventScript_UndoMoveTeach_74:
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_73
	return

EscapeRoom_EventScript_UndoMoveTeach_79:
# 2593 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2594 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_80:
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_79
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_84:
# 2567 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_85:
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_84
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_89:
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_90:
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_89
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_94:
# 2575 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2576 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 2577 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_93

EscapeRoom_EventScript_UndoMoveTeach_97:
# 2606 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2607 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 2608 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_96

EscapeRoom_EventScript_UndoMoveTeach_99:
# 2582 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 2583 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_101:
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_64


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 2638 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 2642 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 2650 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 2645 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 2646 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 2657 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 2661 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 2664 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 2668 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 2683 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 2692 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 2706 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 2709 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2710 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_31
EscapeRoom_EventScript_UndoRareCandy_30:
# 2735 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 2745 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 2753 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
EscapeRoom_EventScript_UndoRareCandy_27:
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_36
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
# 2845 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_38
EscapeRoom_EventScript_UndoRareCandy_35:
# 2851 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2852 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_48
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2685 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 2693 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2694 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 2687 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 2714 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2717 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_33
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 2764 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2765 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_43
EscapeRoom_EventScript_UndoRareCandy_42:
# 2774 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2775 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_51
EscapeRoom_EventScript_UndoRareCandy_50:
# 2786 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2787 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_59
EscapeRoom_EventScript_UndoRareCandy_58:
# 2799 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_68
EscapeRoom_EventScript_UndoRareCandy_66:
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_77
EscapeRoom_EventScript_UndoRareCandy_75:
# 2835 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_31:
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2728 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2729 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 2732 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_30

EscapeRoom_EventScript_UndoRareCandy_33:
# 2700 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_36:
# 2840 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_37:
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_38:
# 2846 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_43:
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2771 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_42

EscapeRoom_EventScript_UndoRareCandy_46:
# 2737 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2740 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_48:
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_55
EscapeRoom_EventScript_UndoRareCandy_54:
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 2889 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_64
	return

EscapeRoom_EventScript_UndoRareCandy_51:
# 2778 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2779 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2780 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_50

EscapeRoom_EventScript_UndoRareCandy_53:
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 2859 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_61
# 2877 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2880 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_73
	return

EscapeRoom_EventScript_UndoRareCandy_55:
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_53
	goto EscapeRoom_EventScript_UndoRareCandy_54

EscapeRoom_EventScript_UndoRareCandy_59:
# 2791 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_58

EscapeRoom_EventScript_UndoRareCandy_61:
# 2862 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2863 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_71
	return

EscapeRoom_EventScript_UndoRareCandy_64:
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005, reverse = FALSE
# 2892 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2893 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_67:
# 2810 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2811 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2815 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_68:
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_67
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_71:
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2866 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2870 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_73:
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return

EscapeRoom_EventScript_UndoRareCandy_76:
# 2823 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2824 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2827 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2828 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2831 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_75

EscapeRoom_EventScript_UndoRareCandy_77:
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_76
	goto EscapeRoom_EventScript_UndoRareCandy_75


EscapeRoom_EventScript_UndoExpCandy::
# 2906 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 2907 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2910 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 2911 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 2916 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 2919 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2920 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2921 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2922 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 2923 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2926 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 2934 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_20
EscapeRoom_EventScript_UndoOtherActions_17:
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_16
EscapeRoom_EventScript_UndoOtherActions_14:
# 2951 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_13
EscapeRoom_EventScript_UndoOtherActions_11:
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_10
EscapeRoom_EventScript_UndoOtherActions_8:
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_UndoOtherActions_7
EscapeRoom_EventScript_UndoOtherActions_6:
# 2989 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 2990 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_24
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 2944 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 2945 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_26
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 2952 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 2953 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_28
	return

EscapeRoom_EventScript_UndoOtherActions_4:
# 2963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_UndoOtherActions_30
# 2971 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoDunsparceTrade, MSGBOX_YESNO
# 2972 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_35
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 2980 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoIcePuzzleRareCandy, MSGBOX_YESNO
# 2981 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_33
	return

EscapeRoom_EventScript_UndoOtherActions_7:
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_5
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_10:
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_UndoOtherActions_4
	goto EscapeRoom_EventScript_UndoOtherActions_8

EscapeRoom_EventScript_UndoOtherActions_13:
# 2951 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_11

EscapeRoom_EventScript_UndoOtherActions_16:
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_14

EscapeRoom_EventScript_UndoOtherActions_19:
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_17

EscapeRoom_EventScript_UndoOtherActions_20:
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_19
	goto EscapeRoom_EventScript_UndoOtherActions_17

EscapeRoom_EventScript_UndoOtherActions_24:
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_26:
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_28:
# 2954 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return

EscapeRoom_EventScript_UndoOtherActions_30:
# 2964 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 2965 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_33:
# 2982 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoIcePuzzleRareCandy
	return

EscapeRoom_EventScript_UndoOtherActions_35:
# 2973 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoDunsparceTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 2999 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3002 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 3005 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 3009 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 3013 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 3021 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 3027 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 3028 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 3006 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 3007 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 3010 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 3011 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 3014 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 3015 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 3019 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 3022 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 3023 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 3033 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 3034 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 3045 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 3046 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3047 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3050 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 3035 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 3036 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 3063 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 3064 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 3065 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 3068 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 3069 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3070 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3073 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 3057 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 3058 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_UndoDunsparceTrade::
# 3078 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_TAUNT
# 3079 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_2
EscapeRoom_EventScript_UndoDunsparceTrade_1:
# 3084 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_TAUNT
# 3085 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_5
EscapeRoom_EventScript_UndoDunsparceTrade_4:
# 3092 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3093 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_9
EscapeRoom_EventScript_UndoDunsparceTrade_7:
# 3096 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3097 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_14
EscapeRoom_EventScript_UndoDunsparceTrade_12:
# 3100 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM12
# 3101 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_18
EscapeRoom_EventScript_UndoDunsparceTrade_17:
# 3107 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_DUNSPARCE
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedDunsparceMessage
# 3111 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3112 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoDunsparceTrade_2:
# 3080 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 3081 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_TAUNT
# 3082 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoDunsparceTrade_1

EscapeRoom_EventScript_UndoDunsparceTrade_5:
# 3086 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 3087 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_TAUNT
# 3088 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoDunsparceTrade_4

EscapeRoom_EventScript_UndoDunsparceTrade_8:
# 3094 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoDunsparceTrade_7

EscapeRoom_EventScript_UndoDunsparceTrade_9:
# 3093 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM12
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_8
	goto EscapeRoom_EventScript_UndoDunsparceTrade_7

EscapeRoom_EventScript_UndoDunsparceTrade_13:
# 3098 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoDunsparceTrade_12

EscapeRoom_EventScript_UndoDunsparceTrade_14:
# 3097 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM12
	goto_if_eq EscapeRoom_EventScript_UndoDunsparceTrade_13
	goto EscapeRoom_EventScript_UndoDunsparceTrade_12

EscapeRoom_EventScript_UndoDunsparceTrade_18:
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM12
	goto EscapeRoom_EventScript_UndoDunsparceTrade_17


EscapeRoom_EventScript_UndoIcePuzzleRareCandy::
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RARE_CANDY2_COMPLETED
# 3120 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIcePuzzleItemReturns
	return


EscapeRoom_EventScript_LiepardNPC::
# 3127 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3128 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3131 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 3132 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 3133 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 3134 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3137 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 3138 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 3140 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3141 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 3143 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3144 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3145 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3148 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3149 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 3150 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3151 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3152 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3155 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 3156 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3159 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3161 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 3162 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3164 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3165 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 3166 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3167 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3168 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3170 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3171 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3173 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 3174 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3177 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 3178 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 3179 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 3183 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3185 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 3186 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 3196 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 3198 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3199 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3200 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3201 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 3202 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 3210 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 3214 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 3204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3205 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 3227 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 3227 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 3229 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 3230 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3232 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 3233 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 3236 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3238 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 3243 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3244 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 3266 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 3268 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3269 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 3272 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 3283 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 3273 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3278 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 3292 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3293 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 3294 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3295 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3298 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 3299 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 3300 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3303 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 3304 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3305 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 3306 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3307 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 3308 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3311 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 3312 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3313 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3314 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 3321 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 3325 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 3326 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 3329 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3332 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3333 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 3335 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 3336 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3337 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3339 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 3347 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3348 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 3350 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3351 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 3352 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 3353 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 3359 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 3361 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 3362 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 3363 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 3370 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3371 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 3384 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 3390 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 3397 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 3398 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 3375 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3377 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 3385 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 3386 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 3387 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 3391 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 3392 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 3403 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 3404 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 3407 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 3408 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 3413 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 3417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 3431 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 3446 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 3447 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 3461 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 3418 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3420 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 3423 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3424 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3425 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3434 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3435 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 3438 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3439 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3440 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3442 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 3448 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3450 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 3453 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3454 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3456 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3457 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 3463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 3464 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3470 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 3471 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3472 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 3473 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3474 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 3475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3484 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 3497 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 3498 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 3514 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 3485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 3493 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 3486 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 3487 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3488 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3489 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 3490 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 3521 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 3523 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3524 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 3525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3526 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3534 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 3535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3536 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 3540 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3543 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3547 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 3548 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3551 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 3552 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3555 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 3556 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 3558 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 3559 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3562 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 3566 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 3569 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_AIPOM, MOVE_TAUNT
# 3575 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3576 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3577 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3578 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3580 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3581 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3583 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 3584 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3585 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 3586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3587 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 3589 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3590 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3591 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3592 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 3597 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 3598 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3599 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3602 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 3603 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3604 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 3606 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3608 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 3615 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 3624 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3625 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 3631 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3632 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 3638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 3639 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 3642 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 3619 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 3620 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 3626 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 3633 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 3646 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3647 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 3649 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 3664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 3650 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 3651 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 3652 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3653 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3656 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3658 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SUN_STONE_SOLD
# 3660 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 3661 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 3673 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 3682 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3683 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 3674 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 3675 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
# 3676 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 3678 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_IronBall, MSGBOX_NPC
# 3679 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoSecretPowerTeach::
# 3693 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_2
EscapeRoom_EventScript_UndoSecretPowerTeach_1:
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_5
EscapeRoom_EventScript_UndoSecretPowerTeach_4:
# 3709 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_10
EscapeRoom_EventScript_UndoSecretPowerTeach_9:
# 3720 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 3721 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_13
EscapeRoom_EventScript_UndoSecretPowerTeach_12:
# 3728 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_SECRET_POWER
# 3729 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_SECRET_POWER, VAR_0x8004
# 3730 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_SECRET_POWER
# 3733 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
# 3733 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
EscapeRoom_EventScript_UndoSecretPowerTeach_17:
# 3737 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
# 3737 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
EscapeRoom_EventScript_UndoSecretPowerTeach_22:
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
EscapeRoom_EventScript_UndoSecretPowerTeach_27:
# 3770 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
# 3770 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
EscapeRoom_EventScript_UndoSecretPowerTeach_32:
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
EscapeRoom_EventScript_UndoSecretPowerTeach_43:
# 3793 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3794 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 3797 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSecretPowerTeach_2:
# 3695 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3698 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3699 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_7
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_5:
# 3706 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_4

EscapeRoom_EventScript_UndoSecretPowerTeach_7:
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_10:
# 3711 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_15
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_13:
# 3722 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_12

EscapeRoom_EventScript_UndoSecretPowerTeach_15:
# 3716 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_18:
# 3734 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3735 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_17

EscapeRoom_EventScript_UndoSecretPowerTeach_23:
# 3738 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3739 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_22

EscapeRoom_EventScript_UndoSecretPowerTeach_28:
# 3746 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_37
# 3752 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_39
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_33:
# 3771 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 3772 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_49
EscapeRoom_EventScript_UndoSecretPowerTeach_48:
# 3775 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3776 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_59
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_37:
# 3749 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_38:
# 3755 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_52
# 3759 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_53
EscapeRoom_EventScript_UndoSecretPowerTeach_51:
# 3763 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_39:
# 3752 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_38
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_44:
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 3783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_57
EscapeRoom_EventScript_UndoSecretPowerTeach_56:
# 3786 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3787 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_61
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43

EscapeRoom_EventScript_UndoSecretPowerTeach_49:
# 3773 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_48

EscapeRoom_EventScript_UndoSecretPowerTeach_52:
# 3756 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3757 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_53:
# 3760 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3761 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_57:
# 3784 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_56

EscapeRoom_EventScript_UndoSecretPowerTeach_59:
# 3777 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_61:
# 3788 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43


EscapeRoom_EventScript_UndoRareCandy_IcePuzzle::
# 3802 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 3803 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 3806 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2
# 3810 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1:
# 3816 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5:
# 3825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8:
# 3839 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3840 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15:
# 3854 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24:
# 3865 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_34:
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_AUTOCLOSE
# 3876 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13:
# 3880 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 3883 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21:
# 3969 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 3973 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 3974 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2:
# 3807 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6:
# 3817 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9:
# 3826 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3827 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11:
# 3820 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14:
# 3844 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 3845 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3846 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3847 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_AUTOCLOSE
# 3848 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16:
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19:
# 3830 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 3831 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22:
# 3894 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3895 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_31:
# 3904 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3905 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_40
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39:
# 3916 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3917 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42:
# 3929 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 3937 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_45:
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_52
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_50:
# 3965 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25:
# 3856 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3857 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3858 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 3862 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27:
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29:
# 3977 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 3978 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_37
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32:
# 3898 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3899 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3900 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3901 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3902 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_31

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35:
# 3867 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3868 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3869 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3870 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 3873 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_34

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_37:
# 3980 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005, reverse = FALSE
# 3981 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 3982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3985 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 3986 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_40:
# 3908 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3909 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3910 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3911 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3912 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43:
# 3921 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3922 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3923 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46:
# 3940 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3941 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3944 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3945 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3946 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3947 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3948 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_45

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47:
# 3938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_45

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_51:
# 3953 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3954 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3957 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3958 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3959 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3960 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3961 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_50

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_52:
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_51
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_50


EscapeRoom_EventScript_CheckRareCandy2Stolen::
# 3992 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 3993 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_EventScript_CheckRareCandy2Stolen_2
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_1:
# 3994 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_COMPLETED
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_2:
# 3993 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_CheckRareCandy2Stolen_1
	return


EscapeRoom_AnnihilapeHintNPC::
# 4002 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4005 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 4017 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 4018 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 4020 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 4006 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 4007 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4008 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 4009 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4010 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 4011 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4012 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 4013 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 4024 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4025 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 4028 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 4032 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 4034 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 4026 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 4029 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer0::
# 4041 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 4048 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 4049 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer1::
# 4054 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4055 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 4064 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 4068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 4069 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 4065 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 4074 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 4080 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 4081 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 4086 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4087 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 4094 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 4095 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 4100 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 4106 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 4107 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 4114 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 4115 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 4123 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 4132 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 4139 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 4140 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 4116 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4117 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 4118 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 4115 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 4124 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 4125 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 4126 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 4127 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 4128 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 4145 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 4152 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 4153 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 4158 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 4165 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 4166 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 4171 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 4178 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 4179 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 4184 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 4192 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4193 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_Trainer8_2
EscapeRoom_EventScript_Trainer8_1:
# 4197 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4198 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer8_2:
# 4194 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4195 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8_1


EscapeRoom_EventScript_Trainer9::
# 4203 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 4210 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 4211 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 4216 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 4223 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 4224 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 4230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_Trainer11_2
EscapeRoom_EventScript_Trainer11_1:
# 4236 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 4244 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4245 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4246 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_Trainer11_5
# 4251 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FINAL_MESSAGE_READ, EscapeRoom_EventScript_Trainer11_9
EscapeRoom_EventScript_Trainer11_8:
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SS_TICKET
# 4260 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer11_11
# 4266 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_EndTheGame, MSGBOX_YESNO
# 4267 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_Trainer11_14
EscapeRoom_EventScript_Trainer11_4:
# 4273 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer11_2:
# 4231 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4232 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
	goto EscapeRoom_EventScript_Trainer11_1

EscapeRoom_EventScript_Trainer11_5:
# 4247 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_A, MSGBOX_AUTOCLOSE
# 4248 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer11_4

EscapeRoom_EventScript_Trainer11_9:
# 4252 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FINAL_MESSAGE_READ
# 4253 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_B, MSGBOX_AUTOCLOSE
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4255 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
	goto EscapeRoom_EventScript_Trainer11_8

EscapeRoom_EventScript_Trainer11_11:
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AlternativeEnding
	goto EscapeRoom_EventScript_Trainer11_4

EscapeRoom_EventScript_Trainer11_14:
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4269 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame
	goto EscapeRoom_EventScript_Trainer11_4


EscapeRoom_EventScript_PostMatchHeal::
# 4280 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4288 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 4303 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 4304 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 4289 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4290 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 4293 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 4297 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4298 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 4291 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 4295 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 4299 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 4309 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4312 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4313 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4314 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 4322 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 4325 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 4331 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4332 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4333 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4334 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4335 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4336 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 4337 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4338 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 4339 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 4340 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 4349 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4350 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 4352 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 4315 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4316 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 4342 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4343 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4344 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 4339 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 4339 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 4317 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4318 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4362 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4363 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4364 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 4371 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 4372 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4375 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 4382 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4383 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 4384 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4385 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4386 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 4392 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 4365 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4366 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 4388 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4389 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4390 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 4367 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4368 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 4398 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4401 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 4404 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4405 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 4408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 4413 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 4415 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4416 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 4417 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4418 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4421 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 4424 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 4427 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4434 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 4436 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4437 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4438 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 4444 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 4406 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 4409 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 4440 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4441 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4442 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 4448 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 4449 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 4450 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4450 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4451 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 4455 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 4456 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4461 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4462 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4463 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4464 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4465 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 4466 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 4467 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 4473 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 4476 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 4469 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4470 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 4467 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 4481 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4484 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 4496 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 4508 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 4520 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 4532 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 4543 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 4544 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 4485 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4486 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 4489 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4490 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 4497 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4498 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 4501 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4502 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 4487 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 4509 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4510 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_IRON_BALL
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 4513 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4514 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_IRON_BALL
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 4499 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 4491 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 4521 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4522 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 4525 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4526 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 4511 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 4503 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 4533 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4534 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 4537 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4538 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 4523 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 4515 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 4535 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 4527 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 4539 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 4549 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4552 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 4555 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 4556 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4557 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 4565 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 4566 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4567 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 4577 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4580 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 4587 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4588 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4589 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4592 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 4593 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4594 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 4595 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 4597 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 4598 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 4599 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 4600 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 4602 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 4603 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4604 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 4605 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4606 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_IRON_BALL
# 4607 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 4608 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 4609 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 4611 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 4612 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 4613 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 4614 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 4616 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4618 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4619 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4620 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4622 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4623 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4624 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4625 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4627 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4629 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4631 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 4558 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4559 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 4568 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4569 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 4560 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 4633 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4634 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4635 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4636 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 4570 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4571 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 4641 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 4642 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4647 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 4648 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 4649 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 4655 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 4651 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4652 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4653 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 4659 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 4660 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4662 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4664 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4665 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 4670 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 4671 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4678 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4679 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4680 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 4681 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4682 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4683 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 4684 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 4692 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_CUT
# 4695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4696 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4697 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4699 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 4686 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4687 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4688 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 4703 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 4704 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4707 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 4715 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4716 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4717 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4718 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4719 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4720 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4722 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 4728 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 4724 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4726 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 4732 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 4733 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4736 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 4745 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4746 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4747 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4748 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4749 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 35
# 4750 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4750 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_BAGON
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 4751 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4752 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4753 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4754 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4755 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 4761 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 4757 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4758 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4759 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 4765 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 4766 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4768 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4771 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4774 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_FINAL_BATTLE_REACHED, 1
# 4775 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_END_ESCAPE_ROOM_STATE, 1
# 4778 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer11End
# 4779 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4782 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxy 5, 3, 34
# 4783 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4784 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 5
# 4785 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_CHAMPION
# 4788 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 4789 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 4790 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 4791 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 4793 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 4797 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer11End:
# 4798 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
	step_end

EscapeRoom_EventScript_TradeZeraForHMCut::
# 4806 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4807 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 4808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 4834 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 4836 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 4811 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4812 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4813 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 4822 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 4825 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4827 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4830 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 4831 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 4815 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4816 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4817 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 4840 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4841 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4844 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 4869 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 4870 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 4927 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 4928 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 4931 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 4863 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 4864 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 4873 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 4874 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4875 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 4884 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 4887 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 4888 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4889 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4891 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4894 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4895 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4896 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4899 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 4900 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 4922 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 4877 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4878 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4879 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 4936 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4937 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4940 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 4965 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 4966 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 5000 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 5001 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 5004 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 4959 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 4960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 4969 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4970 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4971 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 4980 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 4983 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 4984 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4985 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4986 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4989 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4990 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4991 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4994 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 4995 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 4996 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 4973 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4974 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4975 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 5008 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 5009 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 5012 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 5018 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 5019 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 5051 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 5052 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 5055 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 5013 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 5014 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 5022 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 5023 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 5024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 5033 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_DUNSPARCE
# 5036 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 5037 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5038 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 5041 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 5042 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 5043 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5046 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 5047 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 5026 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 5027 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5028 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_GetChoiceItem::
# 5063 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetChoiceItem_1
# 5108 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsNoLongerAvailable, MSGBOX_DEFAULT
# 5109 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_1:
# 5066 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsWhichOne, MSGBOX_DEFAULT
# 5067 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5070 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionChoiceBand, OptionChoiceSpecs, OptionChoiceScarf
# 5073 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_5
# 5076 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_6
# 5079 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_7
# 5083 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsComeAgain, MSGBOX_DEFAULT
# 5084 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_4:
# 5089 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem
# 5092 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RemoveChoiceItem
# 5095 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem VAR_0x8006
# 5098 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_GetChoiceItem_12
# 5103 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CHOICE_ITEM_OBTAINED
	return

EscapeRoom_EventScript_GetChoiceItem_5:
# 5074 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_BAND
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_6:
# 5077 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SPECS
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_7:
# 5080 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SCARF
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_12:
# 5099 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsSwapped, MSGBOX_DEFAULT
# 5100 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem::
# 5114 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 5117 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem VAR_0x8006
# 5118 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1:
# 5122 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 5123 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4:
# 5130 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 5131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7:
# 5140 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10
	return

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2:
# 5119 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5:
# 5124 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 5125 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual1
# 5126 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 5128 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual1:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8:
# 5132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 5133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual2
# 5134 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 5136 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual2:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10:
# 5141 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsAlreadyHaveThis, MSGBOX_DEFAULT
# 5142 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5143 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_RemoveChoiceItem::
# 5149 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_BAND
# 5150 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SPECS
# 5151 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SCARF
# 5153 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 5154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_3
EscapeRoom_EventScript_RemoveChoiceItem_1:
# 5161 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 5162 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_11
	return

EscapeRoom_EventScript_RemoveChoiceItem_2:
# 5158 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_3:
# 5155 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 5156 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 5157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_10:
# 5166 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	return

EscapeRoom_EventScript_RemoveChoiceItem_11:
# 5163 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 5164 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 5165 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 5174 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5175 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 5176 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 5177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 5178 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 5182 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5183 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 5184 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 5186 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 5190 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5191 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 5192 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 5193 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 5194 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindTMSecretPower::
# 5198 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5199 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_TM43
# 5200 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 5201 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_OBTAINED
# 5202 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy2::
# 5206 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5207 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 5208 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 5209 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 19
# 5212 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 1
# 5214 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRescueBell::
# 5218 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5219 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SOOTHE_BELL
# 5220 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RESCUE_BELL_OBTAINED
# 5221 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 5223 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RescueBellExplainMessage, MSGBOX_AUTOCLOSE
# 5224 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5226 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 5233 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 5244 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet1_Onix, MSGBOX_DEFAULT
# 5247 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 5250 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 5253 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 5256 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 5261 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 5276 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 5237 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5238 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5239 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 5248 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 5251 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 5254 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 5257 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 5262 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5263 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 5264 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5265 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5268 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 5273 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 5269 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 5280 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5283 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 5291 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet2_Toedscruel, MSGBOX_DEFAULT
# 5294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 5297 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 5300 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 5303 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 5308 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 5330 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 5284 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5286 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 5295 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 5298 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 5301 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 5304 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 5309 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5310 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 5311 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5312 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5317 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 28, _face_left
# 5318 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 28
# 5323 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 5328 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 5324 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 5334 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 5345 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet3_Dusknoir, MSGBOX_DEFAULT
# 5348 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 5351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 5354 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 5357 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 5362 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 5376 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 5338 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5339 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5340 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 5349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 5352 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 5355 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 5358 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 5363 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5364 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 5365 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5366 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5369 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 5374 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 5370 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 5380 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5383 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 5391 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 5396 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet4_Dunsparce, MSGBOX_DEFAULT
# 5399 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 5402 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 5405 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 5408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 5413 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 5427 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 5384 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5385 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5386 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 5392 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 5400 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 5403 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 5406 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 5409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 5414 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5415 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 5416 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5417 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5420 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 5425 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 5421 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 5432 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 5437 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5438 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 5439 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 5434 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 5433 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 5435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 5444 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5445 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 5446 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 5447 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5448 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5449 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5450 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5451 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 5452 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5453 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 5454 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5455 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5456 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 5463 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5466 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 5469 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 5474 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 5497 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 5498 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 5470 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 5502 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5503 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5504 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5508 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5512 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 5516 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 5526 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5527 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5528 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 5532 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5533 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5535 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 5519 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 5520 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5522 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 5518 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 5517 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 5539 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5540 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5541 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5545 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5549 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 5552 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 5553 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 5554 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 5561 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5562 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5563 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5565 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 5556 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5557 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 5569 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5571 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5575 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 1
	goto_if_eq EscapeRoom_EventScript_GraveStone3_2
# 5575 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 5
	goto_if_eq EscapeRoom_EventScript_GraveStone3_2
# 5579 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone3_1:
# 5584 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_8
# 5588 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_11
# 5595 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_12
# 5596 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_12
# 5603 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_10:
# 5606 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5607 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5609 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
# 5576 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone3_1

EscapeRoom_EventScript_GraveStone3_8:
	end

EscapeRoom_EventScript_GraveStone3_11:
# 5590 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 5591 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5593 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_10

EscapeRoom_EventScript_GraveStone3_12:
# 5598 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5599 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5600 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_10


EscapeRoom_EventScript_GraveStone4::
# 5613 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5614 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5615 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5619 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 3
	goto_if_eq EscapeRoom_EventScript_GraveStone4_2
# 5619 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 4
	goto_if_eq EscapeRoom_EventScript_GraveStone4_2
# 5623 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone4_1:
# 5628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_8
# 5631 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_9
# 5632 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_9
# 5633 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_9
EscapeRoom_EventScript_GraveStone4_7:
# 5640 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5641 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5642 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5644 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
# 5620 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone4_1

EscapeRoom_EventScript_GraveStone4_8:
	end

EscapeRoom_EventScript_GraveStone4_9:
# 5635 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5636 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_7


EscapeRoom_EventScript_GraveStone5::
# 5648 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5649 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5650 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5654 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5658 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 5661 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 5662 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 5663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 5670 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5671 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5672 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5674 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 5665 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 5678 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5680 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5684 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5688 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 5691 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 5692 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 5693 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 5700 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5701 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5702 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5704 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 5695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5696 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 5708 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5709 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5710 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5714 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 6
	goto_if_eq EscapeRoom_EventScript_GraveStone7_4
EscapeRoom_EventScript_GraveStone7_3:
# 5725 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone7_1:
# 5730 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_8
# 5734 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_14
# 5739 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_15
# 5740 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_15
# 5751 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5752 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5753 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_13:
# 5756 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
# 5715 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAIN_EASTER_EGG_CAN_START, EscapeRoom_EventScript_GraveStone7_10
# 5720 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_MainEasterEggCannotBeStartedYet
# 5721 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
	goto EscapeRoom_EventScript_GraveStone7_1

EscapeRoom_EventScript_GraveStone7_4:
# 5714 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 0
	goto_if_eq EscapeRoom_EventScript_GraveStone7_2
	goto EscapeRoom_EventScript_GraveStone7_3

EscapeRoom_EventScript_GraveStone7_8:
	end

EscapeRoom_EventScript_GraveStone7_10:
# 5716 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STATE, 1
# 5717 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_MainEasterEggStep1Complete
	goto EscapeRoom_EventScript_GraveStone7_1

EscapeRoom_EventScript_GraveStone7_14:
# 5736 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 5737 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_13

EscapeRoom_EventScript_GraveStone7_15:
# 5742 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5743 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5745 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5746 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5747 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_13


EscapeRoom_EventScript_GraveStone8::
# 5760 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5761 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5762 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5766 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 0
	goto_if_eq EscapeRoom_EventScript_GraveStone8_2
# 5770 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone8_1:
# 5775 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_6
# 5779 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_9
# 5786 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_10
# 5787 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_10
# 5794 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_8:
# 5797 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5798 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5800 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
# 5767 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone8_1

EscapeRoom_EventScript_GraveStone8_6:
	end

EscapeRoom_EventScript_GraveStone8_9:
# 5781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5784 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_8

EscapeRoom_EventScript_GraveStone8_10:
# 5789 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5790 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5791 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_8


EscapeRoom_EventScript_GraveStone9::
# 5804 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5805 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5806 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5810 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 2
	goto_if_eq EscapeRoom_EventScript_GraveStone9_2
# 5814 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone9_1:
# 5819 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_6
# 5822 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_7
# 5823 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_7
# 5824 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_7
EscapeRoom_EventScript_GraveStone9_5:
# 5831 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5832 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5833 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5835 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
# 5811 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone9_1

EscapeRoom_EventScript_GraveStone9_6:
	end

EscapeRoom_EventScript_GraveStone9_7:
# 5826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5827 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_5


EscapeRoom_EventScript_GraveStone0::
# 5839 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5841 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5845 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5849 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 5852 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 5853 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 5854 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 5861 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5862 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5863 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5865 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 5856 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5857 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 5869 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5870 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 5872 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 5873 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5874 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5875 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5876 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5877 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5878 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5879 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 5882 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 5883 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5884 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5886 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_SPAWNED
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 5890 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5893 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 5929 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 5930 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 5933 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 5895 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 5896 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 5923 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 5924 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 5899 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5900 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 5901 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 5904 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 5905 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 5896 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 5908 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 5909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 5914 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5915 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5916 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 5917 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 5910 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 5911 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 5938 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5939 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5940 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5941 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 5942 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5943 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5944 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 5947 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 5948 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 5949 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 5950 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 5951 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_NIGHTMARE
# 5952 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5953 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5954 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5955 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 5956 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 5957 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5958 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5961 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5962 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 5963 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 5964 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_NONE
# 5965 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 5969 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 5971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5972 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndGame::
# 5979 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5980 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 5983 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAIN_EASTER_EGG_CAN_START
# 5986 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 0
	goto_if_eq EscapeRoom_EventScript_EndGame_2
EscapeRoom_EventScript_EndGame_1:
# 5991 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame_EnterBoat
# 5994 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5995 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 5998 "data/maps/EscapeRoom_Main/scripts.pory"
	special GameClear
# 5999 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 6000 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_EndGame_2:
# 5987 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
	goto EscapeRoom_EventScript_EndGame_1


EscapeRoom_EventScript_EndGame_EnterBoat::
# 6005 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 6006 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq EscapeRoom_EventScript_EndGame_EnterBoat_2
# 6010 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq EscapeRoom_EventScript_EndGame_EnterBoat_3
EscapeRoom_EventScript_EndGame_EnterBoat_1:
# 6014 "data/maps/EscapeRoom_Main/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ESCAPE_ROOM_MAIN
# 6015 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 6017 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, ChampionEnterBoat
# 6018 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 6019 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 34
# 6020 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 35
# 6023 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 35, BoatSailAway
	return

EscapeRoom_EventScript_EndGame_EnterBoat_2:
# 6007 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EnterBoat2
# 6008 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_EndGame_EnterBoat_1

EscapeRoom_EventScript_EndGame_EnterBoat_3:
# 6011 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EnterBoat1
# 6012 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_EndGame_EnterBoat_1


# 6026 "data/maps/EscapeRoom_Main/scripts.pory"
EnterBoat1:
# 6027 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 6028 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 6030 "data/maps/EscapeRoom_Main/scripts.pory"
EnterBoat2:
# 6031 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 6032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 6033 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 6034 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 6034 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 6036 "data/maps/EscapeRoom_Main/scripts.pory"
ChampionEnterBoat:
# 6037 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 6038 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 6039 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 6040 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 6042 "data/maps/EscapeRoom_Main/scripts.pory"
BoatSailAway:
# 6043 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
	step_end

EscapeRoom_EventScript_EscapeRopeEE_message1::
# 6051 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6052 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 2
# 6053 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 6054 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 6055 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 6056 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6057 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EscapeRopeEE_message2andwarp::
# 6061 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 3
# 6062 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRopeEEMessage2, MSGBOX_AUTOCLOSE
# 6063 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6064 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 47, 17
# 6065 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_AlternativeEnding::
# 6071 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6072 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 6075 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 6076 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 6077 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 6078 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 6081 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox TakeEasterEggBoatMessage, MSGBOX_AUTOCLOSE
# 6082 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6085 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame_EnterBoat
# 6088 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 150
# 6089 "data/maps/EscapeRoom_Main/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 9, 7
# 6090 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 6092 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EasterEggFinalMessage::
# 6098 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 6099 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggCompletedMessage1
# 6100 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 6101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6104 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggCompletedMessage2, MSGBOX_AUTOCLOSE
# 6105 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6108 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 6109 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 6110 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 6111 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 7
# 6112 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_CHAMPION_BF
# 6113 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 6114 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 6117 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAIN_EASTER_EGG_COMPLETED
# 6118 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_COMPLETED, 1
	return


EscapeRoom_EventScript_MainEasterEggCannotBeStartedYet::
# 6122 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggCannotStart, MSGBOX_AUTOCLOSE
# 6123 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_MainEasterStep0_HintNPC::
# 6128 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6129 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 6130 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggHintMessage, MSGBOX_AUTOCLOSE
# 6131 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6134 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 6135 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 6136 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 17
# 6137 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
# 6138 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 6140 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggStep1Complete::
# 6145 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 6146 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 6147 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 6148 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 6149 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6151 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep1Completed_HintMessage, MSGBOX_AUTOCLOSE
# 6152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6153 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 6161 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
# 6164 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_EASTER_EGG_WALL_SIGN
	return


EscapeRoom_EventScript_MainEasterEggStep2WallSign::
# 6169 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep2WallSignMessage, MSGBOX_AUTOCLOSE
# 6171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6172 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggStep2Complete::
# 6176 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6177 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STATE, 2
# 6178 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STEP2_COMPLETE_MSG, 0
# 6187 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 6188 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_WALL_SIGN
# 6190 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggStep3WallSign::
# 6195 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6196 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep3WallSignMessage, MSGBOX_AUTOCLOSE
# 6197 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6198 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggStep3Complete::
# 6202 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6203 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STATE, 3
# 6204 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STEP3_COMPLETE_MSG, 0
# 6206 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 6207 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 6208 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 6213 "data/maps/EscapeRoom_Main/scripts.pory"
	setmetatile 80, 19, METATILE_EscapeRoomIceRock, TRUE
# 6216 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_EASTER_EGG_SS_TICKET
# 6218 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggObtainBoatTicket::
# 6223 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6224 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SS_TICKET
# 6225 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 36
# 6226 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_BattleFactorySign::
# 6231 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6232 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggFirstCompletedMessage, MSGBOX_AUTOCLOSE
# 6233 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6234 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


SomethingsGoneWrongMessage::
# 6241 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketch.$"

RespawnChangeMessage::
# 6248 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 6252 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 6258 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6282 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to check?$"

GameCompletionMessage::
# 6317 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed roughly {STR_VAR_1}% of the\n"
	.string "game so far.$"

GameCompletionMessageInitial::
# 6322 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed 0% of the game so far.$"

GameCompletionMessageFinal::
# 6326 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've fully completed the game!$"

SignMessageReadInfoAgain::
# 6330 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

MoveDeleterSignMessage::
# 6336 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 6359 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 6363 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 6367 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 6372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 6377 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 6381 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 6385 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 6394 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 6402 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 6407 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 6412 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 6419 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 6428 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 6432 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something just opened...$"

MApSwitchesAlreadySolved::
# 6436 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchTablet1_Onix::
# 6441 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 95.$"

MapSwitchTablet2_Toedscruel::
# 6448 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 949.$"

MapSwitchTablet3_Dusknoir::
# 6455 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 477.$"

MapSwitchTablet4_Dunsparce::
# 6462 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 206.$"

MapSwitchPointedNorth::
# 6470 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEast::
# 6475 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouth::
# 6480 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWest::
# 6485 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 6492 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 6496 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 6500 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 6508 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "What kind of hint would you like to get?$"

HintsIntroMessage_Finale::
# 6517 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Please note: for this final challenge,\n"
	.string "hint costs are doubled.\p"
	.string "What kind of hint would you like to get?$"

HintsNPCNoHintMessage::
# 6528 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsFinalMessage::
# 6532 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed the escape room.\n"
	.string "I'm no longer needed!$"

HintsNPCHintAlreadyReceivedMessage::
# 6537 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received this hint so\n"
	.string "no time was added to your clock.$"

HintsNPCSolutionAlreadyReceivedMessage::
# 6542 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received the solution\n"
	.string "so no time was added to your clock.$"

HintsNPC_ReviewPreviousStep::
# 6547 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to review the previous step?\n"
	.string "This won't add any extra time.$"

HintsNPC_ReviewExactSequence::
# 6552 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact move sequence?$"

HintsNPC_AskViewExactIcePuzzleSolution::
# 6556 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact ice puzzle\n"
	.string "steps?$"

HintsNPC15minAddedMessage::
# 6562 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "15 minutes were added to your clock.$"

HintsNPC30minAddedMessage::
# 6566 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "30 minutes were added to your clock.$"

HintsNPC60minAddedMessage::
# 6570 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1 hour was added to your clock.$"

HintsNPC120minAddedMessage::
# 6574 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "2 hours were added to your clock.$"

HintsNPC_AnnihilapeSpawn_SmallHint::
# 6581 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Those gravestones seem to be placed in\n"
	.string "an interesting pattern...$"

HintsNPC_ZeraCatchPredamage_SmallHint::
# 6586 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block is what you need,\n"
	.string "but how to get the speed?\p"
	.string "At the graveyard fight the ape.\n"
	.string "Do ghosts always escape?$"

HintsNPC_ZeraoraCatch_SmallHint::
# 6593 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sometimes Zeraora blends in a little too\n"
	.string "well with its environment.\p"
	.string "Can Ferrothorn take advantage?$"

HintsNPC_Trainer0_SmallHint::
# 6599 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sticky Barbs are so annoying.\n"
	.string "If only you had an item.$"

HintsNPC_SafetyGoggles_SmallHint::
# 6604 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An item you're missing may finally be\n"
	.string "within reach.$"

HintsNPC_Trainer1_SmallHint::
# 6609 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora can take out Marowak but needs\n"
	.string "to absorb some additional HP.\p"
	.string "Can both Pokémon carry the Goggles?$"

HintsNPC_MarangaBerry_SmallHint::
# 6615 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Double battles can be difficult.\n"
	.string "Is there a way to avoid them?$"

HintsNPC_Trainer2_SmallHint::
# 6620 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use Cut?$"

HintsNPC_Trainer3_SmallHint::
# 6624 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala is asleep?\n"
	.string "There's gotta be a way to use that.$"

HintsNPC_EggSkip_SmallHint::
# 6629 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Why would you need an egg?$"

HintsNPC_SunStone_SmallHint::
# 6635 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have the ability to progress!$"

HintsNPC_UltraBall_SmallHint::
# 6639 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Someone's got something for you.$"

HintsNPC_Trainer4_SmallHint::
# 6643 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Trump Trump Trump, I feel depleted.\n"
	.string "Assistable moves should be deleted.$"

HintsNPC_TauntHerb_SmallHint::
# 6648 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One new move, your path will unlock.\n"
	.string "Where was that first Rock Smash rock?$"

HintsNPC_MoonStone_SmallHint::
# 6653 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I wonder what the carrier birds are\n"
	.string "carrying today.$"

HintsNPC_BerryJuice_SmallHint::
# 6658 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Are you a Rock Smash rock?\n"
	.string "Because I can't move past you.\p"
	.string "Such a juicy pickup line.$"

HintsNPC_Trainer5_SmallHint::
# 6664 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An Onix so sturdy, I admire.\n"
	.string "The Berry Juice, her true desire.\p"
	.string "That's how Liepard hits her twice.\n"
	.string "Pay Day your partner? That's not nice.$"

HintsNPC_TrapinchRun_SmallHint::
# 6671 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Run!!$"

HintsNPC_RareCandyRevive_SmallHint::
# 6675 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find your way back once more?\n"
	.string "Too bad Liepard will be fainted.$"

HintsNPC_Trainer6_SmallHint::
# 6680 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ring Target Annihilape?\n"
	.string "Yeah, that makes sense.$"

HintsNPC_MapSwitches_SmallHint::
# 6685 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet numbers may have something\n"
	.string "to do with Pokémon...$"

HintsNPC_Trainer7A_SmallHint::
# 6692 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sore eyes?\n"
	.string "Hindsight is 20/20.$"

HintsNPC_Trainer8_SmallHint::
# 6697 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hidden Power Normal does not exist!$"

HintsNPC_IcePuzzleRareCandy_SmallHint::
# 6701 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try taking just one item from the ice\n"
	.string "puzzle.\p"
	.string "Don't be greedy.$"

HintsNPC_ApeEvolution_SmallHint::
# 6707 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Annihilape would be nice.$"

HintsNPC_Trainer9_SmallHint::
# 6711 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Where can you get an extra ¥500?$"

HintsNPC_ToxicOrbSteal_SmallHint::
# 6715 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Muk.$"

HintsNPC_SecretPower_SmallHint::
# 6719 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Make the right choice, revive, and\n"
	.string "you'll have poison.\p"
	.string "That's how you can unlock your Secret\n"
	.string "Power.$"

HintsNPC_RareCandy3_SmallHint::
# 6726 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There are two Secret Bases!$"

HintsNPC_Trainer10_SmallHint::
# 6730 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Kecleon was hit by Flamethrower!\n"
	.string "Huh? Its type didn't change.$"

HintsNPC_Trainer11_SmallHint::
# 6735 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Both of your items are very important!\p"
	.string "Can Heatran be poisoned?\n"
	.string "It's a real struggle.$"

HintsNPC_AnnihilapeSpawn_LargeHint::
# 6746 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones represent a numpad.\n"
	.string "Maybe there's a code written somewhere\l"
	.string "for you to enter.$"

HintsNPC_UltraBall_LargeHint::
# 6752 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's an NPC you still haven't\n"
	.string "interacted with!$"

HintsNPC_ZeraCatchPredamage_LargeHint::
# 6757 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You should pre-damage Ferrothorn for\n"
	.string "Custap Berry Block against Zeraora.\p"
	.string "Grass Knot is great, but Florges is so\n"
	.string "heavy...\p"
	.string "Florges can run?\n"
	.string "That's so spooky!$"

HintsNPC_ZeraoraCatch_LargeHint::
# 6766 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block, Ingrain, Zeraora will stay.\n"
	.string "The Electric type stands in your way.\p"
	.string "One PP, its type will change.\n"
	.string "Which move brings the catch in range?$"

HintsNPC_Trainer0_LargeHint::
# 6773 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Struggling against Rhyperior?\n"
	.string "Skill Swap is really useful!\p"
	.string "Wait, no...\n"
	.string "TM Skill Swap is really useful!$"

HintsNPC_SafetyGoggles_LargeHint::
# 6780 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One of the gravestones is a little\n"
	.string "mysterious.\p"
	.string "Can Zeraora help you out?$"

HintsNPC_Trainer1_LargeHint::
# 6786 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Cut Guy is very tough!\p"
	.string "Zeraora can beat the Marowak, but you\n"
	.string "must use Volt Absorb to keep it alive.\p"
	.string "Start the fight with Grassy Terrain,\n"
	.string "then share the Goggles with Zeraora\l"
	.string "once Lightningrod is removed.$"

HintsNPC_MarangaBerry_LargeHint::
# 6797 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.$"

HintsNPC_Trainer2_LargeHint::
# 6803 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Nature Power won't cut it?\n"
	.string "Just remove the grass.$"

HintsNPC_Trainer3_LargeHint::
# 6808 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala's type keeps Hex from landing.\n"
	.string "Maybe it needs a different held item.\p"
	.string "Magicians never reveal their secret,\n"
	.string "but a little sharing doesn't hurt.\p"
	.string "Why is Komala holding a Snowball?$"

HintsNPC_EggSkip_LargeHint::
# 6816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.\p"
	.string "...\p"
	.string "Or if you only have one Pokémon.$"

HintsNPC_SunStone_LargeHint::
# 6826 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You should fight some Dusknoir.\n"
	.string "A certain ability might help you out.$"

HintsNPC_Trainer4_LargeHint::
# 6831 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Beating Iron Bundle will require some\n"
	.string "preparation at the Dusknoir.\p"
	.string "Can Thief be used with Assist?\n"
	.string "Don't you worry, there's no pressure if\l"
	.string "you fail.$"

HintsNPC_TauntHerb_LargeHint::
# 6840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Taunted Dusknoirs Struggle twice,\n"
	.string "but a single hit would be paradise.\p"
	.string "You'd skip the Twins and not disturb.\n"
	.string "Dusknoir just needs a soothing herb.$"

HintsNPC_MoonStone_LargeHint::
# 6847 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You may not be a thief, but you've got\n"
	.string "a new Trick.\p"
	.string "Is it possible to steal the moon?$"

HintsNPC_BerryJuice_LargeHint::
# 6853 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know Pickup has an in-battle\n"
	.string "effect as well?\p"
	.string "It might come in handy at the Rock\n"
	.string "Smash rocks.\p"
	.string "Make sure you're not too quick!$"

HintsNPC_Trainer5_LargeHint::
# 6861 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6875 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Trapped? Just Run Away!$"

HintsNPC_RareCandyRevive_LargeHint::
# 6879 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Taunt a Dusknoir, now you can run.\n"
	.string "The other side holds all the fun!\p"
	.string "Want Liepard and the Ape to meet?\n"
	.string "Give your cat get a special treat.$"

HintsNPC_Trainer6_LargeHint::
# 6886 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You'll need to set up for Aipom to use\n"
	.string "Custap Endeavor against Rayquaza.\p"
	.string "Oh... You want to use Endeavor into a\n"
	.string "Ghost type?\p"
	.string "It's tricky, but with the right item, it\n"
	.string "might just work.$"

HintsNPC_MapSwitches_LargeHint::
# 6899 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Four stone tablets, have you seen?\n"
	.string "The numbers Mason, what do they mean!\p"
	.string "Every Pokémon has their own.\n"
	.string "In numerical order they are shown.\p"
	.string "Where can the Pokémon be found?$"

HintsNPC_Trainer7A_LargeHint::
# 6909 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What if Peepers means it litterally?\n"
	.string "Perhaps her eyes really are sore.\p"
	.string "It wouldn't be strange for someone her\n"
	.string "age to be a little short-sighted.\p"
	.string "And Caesar... I totally understand his\n"
	.string "struggle.$"

HintsNPC_Trainer8_LargeHint::
# 6919 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dusclops is sus...\n"
	.string "Is there any move you haven't used?$"

HintsNPC_IcePuzzleRareCandy_LargeHint::
# 6924 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right now, TM Secret Power can't be\n"
	.string "taken out of the ice puzzle.\p"
	.string "Escaping with the Rare Candy is\n"
	.string "possible, but you'll need to find a new\l"
	.string "angle.\p"
	.string "Try to avoid instant gratification.$"

HintsNPC_ApeEvolution_LargeHint::
# 6935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find a way to evolve your\n"
	.string "Primeape?\p"
	.string "Rage Fist is very important.$"

HintsNPC_Trainer9_LargeHint::
# 6941 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Annihilape is very neat.\n"
	.string "Any trainers you could never defeat?$"

HintsNPC_ToxicOrbSteal_LargeHint::
# 6946 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My MUK ate a Moon Stone\n"
	.string "and I can't get it out!\p"
	.string "...\p"
	.string "Sorry, that's the wrong escape room.\n"
	.string "This Muk ate something else.$"

HintsNPC_SecretPower_LargeHint::
# 6954 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You must be poisoned to obtain Secret\n"
	.string "Power.\p"
	.string "You can stall out Dusknoir by using\n"
	.string "Substitute, but need something clever\l"
	.string "for the final Memento PP.\p"
	.string "Three different items will be required.$"

HintsNPC_RareCandy3_LargeHint::
# 6965 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find the Secret Bases?\p"
	.string "There's a wall indent and a tree.\n"
	.string "Wait, where's the nurse NPC?$"

HintsNPC_Trainer10_LargeHint::
# 6971 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sheer Force has an interesting\n"
	.string "interaction with Color Change.\p"
	.string "Do you have a Pokémon with Sheer Force?$"

HintsNPC_Trainer11_LargeHint::
# 6977 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This battle is very tricky.\p"
	.string "You'll need to find a way to take out\n"
	.string "Heatran with the Toxic Orb.\p"
	.string "Wandering Spirit can be used to give\n"
	.string "Heatran a new ability, but none of its\l"
	.string "moves make any contact.\p"
	.string "Try giving Heatran a Choice Specs and\n"
	.string "see if you can force it to Struggle.\p"
	.string "It will avoid attacking into Destiny\n"
	.string "Bond so use that to your advantage.\p"
	.string "...\p"
	.string "Did anyone say Disable Annihilape?$"

HintsNPC_AnnihilapeSpawn_Solution::
# 7004 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones form a numpad pattern:\n"
	.string "1 2 3, 4 5 6, 7 8 9, 0.\p"
	.string "Interact with them in the following\n"
	.string "order: 1 8 3 7.$"

HintsNPC_UltraBall_Solution::
# 7011 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Talk to the NPC with the green hat to\n"
	.string "obtain an Ultra Ball.$"

HintsNPC_ZeraCatchPredamage_Solution::
# 7016 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7028 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pre-damage Ferrothorn by letting the\n"
	.string "Annihilape use Grass Knot.\p"
	.string "Have Florges hold a Float Stone and use\n"
	.string "Camouflage to run away.$"

HintsNPC_ZeraoraCatch_Solution::
# 7035 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1. Use Custap Berry Block vs Zeraora\n"
	.string "and let it Snatch Ingrain.\p"
	.string "2. Switch to Florges, use the Ether on\n"
	.string "Camouflage, and let Zeraora copy both\l"
	.string "Grassy Terrain and Camouflage.\p"
	.string "3. Switch to Ferrothorn and use Steel\n"
	.string "Roller.\p"
	.string "You can now catch Zeraora.$"

HintsNPC_Trainer0_Solution::
# 7046 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have to beat the Pincurchin\n"
	.string "trainer.\p"
	.string "1. Give TM Skill Swap to Florges as\n"
	.string "held item.\p"
	.string "2. Sack Ferrothorn and Zeraora to the\n"
	.string "Selfdestructing Pincurchin.\p"
	.string "3. Use Grass Knot.$"

HintsNPC_SafetyGoggles_Solution::
# 7056 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Exp Candy on Zeraora to reach\n"
	.string "level 43.\p"
	.string "Go to the graveyard and interact with\n"
	.string "the bottom-left gravestone to obtain\l"
	.string "the Safety Goggles.$"

HintsNPC_Trainer1_Solution::
# 7064 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7087 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7109 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fight the Annihilape and let it copy\n"
	.string "Steel Roller.\p"
	.string "Set up Grassy Terrain, switch out and\n"
	.string "sack Ferrothorn, use Camouflage, and\l"
	.string "run from battle.\p"
	.string "You can now walk past the Twins and\n"
	.string "pick the Maranga Berry.$"

HintsNPC_Trainer2_Solution::
# 7119 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Florges the Maranga Berry, then\n"
	.string "use Cut to remove the Grass tiles next\l"
	.string "to the Dracozolt trainer.\p"
	.string "Start the battle on a regular tile and\n"
	.string "use Nature Power to win.$"

HintsNPC_Trainer3_Solution::
# 7127 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let Klefki steal your Ring Target with\n"
	.string "Magician, give it Symbiosis, activate\l"
	.string "Komala's Snowball, and you're now able\l"
	.string "to beat it with Trump Card and Hex.$"

intsNPC_Trainer3_Solution_ExactSequence::
# 7134 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Florges (Ring Target) and\n"
	.string "Dunsparce.\p"
	.string "Turn 1: Grassy Terrain + Trump Card.\n"
	.string "Turn 2: Skill Swap + Trump Card.\l"
	.string "Turn 3: Ice Beam (Komala).\l"
	.string "Turn 4-6: Trump Card.\l"
	.string "Turn 7: Hex.\l"
	.string "Repeat untill Komala faints.$"

HintsNPC_EggSkip_Solution::
# 7145 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins cannot fight you when one of\n"
	.string "your Pokémon is an egg.\p"
	.string "Buy an Escape Rope, exit and re-enter\n"
	.string "the cave from where the Liepard Collar\l"
	.string "was located.\p"
	.string "Trade your Florges for the Pokémon egg,\n"
	.string "use the Escape Rope, and you can now\l"
	.string "walk past the Twins again.$"

HintsNPC_SunStone_Solution::
# 7158 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pickup will activate once you've fought\n"
	.string "a few wild Dusknoir.\p"
	.string "You'll get a Sun Stone which can be\n"
	.string "sold to an NPC up north.$"

HintsNPC_Trainer4_Solution::
# 7165 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7193 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7212 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rayquaza carries a Moon Stone.\p"
	.string "Use Trick to steal the Moon Stone and\n"
	.string "sell it to the NPC up north.$"

HintsNPC_BerryJuice_Solution::
# 7218 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Aipom the Iron Ball and fight a\n"
	.string "Shuckle at the Rock Smash rocks.\p"
	.string "Use Endeavor to trigger Shuckle's Berry\n"
	.string "Juice, then Aipom's Pickup activates\l"
	.string "to recover the consumed item.\p"
	.string "Run from the battle and you've now got\n"
	.string "a Berry Juice.$"

HintsNPC_Trainer5_Solution::
# 7230 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7253 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Ability Capsule on Aipom to get\n"
	.string "Run Away.\p"
	.string "Fight the Trapinch and run away.$"

HintsNPC_RareCandyRevive_Solution::
# 7277 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7292 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Assist Taunt against a Dusknoir, sack\n"
	.string "Liepard, then run away.\p"
	.string "Walk past the Twins and Revive Liepard\n"
	.string "with the Rare Candy.$"

HintsNPC_Trainer6_Solution::
# 7299 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7331 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7347 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7361 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teach Cut to Bagon and fight the\n"
	.string "Dusclops trainer.\p"
	.string "Use Cut.$"

HintsNPC_IcePuzzleRareCandy_Solution::
# 7367 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "At this point, only the Rare Candy can\n"
	.string "be taken out of the ice puzzle.\p"
	.string "To do so, the item ball must be used as\n"
	.string "an obstacle within the puzzle itself.$"

HintsNPC_IcePuzzleRareCandy_Solution_IcePuzzleSteps::
# 7375 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW} (ignore the\n"
	.string "item) {LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{LEFT_ARROW} "
	.string "(take the item) {DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}.$"

HintsNPC_ApeEvolution_Solution::
# 7383 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have Primeape use Rage Fist 20 times\n"
	.string "(Sentret is the easiest target).\p"
	.string "You can now give it the Rare Candy to\n"
	.string "evolve into Annihilape.$"

HintsNPC_Trainer9_Solution::
# 7391 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're finally able to defeat the\n"
	.string "Urshifu twins.\p"
	.string "Keep using Rage Fist (start with the\n"
	.string "Urshifu-Rapid-Strike) to win.$"

HintsNPC_ToxicOrbSteal_Solution::
# 7403 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Muk is holding a Toxic Orb.\p"
	.string "Buy TM Thief, teach it to Annihilape,\n"
	.string "and steal the Toxic Orb from Muk.$"

HintsNPC_SecretPower_Solution_Refresher::
# 7410 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Buy TM Thief, teach it to Annihilape,\n"
	.string "and steal the Toxic Orb from Muk.$"

HintsNPC_SecretPower_Solution::
# 7415 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7452 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{DOWN_ARROW}"
	.string "{LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW}.$"

HintsNPC_RareCandy3_Solution::
# 7458 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7473 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7491 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokémon will need the following\n"
	.string "setup:\p"
	.string "Annihilape (Choice Specs)\n"
	.string "Rage Fist / Role Play / Mimic / Taunt.\p"
	.string "Yamask (Toxic Orb)\n"
	.string "Trick / Disable / Destiny Bond / X.\p"
	.string "Want to continue?$"

HintsNPC_Trainer11_Solution::
# 7504 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You can win by taking out Heatran with\n"
	.string "the Toxic Orb.\p"
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
# 7530 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Annihilape (Choice Specs) and\n"
	.string "Yamask (Toxic Orb).\p"
	.string "Turn 1: Role Play (Yamask) + Trick\n"
	.string "(Kecleon, give Toxic Orb).\p"
	.string "Turn 2: Role Play (Yamask) + Trick\n"
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
	.string "Other variations are possible as well.$"

AntiSoftlockIntroMessage::
# 7574 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 7584 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 7588 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 7594 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 7599 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 7603 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 7607 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 7613 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 7618 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 7622 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoSecretPower::
# 7625 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Secret Power$"

OptionUndoCut::
# 7628 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 7631 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 7634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 7637 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 7641 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 7646 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "used on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 7651 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 7656 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 7660 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 7665 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 7670 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 7674 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 7678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 7682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 7688 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 7693 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 7700 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 7704 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 7709 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

AntiSoftlockAskUndoDunsparceTrade::
# 7714 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "trade and get back Dunsparce?$"

AntiSoftlockAskUndoIcePuzzleRareCandy::
# 7719 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to place the Rare Candy\n"
	.string "back inside the ice puzzle?$"

ZeraoraHintMessage1::
# 7726 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 7736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 7743 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 7754 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 7758 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 7765 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 7769 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 7773 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your energy trying to catch\n"
	.string "or beat her.$"

FourTabletsHintMessage1::
# 7785 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 7791 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?$"

FourTabletsHintMessage3::
# 7796 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake???$"

StonesBuyNPCInitialMessage_no_item::
# 7803 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 7811 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 7817 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for an Iron Ball?$"

StonesBuyNPCSellAcceptedMessage::
# 7825 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_IronBall::
# 7829 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the ball will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 7833 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 7837 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 7841 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 7848 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 7852 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 7856 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 7860 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 7867 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 7871 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretPowerTmReturned::
# 7878 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TM43 Secret Power was returned to its\n"
	.string "previous location.$"

RareCandy2Returned::
# 7883 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Rare Candy was returned to its\n"
	.string "previous location.$"

MonForgotSecretPower::
# 7888 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

SSTicketReturned::
# 7892 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The SS Ticket was returned to its\n"
	.string "previous location.$"

MartNPC_AskToShop::
# 7899 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 7905 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

ChoiceItemsFirstMessage::
# 7911 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Impressive, you saw right through my\n"
	.string "facade!\p"
	.string "I think you've earned a reward!\n"
	.string "Take your pick of my Choice items.\p"
	.string "You can always return if you'd like to\n"
	.string "try a different one.$"

ChoiceItemsNoLongerAvailable::
# 7920 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It seems you've made the right choice.$"

ChoiceItemsWhichOne::
# 7924 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Which item would you like to have?$"

ChoiceItemsComeAgain::
# 7928 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back anytime.$"

ChoiceItemsSwapped::
# 7932 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You returned the other Choice item.$"

ChoiceItemsAlreadyHaveThis::
# 7936 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You already have this one.$"

OptionChoiceBand::
# 7940 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Band$"

OptionChoiceSpecs::
# 7944 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Specs$"

OptionChoiceScarf::
# 7948 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Scarf$"

PrimeapeObtainMessage::
# 7954 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 7958 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

RescueBellExplainMessage::
# 7964 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Rescue Bell to teleport out of\n"
	.string "the ice puzzle if you're stuck.\p"
	.string "When used, any obtained items will be\n"
	.string "placed back inside the ice puzzle.$"

AskDeleteMove::
# 7973 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 7979 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 7985 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 7989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 7993 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 7999 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 8003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 8007 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 8014 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 8019 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 8024 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 8030 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 8036 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 8041 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 8045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 8049 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 8053 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 8057 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 8062 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 8067 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 8072 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 8078 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 8082 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 8086 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 8090 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 8094 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 8099 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 8103 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 8108 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 8114 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 8120 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 8124 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

PlayerObtainedDunsparceMessage::
# 8128 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

DoubleBattle_NotEnoughMons::
# 8134 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 8141 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You think you are ready?\n"
	.string "You really need three.\l"
	.string "One of them might hold the key.$"

Trainer0_Outro::
# 8147 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "But sharing is caring...$"

Trainer0_PostBattle::
# 8151 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go.$"

Trainer1_Intro::
# 8157 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 8163 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 8167 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 8172 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 8179 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 8185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 8190 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love writing in 486578!$"

Trainer2_PostBattle::
# 8194 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 8200 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 8205 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 8209 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 8214 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 8220 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 8225 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 8229 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know that 5A + 2L = 525?$"

Trainer5_Intro::
# 8236 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 8241 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 8245 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 8249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 8256 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 8263 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 8267 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My birds have traveled through all\n"
	.string "sorts of areas.\p"
	.string "Your Pokédex would be full by now if\n"
	.string "you'd done the same!$"

Trainer7A_Intro::
# 8276 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 8283 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 8287 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "bsqajmnq? qsq.$"

Trainer7B_Intro::
# 8294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 8299 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 8303 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 8310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Ghost type mons are everywhere,\n"
	.string "you still haven't seen mine.$"

Trainer8_Outro::
# 8322 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 8326 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "$"

Trainer9_Intro::
# 8332 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 8337 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try hard in every fight!$"

Trainer9_PostBattle::
# 8341 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Are we done now?$"

Trainer10_Intro::
# 8348 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Darwinism?\n"
	.string "More like Schmarminism...\p"
	.string "Kecleon has changed enough already!$"

Trainer10_Outro::
# 8355 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a struggle!$"

Trainer10_PostBattle::
# 8359 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Kecleon's ability is amazing!$"

Trainer11_Intro::
# 8365 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So you've finally made it to the end...\p"
	.string "No more hints.\p"
	.string "No more clues.\p"
	.string "It's time for your final test.$"

Trainer11_Outro::
# 8372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

Trainer11_PostBattle_A::
# 8376 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please read the sign first.$"

Trainer11_PostBattle_B::
# 8380 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This game has been a true passion\n"
	.string "project of mine.\p"
	.string "An absurd amount of time, effort, and\n"
	.string "care went into every small detail.\p"
	.string "If you enjoyed the experience, please\n"
	.string "let me know via the game's thread on\l"
	.string "PokéCommunity.\p"
	.string "It really does mean lot to me.\p"
	.string "Thank you so much for playing.\n"
	.string " - Ketch.$"

Trainer11_EndTheGame::
# 8397 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wanna get out of here?$"

EscapeRoomEndCongratz::
# 8403 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have completed\n"
	.string "the escape room!$"

EndEscapeRoomSignMessage::
# 8408 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your final time: {STR_VAR_1}.\p"
	.string "Small hints used: {STR_VAR_2}.\n"
	.string "Large hints used: {STR_VAR_3}.\l"
	.string "Solutions used: {STR_VAR_5}.$"

EscapeRopeEEMessage2::
# 8417 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just kidding.$"

TakeEasterEggBoatMessage::
# 8423 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An SS Ticket!?\p"
	.string "I'm impressed... You've actually\n"
	.string "managed to get it.\p"
	.string "Alright, let's go.$"

EasterEggCannotStart::
# 8432 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Nothing happened.\p"
	.string "Perhaps you should try this on a save\n"
	.string "file that has already completed the\l"
	.string "escape room.$"

EasterEggCompletedMessage1::
# 8440 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have completed\n"
	.string "the easter egg!$"

EasterEggCompletedMessage2::
# 8445 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You may be one of the first to complete\n"
	.string "this easter egg.\p"
	.string "In the case you are, please notify me\n"
	.string "(Ketch) and get your name added ingame\l"
	.string "on the sign above.\p"
	.string "...\p"
	.string "Enjoy the Battle Factory!$"

EasterEggFirstCompletedMessage::
# 8458 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're the first to complete the\n"
	.string "easter egg!\p"
	.string "(assuming your game is up to date)$"

EasterEggHintMessage::
# 8464 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Interested in easter eggs?\p"
	.string "Your first clue exists before time\n"
	.string "begins.$"

EasterEggStep1Completed::
# 8470 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "EASTER EGG STEP 1$"

EasterEggStep2Completed::
# 8474 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "EASTER EGG STEP 2$"

EasterEggStep3Completed::
# 8478 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "EASTER EGG STEP 3$"

EasterEggStep1Completed_HintMessage::
# 8482 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thud!$"

EasterEggStep2WallSignMessage::
# 8486 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I see you like easter eggs.$"

EasterEggStep3WallSignMessage::
# 8490 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zhxrg Vzdpbnej lxg bnvq bke zrqwvg...$"
