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
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 70 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 76 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 80 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_STICKY_BARB_RETURN, 1, EscapeRoom_MapScripts_ReturnStickyBarb
# 81 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 82 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
# 85 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_JUST_ESCAPED_ICE_PUZZLE, 1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROPE_EE_STATE, 1, EscapeRoom_EventScript_EscapeRopeEE_message1
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 99 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_5
EscapeRoom_MapScript_OnTransitionScripts_4:
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FINAL_MESSAGE_READ, EscapeRoom_MapScript_OnTransitionScripts_7
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 95 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_5:
# 100 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	goto EscapeRoom_MapScript_OnTransitionScripts_4

EscapeRoom_MapScript_OnTransitionScripts_7:
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
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
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 452 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 467 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 472 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 477 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 484 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 479 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 492 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 532 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 563 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 586 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 600 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIcePuzzleItemReturns::
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_JUST_ESCAPED_ICE_PUZZLE, 0
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_3
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1:
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_8
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2:
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11:
# 620 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM43
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31:
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_38
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_AUTOCLOSE
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37:
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_3:
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_7:
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16:
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26:
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RARE_CANDY
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_35
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_34:
# 672 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_AUTOCLOSE
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_41:
# 684 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RARE_CANDY2_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_8:
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_7
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12:
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13:
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17:
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18:
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22:
# 622 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23:
# 621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27:
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28:
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32:
# 627 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM43
# 628 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_35:
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_RARE_CANDY
# 668 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_34

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_38:
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_DEFAULT
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoSecretPowerTeach
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42:
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_DEFAULT
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy_IcePuzzle
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_41


EscapeRoom_MapScript_GameStartScripts::
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 700 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 701 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 709 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 710 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 717 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 777 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 783 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 785 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 786 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 788 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 837 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 870 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 877 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 887 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 892 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MainSignWhatToRead, MSGBOX_MAIN_SIGN
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_3
EscapeRoom_EventScript_MainInfoSign_1:
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_MainInfoSign_6
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_MainInfoSign_7
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetGameCompletion
# 928 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessage, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_3:
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 935 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_11
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_6:
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageInitial, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_7:
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageFinal, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_11:
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_GetGameCompletion::
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 0
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_GetGameCompletion_2
EscapeRoom_EventScript_GetGameCompletion_1:
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_GetGameCompletion_5
EscapeRoom_EventScript_GetGameCompletion_4:
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_8
EscapeRoom_EventScript_GetGameCompletion_7:
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_11
EscapeRoom_EventScript_GetGameCompletion_10:
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_14
EscapeRoom_EventScript_GetGameCompletion_13:
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_17
EscapeRoom_EventScript_GetGameCompletion_16:
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_20
EscapeRoom_EventScript_GetGameCompletion_19:
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_23
EscapeRoom_EventScript_GetGameCompletion_22:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_GetGameCompletion_26
EscapeRoom_EventScript_GetGameCompletion_25:
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_29
EscapeRoom_EventScript_GetGameCompletion_28:
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_GetGameCompletion_32
EscapeRoom_EventScript_GetGameCompletion_31:
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_GetGameCompletion_35
EscapeRoom_EventScript_GetGameCompletion_34:
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_38
EscapeRoom_EventScript_GetGameCompletion_37:
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_GetGameCompletion_41
EscapeRoom_EventScript_GetGameCompletion_40:
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_GetGameCompletion_44
EscapeRoom_EventScript_GetGameCompletion_43:
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_47
EscapeRoom_EventScript_GetGameCompletion_46:
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_GetGameCompletion_50
EscapeRoom_EventScript_GetGameCompletion_49:
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_53
EscapeRoom_EventScript_GetGameCompletion_52:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_56
EscapeRoom_EventScript_GetGameCompletion_55:
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_59
EscapeRoom_EventScript_GetGameCompletion_58:
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_GetGameCompletion_62
EscapeRoom_EventScript_GetGameCompletion_61:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_65
EscapeRoom_EventScript_GetGameCompletion_64:
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_68
EscapeRoom_EventScript_GetGameCompletion_67:
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_70
	return

EscapeRoom_EventScript_GetGameCompletion_2:
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 2
	goto EscapeRoom_EventScript_GetGameCompletion_1

EscapeRoom_EventScript_GetGameCompletion_5:
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 8
	goto EscapeRoom_EventScript_GetGameCompletion_4

EscapeRoom_EventScript_GetGameCompletion_8:
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 12
	goto EscapeRoom_EventScript_GetGameCompletion_7

EscapeRoom_EventScript_GetGameCompletion_11:
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 18
	goto EscapeRoom_EventScript_GetGameCompletion_10

EscapeRoom_EventScript_GetGameCompletion_14:
# 972 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 20
	goto EscapeRoom_EventScript_GetGameCompletion_13

EscapeRoom_EventScript_GetGameCompletion_17:
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 23
	goto EscapeRoom_EventScript_GetGameCompletion_16

EscapeRoom_EventScript_GetGameCompletion_20:
# 982 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 28
	goto EscapeRoom_EventScript_GetGameCompletion_19

EscapeRoom_EventScript_GetGameCompletion_23:
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 33
	goto EscapeRoom_EventScript_GetGameCompletion_22

EscapeRoom_EventScript_GetGameCompletion_26:
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 35
	goto EscapeRoom_EventScript_GetGameCompletion_25

EscapeRoom_EventScript_GetGameCompletion_29:
# 1000 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 41
	goto EscapeRoom_EventScript_GetGameCompletion_28

EscapeRoom_EventScript_GetGameCompletion_32:
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 44
	goto EscapeRoom_EventScript_GetGameCompletion_31

EscapeRoom_EventScript_GetGameCompletion_35:
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 46
	goto EscapeRoom_EventScript_GetGameCompletion_34

EscapeRoom_EventScript_GetGameCompletion_38:
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 49
	goto EscapeRoom_EventScript_GetGameCompletion_37

EscapeRoom_EventScript_GetGameCompletion_41:
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 55
	goto EscapeRoom_EventScript_GetGameCompletion_40

EscapeRoom_EventScript_GetGameCompletion_44:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 57
	goto EscapeRoom_EventScript_GetGameCompletion_43

EscapeRoom_EventScript_GetGameCompletion_47:
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 63
	goto EscapeRoom_EventScript_GetGameCompletion_46

EscapeRoom_EventScript_GetGameCompletion_50:
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 68
	goto EscapeRoom_EventScript_GetGameCompletion_49

EscapeRoom_EventScript_GetGameCompletion_53:
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 73
	goto EscapeRoom_EventScript_GetGameCompletion_52

EscapeRoom_EventScript_GetGameCompletion_56:
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 78
	goto EscapeRoom_EventScript_GetGameCompletion_55

EscapeRoom_EventScript_GetGameCompletion_59:
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 84
	goto EscapeRoom_EventScript_GetGameCompletion_58

EscapeRoom_EventScript_GetGameCompletion_62:
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 89
	goto EscapeRoom_EventScript_GetGameCompletion_61

EscapeRoom_EventScript_GetGameCompletion_65:
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 91
	goto EscapeRoom_EventScript_GetGameCompletion_64

EscapeRoom_EventScript_GetGameCompletion_68:
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 95
	goto EscapeRoom_EventScript_GetGameCompletion_67

EscapeRoom_EventScript_GetGameCompletion_70:
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 100
	return


EscapeRoom_EventScript_MoveDeleterSign::
# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
EscapeRoom_EventScript_EndSign_1:
# 1107 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 1109 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 1110 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 1092 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_END_ESCAPE_ROOM_STATE, 2
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 1095 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_Heal_Pokemon_Nurse1::
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 1139 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1140 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_2
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_5
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage_Finale, MSGBOX_HINTNPC
EscapeRoom_EventScript_HintsNPC_4:
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_9
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_10
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_HintsNPC_11
# 1181 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_8:
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsFinalMessage, MSGBOX_AUTOCLOSE
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HintsNPC_5:
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_HINTNPC
	goto EscapeRoom_EventScript_HintsNPC_4

EscapeRoom_EventScript_HintsNPC_9:
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_SmallHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_10:
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_LargeHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_11:
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_Solution
	goto EscapeRoom_EventScript_HintsNPC_8


EscapeRoom_EventScript_HintsNPC_SmallHint::
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_SmallHint_2
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_3
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_4
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_5
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_6
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_SmallHint_7
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_8
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_9
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_10
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_11
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_12
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_SmallHint_13
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_14
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_SmallHint_15
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_16
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_17
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_18
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_SmallHint_19
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_20
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_21
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_SmallHint_22
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_23
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_24
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_25
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_26
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_SmallHint_36
EscapeRoom_EventScript_HintsNPC_SmallHint_35:
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_28
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_29
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_30
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_31
EscapeRoom_EventScript_HintsNPC_SmallHint_1:
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_69
EscapeRoom_EventScript_HintsNPC_SmallHint_68:
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_66
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_SmallHint_64:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_SmallHint_2:
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_SmallHint
# 1193 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SMALL_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_3:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_SmallHint
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_SMALL_HINT, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_4:
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_SmallHint
# 1202 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_COMPLETED_SMALL_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_5:
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_SmallHint
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERAORA_CAUGHT_SMALL_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_6:
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_SmallHint
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SMALL_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_7:
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_SmallHint
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SMALL_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_8:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_SmallHint
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SMALL_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_9:
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_SmallHint
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SMALL_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_10:
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_SmallHint
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SMALL_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_11:
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_SmallHint
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SMALL_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_12:
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_SmallHint
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SMALL_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_13:
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_SmallHint
# 1251 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SMALL_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_14:
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_SmallHint
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SMALL_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_15:
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_SmallHint
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SMALL_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_16:
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_SmallHint
# 1266 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SMALL_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_17:
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_SmallHint
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SMALL_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_18:
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_SmallHint
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SMALL_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_19:
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_SmallHint
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SMALL_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_20:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_SmallHint
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SMALL_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_21:
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_SmallHint
# 1291 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SMALL_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_22:
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_SmallHint
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SMALL_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_23:
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_SmallHint
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SMALL_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_24:
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_SmallHint
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SMALL_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_25:
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_SmallHint
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SMALL_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_26:
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_SmallHint
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SMALL_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_27:
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_SmallHint
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SMALL_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_28:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_SmallHint
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SMALL_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_29:
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_SmallHint
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SMALL_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_30:
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_SmallHint
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SMALL_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_31:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_SmallHint
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SMALL_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_36:
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_27
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_35

EscapeRoom_EventScript_HintsNPC_SmallHint_65:
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_73
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
EscapeRoom_EventScript_HintsNPC_SmallHint_72:
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SMALL_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_64

EscapeRoom_EventScript_HintsNPC_SmallHint_66:
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_64

EscapeRoom_EventScript_HintsNPC_SmallHint_69:
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_65
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_68

EscapeRoom_EventScript_HintsNPC_SmallHint_73:
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 15
# 1355 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC15minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_72


EscapeRoom_EventScript_HintsNPC_LargeHint::
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_LargeHint_2
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_3
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_4
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_5
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_6
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_LargeHint_7
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_8
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_9
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_10
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_11
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_12
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_LargeHint_13
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_14
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_LargeHint_15
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_16
# 1465 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_17
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_18
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_LargeHint_19
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_20
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_21
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_LargeHint_22
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_23
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_24
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_25
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_26
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_LargeHint_36
EscapeRoom_EventScript_HintsNPC_LargeHint_35:
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_28
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_29
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_30
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_31
EscapeRoom_EventScript_HintsNPC_LargeHint_1:
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_69
EscapeRoom_EventScript_HintsNPC_LargeHint_68:
# 1563 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_66
# 1569 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1570 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_LargeHint_64:
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_LargeHint_2:
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_LargeHint
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_LARGE_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_3:
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_LargeHint
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_LARGE_HINT, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_4:
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_LargeHint
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_LARGE_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_5:
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_LargeHint
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_LARGE_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_6:
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_LargeHint
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_LARGE_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_7:
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_LargeHint
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_LARGE_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_8:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_LargeHint
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_LARGE_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_9:
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_LargeHint
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_LARGE_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_10:
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_LargeHint
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_LARGE_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_11:
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_LargeHint
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_LARGE_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_12:
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_LargeHint
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_LARGE_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_13:
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_LargeHint
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_LARGE_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_14:
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_LargeHint
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_LARGE_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_15:
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_LargeHint
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_LARGE_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_16:
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_LargeHint
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_LARGE_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_17:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_LargeHint
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_LARGE_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_18:
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_LargeHint
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_LARGE_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_19:
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_LargeHint
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_LARGE_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_20:
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_LargeHint
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_LARGE_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_21:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_LargeHint
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_LARGE_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_22:
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_LargeHint
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_LARGE_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_23:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_LargeHint
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_LARGE_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_24:
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_LargeHint
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_LARGE_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_25:
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_LargeHint
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_LARGE_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_26:
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_LargeHint
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_LARGE_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_27:
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_LargeHint
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_LARGE_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_28:
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_LargeHint
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_LARGE_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_29:
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_LargeHint
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_LARGE_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_30:
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_LargeHint
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_LARGE_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_31:
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_LargeHint
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_LARGE_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_36:
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_27
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_35

EscapeRoom_EventScript_HintsNPC_LargeHint_65:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_73
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
EscapeRoom_EventScript_HintsNPC_LargeHint_72:
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_LARGE_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_64

EscapeRoom_EventScript_HintsNPC_LargeHint_66:
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_64

EscapeRoom_EventScript_HintsNPC_LargeHint_69:
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_65
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_68

EscapeRoom_EventScript_HintsNPC_LargeHint_73:
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1551 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_72


EscapeRoom_EventScript_HintsNPC_Solution::
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_Solution_2
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_3
# 1591 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_4
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_Solution_5
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_6
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_Solution_7
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_8
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_9
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_10
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_11
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_12
# 1658 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_Solution_13
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_14
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_Solution_15
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_IRON_BALL_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_16
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_17
# 1683 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_Solution_18
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_Solution_19
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_20
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_21
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_Solution_22
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_23
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_24
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_25
# 1745 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_26
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_Solution_36
EscapeRoom_EventScript_HintsNPC_Solution_35:
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_28
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_29
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_30
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_31
EscapeRoom_EventScript_HintsNPC_Solution_1:
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_Solution_65
# 1823 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_Solution_64:
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_Solution_2:
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_Solution
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SOLUTION, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_3:
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_UltraBall_Solution
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_GET_ULTRA_BALL_SOLUTION, FLAG_GET_ULTRA_BALL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_4:
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_SOLUTION, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_5:
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_Solution
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_SOLUTION, FLAG_ZERA_CATCH_SOLUTION
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_68
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_6:
# 1608 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_Solution
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SOLUTION, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_7:
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_Solution
# 1614 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SOLUTION, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_8:
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SOLUTION, FLAG_TRAINER1_SOLUTION
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1623 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_70
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_9:
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_Solution
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SOLUTION, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_10:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_Solution
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SOLUTION, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_11:
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_Solution
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SOLUTION, FLAG_TRAINER3_SOLUTION
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_72
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_12:
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_Solution
# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SOLUTION, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_13:
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_Solution
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SOLUTION, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_14:
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_Solution
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SOLUTION, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_15:
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_Solution
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SOLUTION, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_16:
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_Solution
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SOLUTION, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_17:
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_Solution
# 1680 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SOLUTION, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_18:
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SOLUTION, FLAG_TRAINER5_SOLUTION
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_74
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_19:
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_Solution
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SOLUTION, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_20:
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_Solution
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SOLUTION, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_21:
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SOLUTION, FLAG_TRAINER6_SOLUTION
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_76
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_22:
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_Solution
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SOLUTION, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_23:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_Solution
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SOLUTION, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_24:
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_Solution
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SOLUTION, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_25:
# 1735 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SOLUTION, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AskViewExactIcePuzzleSolution, MSGBOX_YESNO
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_78
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_26:
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_Solution
# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SOLUTION, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_27:
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_Solution
# 1752 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SOLUTION, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_28:
# 1756 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SOLUTION, FLAG_SECRET_POWER_SOLUTION
# 1760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AskViewExactIcePuzzleSolution, MSGBOX_YESNO
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_81
EscapeRoom_EventScript_HintsNPC_Solution_80:
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_89
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_29:
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_Solution
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SOLUTION, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_30:
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_Solution
# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SOLUTION, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_31:
# 1783 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SOLUTION, FLAG_TRAINER11_SOLUTION
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution_MoveSetup, MSGBOX_YESNO
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_83
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_36:
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_27
	goto EscapeRoom_EventScript_HintsNPC_Solution_35

EscapeRoom_EventScript_HintsNPC_Solution_65:
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_86
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 120
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC120minAddedMessage
EscapeRoom_EventScript_HintsNPC_Solution_85:
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1819 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SOLUTIONS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_Solution_64

EscapeRoom_EventScript_HintsNPC_Solution_68:
# 1603 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_70:
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_72:
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox intsNPC_Trainer3_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_74:
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_76:
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_78:
# 1741 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution_IcePuzzleSteps
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_81:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution_IcePuzzleSteps
	goto EscapeRoom_EventScript_HintsNPC_Solution_80

EscapeRoom_EventScript_HintsNPC_Solution_83:
# 1791 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_91
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_86:
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_Solution_85

EscapeRoom_EventScript_HintsNPC_Solution_89:
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_91:
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 1837 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1852 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1878 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_MAX_REVIVE, EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_23
EscapeRoom_EventScript_ReturnLostItems_22:
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_33
EscapeRoom_EventScript_ReturnLostItems_32:
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_42:
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_49
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_49
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MAX_REVIVE
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 1924 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 1944 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_28
EscapeRoom_EventScript_ReturnLostItems_26:
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_35
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_23:
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 1972 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_22

EscapeRoom_EventScript_ReturnLostItems_25:
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_27:
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_25
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_28:
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_27
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_33:
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1981 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_32

EscapeRoom_EventScript_ReturnLostItems_35:
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_38:
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_47
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_43:
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_54:
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_68
EscapeRoom_EventScript_ReturnLostItems_67:
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_79
EscapeRoom_EventScript_ReturnLostItems_78:
# 2021 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_83
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_44:
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_47:
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 1991 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_49:
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_63
EscapeRoom_EventScript_ReturnLostItems_61:
# 2063 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_59
EscapeRoom_EventScript_ReturnLostItems_57:
# 2076 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_70
	return

EscapeRoom_EventScript_ReturnLostItems_55:
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_54

EscapeRoom_EventScript_ReturnLostItems_58:
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_72
# 2048 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_59:
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2067 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_62:
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_58
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_63:
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_62
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_68:
# 2008 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_67

EscapeRoom_EventScript_ReturnLostItems_70:
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_72:
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_73:
# 2050 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_81
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_76:
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_79:
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2016 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_78

EscapeRoom_EventScript_ReturnLostItems_81:
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2057 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_83:
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_42


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 2096 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2097 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 2115 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 2122 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2136 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 2161 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_29
EscapeRoom_EventScript_UndoUsedItems_28:
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_32
EscapeRoom_EventScript_UndoUsedItems_31:
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
EscapeRoom_EventScript_UndoUsedItems_34:
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_42
EscapeRoom_EventScript_UndoUsedItems_41:
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 2198 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SECRET_POWER
# 2200 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 2204 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_44
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 2123 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2124 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 2129 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2130 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_ANNIHILAPE
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2138 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_29:
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2171 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_28

EscapeRoom_EventScript_UndoUsedItems_32:
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_31

EscapeRoom_EventScript_UndoUsedItems_35:
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_34

EscapeRoom_EventScript_UndoUsedItems_42:
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_41

EscapeRoom_EventScript_UndoUsedItems_44:
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38:
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21:
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 2264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2290 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 2295 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 2296 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45:
# 2304 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 2311 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66:
# 2332 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72:
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 2343 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 2228 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 2242 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSecretPower, OptionUndoRareCandy
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13:
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14:
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37:
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41:
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 2309 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 2312 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 2316 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 2326 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76
# 2330 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70:
# 2320 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73:
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79
# 2337 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76:
# 2327 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79:
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 2354 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_5
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_6
EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_10
# 2375 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_11
EscapeRoom_EventScript_AskUndoMoveTeach_9:
# 2383 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 2384 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2387 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_18
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 2349 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2350 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_5:
# 2355 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2356 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_14
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_6:
# 2362 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 2363 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_16
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_10:
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_20
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_11:
# 2376 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 2377 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_22
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_14:
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_16:
# 2364 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_18:
# 2389 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_AskUndoMoveTeach_20:
# 2371 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_22:
# 2378 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9


EscapeRoom_EventScript_UndoMoveTeach::
# 2395 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2398 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 2399 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 2420 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 2424 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_10:
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_32:
# 2477 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2478 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2482 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_46
EscapeRoom_EventScript_UndoMoveTeach_45:
# 2489 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 2491 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_57
EscapeRoom_EventScript_UndoMoveTeach_55:
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_53:
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 2551 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_65
EscapeRoom_EventScript_UndoMoveTeach_64:
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_74
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_23
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 2416 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 2404 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 2428 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, VAR_0x8008
# 2429 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 2407 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, VAR_0x8008
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_23:
# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_26:
# 2440 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_41
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_33:
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM43
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_35:
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_39:
# 2443 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_40:
# 2449 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_41:
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_40
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_46:
# 2483 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2484 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_45

EscapeRoom_EventScript_UndoMoveTeach_49:
# 2450 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2451 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2455 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 2505 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2507 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_56:
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_57:
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_56
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_62:
# 2521 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2522 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_69
EscapeRoom_EventScript_UndoMoveTeach_67:
# 2527 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_85
EscapeRoom_EventScript_UndoMoveTeach_83:
# 2534 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 2535 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 2536 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_94
EscapeRoom_EventScript_UndoMoveTeach_93:
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_99
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_65:
# 2552 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_80
EscapeRoom_EventScript_UndoMoveTeach_78:
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_90
EscapeRoom_EventScript_UndoMoveTeach_88:
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 2567 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_97
EscapeRoom_EventScript_UndoMoveTeach_96:
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_101
	goto EscapeRoom_EventScript_UndoMoveTeach_64

EscapeRoom_EventScript_UndoMoveTeach_68:
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2525 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_69:
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_68
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_72:
# 2585 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 2586 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_73:
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_72
	return

EscapeRoom_EventScript_UndoMoveTeach_74:
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_73
	return

EscapeRoom_EventScript_UndoMoveTeach_79:
# 2555 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2556 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_80:
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_79
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_84:
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2530 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_85:
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_84
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_89:
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_90:
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_89
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_94:
# 2537 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2538 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 2539 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_93

EscapeRoom_EventScript_UndoMoveTeach_97:
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 2570 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_96

EscapeRoom_EventScript_UndoMoveTeach_99:
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_101:
# 2575 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 2576 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2579 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_64


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 2595 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 2600 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 2603 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 2612 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 2607 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 2608 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 2620 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 2626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 2629 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 2638 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 2642 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 2624 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 2627 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 2630 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 2645 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 2654 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 2668 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 2671 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 2686 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_31
EscapeRoom_EventScript_UndoRareCandy_30:
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 2707 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 2708 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
EscapeRoom_EventScript_UndoRareCandy_27:
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_36
# 2804 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_38
EscapeRoom_EventScript_UndoRareCandy_35:
# 2813 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_48
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 2646 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2647 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 2655 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2656 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2677 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 2660 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_33
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_43
EscapeRoom_EventScript_UndoRareCandy_42:
# 2736 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2737 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_51
EscapeRoom_EventScript_UndoRareCandy_50:
# 2748 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2749 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_59
EscapeRoom_EventScript_UndoRareCandy_58:
# 2761 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_68
EscapeRoom_EventScript_UndoRareCandy_66:
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_77
EscapeRoom_EventScript_UndoRareCandy_75:
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_31:
# 2688 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2689 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2691 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 2694 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_30

EscapeRoom_EventScript_UndoRareCandy_33:
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_36:
# 2802 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_37:
# 2805 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_38:
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_43:
# 2730 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2731 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2732 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2733 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_42

EscapeRoom_EventScript_UndoRareCandy_46:
# 2699 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2700 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2701 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2702 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 2705 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_48:
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_55
EscapeRoom_EventScript_UndoRareCandy_54:
# 2850 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 2851 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_64
	return

EscapeRoom_EventScript_UndoRareCandy_51:
# 2740 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2741 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2742 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2744 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_50

EscapeRoom_EventScript_UndoRareCandy_53:
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_61
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_73
	return

EscapeRoom_EventScript_UndoRareCandy_55:
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_53
	goto EscapeRoom_EventScript_UndoRareCandy_54

EscapeRoom_EventScript_UndoRareCandy_59:
# 2753 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2754 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2755 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_58

EscapeRoom_EventScript_UndoRareCandy_61:
# 2824 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_71
	return

EscapeRoom_EventScript_UndoRareCandy_64:
# 2853 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005, reverse = FALSE
# 2854 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2859 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_67:
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2777 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2778 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2779 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2780 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_68:
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_67
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_71:
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM, reverse = FALSE
# 2827 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2828 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2831 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2832 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_73:
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return

EscapeRoom_EventScript_UndoRareCandy_76:
# 2785 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2786 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2789 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2790 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2791 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_75

EscapeRoom_EventScript_UndoRareCandy_77:
# 2783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_76
	goto EscapeRoom_EventScript_UndoRareCandy_75


EscapeRoom_EventScript_UndoExpCandy::
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2872 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 2878 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2883 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2884 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 2905 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 2922 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 2923 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2926 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 2898 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 2906 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 2907 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 2915 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 2905 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 2908 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 2916 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 2931 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 2932 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 2950 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 2954 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 2960 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 2961 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 2939 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2940 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2944 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2948 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 2951 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2952 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 2955 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 2956 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 2966 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2967 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 2974 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 2975 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 2978 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2980 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2983 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2970 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 2988 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2989 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 2996 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 3001 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 3002 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3003 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3006 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 2990 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 2991 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2992 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_LiepardNPC::
# 3013 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3014 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 3019 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 3020 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3023 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 3024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 3026 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3027 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3028 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 3029 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3030 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3031 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3034 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3035 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 3036 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3038 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3043 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 3044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3045 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3047 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 3048 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 3049 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3050 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 3052 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3053 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3054 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3057 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 3058 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 3060 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3063 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 3064 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 3065 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 3066 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 3069 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 3070 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3071 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 3072 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 3082 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3083 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 3084 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3085 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3086 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3087 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 3088 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 3096 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3097 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 3100 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 3090 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3091 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 3109 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 3112 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 3113 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 3113 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 3116 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3118 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 3121 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 3122 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3124 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 3125 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 3129 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3130 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 3152 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3153 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 3154 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3155 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 3159 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3164 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 3178 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3179 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 3185 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 3186 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3189 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 3190 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3191 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 3192 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 3198 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3199 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3200 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 3203 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 3204 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 3208 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 3212 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 3215 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3218 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 3221 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 3222 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3225 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 3233 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 3236 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3237 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 3238 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3240 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 3243 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 3244 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 3245 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 3246 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 3247 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 3248 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 3249 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 3256 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3257 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3260 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 3270 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 3276 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 3283 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 3284 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 3261 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 3262 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 3272 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 3273 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 3277 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 3278 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 3289 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 3290 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 3293 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 3294 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 3299 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 3302 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 3303 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 3332 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 3333 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 3347 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 3304 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3305 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3306 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3310 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3311 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3312 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3313 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 3319 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3320 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3321 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 3324 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3325 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3326 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3327 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3328 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 3334 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3335 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3336 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 3339 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3341 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3342 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3343 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 3349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 3350 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 3355 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3356 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 3359 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 3361 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 3368 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3370 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 3383 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 3384 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 3400 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 3371 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 3379 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 3372 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3375 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 3407 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3408 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 3409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 3411 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3412 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3420 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 3421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3422 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 3425 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 3426 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3429 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 3430 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 3434 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 3438 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 3442 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3443 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 3444 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 3445 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3448 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 3452 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 3459 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3460 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3461 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3462 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3464 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3465 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3467 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 3468 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 3470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3471 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 3473 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3474 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3476 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3483 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 3484 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3486 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 3487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3488 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 3490 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3492 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 3499 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3501 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 3508 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3509 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 3515 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3516 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 3522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 3523 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 3526 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 3504 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 3510 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 3517 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 3530 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3531 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 3548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3549 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 3534 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 3535 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 3536 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3537 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 3538 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3540 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3542 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SUN_STONE_SOLD
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 3545 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 3554 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3555 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 3566 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 3558 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 3559 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_IRON_BALL
# 3560 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 3562 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_IronBall, MSGBOX_NPC
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoSecretPowerTeach::
# 3577 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3578 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_2
EscapeRoom_EventScript_UndoSecretPowerTeach_1:
# 3588 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_5
EscapeRoom_EventScript_UndoSecretPowerTeach_4:
# 3593 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_10
EscapeRoom_EventScript_UndoSecretPowerTeach_9:
# 3604 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 3605 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_13
EscapeRoom_EventScript_UndoSecretPowerTeach_12:
# 3612 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_SECRET_POWER
# 3613 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_SECRET_POWER, VAR_0x8004
# 3614 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_SECRET_POWER
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
EscapeRoom_EventScript_UndoSecretPowerTeach_17:
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
EscapeRoom_EventScript_UndoSecretPowerTeach_22:
# 3627 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
# 3627 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
EscapeRoom_EventScript_UndoSecretPowerTeach_27:
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
EscapeRoom_EventScript_UndoSecretPowerTeach_32:
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
EscapeRoom_EventScript_UndoSecretPowerTeach_43:
# 3677 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3678 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3679 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 3681 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSecretPowerTeach_2:
# 3579 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3582 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3583 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_7
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_5:
# 3590 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_4

EscapeRoom_EventScript_UndoSecretPowerTeach_7:
# 3584 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_10:
# 3595 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 3598 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3599 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_15
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_13:
# 3606 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_12

EscapeRoom_EventScript_UndoSecretPowerTeach_15:
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_18:
# 3618 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3619 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_17

EscapeRoom_EventScript_UndoSecretPowerTeach_23:
# 3622 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3623 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_22

EscapeRoom_EventScript_UndoSecretPowerTeach_28:
# 3630 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3631 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_37
# 3636 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_39
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_33:
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 3656 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_49
EscapeRoom_EventScript_UndoSecretPowerTeach_48:
# 3659 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3660 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_59
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_37:
# 3633 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_38:
# 3639 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_52
# 3643 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_53
EscapeRoom_EventScript_UndoSecretPowerTeach_51:
# 3647 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_39:
# 3636 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_38
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_44:
# 3666 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 3667 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_57
EscapeRoom_EventScript_UndoSecretPowerTeach_56:
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_61
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43

EscapeRoom_EventScript_UndoSecretPowerTeach_49:
# 3657 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_48

EscapeRoom_EventScript_UndoSecretPowerTeach_52:
# 3640 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3641 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_53:
# 3644 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3645 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_57:
# 3668 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_56

EscapeRoom_EventScript_UndoSecretPowerTeach_59:
# 3661 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_61:
# 3672 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43


EscapeRoom_EventScript_UndoRareCandy_IcePuzzle::
# 3686 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 3687 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3695 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1:
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5:
# 3709 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8:
# 3723 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3724 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3727 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15:
# 3738 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24:
# 3749 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_33
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32:
# 3759 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_AUTOCLOSE
# 3760 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13:
# 3764 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 3767 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21:
# 3853 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2:
# 3691 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6:
# 3701 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3702 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9:
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3711 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11:
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14:
# 3728 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 3729 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3730 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3731 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_AUTOCLOSE
# 3732 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16:
# 3727 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19:
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 3715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22:
# 3778 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3779 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_30
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29:
# 3788 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_36
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35:
# 3800 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3801 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_38:
# 3813 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 3821 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3822 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41:
# 3834 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3835 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_48
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46:
# 3849 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25:
# 3740 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3741 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3742 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 3746 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27:
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_30:
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3783 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3784 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3785 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3786 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_33:
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3752 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3753 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3754 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 3757 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_36:
# 3792 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3793 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3794 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39:
# 3805 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3806 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3807 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_38

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42:
# 3824 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3825 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3828 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3829 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3830 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3831 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3832 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43:
# 3822 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47:
# 3837 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3838 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3841 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3842 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3844 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3845 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_48:
# 3835 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46


EscapeRoom_EventScript_CheckRareCandy2Stolen::
# 3857 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 3858 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_EventScript_CheckRareCandy2Stolen_2
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_1:
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_COMPLETED
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_2:
# 3858 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_CheckRareCandy2Stolen_1
	return


EscapeRoom_AnnihilapeHintNPC::
# 3867 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3870 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 3882 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 3883 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 3885 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 3871 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 3872 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3873 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3874 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 3876 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3877 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 3878 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 3889 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3890 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 3893 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 3897 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 3899 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 3891 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 3894 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer0::
# 3906 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 3913 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 3914 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer1::
# 3919 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3920 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 3929 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 3933 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 3934 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 3930 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 3939 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 3945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 3946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3952 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 3959 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 3960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 3965 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 3971 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 3972 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 3979 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 3980 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 3988 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 3997 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 4004 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 4005 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 3981 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3982 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 3983 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 3980 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 3989 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 3990 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 3991 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IRON_BALL_CONSUMED
# 3992 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 3993 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 4010 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 4017 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 4018 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 4023 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 4030 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 4031 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 4036 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 4043 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 4044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 4049 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 4057 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4058 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_Trainer8_2
EscapeRoom_EventScript_Trainer8_1:
# 4062 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4063 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer8_2:
# 4059 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4060 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8_1


EscapeRoom_EventScript_Trainer9::
# 4068 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 4075 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 4076 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 4081 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 4088 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 4089 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 4095 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_Trainer11_2
EscapeRoom_EventScript_Trainer11_1:
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 4109 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4110 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4111 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_Trainer11_5
# 4116 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FINAL_MESSAGE_READ, EscapeRoom_EventScript_Trainer11_9
EscapeRoom_EventScript_Trainer11_8:
# 4129 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SS_TICKET
# 4130 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer11_11
# 4136 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_EndTheGame, MSGBOX_YESNO
# 4137 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_Trainer11_16
EscapeRoom_EventScript_Trainer11_4:
# 4143 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer11_2:
# 4096 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4097 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
	goto EscapeRoom_EventScript_Trainer11_1

EscapeRoom_EventScript_Trainer11_5:
# 4112 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_A, MSGBOX_AUTOCLOSE
# 4113 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer11_4

EscapeRoom_EventScript_Trainer11_9:
# 4117 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FINAL_MESSAGE_READ
# 4118 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_B, MSGBOX_AUTOCLOSE
# 4119 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4120 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 4123 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 0
	goto_if_eq EscapeRoom_EventScript_Trainer11_14
	goto EscapeRoom_EventScript_Trainer11_8

EscapeRoom_EventScript_Trainer11_11:
# 4131 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AlternativeEnding
	goto EscapeRoom_EventScript_Trainer11_4

EscapeRoom_EventScript_Trainer11_14:
# 4124 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
	goto EscapeRoom_EventScript_Trainer11_8

EscapeRoom_EventScript_Trainer11_16:
# 4138 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4139 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame
	goto EscapeRoom_EventScript_Trainer11_4


EscapeRoom_EventScript_PostMatchHeal::
# 4150 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 4155 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4158 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 4173 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 4174 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 4159 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 4163 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4164 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 4167 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4168 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 4161 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 4165 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 4169 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 4179 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4182 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4183 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4184 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 4192 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 4195 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 4201 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4202 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4203 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4204 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4205 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4206 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 4207 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4208 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 4209 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 4210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 4219 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4220 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 4222 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 4185 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4186 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 4212 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4213 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4214 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 4209 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 4209 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 4187 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4188 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 4229 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4232 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4233 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 4241 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 4242 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4245 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 4252 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4253 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4255 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4256 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 4262 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 4235 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4236 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 4258 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4260 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 4237 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4238 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4271 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 4274 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4275 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 4278 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 4283 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4284 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4286 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 4287 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4288 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4291 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 4297 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4304 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 4306 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4307 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 4314 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 4276 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 4279 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 4310 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4311 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4312 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 4318 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 4319 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 4320 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4320 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4321 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 4325 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 4326 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4331 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4332 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4333 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4334 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4335 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 4336 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 4337 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 4343 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 4346 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 4339 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4340 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4341 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 4337 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 4351 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4354 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 4366 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 4378 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_IRON_BALL_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 4390 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 4402 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 4413 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 4355 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4356 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4360 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 4367 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 4371 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4372 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 4357 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 4379 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4380 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_IRON_BALL
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 4383 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4384 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_IRON_BALL
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 4369 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 4361 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 4391 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4392 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 4395 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4396 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 4381 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 4373 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 4403 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4404 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 4407 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 4393 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 4385 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 4405 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 4397 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 4409 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 4419 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4422 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 4425 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 4426 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 4435 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 4436 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 4445 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 4447 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4450 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 4457 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4458 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4459 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4460 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4462 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 4463 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4464 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 4465 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 4467 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 4468 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 4469 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 4470 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 4472 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 4473 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4474 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 4475 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4476 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_IRON_BALL
# 4477 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 4478 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 4479 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 4481 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 4482 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 4483 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 4484 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 4486 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4487 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4488 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4489 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4490 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4491 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4492 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4493 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4495 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4496 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4497 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4498 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4499 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4500 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 4428 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4429 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 4438 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4439 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 4430 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 4503 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4504 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4505 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4506 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 4440 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4441 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 4511 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 4512 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4517 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 4518 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 4519 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 4525 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 4521 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4523 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 4529 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 4530 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4532 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4533 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4534 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4535 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 4540 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 4541 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4548 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4549 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4550 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 4551 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4552 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4553 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 4554 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 4562 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_CUT
# 4565 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4566 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4567 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4569 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 4556 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4557 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4558 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 4573 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4577 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 4585 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4586 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4587 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4588 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4591 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4592 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 4598 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 4594 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4595 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4596 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 4602 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 4603 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4606 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 4615 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4616 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4617 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4618 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4619 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 35
# 4620 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4620 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_BAGON
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 4621 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4622 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4623 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4624 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4625 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 4631 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 4627 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4629 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 4635 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 4636 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4641 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4644 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_FINAL_BATTLE_REACHED, 1
# 4645 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_END_ESCAPE_ROOM_STATE, 1
# 4648 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer11End
# 4649 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4652 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxy 5, 3, 34
# 4653 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4654 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 5
# 4655 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_CHAMPION
# 4657 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 4661 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer11End:
# 4662 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
	step_end

EscapeRoom_EventScript_TradeZeraForHMCut::
# 4670 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4671 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 4672 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 4699 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 4701 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 4676 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4677 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4678 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 4687 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 4690 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4691 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4692 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4695 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 4696 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 4680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4681 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4682 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 4705 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4706 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4709 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 4734 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 4735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 4792 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 4793 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 4796 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 4712 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 4728 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 4729 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 4713 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 4714 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 4722 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 4723 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 4738 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 4739 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4740 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 4749 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 4752 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 4753 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4754 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4756 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4759 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4761 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4764 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 4765 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 4787 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 4716 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 4718 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 4719 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 4742 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4743 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4744 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 4801 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4802 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4805 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 4830 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 4831 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 4865 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 4866 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 4869 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 4808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 4824 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 4825 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 4809 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 4810 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4811 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 4818 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 4819 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 4834 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4835 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4836 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 4845 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 4848 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 4849 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4850 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4851 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4854 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4855 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4856 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4859 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 4860 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 4861 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 4812 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 4814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 4815 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 4838 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4839 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4840 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 4873 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4874 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4877 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 4883 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 4884 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 4913 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 4914 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 4917 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 4878 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 4879 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 4887 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 4888 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4889 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 4898 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 4899 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4900 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 4903 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4904 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4905 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4908 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 4909 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 4891 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4892 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4893 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_GetChoiceItem::
# 4925 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetChoiceItem_1
# 4970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsNoLongerAvailable, MSGBOX_DEFAULT
# 4971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_1:
# 4928 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsWhichOne, MSGBOX_DEFAULT
# 4929 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4932 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionChoiceBand, OptionChoiceSpecs, OptionChoiceScarf
# 4935 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_5
# 4938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_6
# 4941 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_7
# 4945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsComeAgain, MSGBOX_DEFAULT
# 4946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_4:
# 4951 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem
# 4954 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RemoveChoiceItem
# 4957 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem VAR_0x8006
# 4960 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_GetChoiceItem_12
# 4965 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CHOICE_ITEM_OBTAINED
	return

EscapeRoom_EventScript_GetChoiceItem_5:
# 4936 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_BAND
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_6:
# 4939 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SPECS
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_7:
# 4942 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SCARF
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_12:
# 4961 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsSwapped, MSGBOX_DEFAULT
# 4962 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem::
# 4976 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 4979 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem VAR_0x8006
# 4980 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1:
# 4984 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4985 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4:
# 4992 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4993 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7:
# 5002 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10
	return

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2:
# 4981 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5:
# 4986 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual1
# 4988 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4990 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual1:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8:
# 4994 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4995 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual2
# 4996 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4998 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual2:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10:
# 5003 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsAlreadyHaveThis, MSGBOX_DEFAULT
# 5004 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5005 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_RemoveChoiceItem::
# 5011 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_BAND
# 5012 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SPECS
# 5013 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SCARF
# 5015 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 5016 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_3
EscapeRoom_EventScript_RemoveChoiceItem_1:
# 5023 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 5024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_11
	return

EscapeRoom_EventScript_RemoveChoiceItem_2:
# 5020 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_3:
# 5017 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 5018 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 5019 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_10:
# 5028 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	return

EscapeRoom_EventScript_RemoveChoiceItem_11:
# 5025 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 5026 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 5027 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 5036 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5037 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 5038 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 5039 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 5040 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 5044 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5045 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 5046 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 5047 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 5048 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 5052 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5053 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 5054 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 5055 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 5056 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindTMSecretPower::
# 5060 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5061 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_TM43
# 5062 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 5063 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_OBTAINED
# 5064 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy2::
# 5068 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5069 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 5070 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 5071 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 19
# 5074 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 1
# 5076 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRescueBell::
# 5080 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5081 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SOOTHE_BELL
# 5082 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RESCUE_BELL_OBTAINED
# 5083 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 5085 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RescueBellExplainMessage, MSGBOX_AUTOCLOSE
# 5086 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5088 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 5096 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5099 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 5107 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet1_Onix, MSGBOX_DEFAULT
# 5110 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 5113 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 5116 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 5119 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 5124 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 5139 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 5100 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5102 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 5111 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 5114 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 5117 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 5120 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 5125 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5126 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 5127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5128 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 5136 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 5132 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 5143 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5146 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 5154 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet2_Toedscruel, MSGBOX_DEFAULT
# 5157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 5160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 5163 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 5166 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 5171 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 5147 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5148 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5149 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 5158 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 5161 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 5164 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 5167 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 5172 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5173 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 5174 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5175 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 5183 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 5179 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 5189 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5192 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 5200 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet3_Dusknoir, MSGBOX_DEFAULT
# 5203 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 5206 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 5209 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 5212 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 5217 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 5231 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 5193 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5194 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5195 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 5204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 5207 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 5210 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 5213 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 5218 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5219 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 5220 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5221 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5224 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 5229 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 5225 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 5235 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5238 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 5246 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 5251 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet4_Dunsparce, MSGBOX_DEFAULT
# 5254 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 5257 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 5260 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 5263 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 5268 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 5282 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 5239 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5240 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5241 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 5247 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 5255 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 5258 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 5261 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 5264 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 5269 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5270 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 5271 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5272 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5275 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 5280 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 5276 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 5287 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 5292 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5293 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 5294 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 5289 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 5288 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 5290 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 5299 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5300 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 5301 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 5302 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5303 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5304 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5305 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5306 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 5307 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5308 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 5309 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5310 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5311 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 5318 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5321 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 5324 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 5329 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 5352 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 5353 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 5325 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 5357 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5358 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5359 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5363 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5367 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 5371 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 5381 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5382 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5383 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 5387 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5388 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5390 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 5374 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 5375 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5377 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 5373 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 5372 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 5394 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5395 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5396 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5400 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5404 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 5407 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 5408 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 5409 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 5416 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5417 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5418 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5420 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 5411 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5412 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 5424 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5425 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5426 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5430 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 1
	goto_if_eq EscapeRoom_EventScript_GraveStone3_2
# 5430 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 5
	goto_if_eq EscapeRoom_EventScript_GraveStone3_2
# 5434 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone3_1:
# 5439 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_8
# 5443 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_11
# 5450 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_12
# 5451 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_12
# 5458 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_10:
# 5461 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5462 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5464 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
# 5431 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone3_1

EscapeRoom_EventScript_GraveStone3_8:
	end

EscapeRoom_EventScript_GraveStone3_11:
# 5445 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 5446 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5448 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_10

EscapeRoom_EventScript_GraveStone3_12:
# 5453 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5454 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5455 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_10


EscapeRoom_EventScript_GraveStone4::
# 5468 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5469 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5470 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5474 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 3
	goto_if_eq EscapeRoom_EventScript_GraveStone4_2
# 5474 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 4
	goto_if_eq EscapeRoom_EventScript_GraveStone4_2
# 5478 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone4_1:
# 5483 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_8
# 5486 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_9
# 5487 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_9
# 5488 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_9
EscapeRoom_EventScript_GraveStone4_7:
# 5495 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5496 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5497 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5499 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
# 5475 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone4_1

EscapeRoom_EventScript_GraveStone4_8:
	end

EscapeRoom_EventScript_GraveStone4_9:
# 5490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5491 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_7


EscapeRoom_EventScript_GraveStone5::
# 5503 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5504 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5505 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5509 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5513 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 5516 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 5517 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 5518 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 5525 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5526 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5527 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5529 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 5520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5521 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 5533 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5539 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5543 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 5546 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 5547 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 5548 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 5555 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5556 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5557 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5559 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 5550 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5551 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 5563 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5565 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5569 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 6
	goto_if_eq EscapeRoom_EventScript_GraveStone7_4
EscapeRoom_EventScript_GraveStone7_3:
# 5574 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone7_1:
# 5579 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_8
# 5583 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_11
# 5588 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_12
# 5589 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_12
# 5600 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5601 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5602 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_10:
# 5605 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
# 5570 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STATE, 1
# 5571 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_MainEasterEggStep1Complete
	goto EscapeRoom_EventScript_GraveStone7_1

EscapeRoom_EventScript_GraveStone7_4:
# 5569 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 0
	goto_if_eq EscapeRoom_EventScript_GraveStone7_2
	goto EscapeRoom_EventScript_GraveStone7_3

EscapeRoom_EventScript_GraveStone7_8:
	end

EscapeRoom_EventScript_GraveStone7_11:
# 5585 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 5586 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_10

EscapeRoom_EventScript_GraveStone7_12:
# 5591 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5592 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5594 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5595 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5596 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_10


EscapeRoom_EventScript_GraveStone8::
# 5609 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5610 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5611 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5615 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 0
	goto_if_eq EscapeRoom_EventScript_GraveStone8_2
# 5619 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone8_1:
# 5624 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_6
# 5628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_9
# 5635 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_10
# 5636 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_10
# 5643 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_8:
# 5646 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5647 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5649 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
# 5616 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone8_1

EscapeRoom_EventScript_GraveStone8_6:
	end

EscapeRoom_EventScript_GraveStone8_9:
# 5630 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 5631 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5633 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_8

EscapeRoom_EventScript_GraveStone8_10:
# 5638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5639 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5640 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_8


EscapeRoom_EventScript_GraveStone9::
# 5653 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5659 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_GRAVESTONE_EASTER_EGG, 2
	goto_if_eq EscapeRoom_EventScript_GraveStone9_2
# 5663 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
EscapeRoom_EventScript_GraveStone9_1:
# 5668 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_6
# 5671 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_7
# 5672 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_7
# 5673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_7
EscapeRoom_EventScript_GraveStone9_5:
# 5680 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5681 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5682 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5684 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
# 5660 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_GRAVESTONE_EASTER_EGG, 1
	goto EscapeRoom_EventScript_GraveStone9_1

EscapeRoom_EventScript_GraveStone9_6:
	end

EscapeRoom_EventScript_GraveStone9_7:
# 5675 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5676 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_5


EscapeRoom_EventScript_GraveStone0::
# 5688 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5689 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5690 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5694 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_GRAVESTONE_EASTER_EGG, 0
# 5698 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 5701 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 5702 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 5703 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 5710 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5711 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5712 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5714 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 5705 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5706 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 5718 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5719 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 5721 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 5722 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5723 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5724 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5725 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5726 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5727 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5728 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5730 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 5731 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 5732 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5733 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5735 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_SPAWNED
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 5739 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5742 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 5778 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 5779 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 5782 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 5744 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 5745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 5772 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 5773 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 5748 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5749 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 5750 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 5753 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 5754 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 5745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 5757 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 5758 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 5763 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5764 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5765 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 5766 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 5759 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 5760 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 5787 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5788 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5789 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5790 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 5791 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5792 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5793 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 5796 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 5797 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 5798 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 5799 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 5800 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_NIGHTMARE
# 5801 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5802 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5803 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5804 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 5805 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 5806 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5807 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5810 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5811 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 5812 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 5813 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_NONE
# 5814 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 5818 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5819 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 5820 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5821 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndGame::
# 5828 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5829 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 5832 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame_EnterBoat
# 5835 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5836 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 5839 "data/maps/EscapeRoom_Main/scripts.pory"
	special GameClear
# 5840 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5841 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EndGame_EnterBoat::
# 5846 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 5847 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq EscapeRoom_EventScript_EndGame_EnterBoat_2
# 5851 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq EscapeRoom_EventScript_EndGame_EnterBoat_3
EscapeRoom_EventScript_EndGame_EnterBoat_1:
# 5855 "data/maps/EscapeRoom_Main/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ESCAPE_ROOM_MAIN
# 5856 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 5858 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, ChampionEnterBoat
# 5859 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 5860 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 34
# 5861 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 35
# 5864 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 35, BoatSailAway
	return

EscapeRoom_EventScript_EndGame_EnterBoat_2:
# 5848 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EnterBoat2
# 5849 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_EndGame_EnterBoat_1

EscapeRoom_EventScript_EndGame_EnterBoat_3:
# 5852 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EnterBoat1
# 5853 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_EndGame_EnterBoat_1


# 5867 "data/maps/EscapeRoom_Main/scripts.pory"
EnterBoat1:
# 5868 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5869 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 5871 "data/maps/EscapeRoom_Main/scripts.pory"
EnterBoat2:
# 5872 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 5873 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 5874 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5875 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 5875 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 5877 "data/maps/EscapeRoom_Main/scripts.pory"
ChampionEnterBoat:
# 5878 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 5879 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 5880 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5881 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
	step_end

# 5883 "data/maps/EscapeRoom_Main/scripts.pory"
BoatSailAway:
# 5884 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
# 5885 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_slow_down
	step_end

EscapeRoom_EventScript_EscapeRopeEE_message1::
# 5892 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5893 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 2
# 5894 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 5895 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 5896 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 5897 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5898 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EscapeRopeEE_message2andwarp::
# 5902 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROPE_EE_STATE, 3
# 5903 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRopeEEMessage2, MSGBOX_AUTOCLOSE
# 5904 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5905 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 47, 17
# 5906 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_AlternativeEnding::
# 5912 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5913 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 5916 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 5917 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 5918 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 34
# 5919 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 5922 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox TakeEasterEggBoatMessage, MSGBOX_AUTOCLOSE
# 5923 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5926 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndGame_EnterBoat
# 5929 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 150
# 5930 "data/maps/EscapeRoom_Main/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 9, 10
# 5931 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5933 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EasterEggFinalMessage::
# 5939 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 5940 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggCompletedMessage1
# 5941 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 5942 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggCompletedMessage2, MSGBOX_AUTOCLOSE
# 5946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5949 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 5950 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 5951 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 5952 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 7
# 5953 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_CHAMPION_BF
# 5954 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 5955 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 5958 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAIN_EASTER_EGG_COMPLETED
# 5959 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_COMPLETED, 1
	return


EscapeRoom_EventScript_ObtainBoatTicket::
# 5963 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5964 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SS_TICKET
# 5965 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterStep0_HintNPC::
# 5970 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5971 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 5972 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggHintMessage, MSGBOX_AUTOCLOSE
# 5973 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5976 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 5977 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 15
# 5978 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 17
# 5979 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
# 5980 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 5982 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggStep1Complete::
# 5987 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5988 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5989 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 5990 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5991 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5993 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep1Completed_HintMessage, MSGBOX_AUTOCLOSE
# 5994 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5995 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5997 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep1Completed, MSGBOX_AUTOCLOSE
# 5998 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6001 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_EASTER_EGG_HINT_0_NPC
	return


EscapeRoom_EventScript_MainEasterEggStep2WallSign::
# 6006 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6007 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_EASTER_EGG_ROCK_SMACH_USED, EscapeRoom_EventScript_MainEasterEggStep2WallSign_2
# 6012 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep2WallSignMessageOpened, MSGBOX_AUTOCLOSE
# 6013 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_MainEasterEggStep2WallSign_1:
# 6015 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainEasterEggStep2WallSign_2:
# 6008 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep2WallSignMessage, MSGBOX_AUTOCLOSE
# 6009 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainEasterEggStep2WallSign_1


EscapeRoom_EventScript_MainEasterEggStep2Complete::
# 6019 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6020 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STATE, 2
# 6021 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAIN_EASTER_EGG_STEP2_COMPLETE_MSG, 0
# 6023 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 6024 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep2Completed, MSGBOX_AUTOCLOSE
# 6025 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6026 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MainEasterEggStep3WallSign::
# 6031 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 6032 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EasterEggStep3WallSignMessage, MSGBOX_AUTOCLOSE
# 6033 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 6034 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


SomethingsGoneWrongMessage::
# 6043 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 6050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 6054 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 6060 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6084 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6115 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to check?$"

GameCompletionMessage::
# 6119 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed roughly {STR_VAR_1}% of the\n"
	.string "game so far.$"

GameCompletionMessageInitial::
# 6124 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed 0% of the game so far.$"

GameCompletionMessageFinal::
# 6128 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've fully completed the game!$"

SignMessageReadInfoAgain::
# 6132 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

MoveDeleterSignMessage::
# 6138 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6155 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 6161 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 6165 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 6169 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 6174 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 6179 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 6183 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 6187 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 6196 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 6204 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 6209 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 6214 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 6221 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 6230 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 6234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something just opened...$"

MApSwitchesAlreadySolved::
# 6238 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchTablet1_Onix::
# 6243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 95.$"

MapSwitchTablet2_Toedscruel::
# 6250 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 949.$"

MapSwitchTablet3_Dusknoir::
# 6257 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 477.$"

MapSwitchTablet4_Dunsparce::
# 6264 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet engraved with the\n"
	.string "number 206.$"

MapSwitchPointedNorth::
# 6272 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEast::
# 6277 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouth::
# 6282 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWest::
# 6287 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 6294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 6298 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 6302 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 6310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "What kind of hint would you like to get?$"

HintsIntroMessage_Finale::
# 6319 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Please note: for this final challenge,\n"
	.string "hint costs are doubled.\p"
	.string "What kind of hint would you like to get?$"

HintsNPCNoHintMessage::
# 6330 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsFinalMessage::
# 6334 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed the escape room.\n"
	.string "I'm no longer needed!$"

HintsNPCHintAlreadyReceivedMessage::
# 6339 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received this hint so\n"
	.string "no time was added to your clock.$"

HintsNPCSolutionAlreadyReceivedMessage::
# 6344 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received the solution\n"
	.string "so no time was added to your clock.$"

HintsNPC_ReviewPreviousStep::
# 6349 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to review the previous step?\n"
	.string "This won't add any extra time.$"

HintsNPC_ReviewExactSequence::
# 6354 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact move sequence?$"

HintsNPC_AskViewExactIcePuzzleSolution::
# 6358 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact ice puzzle\n"
	.string "steps?$"

HintsNPC15minAddedMessage::
# 6364 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "15 minutes were added to your clock.$"

HintsNPC30minAddedMessage::
# 6368 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "30 minutes were added to your clock.$"

HintsNPC60minAddedMessage::
# 6372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1 hour was added to your clock.$"

HintsNPC120minAddedMessage::
# 6376 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "2 hours were added to your clock.$"

HintsNPC_AnnihilapeSpawn_SmallHint::
# 6383 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Those gravestones seem to be placed in\n"
	.string "an interesting pattern...$"

HintsNPC_ZeraCatchPredamage_SmallHint::
# 6388 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block is what you need,\n"
	.string "but how to get the speed?\p"
	.string "At the graveyard fight the ape.\n"
	.string "Do ghosts always escape?$"

HintsNPC_ZeraoraCatch_SmallHint::
# 6395 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sometimes Zeraora blends in a little too\n"
	.string "well with its environment.\p"
	.string "Can Ferrothorn take advantage?$"

HintsNPC_Trainer0_SmallHint::
# 6401 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sticky Barbs are so annoying.\n"
	.string "If only you had an item.$"

HintsNPC_SafetyGoggles_SmallHint::
# 6406 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An item you're missing may finally be\n"
	.string "within reach.$"

HintsNPC_Trainer1_SmallHint::
# 6411 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora can take out Marowak but needs\n"
	.string "to absorb some additional HP.\p"
	.string "Can both Pokémon carry the Goggles?$"

HintsNPC_MarangaBerry_SmallHint::
# 6417 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Double battles can be difficult.\n"
	.string "Is there a way to avoid them?$"

HintsNPC_Trainer2_SmallHint::
# 6422 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use Cut?$"

HintsNPC_Trainer3_SmallHint::
# 6426 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala is asleep?\n"
	.string "There's gotta be a way to use that.$"

HintsNPC_EggSkip_SmallHint::
# 6431 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Why would you need an egg?$"

HintsNPC_SunStone_SmallHint::
# 6437 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have the ability to progress!$"

HintsNPC_UltraBall_SmallHint::
# 6441 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Someone's got something for you.$"

HintsNPC_Trainer4_SmallHint::
# 6445 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Trump Trump Trump, I feel depleted.\n"
	.string "Assistable moves should be deleted.$"

HintsNPC_TauntHerb_SmallHint::
# 6450 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One new move, your path will unlock.\n"
	.string "Where was that first Rock Smash rock?$"

HintsNPC_MoonStone_SmallHint::
# 6455 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I wonder what the carrier birds are\n"
	.string "carrying today.$"

HintsNPC_BerryJuice_SmallHint::
# 6460 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Are you a Rock Smash rock?\n"
	.string "Because I can't move past you.\p"
	.string "Such a juicy pickup line.$"

HintsNPC_Trainer5_SmallHint::
# 6466 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An Onix so sturdy, I admire.\n"
	.string "The Berry Juice, her true desire.\p"
	.string "That's how Liepard hits her twice.\n"
	.string "Pay Day your partner? That's not nice.$"

HintsNPC_TrapinchRun_SmallHint::
# 6473 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Run!!$"

HintsNPC_RareCandyRevive_SmallHint::
# 6477 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find your way back once more?\n"
	.string "Too bad Liepard will be fainted.$"

HintsNPC_Trainer6_SmallHint::
# 6482 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ring Target Annihilape?\n"
	.string "Yeah, that makes sense.$"

HintsNPC_MapSwitches_SmallHint::
# 6487 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet numbers may have something\n"
	.string "to do with Pokémon...$"

HintsNPC_Trainer7A_SmallHint::
# 6494 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sore eyes?\n"
	.string "Hindsight is 20/20.$"

HintsNPC_Trainer8_SmallHint::
# 6499 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hidden Power Normal does not exist!$"

HintsNPC_IcePuzzleRareCandy_SmallHint::
# 6503 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try taking just one item from the ice\n"
	.string "puzzle.\p"
	.string "Don't be greedy.$"

HintsNPC_Trainer9_SmallHint::
# 6509 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need an extra ¥500?\n"
	.string "Annihilape might help you out.$"

HintsNPC_ToxicOrbSteal_SmallHint::
# 6514 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Muk.$"

HintsNPC_SecretPower_SmallHint::
# 6518 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Make the right choice, revive, and\n"
	.string "you'll have poison.\p"
	.string "That's how you can unlock your Secret\n"
	.string "Power.$"

HintsNPC_RareCandy3_SmallHint::
# 6525 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There are two Secret Bases!$"

HintsNPC_Trainer10_SmallHint::
# 6529 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Kecleon was hit by Flamethrower!\n"
	.string "Huh? Its type didn't change.$"

HintsNPC_Trainer11_SmallHint::
# 6534 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Both of your items are very important!\p"
	.string "Can Heatran be poisoned?\n"
	.string "It's a real struggle.$"

HintsNPC_AnnihilapeSpawn_LargeHint::
# 6545 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones represent a numpad.\n"
	.string "Maybe there's a code written somewhere\l"
	.string "for you to enter.$"

HintsNPC_UltraBall_LargeHint::
# 6551 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's an NPC you still haven't\n"
	.string "interacted with!$"

HintsNPC_ZeraCatchPredamage_LargeHint::
# 6556 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You should pre-damage Ferrothorn for\n"
	.string "Custap Berry Block against Zeraora.\p"
	.string "Grass Knot is great, but Florges is so\n"
	.string "heavy...\p"
	.string "Florges can run?\n"
	.string "That's so spooky!$"

HintsNPC_ZeraoraCatch_LargeHint::
# 6565 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block, Ingrain, Zeraora will stay.\n"
	.string "The Electric type stands in your way.\p"
	.string "One PP, its type will change.\n"
	.string "Which move brings the catch in range?$"

HintsNPC_Trainer0_LargeHint::
# 6572 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Struggling against Rhyperior?\n"
	.string "Skill Swap is really useful!\p"
	.string "Wait, no...\n"
	.string "TM Skill Swap is really useful!$"

HintsNPC_SafetyGoggles_LargeHint::
# 6579 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One of the gravestones is a little\n"
	.string "mysterious.\p"
	.string "Can Zeraora help you out?$"

HintsNPC_Trainer1_LargeHint::
# 6585 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Cut Guy is very tough!\p"
	.string "Zeraora can beat the Marowak, but you\n"
	.string "must use Volt Absorb to keep it alive.\p"
	.string "Start the fight with Grassy Terrain,\n"
	.string "then share the Goggles with Zeraora\l"
	.string "once Lightningrod is removed.$"

HintsNPC_MarangaBerry_LargeHint::
# 6596 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.$"

HintsNPC_Trainer2_LargeHint::
# 6602 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Nature Power won't cut it?\n"
	.string "Just remove the grass.$"

HintsNPC_Trainer3_LargeHint::
# 6607 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala's type keeps Hex from landing.\n"
	.string "Maybe it needs a different held item.\p"
	.string "Magicians never reveal their secret,\n"
	.string "but a little sharing doesn't hurt.\p"
	.string "Why is Komala holding a Snowball?$"

HintsNPC_EggSkip_LargeHint::
# 6615 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.\p"
	.string "...\p"
	.string "Or if you only have one Pokémon.$"

HintsNPC_SunStone_LargeHint::
# 6625 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You should fight some Dusknoir.\n"
	.string "A certain ability might help you out.$"

HintsNPC_Trainer4_LargeHint::
# 6630 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Beating Iron Bundle will require some\n"
	.string "preparation at the Dusknoir.\p"
	.string "Can Thief be used with Assist?\n"
	.string "Don't you worry, there's no pressure if\l"
	.string "you fail.$"

HintsNPC_TauntHerb_LargeHint::
# 6639 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Taunted Dusknoirs Struggle twice,\n"
	.string "but a single hit would be paradise.\p"
	.string "You'd skip the Twins and not disturb.\n"
	.string "Dusknoir just needs a soothing herb.$"

HintsNPC_MoonStone_LargeHint::
# 6646 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You may not be a thief, but you've got\n"
	.string "a new Trick.\p"
	.string "Is it possible to steal the moon?$"

HintsNPC_BerryJuice_LargeHint::
# 6652 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know Pickup has an in-battle\n"
	.string "effect as well?\p"
	.string "It might come in handy at the Rock\n"
	.string "Smash rocks.\p"
	.string "Make sure you're not too quick!$"

HintsNPC_Trainer5_LargeHint::
# 6660 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6674 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Trapped? Just Run Away!$"

HintsNPC_RareCandyRevive_LargeHint::
# 6678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Taunt a Dusknoir, now you can run.\n"
	.string "The other side holds all the fun!\p"
	.string "Want Liepard and the Ape to meet?\n"
	.string "Give your cat get a special treat.$"

HintsNPC_Trainer6_LargeHint::
# 6685 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You'll need to set up for Aipom to use\n"
	.string "Custap Endeavor vs Rayquaza.\p"
	.string "Oh... You want to use Endeavor against\n"
	.string "a Ghost type?\p"
	.string "It's tricky, but with the right item, it\n"
	.string "might just work.\p"
	.string "Endeavor for you, Endeavor for me.$"

HintsNPC_MapSwitches_LargeHint::
# 6698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Four stone tablets, have you seen?\n"
	.string "The numbers Mason, what do they mean!\p"
	.string "Every Pokémon has their own.\n"
	.string "In numerical order they are shown.\p"
	.string "Where can the Pokémon be found?$"

HintsNPC_Trainer7A_LargeHint::
# 6708 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What if Peepers means it litterally?\n"
	.string "Perhaps her eyes really are sore.\p"
	.string "It wouldn't be strange for someone her\n"
	.string "age to be a little short-sighted.\p"
	.string "And Caesar... I totally understand his\n"
	.string "struggle.$"

HintsNPC_Trainer8_LargeHint::
# 6718 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dusclops is sus...\n"
	.string "Is there any move you haven't used?$"

HintsNPC_IcePuzzleRareCandy_LargeHint::
# 6723 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right now, TM Secret Power can't be\n"
	.string "taken out of the ice puzzle.\p"
	.string "Escaping with the Rare Candy is\n"
	.string "possible, but you'll need to find a new\l"
	.string "angle.\p"
	.string "Try to avoid instant gratification.$"

HintsNPC_Trainer9_LargeHint::
# 6734 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use twenty harmless Rage Fists, you'll\n"
	.string "have everything you need.\p"
	.string "Are there any trainers you could never\n"
	.string "defeat?$"

HintsNPC_ToxicOrbSteal_LargeHint::
# 6741 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My MUK ate a Moon Stone\n"
	.string "and I can't get it out!\p"
	.string "...\p"
	.string "Sorry, that's the wrong escape room.\n"
	.string "This Muk ate something else.$"

HintsNPC_SecretPower_LargeHint::
# 6749 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Compared to a Choice Scarf, the\n"
	.string "Dusknoir are slower.\p"
	.string "Stall and revive, its PP will get lower.\p"
	.string "The Toxic Orb triggers, let the poison\n"
	.string "run its course.\p"
	.string "Head to the ice, Secret Power is yours.$"

HintsNPC_RareCandy3_LargeHint::
# 6759 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Can you find the Secret Bases?\p"
	.string "There's a wall indent and a tree.\n"
	.string "Wait, where's the nurse NPC?$"

HintsNPC_Trainer10_LargeHint::
# 6765 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sheer Force has an interesting\n"
	.string "interaction with Color Change.\p"
	.string "Do you have a Pokémon with Sheer Force?$"

HintsNPC_Trainer11_LargeHint::
# 6771 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6793 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones form a numpad pattern:\n"
	.string "1 2 3, 4 5 6, 7 8 9, 0.\p"
	.string "Interact with them in the following\n"
	.string "order: 1 8 3 7.$"

HintsNPC_UltraBall_Solution::
# 6800 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Talk to the NPC with the green hat to\n"
	.string "obtain an Ultra Ball.$"

HintsNPC_ZeraCatchPredamage_Solution::
# 6805 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6817 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pre-damage Ferrothorn by letting the\n"
	.string "Annihilape use Grass Knot.\p"
	.string "Have Florges hold a Float Stone and use\n"
	.string "Camouflage to run away.$"

HintsNPC_ZeraoraCatch_Solution::
# 6824 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1. Use Custap Berry Block vs Zeraora\n"
	.string "and let it Snatch Ingrain.\p"
	.string "2. Switch to Florges, use the Ether on\n"
	.string "Camouflage, and let Zeraora copy both\l"
	.string "Grassy Terrain and Camouflage.\p"
	.string "3. Switch to Ferrothorn and use Steel\n"
	.string "Roller.\p"
	.string "You can now catch Zeraora.$"

HintsNPC_Trainer0_Solution::
# 6835 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have to beat the Pincurchin\n"
	.string "trainer.\p"
	.string "1. Give TM Skill Swap to Florges as\n"
	.string "held item.\p"
	.string "2. Sack Ferrothorn and Zeraora to the\n"
	.string "Selfdestructing Pincurchin.\p"
	.string "3. Use Grass Knot.$"

HintsNPC_SafetyGoggles_Solution::
# 6845 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Exp Candy on Zeraora to reach\n"
	.string "level 43.\p"
	.string "Go to the graveyard and interact with\n"
	.string "the bottom-left gravestone to obtain\l"
	.string "the Safety Goggles.$"

HintsNPC_Trainer1_Solution::
# 6853 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6876 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6898 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fight the Annihilape and let it copy\n"
	.string "Steel Roller.\p"
	.string "Set up Grassy Terrain, switch out and\n"
	.string "sack Ferrothorn, use Camouflage, and\l"
	.string "run from battle.\p"
	.string "You can now walk past the Twins and\n"
	.string "pick the Maranga Berry.$"

HintsNPC_Trainer2_Solution::
# 6908 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Florges the Maranga Berry, then\n"
	.string "use Cut to remove the Grass tiles next\l"
	.string "to the Dracozolt trainer.\p"
	.string "Start the battle on a regular tile and\n"
	.string "use Nature Power to win.$"

HintsNPC_Trainer3_Solution::
# 6916 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let Klefki steal your Ring Target with\n"
	.string "Magician, give it Symbiosis, activate\l"
	.string "Komala's Snowball, and you're now able\l"
	.string "to beat it with Trump Card and Hex.$"

intsNPC_Trainer3_Solution_ExactSequence::
# 6923 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Florges (Ring Target) and\n"
	.string "Dunsparce.\p"
	.string "Turn 1: Grassy Terrain + Trump Card.\n"
	.string "Turn 2: Skill Swap + Trump Card.\l"
	.string "Turn 3: Ice Beam (Komala).\l"
	.string "Turn 4-6: Trump Card.\l"
	.string "Turn 7: Hex.\l"
	.string "Repeat untill Komala faints.$"

HintsNPC_EggSkip_Solution::
# 6934 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins cannot fight you when one of\n"
	.string "your Pokémon is an egg.\p"
	.string "Buy an Escape Rope, exit and re-enter\n"
	.string "the cave from where the Liepard Collar\l"
	.string "was located.\p"
	.string "Trade your Florges for the Pokémon egg,\n"
	.string "use the Escape Rope, and you can now\l"
	.string "walk past the Twins again.$"

HintsNPC_SunStone_Solution::
# 6947 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pickup will activate once you've fought\n"
	.string "a few wild Dusknoir.\p"
	.string "You'll get a Sun Stone which can be\n"
	.string "sold to an NPC up north.$"

HintsNPC_Trainer4_Solution::
# 6954 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6982 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7001 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rayquaza carries a Moon Stone.\p"
	.string "Use Trick to steal the Moon Stone and\n"
	.string "sell it to the NPC up north.$"

HintsNPC_BerryJuice_Solution::
# 7007 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Aipom the Iron Ball and fight a\n"
	.string "Shuckle at the Rock Smash rocks.\p"
	.string "Use Endeavor to trigger Shuckle's Berry\n"
	.string "Juice, then Aipom's Pickup activates\l"
	.string "to recover the consumed item.\p"
	.string "Run from the battle and you've now got\n"
	.string "a Berry Juice.$"

HintsNPC_Trainer5_Solution::
# 7019 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7042 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7060 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Ability Capsule on Aipom to get\n"
	.string "Run Away.\p"
	.string "Fight the Trapinch and run away.$"

HintsNPC_RareCandyRevive_Solution::
# 7066 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7081 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Assist Taunt against a Dusknoir, sack\n"
	.string "Liepard, then run away.\p"
	.string "Walk past the Twins and Revive Liepard\n"
	.string "with the Rare Candy.$"

HintsNPC_Trainer6_Solution::
# 7088 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7120 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7136 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7150 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teach Cut to Bagon and fight the\n"
	.string "Dusclops trainer.\p"
	.string "Use Cut.$"

HintsNPC_IcePuzzleRareCandy_Solution::
# 7156 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "At this point, only the Rare Candy can\n"
	.string "be taken out of the ice puzzle.\p"
	.string "To do so, the item ball must be used as\n"
	.string "an obstacle within the puzzle itself.$"

HintsNPC_IcePuzzleRareCandy_Solution_IcePuzzleSteps::
# 7164 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW} (ignore the\n"
	.string "item) {LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{LEFT_ARROW} "
	.string "(take the item) {DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}.$"

HintsNPC_Trainer9_Solution::
# 7172 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have Primeape use Rage Fist 20 times\n"
	.string "(Sentret is the easiest target), then\l"
	.string "give it the Rare Candy to evolve into\l"
	.string "Annihilape.\p"
	.string "Now you're finally able to defeat the\n"
	.string "Twins.\p"
	.string "Keep using Rage Fist (start with the\n"
	.string "Urshifu-Rapid-Strike) to win.$"

HintsNPC_ToxicOrbSteal_Solution::
# 7185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Muk is holding a Toxic Orb.\p"
	.string "Buy TM Thief, teach it to Annihilape,\n"
	.string "and steal the Toxic Orb from Muk.$"

HintsNPC_SecretPower_Solution_Refresher::
# 7192 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Buy TM Thief, teach it to Annihilape,\n"
	.string "and steal the Toxic Orb from Muk.$"

HintsNPC_SecretPower_Solution::
# 7197 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{DOWN_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}{UP_ARROW}{RIGHT_ARROW}"
	.string "{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{UP_ARROW}{LEFT_ARROW}{DOWN_ARROW}"
	.string "{LEFT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW}{RIGHT_ARROW}{DOWN_ARROW}.$"

HintsNPC_RareCandy3_Solution::
# 7240 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7255 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7273 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokémon will need the following\n"
	.string "setup:\p"
	.string "Annihilape (Choice Specs)\n"
	.string "Rage Fist / Role Play / Mimic / Taunt.\p"
	.string "Yamask (Toxic Orb)\n"
	.string "Trick / Disable / Destiny Bond / X.\p"
	.string "Want to continue?$"

HintsNPC_Trainer11_Solution::
# 7286 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7312 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 7356 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 7366 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 7370 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 7376 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 7381 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 7385 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 7389 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 7395 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 7400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 7404 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoSecretPower::
# 7407 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Secret Power$"

OptionUndoCut::
# 7410 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 7413 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 7416 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 7419 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 7423 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 7428 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "used on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 7433 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 7438 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 7442 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 7447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 7452 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 7456 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 7460 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 7464 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 7470 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 7475 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 7482 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 7486 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 7491 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 7498 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 7508 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 7515 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 7526 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 7530 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 7537 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 7541 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 7545 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your energy trying to catch\n"
	.string "or beat her.$"

FourTabletsHintMessage1::
# 7557 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 7563 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?$"

FourTabletsHintMessage3::
# 7568 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake???$"

StonesBuyNPCInitialMessage_no_item::
# 7575 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 7583 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 7589 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for an Iron Ball?$"

StonesBuyNPCSellAcceptedMessage::
# 7597 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_IronBall::
# 7601 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the ball will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 7605 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 7609 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 7613 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 7620 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 7624 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 7628 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 7632 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 7639 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 7643 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretPowerTmReturned::
# 7650 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TM43 Secret Power was returned to its\n"
	.string "previous location.$"

RareCandy2Returned::
# 7655 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Rare Candy was returned to its\n"
	.string "previous location.$"

MonForgotSecretPower::
# 7660 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MartNPC_AskToShop::
# 7666 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 7672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

ChoiceItemsFirstMessage::
# 7678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Impressive, you saw right through my\n"
	.string "facade!\p"
	.string "I think you've earned a reward!\n"
	.string "Take your pick of my Choice items.\p"
	.string "You can always return if you'd like to\n"
	.string "try a different one.$"

ChoiceItemsNoLongerAvailable::
# 7687 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It seems you've made the right choice.$"

ChoiceItemsWhichOne::
# 7691 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Which item would you like to have?$"

ChoiceItemsComeAgain::
# 7695 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back anytime.$"

ChoiceItemsSwapped::
# 7699 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You returned the other Choice item.$"

ChoiceItemsAlreadyHaveThis::
# 7703 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You already have this one.$"

OptionChoiceBand::
# 7707 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Band$"

OptionChoiceSpecs::
# 7711 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Specs$"

OptionChoiceScarf::
# 7715 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Scarf$"

PrimeapeObtainMessage::
# 7721 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 7725 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

RescueBellExplainMessage::
# 7731 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Rescue Bell to teleport out of\n"
	.string "the ice puzzle if you're stuck.\p"
	.string "When used, any obtained items will be\n"
	.string "placed back inside the ice puzzle.$"

AskDeleteMove::
# 7740 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 7746 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 7752 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 7756 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 7760 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 7766 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 7770 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 7774 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 7781 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 7786 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 7791 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 7797 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 7803 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 7808 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 7812 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 7816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 7820 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 7824 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 7829 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 7834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 7839 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 7845 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 7849 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 7853 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 7857 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 7861 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 7866 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 7870 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 7875 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 7881 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 7887 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 7891 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 7897 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 7904 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You think you are ready?\n"
	.string "You really need three.\l"
	.string "One of them might hold the key.$"

Trainer0_Outro::
# 7910 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "But sharing is caring...$"

Trainer0_PostBattle::
# 7914 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go.$"

Trainer1_Intro::
# 7920 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 7926 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 7930 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 7935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 7942 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 7948 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 7953 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love writing in 686578!$"

Trainer2_PostBattle::
# 7957 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 7963 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 7968 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 7972 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 7977 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 7983 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 7988 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 7992 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know 5(A->L) + 2(L->O) = 525?$"

Trainer5_Intro::
# 7999 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 8004 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 8008 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 8012 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 8019 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 8026 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 8030 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My birds have traveled through all\n"
	.string "sorts of areas.\p"
	.string "Your Pokédex would be full by now if\n"
	.string "you'd done the same!$"

Trainer7A_Intro::
# 8039 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 8046 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 8050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "bsqajmnq? qsq.$"

Trainer7B_Intro::
# 8058 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 8063 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 8067 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 8074 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Ghost type mons are everywhere,\n"
	.string "you still haven't seen mine.$"

Trainer8_Outro::
# 8086 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 8090 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "$"

Trainer9_Intro::
# 8096 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 8101 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try hard in every fight!$"

Trainer9_PostBattle::
# 8105 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is this your last time passing through?$"

Trainer10_Intro::
# 8111 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Darwinism?\n"
	.string "More like Schmarminism...\p"
	.string "Kecleon doesn't need any changes!$"

Trainer10_Outro::
# 8117 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a struggle!$"

Trainer10_PostBattle::
# 8121 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So Kecleon isn't the only Pokémon with\n"
	.string "the ability to change?$"

Trainer11_Intro::
# 8128 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So you've finally made it to the end...\p"
	.string "No more hints.\p"
	.string "No more clues.\p"
	.string "It's time for your final test.$"

Trainer11_Outro::
# 8135 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

Trainer11_PostBattle_A::
# 8139 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please read the sign first.$"

Trainer11_PostBattle_B::
# 8143 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This game has been a true passion\n"
	.string "project of mine.\p"
	.string "An absurd amount of time, effort, and\n"
	.string "care was put into every small detail.\p"
	.string "If you enjoyed the experience, please\n"
	.string "let me know via the game's thread on\l"
	.string "PokéCommunity.\p"
	.string "It really does mean lot to me.\p"
	.string "Thank you so much for playing.\n"
	.string " - Ketch.$"

Trainer11_EndTheGame::
# 8160 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wanna get out of here?$"

EscapeRoomEndCongratz::
# 8166 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have completed\n"
	.string "the escape room!$"

EndEscapeRoomSignMessage::
# 8171 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your final time: {STR_VAR_1}.\p"
	.string "Small hints used: {STR_VAR_2}.\n"
	.string "Large hints used: {STR_VAR_3}.\l"
	.string "Solutions used: {STR_VAR_5}.$"

EscapeRopeEEMessage2::
# 8180 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just kidding.$"

TakeEasterEggBoatMessage::
# 8186 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An SS Ticket!?\p"
	.string "I'm impressed... You've actually\n"
	.string "managed to do it.\p"
	.string "Alright, let's go.$"

EasterEggCompletedMessage1::
# 8195 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have completed\n"
	.string "the main easter egg!$"

EasterEggCompletedMessage2::
# 8200 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Enjoy the Battle Factory!$"

EasterEggHintMessage::
# 8204 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Interested in easter eggs?\p"
	.string "The first clue lies before the\n"
	.string "beginning of time.$"

EasterEggStep1Completed::
# 8210 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Easter egg step 1)$"

EasterEggStep2Completed::
# 8214 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Easter egg step 2)$"

EasterEggStep3Completed::
# 8218 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Easter egg step 3)$"

EasterEggStep1Completed_HintMessage::
# 8222 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thud!$"

EasterEggStep2WallSignMessage::
# 8226 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

EasterEggStep2WallSignMessageOpened::
# 8230 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a big hole in the wall.$"

EasterEggStep3WallSignMessage::
# 8234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Yhzvi Ltaempcc hyy knis vhz kvgwns...$"
