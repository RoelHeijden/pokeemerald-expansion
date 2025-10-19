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
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 96 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 92 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 97 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 120 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfSecretPowerObtained
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_MapScript_OnResumeScripts_13
EscapeRoom_MapScript_OnResumeScripts_12:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_MapScript_OnResumeScripts_16
EscapeRoom_MapScript_OnResumeScripts_15:
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_20
EscapeRoom_MapScript_OnResumeScripts_18:
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_24
EscapeRoom_MapScript_OnResumeScripts_23:
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_27
EscapeRoom_MapScript_OnResumeScripts_26:
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_30
EscapeRoom_MapScript_OnResumeScripts_29:
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 159 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 162 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_32
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 105 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 116 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckZeraPredamageStep
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_16:
# 129 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckRareCandyReviveStep
	goto EscapeRoom_MapScript_OnResumeScripts_15

EscapeRoom_MapScript_OnResumeScripts_19:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_20:
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_19
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_24:
# 139 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_23

EscapeRoom_MapScript_OnResumeScripts_27:
# 145 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStickyBarbStolen
	goto EscapeRoom_MapScript_OnResumeScripts_26

EscapeRoom_MapScript_OnResumeScripts_30:
# 150 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_29

EscapeRoom_MapScript_OnResumeScripts_32:
# 163 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 185 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 188 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 200 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 204 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 217 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 223 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 227 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 228 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 231 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 225 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 229 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckStickyBarbStolen::
# 242 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_2
EscapeRoom_MapScripts_CheckStickyBarbStolen_1:
# 246 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_5
EscapeRoom_MapScripts_CheckStickyBarbStolen_4:
# 250 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_8
EscapeRoom_MapScripts_CheckStickyBarbStolen_7:
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 255 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_10
	return

EscapeRoom_MapScripts_CheckStickyBarbStolen_2:
# 244 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_1

EscapeRoom_MapScripts_CheckStickyBarbStolen_5:
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_4

EscapeRoom_MapScripts_CheckStickyBarbStolen_8:
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_7

EscapeRoom_MapScripts_CheckStickyBarbStolen_10:
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 262 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 263 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 264 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_8
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_11
EscapeRoom_MapScripts_CheckIfAskPreDamage_10:
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 265 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_10


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 287 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 288 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 288 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 293 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 298 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 307 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 318 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 319 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 289 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 320 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 319 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_CheckIfAskWarpBack::
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskWarpBack_3
EscapeRoom_MapScripts_CheckIfAskWarpBack_1:
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
Equal:
	return

EscapeRoom_MapScripts_CheckIfAskWarpBack_2:
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_LOCATED_AT_SECTION_X, VAR_RESPAWN_AT_SECTION_X
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_eq Equal
# 331 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 1
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1

EscapeRoom_MapScripts_CheckIfAskWarpBack_3:
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_MapScripts_CheckIfAskWarpBack_2
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1


EscapeRoom_MapScripts_CheckIfSecretPowerObtained::
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_4
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1:
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FIELD_POISON_WHITEOUT
	return

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2:
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_8:
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_THIEF
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_3:
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FIELD_POISON_WHITEOUT, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_4:
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_3
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_9:
# 359 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_8


EscapeRoom_MapScripts_CheckZeraPredamageStep::
# 375 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FERROTHORN
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 19
	goto_if_le EscapeRoom_MapScripts_CheckZeraPredamageStep_1
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_1:
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_PREDAMAGE_COMPLETED
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FERROTHORN
# 383 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_0x8004
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_FLORGES
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_ne EscapeRoom_MapScripts_CheckZeraPredamageStep_3
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_ne EscapeRoom_MapScripts_CheckZeraPredamageStep_3
	return

EscapeRoom_MapScripts_CheckZeraPredamageStep_3:
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 389 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 390 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_MapScripts_CheckRareCandyReviveStep::
# 397 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, 3
	goto_if_eq EscapeRoom_MapScripts_CheckRareCandyReviveStep_2
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_1:
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_REVIVE_COMPLETED
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_LIEPARD
	goto_if_ne EscapeRoom_MapScripts_CheckRareCandyReviveStep_5
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_2:
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_MapScripts_CheckRareCandyReviveStep_1
	return

EscapeRoom_MapScripts_CheckRareCandyReviveStep_5:
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 407 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 420 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 421 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 431 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 432 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 443 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 444 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 476 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 484 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 532 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 562 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 563 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIcePuzzleItemReturns::
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_JUST_ESCAPED_ICE_PUZZLE, 0
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_3
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1:
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_8
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6:
# 668 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2:
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 596 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11:
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21:
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM43
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31:
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_38
# 620 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_AUTOCLOSE
# 621 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_3:
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_1

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_7:
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16:
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26:
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RARE_CANDY
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_35
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_34:
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_AUTOCLOSE
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_41:
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RARE_CANDY2_OBTAINED
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_8:
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_7
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_6

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12:
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_13:
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_12
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_11

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17:
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_18:
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_17
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_16

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22:
# 603 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 604 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_23:
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_22
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_21

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27:
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_28:
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_RARE_CANDY
	goto_if_eq EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_27
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_26

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_32:
# 608 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM43
# 609 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_31

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_35:
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_RARE_CANDY
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_34

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_38:
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretPowerTmReturned, MSGBOX_DEFAULT
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoSecretPowerTeach
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_37

EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_42:
# 654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandy2Returned, MSGBOX_DEFAULT
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy_IcePuzzle
	goto EscapeRoom_MapScripts_CheckIcePuzzleItemReturns_41


EscapeRoom_MapScript_GameStartScripts::
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 684 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 686 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 749 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 754 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 760 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 761 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 766 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 815 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 825 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 846 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 849 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 856 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 857 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 878 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 880 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 885 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 895 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MainSignWhatToRead, MSGBOX_MAIN_SIGN
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_3
EscapeRoom_EventScript_MainInfoSign_1:
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_MainInfoSign_6
# 902 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_MainInfoSign_7
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetGameCompletion
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessage, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_3:
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_11
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_6:
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageInitial, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_7:
# 903 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageFinal, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_11:
# 917 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_GetGameCompletion::
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 0
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_GetGameCompletion_2
EscapeRoom_EventScript_GetGameCompletion_1:
# 936 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_GetGameCompletion_5
EscapeRoom_EventScript_GetGameCompletion_4:
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_8
EscapeRoom_EventScript_GetGameCompletion_7:
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_11
EscapeRoom_EventScript_GetGameCompletion_10:
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_14
EscapeRoom_EventScript_GetGameCompletion_13:
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_17
EscapeRoom_EventScript_GetGameCompletion_16:
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_20
EscapeRoom_EventScript_GetGameCompletion_19:
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_23
EscapeRoom_EventScript_GetGameCompletion_22:
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_GetGameCompletion_26
EscapeRoom_EventScript_GetGameCompletion_25:
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_29
EscapeRoom_EventScript_GetGameCompletion_28:
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_GetGameCompletion_32
EscapeRoom_EventScript_GetGameCompletion_31:
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_GetGameCompletion_35
EscapeRoom_EventScript_GetGameCompletion_34:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_38
EscapeRoom_EventScript_GetGameCompletion_37:
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_GetGameCompletion_41
EscapeRoom_EventScript_GetGameCompletion_40:
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_GetGameCompletion_44
EscapeRoom_EventScript_GetGameCompletion_43:
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_47
EscapeRoom_EventScript_GetGameCompletion_46:
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_GetGameCompletion_50
EscapeRoom_EventScript_GetGameCompletion_49:
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_53
EscapeRoom_EventScript_GetGameCompletion_52:
# 1027 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_56
EscapeRoom_EventScript_GetGameCompletion_55:
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_59
EscapeRoom_EventScript_GetGameCompletion_58:
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_GetGameCompletion_62
EscapeRoom_EventScript_GetGameCompletion_61:
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_65
EscapeRoom_EventScript_GetGameCompletion_64:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_68
EscapeRoom_EventScript_GetGameCompletion_67:
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_70
	return

EscapeRoom_EventScript_GetGameCompletion_2:
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 2
	goto EscapeRoom_EventScript_GetGameCompletion_1

EscapeRoom_EventScript_GetGameCompletion_5:
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 8
	goto EscapeRoom_EventScript_GetGameCompletion_4

EscapeRoom_EventScript_GetGameCompletion_8:
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 12
	goto EscapeRoom_EventScript_GetGameCompletion_7

EscapeRoom_EventScript_GetGameCompletion_11:
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 18
	goto EscapeRoom_EventScript_GetGameCompletion_10

EscapeRoom_EventScript_GetGameCompletion_14:
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 20
	goto EscapeRoom_EventScript_GetGameCompletion_13

EscapeRoom_EventScript_GetGameCompletion_17:
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 23
	goto EscapeRoom_EventScript_GetGameCompletion_16

EscapeRoom_EventScript_GetGameCompletion_20:
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 28
	goto EscapeRoom_EventScript_GetGameCompletion_19

EscapeRoom_EventScript_GetGameCompletion_23:
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 33
	goto EscapeRoom_EventScript_GetGameCompletion_22

EscapeRoom_EventScript_GetGameCompletion_26:
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 35
	goto EscapeRoom_EventScript_GetGameCompletion_25

EscapeRoom_EventScript_GetGameCompletion_29:
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 41
	goto EscapeRoom_EventScript_GetGameCompletion_28

EscapeRoom_EventScript_GetGameCompletion_32:
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 44
	goto EscapeRoom_EventScript_GetGameCompletion_31

EscapeRoom_EventScript_GetGameCompletion_35:
# 990 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 46
	goto EscapeRoom_EventScript_GetGameCompletion_34

EscapeRoom_EventScript_GetGameCompletion_38:
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 49
	goto EscapeRoom_EventScript_GetGameCompletion_37

EscapeRoom_EventScript_GetGameCompletion_41:
# 1000 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 55
	goto EscapeRoom_EventScript_GetGameCompletion_40

EscapeRoom_EventScript_GetGameCompletion_44:
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 57
	goto EscapeRoom_EventScript_GetGameCompletion_43

EscapeRoom_EventScript_GetGameCompletion_47:
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 63
	goto EscapeRoom_EventScript_GetGameCompletion_46

EscapeRoom_EventScript_GetGameCompletion_50:
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 68
	goto EscapeRoom_EventScript_GetGameCompletion_49

EscapeRoom_EventScript_GetGameCompletion_53:
# 1023 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 73
	goto EscapeRoom_EventScript_GetGameCompletion_52

EscapeRoom_EventScript_GetGameCompletion_56:
# 1028 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 78
	goto EscapeRoom_EventScript_GetGameCompletion_55

EscapeRoom_EventScript_GetGameCompletion_59:
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 84
	goto EscapeRoom_EventScript_GetGameCompletion_58

EscapeRoom_EventScript_GetGameCompletion_62:
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 89
	goto EscapeRoom_EventScript_GetGameCompletion_61

EscapeRoom_EventScript_GetGameCompletion_65:
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 91
	goto EscapeRoom_EventScript_GetGameCompletion_64

EscapeRoom_EventScript_GetGameCompletion_68:
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 95
	goto EscapeRoom_EventScript_GetGameCompletion_67

EscapeRoom_EventScript_GetGameCompletion_70:
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 100
	return


EscapeRoom_EventScript_MoveDeleterSign::
# 1060 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1061 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 1069 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 1086 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 1088 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 1074 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_Heal_Pokemon_Nurse1::
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 1109 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 1110 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 1117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 1124 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 1118 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 1122 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_2
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_5
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage_Finale, MSGBOX_HINTNPC
EscapeRoom_EventScript_HintsNPC_4:
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_9
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_10
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_HintsNPC_11
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_8:
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsFinalMessage, MSGBOX_AUTOCLOSE
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HintsNPC_5:
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_HINTNPC
	goto EscapeRoom_EventScript_HintsNPC_4

EscapeRoom_EventScript_HintsNPC_9:
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_SmallHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_10:
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_LargeHint
	goto EscapeRoom_EventScript_HintsNPC_8

EscapeRoom_EventScript_HintsNPC_11:
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_Solution
	goto EscapeRoom_EventScript_HintsNPC_8


EscapeRoom_EventScript_HintsNPC_SmallHint::
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_SmallHint_2
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_3
# 1180 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_4
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_5
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_SmallHint_6
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_7
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_8
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_9
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_10
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_11
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_SmallHint_12
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_13
# 1234 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_SmallHint_14
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_HintsNPC_SmallHint_15
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_16
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_SmallHint_17
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_SmallHint_18
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_19
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_20
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_SmallHint_21
# 1278 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_22
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_23
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_24
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_25
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_SmallHint_35
EscapeRoom_EventScript_HintsNPC_SmallHint_34:
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_SmallHint_27
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_28
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_29
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_30
EscapeRoom_EventScript_HintsNPC_SmallHint_1:
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_67
EscapeRoom_EventScript_HintsNPC_SmallHint_66:
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_64
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_SmallHint_62:
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_SmallHint_2:
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_SmallHint
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SMALL_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_3:
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_SmallHint
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_COMPLETED_SMALL_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_4:
# 1181 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_SmallHint
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERAORA_CAUGHT_SMALL_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_5:
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_SmallHint
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SMALL_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_6:
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_SmallHint
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SMALL_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_7:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_SmallHint
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SMALL_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_8:
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_SmallHint
# 1202 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SMALL_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_9:
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_SmallHint
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SMALL_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_10:
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_SmallHint
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SMALL_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_11:
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_SmallHint
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SMALL_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_12:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_SmallHint
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SMALL_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_13:
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_SmallHint
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SMALL_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_14:
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_SmallHint
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SMALL_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_15:
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_SmallHint
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SMALL_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_16:
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_SmallHint
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SMALL_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_17:
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_SmallHint
# 1251 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SMALL_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_18:
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_SmallHint
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SMALL_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_19:
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_SmallHint
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SMALL_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_20:
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_SmallHint
# 1266 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SMALL_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_21:
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_SmallHint
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SMALL_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_22:
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_SmallHint
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SMALL_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_23:
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_SmallHint
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SMALL_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_24:
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_SmallHint
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SMALL_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_25:
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_SmallHint
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SMALL_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_26:
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_SmallHint
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SMALL_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_27:
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_SmallHint
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SMALL_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_28:
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_SmallHint
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SMALL_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_29:
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_SmallHint
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SMALL_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_30:
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_SmallHint
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SMALL_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_1

EscapeRoom_EventScript_HintsNPC_SmallHint_35:
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_SmallHint_26
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_34

EscapeRoom_EventScript_HintsNPC_SmallHint_63:
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_SmallHint_71
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
EscapeRoom_EventScript_HintsNPC_SmallHint_70:
# 1336 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SMALL_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_62

EscapeRoom_EventScript_HintsNPC_SmallHint_64:
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_62

EscapeRoom_EventScript_HintsNPC_SmallHint_67:
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_SmallHint_63
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_66

EscapeRoom_EventScript_HintsNPC_SmallHint_71:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 15
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC15minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_SmallHint_70


EscapeRoom_EventScript_HintsNPC_LargeHint::
# 1362 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_LargeHint_2
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_3
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_4
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_5
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_LargeHint_6
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_7
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_8
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_9
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_10
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_11
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_LargeHint_12
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_13
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_LargeHint_14
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_HintsNPC_LargeHint_15
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_16
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_LargeHint_17
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_LargeHint_18
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_19
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_20
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_LargeHint_21
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_22
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_23
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_24
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_25
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_LargeHint_35
EscapeRoom_EventScript_HintsNPC_LargeHint_34:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_LargeHint_27
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_28
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_29
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_30
EscapeRoom_EventScript_HintsNPC_LargeHint_1:
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HINT_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_67
EscapeRoom_EventScript_HintsNPC_LargeHint_66:
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_64
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCHintAlreadyReceivedMessage
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_LargeHint_62:
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_LargeHint_2:
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_LargeHint
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_LARGE_HINT, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_3:
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_LargeHint
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_LARGE_HINT, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_4:
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_LargeHint
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_LARGE_HINT, FLAG_ZERA_CATCH_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_5:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_LargeHint
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_LARGE_HINT, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_6:
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_LargeHint
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_LARGE_HINT, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_7:
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_LargeHint
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_LARGE_HINT, FLAG_TRAINER1_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_8:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_LargeHint
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_LARGE_HINT, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_9:
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_LargeHint
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_LARGE_HINT, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_10:
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_LargeHint
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_LARGE_HINT, FLAG_TRAINER3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_11:
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_LargeHint
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_LARGE_HINT, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_12:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_LargeHint
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_LARGE_HINT, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_13:
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_LargeHint
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_LARGE_HINT, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_14:
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_LargeHint
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_LARGE_HINT, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_15:
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_LargeHint
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_LARGE_HINT, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_16:
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_LargeHint
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_LARGE_HINT, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_17:
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_LargeHint
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_LARGE_HINT, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_18:
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_LargeHint
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_LARGE_HINT, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_19:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_LargeHint
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_LARGE_HINT, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_20:
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_LargeHint
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_LARGE_HINT, FLAG_TRAINER6_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_21:
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_LargeHint
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_LARGE_HINT, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_22:
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_LargeHint
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_LARGE_HINT, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_23:
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_LargeHint
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_LARGE_HINT, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_24:
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_LargeHint
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_LARGE_HINT, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_25:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_LargeHint
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_LARGE_HINT, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_26:
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_LargeHint
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_LARGE_HINT, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_27:
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_LargeHint
# 1497 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_LARGE_HINT, FLAG_SECRET_POWER_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_28:
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_LargeHint
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_LARGE_HINT, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_29:
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_LargeHint
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_LARGE_HINT, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_30:
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_LargeHint
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_LARGE_HINT, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_1

EscapeRoom_EventScript_HintsNPC_LargeHint_35:
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_LargeHint_26
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_34

EscapeRoom_EventScript_HintsNPC_LargeHint_63:
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_LargeHint_71
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
EscapeRoom_EventScript_HintsNPC_LargeHint_70:
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_LARGE_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_62

EscapeRoom_EventScript_HintsNPC_LargeHint_64:
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_62

EscapeRoom_EventScript_HintsNPC_LargeHint_67:
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_LargeHint_63
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_66

EscapeRoom_EventScript_HintsNPC_LargeHint_71:
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 30
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC30minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_LargeHint_70


EscapeRoom_EventScript_HintsNPC_Solution::
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_HintsNPC_Solution_2
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_PREDAMAGE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_3
# 1563 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_HintsNPC_Solution_4
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_5
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_HintsNPC_Solution_6
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_7
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_8
# 1600 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_9
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_10
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_11
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_HintsNPC_Solution_12
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_13
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_HintsNPC_Solution_14
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_HintsNPC_Solution_15
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_16
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_HintsNPC_Solution_17
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_HintsNPC_Solution_18
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_REVIVE_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_19
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_20
# 1676 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_HintsNPC_Solution_21
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_22
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_23
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_24
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_25
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_STOLEN_AT_SOME_POINT, EscapeRoom_EventScript_HintsNPC_Solution_35
EscapeRoom_EventScript_HintsNPC_Solution_34:
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_HintsNPC_Solution_27
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_28
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_29
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_30
EscapeRoom_EventScript_HintsNPC_Solution_1:
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SOLUTION_ALREADY_RECEIVED, EscapeRoom_EventScript_HintsNPC_Solution_63
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCSolutionAlreadyReceivedMessage
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HintsNPC_Solution_62:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SOLUTION_ALREADY_RECEIVED
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HINT_ALREADY_RECEIVED
	return

EscapeRoom_EventScript_HintsNPC_Solution_2:
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_AnnihilapeSpawn_Solution
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ANNIHILAPE_SPAWNED_SOLUTION, FLAG_ANNIHILAPE_SPAWNED_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_3:
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_PREDAMAGE_SOLUTION, FLAG_ZERA_PREDAMAGE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_4:
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraoraCatch_Solution
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ZERA_CATCH_SOLUTION, FLAG_ZERA_CATCH_SOLUTION
# 1568 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1569 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_66
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_5:
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer0_Solution
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER0_SOLUTION, FLAG_TRAINER0_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_6:
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SafetyGoggles_Solution
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SAFETY_GOGGLES_SOLUTION, FLAG_SAFETY_GOGGLES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_7:
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer1_Solution
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER1_SOLUTION, FLAG_TRAINER1_SOLUTION
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_68
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_8:
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MarangaBerry_Solution
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MARANGA_BERRY_SOLUTION, FLAG_MARANGA_BERRY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_9:
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer2_Solution
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER2_SOLUTION, FLAG_TRAINER2_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_10:
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer3_Solution
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER3_SOLUTION, FLAG_TRAINER3_SOLUTION
# 1610 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewExactSequence, MSGBOX_YESNO
# 1611 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_70
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_11:
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_EggSkip_Solution
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_EGG_SKIP_SOLUTION, FLAG_EGG_SKIP_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_12:
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SunStone_Solution
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SUN_STONE_SOLUTION, FLAG_SUN_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_13:
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer4_Solution
# 1632 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER4_SOLUTION, FLAG_TRAINER4_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_14:
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TauntHerb_Solution
# 1637 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TAUNT_HERB_SOLUTION, FLAG_TAUNT_HERB_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_15:
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MoonStone_Solution
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MOON_STONE_SOLUTION, FLAG_MOON_STONE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_16:
# 1646 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_BerryJuice_Solution
# 1647 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_BERRY_JUICE_SOLUTION, FLAG_BERRY_JUICE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_17:
# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer5_Solution
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER5_SOLUTION, FLAG_TRAINER5_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_18:
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_TrapinchRun_Solution
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAPINCH_RUN_SOLUTION, FLAG_TRAPINCH_RUN_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_19:
# 1661 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_Solution
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY_REVIVE_SOLUTION, FLAG_RARE_CANDY_REVIVE_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_20:
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer6_Solution
# 1667 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER6_SOLUTION, FLAG_TRAINER6_SOLUTION
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_72
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_21:
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_MapSwitches_Solution
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_MAP_SWITCHES_SOLUTION, FLAG_MAP_SWITCHES_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_22:
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer7A_Solution
# 1687 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER7A_SOLUTION, FLAG_TRAINER7A_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_23:
# 1691 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer8_Solution
# 1692 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER8_SOLUTION, FLAG_TRAINER8_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_24:
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_IcePuzzleRareCandy_Solution
# 1697 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_ICEPUZZLE_RARECANDY_SOLUTION, FLAG_ICEPUZZLE_RARECANDY_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_25:
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer9_Solution
# 1702 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER9_SOLUTION, FLAG_TRAINER9_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_26:
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_Solution
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TOXIC_ORB_STEAL_SOLUTION, FLAG_TOXIC_ORB_STEAL_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_27:
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SecretPower_Solution
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_SECRET_POWER_SOLUTION, FLAG_SECRET_POWER_SOLUTION
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ReviewPreviousStep, MSGBOX_YESNO
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_Solution_74
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_28:
# 1722 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandy3_Solution
# 1723 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_RARE_CANDY3_SOLUTION, FLAG_RARE_CANDY3_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_29:
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer10_Solution
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER10_SOLUTION, FLAG_TRAINER10_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_30:
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Trainer11_Solution
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	handlehintorsolution FLAG_TRAINER11_SOLUTION, FLAG_TRAINER11_SOLUTION
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_35:
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_HintsNPC_Solution_26
	goto EscapeRoom_EventScript_HintsNPC_Solution_34

EscapeRoom_EventScript_HintsNPC_Solution_63:
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_HintsNPC_Solution_77
# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 120
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC120minAddedMessage
EscapeRoom_EventScript_HintsNPC_Solution_76:
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1753 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_SOLUTIONS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_HintsNPC_Solution_62

EscapeRoom_EventScript_HintsNPC_Solution_66:
# 1570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ZeraCatchPredamage_Solution_Refresher
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_68:
# 1591 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox intsNPC_Trainer1_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_70:
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox intsNPC_Trainer3_Solution_ExactSequence
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_72:
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_RareCandyRevive_Solution
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_74:
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_ToxicOrbSteal_Solution
	goto EscapeRoom_EventScript_HintsNPC_Solution_1

EscapeRoom_EventScript_HintsNPC_Solution_77:
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	addgametime 60
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC60minAddedMessage
	goto EscapeRoom_EventScript_HintsNPC_Solution_76


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1790 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 1791 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 1799 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 1800 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 1819 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_MAX_REVIVE, EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_23
EscapeRoom_EventScript_ReturnLostItems_22:
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_33
EscapeRoom_EventScript_ReturnLostItems_32:
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_38
EscapeRoom_EventScript_ReturnLostItems_37:
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_42
EscapeRoom_EventScript_ReturnLostItems_40:
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_47
EscapeRoom_EventScript_ReturnLostItems_45:
# 1975 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_52
# 1975 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_52
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2031 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 1837 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 1854 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MAX_REVIVE
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_MAX_REVIVE
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 1855 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 1878 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_28
EscapeRoom_EventScript_ReturnLostItems_26:
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_35
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_23:
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 1907 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_22

EscapeRoom_EventScript_ReturnLostItems_25:
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_27:
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_25
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_28:
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_27
	goto EscapeRoom_EventScript_ReturnLostItems_26

EscapeRoom_EventScript_ReturnLostItems_33:
# 1913 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
# 1914 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_32

EscapeRoom_EventScript_ReturnLostItems_35:
# 1897 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_38:
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_41:
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_50
	goto EscapeRoom_EventScript_ReturnLostItems_40

EscapeRoom_EventScript_ReturnLostItems_42:
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_41
	goto EscapeRoom_EventScript_ReturnLostItems_40

EscapeRoom_EventScript_ReturnLostItems_46:
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_58
EscapeRoom_EventScript_ReturnLostItems_57:
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_71
EscapeRoom_EventScript_ReturnLostItems_70:
# 1956 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_82
EscapeRoom_EventScript_ReturnLostItems_81:
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_86
	goto EscapeRoom_EventScript_ReturnLostItems_45

EscapeRoom_EventScript_ReturnLostItems_47:
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_46
	goto EscapeRoom_EventScript_ReturnLostItems_45

EscapeRoom_EventScript_ReturnLostItems_50:
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_40

EscapeRoom_EventScript_ReturnLostItems_52:
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_66
EscapeRoom_EventScript_ReturnLostItems_64:
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_62
EscapeRoom_EventScript_ReturnLostItems_60:
# 2018 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_73
	return

EscapeRoom_EventScript_ReturnLostItems_58:
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1944 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_61:
# 1981 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_75
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_60

EscapeRoom_EventScript_ReturnLostItems_62:
# 2008 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_79
	goto EscapeRoom_EventScript_ReturnLostItems_60

EscapeRoom_EventScript_ReturnLostItems_65:
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_61
	goto EscapeRoom_EventScript_ReturnLostItems_64

EscapeRoom_EventScript_ReturnLostItems_66:
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_65
	goto EscapeRoom_EventScript_ReturnLostItems_64

EscapeRoom_EventScript_ReturnLostItems_71:
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1951 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_70

EscapeRoom_EventScript_ReturnLostItems_73:
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 2021 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_75:
# 1983 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_60

EscapeRoom_EventScript_ReturnLostItems_76:
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_84
	goto EscapeRoom_EventScript_ReturnLostItems_60

EscapeRoom_EventScript_ReturnLostItems_79:
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_60

EscapeRoom_EventScript_ReturnLostItems_82:
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_81

EscapeRoom_EventScript_ReturnLostItems_84:
# 1994 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_60

EscapeRoom_EventScript_ReturnLostItems_86:
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 1966 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_45


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 2037 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2042 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 2057 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 2063 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 2064 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 2069 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2084 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 2096 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_29
EscapeRoom_EventScript_UndoUsedItems_28:
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_32
EscapeRoom_EventScript_UndoUsedItems_31:
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
EscapeRoom_EventScript_UndoUsedItems_34:
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_42
EscapeRoom_EventScript_UndoUsedItems_41:
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 2140 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SECRET_POWER
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_44
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 2059 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 2065 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 2067 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 2072 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_ANNIHILAPE
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2080 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2081 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2092 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 2097 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_29:
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_28

EscapeRoom_EventScript_UndoUsedItems_32:
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 2120 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_31

EscapeRoom_EventScript_UndoUsedItems_35:
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_34

EscapeRoom_EventScript_UndoUsedItems_42:
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_41

EscapeRoom_EventScript_UndoUsedItems_44:
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38:
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21:
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14
# 2228 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45:
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 2267 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66:
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72:
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 2160 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSecretPower, OptionUndoRareCandy
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 2196 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2197 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13:
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14:
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37:
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41:
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 2251 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 2258 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 2268 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76
# 2272 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70:
# 2262 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73:
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76:
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79:
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 2290 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 2296 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_5
# 2303 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_6
EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_10
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_11
EscapeRoom_EventScript_AskUndoMoveTeach_9:
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 2326 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 2330 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_18
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 2291 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_5:
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_14
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_6:
# 2304 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_16
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_10:
# 2311 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2312 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_20
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_11:
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_22
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_14:
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_16:
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_18:
# 2331 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_AskUndoMoveTeach_20:
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_22:
# 2320 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9


EscapeRoom_EventScript_UndoMoveTeach::
# 2337 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2340 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 2362 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 2366 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_10:
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 2405 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
# 2411 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_32:
# 2419 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2420 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2424 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_46
EscapeRoom_EventScript_UndoMoveTeach_45:
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_57
EscapeRoom_EventScript_UndoMoveTeach_55:
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_53:
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_65
EscapeRoom_EventScript_UndoMoveTeach_64:
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_74
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 2342 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 2351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_23
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, VAR_0x8008
# 2371 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 2349 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 2374 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, VAR_0x8008
# 2375 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_23:
# 2352 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_26:
# 2382 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2383 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_41
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_33:
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 2412 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM43
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_35:
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_39:
# 2385 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_40:
# 2391 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
# 2395 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 2399 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_41:
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_40
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_46:
# 2425 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_45

EscapeRoom_EventScript_UndoMoveTeach_49:
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2393 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 2396 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 2448 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2449 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2452 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_56:
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_57:
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_56
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_62:
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2464 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_69
EscapeRoom_EventScript_UndoMoveTeach_67:
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_85
EscapeRoom_EventScript_UndoMoveTeach_83:
# 2476 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 2477 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 2478 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_94
EscapeRoom_EventScript_UndoMoveTeach_93:
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_99
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_65:
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 2495 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2496 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_80
EscapeRoom_EventScript_UndoMoveTeach_78:
# 2500 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_90
EscapeRoom_EventScript_UndoMoveTeach_88:
# 2507 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 2508 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 2509 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_97
EscapeRoom_EventScript_UndoMoveTeach_96:
# 2516 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_101
	goto EscapeRoom_EventScript_UndoMoveTeach_64

EscapeRoom_EventScript_UndoMoveTeach_68:
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_69:
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_68
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_72:
# 2527 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 2530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 2531 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_73:
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_72
	return

EscapeRoom_EventScript_UndoMoveTeach_74:
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_73
	return

EscapeRoom_EventScript_UndoMoveTeach_79:
# 2497 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2498 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_80:
# 2496 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_79
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_84:
# 2471 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_85:
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_84
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_89:
# 2502 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2503 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_90:
# 2501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_89
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_94:
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2480 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_93

EscapeRoom_EventScript_UndoMoveTeach_97:
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 2512 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_96

EscapeRoom_EventScript_UndoMoveTeach_99:
# 2486 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 2487 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_101:
# 2517 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 2518 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2521 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_64


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 2537 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 2538 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 2541 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 2546 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 2550 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 2571 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 2580 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2583 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 2587 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 2628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_31
EscapeRoom_EventScript_UndoRareCandy_30:
# 2639 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 2650 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 2654 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 2657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
EscapeRoom_EventScript_UndoRareCandy_27:
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_36
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
# 2749 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_38
EscapeRoom_EventScript_UndoRareCandy_35:
# 2755 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 2756 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_48
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 2618 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2620 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2621 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 2602 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_33
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 2668 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2669 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_43
EscapeRoom_EventScript_UndoRareCandy_42:
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_51
EscapeRoom_EventScript_UndoRareCandy_50:
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2691 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_59
EscapeRoom_EventScript_UndoRareCandy_58:
# 2703 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 2711 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_68
EscapeRoom_EventScript_UndoRareCandy_66:
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_77
EscapeRoom_EventScript_UndoRareCandy_75:
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_31:
# 2630 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2631 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2632 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 2636 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_30

EscapeRoom_EventScript_UndoRareCandy_33:
# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_36:
# 2744 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_37:
# 2747 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_38:
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_43:
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2673 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2674 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_42

EscapeRoom_EventScript_UndoRareCandy_46:
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2642 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2643 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2644 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 2647 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_48:
# 2759 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_55
EscapeRoom_EventScript_UndoRareCandy_54:
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_64
	return

EscapeRoom_EventScript_UndoRareCandy_51:
# 2682 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2683 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2685 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2686 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_50

EscapeRoom_EventScript_UndoRareCandy_53:
# 2762 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_61
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2784 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_73
	return

EscapeRoom_EventScript_UndoRareCandy_55:
# 2759 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_53
	goto EscapeRoom_EventScript_UndoRareCandy_54

EscapeRoom_EventScript_UndoRareCandy_59:
# 2695 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2696 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_58

EscapeRoom_EventScript_UndoRareCandy_61:
# 2766 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2767 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_71
	return

EscapeRoom_EventScript_UndoRareCandy_64:
# 2795 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005
# 2796 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2800 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_67:
# 2714 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2719 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2720 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2721 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2722 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_68:
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_67
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_71:
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2774 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_73:
# 2785 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return

EscapeRoom_EventScript_UndoRareCandy_76:
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 2728 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 2731 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2732 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2733 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 2735 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_75

EscapeRoom_EventScript_UndoRareCandy_77:
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_76
	goto EscapeRoom_EventScript_UndoRareCandy_75


EscapeRoom_EventScript_UndoExpCandy::
# 2810 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 2811 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 2815 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 2823 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2824 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2825 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 2827 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 2838 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 2847 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 2840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 2848 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 2856 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 2857 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 2847 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 2850 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 2874 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2877 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 2880 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 2884 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 2892 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 2898 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 2906 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 2907 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2886 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 2889 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2890 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 2893 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2894 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 2902 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 2912 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 2920 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 2921 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 2924 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 2925 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2926 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 2915 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2916 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 2934 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 2944 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 2948 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2949 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2952 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_LiepardNPC::
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2960 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2963 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 2964 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 2965 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2966 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 2970 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 2972 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2973 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2974 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 2975 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2976 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2977 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2980 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2981 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 2982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2983 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2984 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2987 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 2988 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2989 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 2990 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2991 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 2994 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 2995 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2996 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2999 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3000 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 3001 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3002 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 3003 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 3005 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 3006 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3009 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 3010 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 3011 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 3012 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 3015 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 3016 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 3028 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3029 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 3030 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3031 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 3033 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 3034 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3043 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 3046 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 3049 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 3036 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 3058 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 3061 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 3062 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3064 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 3065 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 3067 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 3068 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3070 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 3071 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 3075 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3076 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 3098 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3099 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 3100 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 3104 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 3124 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3125 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 3126 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3127 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3130 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 3131 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 3132 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3135 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 3136 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 3138 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3139 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 3140 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3143 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 3144 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 3145 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3146 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 3149 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 3150 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 3153 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 3154 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 3161 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 3162 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3164 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3165 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 3167 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 3168 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 3171 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 3179 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 3182 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3183 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 3185 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3186 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 3189 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 3190 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 3191 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 3192 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 3195 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 3202 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3203 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3206 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 3213 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 3222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 3229 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 3230 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 3207 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 3208 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3209 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 3218 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 3236 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 3240 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 3245 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 3248 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 3249 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 3264 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 3278 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 3279 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 3293 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 3250 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3251 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3252 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 3255 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3256 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3257 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3258 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3259 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 3265 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3266 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 3270 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3272 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3273 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3274 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 3281 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 3282 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 3285 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3286 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3287 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3288 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 3289 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 3295 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 3296 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 3301 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3302 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 3303 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3304 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 3305 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3306 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 3307 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 3314 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3316 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 3329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 3346 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 3325 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 3319 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3320 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3321 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 3353 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 3355 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3356 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 3365 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 3367 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3368 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 3371 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 3372 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3375 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3379 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 3380 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 3383 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 3384 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 3387 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 3388 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 3389 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 3390 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 3391 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3394 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 3395 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 3398 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 3405 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3406 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3407 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3408 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3411 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3413 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 3414 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3415 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 3417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3420 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3422 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 3427 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 3428 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3429 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 3430 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3434 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 3436 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3438 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 3445 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3447 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 3454 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 3461 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 3468 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 3472 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 3450 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 3456 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 3463 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 3476 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3477 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 3479 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 3494 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3495 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 3480 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3483 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 3484 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3485 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3486 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3488 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SUN_STONE_SOLD
# 3490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 3500 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3501 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 3512 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 3513 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 3504 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 3505 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 3506 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 3508 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 3509 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoSecretPowerTeach::
# 3523 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3524 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_2
EscapeRoom_EventScript_UndoSecretPowerTeach_1:
# 3534 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3535 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_5
EscapeRoom_EventScript_UndoSecretPowerTeach_4:
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3540 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_10
EscapeRoom_EventScript_UndoSecretPowerTeach_9:
# 3550 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 3551 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_13
EscapeRoom_EventScript_UndoSecretPowerTeach_12:
# 3558 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_SECRET_POWER
# 3559 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_SECRET_POWER, VAR_0x8004
# 3560 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_SECRET_POWER
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
EscapeRoom_EventScript_UndoSecretPowerTeach_17:
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
EscapeRoom_EventScript_UndoSecretPowerTeach_22:
# 3573 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
# 3573 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
EscapeRoom_EventScript_UndoSecretPowerTeach_27:
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
EscapeRoom_EventScript_UndoSecretPowerTeach_32:
# 3611 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
# 3611 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
EscapeRoom_EventScript_UndoSecretPowerTeach_43:
# 3623 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3624 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3625 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3626 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 3627 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSecretPowerTeach_2:
# 3525 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3528 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3529 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_7
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_5:
# 3536 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_4

EscapeRoom_EventScript_UndoSecretPowerTeach_7:
# 3530 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_10:
# 3541 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3545 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_15
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_13:
# 3552 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_12

EscapeRoom_EventScript_UndoSecretPowerTeach_15:
# 3546 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_18:
# 3564 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 3565 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_17

EscapeRoom_EventScript_UndoSecretPowerTeach_23:
# 3568 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3569 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_22

EscapeRoom_EventScript_UndoSecretPowerTeach_28:
# 3576 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3577 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_37
# 3582 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_39
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_33:
# 3601 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 3602 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_49
EscapeRoom_EventScript_UndoSecretPowerTeach_48:
# 3605 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3606 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_59
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_37:
# 3579 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_38:
# 3585 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_52
# 3589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_53
EscapeRoom_EventScript_UndoSecretPowerTeach_51:
# 3593 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_39:
# 3582 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_38
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_44:
# 3612 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 3613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_57
EscapeRoom_EventScript_UndoSecretPowerTeach_56:
# 3616 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_61
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43

EscapeRoom_EventScript_UndoSecretPowerTeach_49:
# 3603 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_48

EscapeRoom_EventScript_UndoSecretPowerTeach_52:
# 3586 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3587 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_53:
# 3590 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3591 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_57:
# 3614 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_56

EscapeRoom_EventScript_UndoSecretPowerTeach_59:
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_61:
# 3618 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43


EscapeRoom_EventScript_UndoRareCandy_IcePuzzle::
# 3632 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 3633 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 3636 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2
# 3640 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3641 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1:
# 3646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5:
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8:
# 3669 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15:
# 3684 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24:
# 3695 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_33
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32:
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_AUTOCLOSE
# 3706 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13:
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 3713 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21:
# 3799 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	return

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_2:
# 3637 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_1

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_6:
# 3647 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3648 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_9:
# 3656 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_11:
# 3650 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_5

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14:
# 3674 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 3675 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3676 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3677 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_AUTOCLOSE
# 3678 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_13

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_16:
# 3673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_14
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_15

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_19:
# 3660 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 3661 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_22:
# 3724 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_30
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29:
# 3734 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_36
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35:
# 3746 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_38:
# 3759 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 3767 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 3768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41:
# 3780 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_48
EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46:
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_21

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_25:
# 3686 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 3687 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3688 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3689 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 3692 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_24

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_27:
# 3663 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_8

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_30:
# 3728 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3729 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3730 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3731 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3732 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_29

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_33:
# 3697 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3698 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3699 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 3703 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_32

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_36:
# 3738 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3739 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3740 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3741 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3742 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_35

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_39:
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 3752 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 3753 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_38

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42:
# 3770 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3771 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3774 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3775 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3776 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3777 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3778 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_43:
# 3768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_42
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_41

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47:
# 3783 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 3784 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 3787 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 3788 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 3789 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 3790 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 3791 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46

EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_48:
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_47
	goto EscapeRoom_EventScript_UndoRareCandy_IcePuzzle_46


EscapeRoom_EventScript_CheckRareCandy2Stolen::
# 3803 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 0
# 3804 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY2_OBTAINED, EscapeRoom_EventScript_CheckRareCandy2Stolen_2
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_1:
# 3805 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_COMPLETED
	return

EscapeRoom_EventScript_CheckRareCandy2Stolen_2:
# 3804 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY2_COMPLETED, EscapeRoom_EventScript_CheckRareCandy2Stolen_1
	return


EscapeRoom_AnnihilapeHintNPC::
# 3813 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3816 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 3828 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 3829 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 3831 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 3817 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3819 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 3820 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3821 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 3822 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3823 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 3824 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 3835 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3836 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 3839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 3845 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 3837 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 3840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer0::
# 3852 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 3860 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer1::
# 3865 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3866 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 3879 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 3880 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 3876 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 3885 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 3891 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 3892 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 3897 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3898 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 3905 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 3906 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 3911 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 3917 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 3918 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 3925 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 3926 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 3934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 3943 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 3927 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3928 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 3929 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 3926 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 3935 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 3936 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 3937 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 3938 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 3939 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 3956 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 3963 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 3964 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 3969 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 3976 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 3977 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 3982 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 3989 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 3990 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 3995 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 4003 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_Trainer8_2
EscapeRoom_EventScript_Trainer8_1:
# 4008 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4009 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer8_2:
# 4005 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4006 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8_1


EscapeRoom_EventScript_Trainer9::
# 4014 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 4021 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 4022 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 4027 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 4034 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 4035 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 4041 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_Trainer11_2
EscapeRoom_EventScript_Trainer11_1:
# 4047 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 4055 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4056 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4057 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_Trainer11_5
# 4062 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_B, MSGBOX_AUTOCLOSE
# 4063 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_Trainer11_4:
# 4065 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer11_2:
# 4042 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4043 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
	goto EscapeRoom_EventScript_Trainer11_1

EscapeRoom_EventScript_Trainer11_5:
# 4058 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_A, MSGBOX_AUTOCLOSE
# 4059 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer11_4


EscapeRoom_EventScript_PostMatchHeal::
# 4072 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 4077 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4080 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 4095 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 4096 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 4081 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4082 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 4085 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4086 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 4089 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4090 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 4083 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 4087 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 4091 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4104 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4105 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4106 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 4114 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 4117 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 4123 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4124 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4125 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4126 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4127 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 4128 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 4129 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4130 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 4131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 4132 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 4141 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4142 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 4144 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 4107 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4108 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 4134 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4135 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4136 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 4131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 4131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 4109 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4110 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 4151 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4154 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4155 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4156 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 4163 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 4164 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4167 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 4174 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 4176 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4177 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 4178 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 4184 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 4157 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 4180 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4181 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4182 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 4159 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4160 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 4190 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4193 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 4196 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 4200 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 4205 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4206 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 4207 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4208 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 4209 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4210 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 4213 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 4216 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 4219 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4226 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4227 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 4228 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4229 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 4230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 4236 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 4198 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 4201 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 4232 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4233 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 4240 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 4241 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 4242 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4242 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 4243 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 4247 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 4248 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4253 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4255 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4256 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4257 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 4258 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 4265 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4262 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4263 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 4273 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4276 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 4288 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 4300 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 4312 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 4324 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 4335 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 4336 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 4277 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4278 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 4281 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 4289 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4290 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 4293 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 4279 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 4301 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4302 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 4305 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4306 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 4291 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 4283 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 4313 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4314 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 4317 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4318 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 4303 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 4295 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 4325 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4326 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 4329 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4330 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 4315 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 4307 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 4327 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 4319 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 4331 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 4341 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4344 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 4347 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 4348 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4349 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 4357 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 4358 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 4367 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 4369 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4372 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 4379 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4380 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 4381 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4382 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 4384 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 4385 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4386 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 4387 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 4389 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 4390 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 4391 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 4392 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 4394 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 4395 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4396 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 4397 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4398 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 4399 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 4400 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 4401 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 4403 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 4404 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 4405 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 4406 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 4408 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4409 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4410 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4411 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 4412 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4413 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4415 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4417 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4418 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4419 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4420 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4421 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4422 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 4423 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 4350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 4360 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 4361 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 4352 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 4425 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4428 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 4362 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 4363 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 4433 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 4434 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4439 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 4440 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 4441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 4447 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 4443 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4444 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4445 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 4451 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 4452 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4454 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4455 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4456 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4457 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 4462 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 4463 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4470 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 4471 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4472 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 4473 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4474 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 4475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 4476 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 4484 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_CUT
# 4487 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 4488 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4489 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 4491 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 4478 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4479 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4480 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 4495 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 4496 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4499 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 4507 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 4508 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4509 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4510 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4511 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 4512 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4513 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 4514 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 4520 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 4516 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4517 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4518 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 4524 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 4525 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4528 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 4537 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 4538 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 4539 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 4540 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 4541 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 35
# 4542 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4542 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_BAGON
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 4543 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4544 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 4545 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4546 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 4547 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 4553 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 4549 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4550 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4551 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 4557 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 4558 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 4561 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 4564 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_FINAL_BATTLE_REACHED, 1
# 4567 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer11End
# 4568 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 4569 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
	return


# 4572 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer11End:
# 4573 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 4576 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 4577 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

EscapeRoom_EventScript_TradeZeraForHMCut::
# 4584 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4585 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 4586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 4613 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 4615 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4591 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4592 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 4601 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 4604 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4605 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4606 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4609 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 4610 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 4594 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4595 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4596 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 4619 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4620 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4623 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 4648 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 4649 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 4706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 4707 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 4710 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 4626 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 4642 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 4643 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 4627 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4629 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 4636 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 4637 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 4652 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 4653 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4654 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 4666 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 4667 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4668 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4670 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4673 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4675 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4678 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 4679 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 4701 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 4630 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 4632 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 4633 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 4656 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4657 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4658 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 4715 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4716 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4719 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 4744 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 4745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 4779 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 4780 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 4783 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 4722 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 4738 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 4739 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 4723 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 4724 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 4732 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 4733 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 4748 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 4749 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4750 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 4759 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 4762 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 4763 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4764 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4765 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4768 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4770 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4773 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 4774 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 4775 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 4726 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 4728 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 4729 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 4752 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4753 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4754 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 4787 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 4788 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 4791 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 4797 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 4798 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 4827 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 4828 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 4831 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 4792 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 4793 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 4801 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 4802 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4803 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 4812 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 4813 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4814 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 4817 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4818 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 4819 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4822 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 4823 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 4805 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 4806 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4807 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_GetChoiceItem::
# 4839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetChoiceItem_1
# 4884 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsNoLongerAvailable, MSGBOX_DEFAULT
# 4885 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_1:
# 4842 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsWhichOne, MSGBOX_DEFAULT
# 4843 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4846 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionChoiceBand, OptionChoiceSpecs, OptionChoiceScarf
# 4849 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_5
# 4852 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_6
# 4855 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_7
# 4859 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsComeAgain, MSGBOX_DEFAULT
# 4860 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_4:
# 4865 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem
# 4868 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RemoveChoiceItem
# 4871 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem VAR_0x8006
# 4874 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_GetChoiceItem_12
# 4879 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CHOICE_ITEM_OBTAINED
	return

EscapeRoom_EventScript_GetChoiceItem_5:
# 4850 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_BAND
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_6:
# 4853 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SPECS
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_7:
# 4856 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SCARF
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_12:
# 4875 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsSwapped, MSGBOX_DEFAULT
# 4876 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem::
# 4890 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 4893 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem VAR_0x8006
# 4894 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1:
# 4898 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4899 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4:
# 4906 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4907 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7:
# 4916 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10
	return

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2:
# 4895 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5:
# 4900 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4901 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual1
# 4902 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4904 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual1:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8:
# 4908 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4909 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual2
# 4910 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4912 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual2:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10:
# 4917 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsAlreadyHaveThis, MSGBOX_DEFAULT
# 4918 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4919 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_RemoveChoiceItem::
# 4925 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_BAND
# 4926 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SPECS
# 4927 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SCARF
# 4929 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4930 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_3
EscapeRoom_EventScript_RemoveChoiceItem_1:
# 4937 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_11
	return

EscapeRoom_EventScript_RemoveChoiceItem_2:
# 4934 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_3:
# 4931 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 4932 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 4933 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_10:
# 4942 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	return

EscapeRoom_EventScript_RemoveChoiceItem_11:
# 4939 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 4940 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 4941 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 4950 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4951 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 4952 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 4953 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 4954 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 4958 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4959 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 4960 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 4961 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 4962 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 4966 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4967 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 4968 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 4969 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 4970 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindTMSecretPower::
# 4974 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4975 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_TM43
# 4976 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 4977 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_OBTAINED
# 4978 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy2::
# 4982 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4983 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 4984 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 4985 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 19
# 4988 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY2_STOLEN_CHECK, 1
# 4990 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRescueBell::
# 4994 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4995 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SOOTHE_BELL
# 4996 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RESCUE_BELL_OBTAINED
# 4997 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 4999 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RescueBellExplainMessage, MSGBOX_AUTOCLOSE
# 5000 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5002 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 5010 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5013 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 5021 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet1_Onix, MSGBOX_DEFAULT
# 5024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 5027 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 5030 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 5033 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 5038 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 5053 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 5014 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5015 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5016 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 5025 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 5028 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 5031 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 5034 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 5039 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5040 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 5041 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5042 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5045 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 5050 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 5046 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 5057 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5060 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 5068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet2_Zeraora, MSGBOX_DEFAULT
# 5071 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 5074 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 5077 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 5080 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 5085 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 5099 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 5061 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5062 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5063 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 5072 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 5075 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 5078 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 5081 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 5086 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5087 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 5088 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5089 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5092 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 5097 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 5093 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 5103 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5106 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 5114 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet3_Dusknoir, MSGBOX_DEFAULT
# 5117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 5120 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 5123 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 5126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 5131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 5145 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 5107 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5108 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5109 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 5118 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 5121 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 5124 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 5127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 5132 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5133 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 5134 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5135 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5138 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 5143 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 5139 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 5149 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5152 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 5160 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 5165 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchTablet4_Dunsparce, MSGBOX_DEFAULT
# 5168 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 5171 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 5174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 5177 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 5182 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 5196 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 5153 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 5154 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5155 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 5161 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 5169 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 5172 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEast, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 5175 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouth, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 5178 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWest, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 5183 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 5184 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 5186 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5189 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 5194 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 5190 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 5201 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 5206 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5207 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 5208 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 5203 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 5202 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 5204 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 5213 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5214 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 5215 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 5216 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5217 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5218 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5219 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 5220 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 5221 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5222 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 5223 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5224 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5225 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 5232 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5235 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 5238 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 5243 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 5266 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 5267 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 5239 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 5271 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5272 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5273 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5276 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 5280 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 5290 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5291 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5292 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 5296 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5297 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5300 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 5283 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 5284 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5286 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 5282 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 5281 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 5304 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5305 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5306 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5309 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 5312 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 5313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 5314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 5321 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5322 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5323 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5325 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 5316 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5317 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 5329 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5330 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5331 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5334 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 5338 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 5345 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 5346 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 5353 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 5356 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5357 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5359 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 5340 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 5341 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5343 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 5348 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5349 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5350 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 5363 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5364 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5365 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5368 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 5371 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 5372 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 5373 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 5380 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5381 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5382 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5384 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 5375 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5376 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 5388 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5389 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5390 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5393 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 5396 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 5397 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 5398 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 5405 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5406 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5407 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5409 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 5400 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5401 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 5413 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5414 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5415 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5418 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 5421 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 5422 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 5423 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 5430 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5431 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5432 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5434 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 5425 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5426 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 5438 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5439 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5440 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5443 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 5447 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 5454 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 5455 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 5466 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5467 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5468 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 5470 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 5451 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 5452 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 5457 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5458 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5460 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5461 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5462 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 5474 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5475 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5476 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5479 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 5483 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 5490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 5491 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 5498 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 5501 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5502 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5504 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 5485 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 5486 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5488 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 5493 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5494 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5495 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 5508 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5509 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5510 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5513 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 5516 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 5517 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 5518 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 5525 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5526 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5527 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5529 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 5520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5521 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 5533 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 5535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5538 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 5541 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 5542 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 5543 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 5550 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 5551 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 5552 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 5554 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 5545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 5546 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 5558 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5559 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 5561 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 5562 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5563 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5564 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5565 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5566 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5567 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5568 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 5570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 5571 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 5572 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5573 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 5575 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_SPAWNED
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 5579 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5582 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 5622 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 5623 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 5626 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 5584 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 5585 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 5616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 5617 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 5588 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 5589 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 5590 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 5593 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 5594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 5585 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 5601 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 5602 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 5607 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5608 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5609 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 5610 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 5603 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 5604 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 5631 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 5632 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 5633 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 5634 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 5635 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5636 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 5637 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 5651 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 5662 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 5663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 5664 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 5665 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


SomethingsGoneWrongMessage::
# 5672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 5679 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 5683 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 5689 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1) The game's mechanics reflect GEN 9\n"
	.string "where possible; overworld mechanics\l"
	.string "are the main exception.\p"
	.string "2) Moves & learnsets are mostly vanilla.\n"
	.string "Move PP may be reduced (e.g. 5 PP Mimic)\l"
	.string "to suit puzzle design.\p"
	.string "3) Battle RNG has been disabled.\n"
	.string "Outcomes are deterministic (0% or 100%)\l"
	.string "with Assist as sole exception.\p"
	.string "4) You won't get softlocked.\n"
	.string "The game has an anti-softlock system\l"
	.string "to undo any mistake you could make.\l"
	.string "This may include side effects (such as\l"
	.string "healing your party) to prevent gaining\l"
	.string "an advantage via the system.\p"
	.string "Keep reading?$"

SignMessage1_part2::
# 5712 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "5) There are QOL features to further\n"
	.string "reduce the need for save states:\l"
	.string "- Wild battles can be forfeited.\l"
	.string "- Lost items may return after battle.\l"
	.string "- Pre-damaged states can be restored.\l"
	.string "- Losing far from the respawn lets you\l"
	.string "   warp back to the battle area.\p"
	.string "None of these features are required to\n"
	.string "solve any of the puzzles.\p"
	.string "6) Your party is fully healed each time\n"
	.string "you beat a trainer.\p"
	.string "7) Any Pokémon could have custom IVs or\n"
	.string "EVs, including wild Pokémon.\p"
	.string "8) EXP gain from battling has been\n"
	.string "disabled.\p"
	.string "9) There are no hidden items.$"

MainSignWhatToRead::
# 5735 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to check?$"

GameCompletionMessage::
# 5739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed roughly {STR_VAR_1}% of the\n"
	.string "game so far.$"

GameCompletionMessageInitial::
# 5744 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed 0% of the game so far.$"

GameCompletionMessageFinal::
# 5748 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've fully completed the game!$"

SignMessageReadInfoAgain::
# 5752 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

MoveDeleterSignMessage::
# 5758 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP after your\l"
	.string "Pokémon used Struggle.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

EscapeRoomEndCongratz::
# 5774 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 5779 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your final time: {STR_VAR_1}.\p"
	.string "Small hints used: {STR_VAR_2}.\n"
	.string "Large hints used: {STR_VAR_3}.\l"
	.string "Solutions used: {STR_VAR_5}.$"

AnnihilapeStatueMessage::
# 5788 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 5794 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 5798 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 5802 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 5807 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 5812 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 5816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 5820 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 5829 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 5837 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 5842 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 5847 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 5854 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 5863 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 5867 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something just opened...$"

MApSwitchesAlreadySolved::
# 5871 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchTablet1_Onix::
# 5876 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet with an engraving\n"
	.string "of an Onix.$"

MapSwitchTablet2_Zeraora::
# 5881 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet with an engraving\n"
	.string "of a Zeraora.$"

MapSwitchTablet3_Dusknoir::
# 5886 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet with an engraving\n"
	.string "of a Dusknoir.$"

MapSwitchTablet4_Dunsparce::
# 5891 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's a stone tablet with an engraving\n"
	.string "of a Dunsparce.$"

MapSwitchPointedNorth::
# 5897 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEast::
# 5902 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouth::
# 5907 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWest::
# 5912 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 5919 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 5923 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 5927 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 5935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "What kind of hint would you like to get?$"

HintsIntroMessage_Finale::
# 5944 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Please note: for this final challenge,\n"
	.string "hint costs are doubled.\p"
	.string "What kind of hint would you like to get?$"

HintsNPCNoHintMessage::
# 5955 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsFinalMessage::
# 5959 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed the escape room.\n"
	.string "I'm no longer needed!$"

HintsNPCHintAlreadyReceivedMessage::
# 5964 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received this hint so\n"
	.string "no time was added to your clock.$"

HintsNPCSolutionAlreadyReceivedMessage::
# 5969 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've already received the solution\n"
	.string "so no time was added to your clock.$"

HintsNPC_ReviewPreviousStep::
# 5974 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need a refresher on the prior step?\n"
	.string "This won't add any extra time.$"

HintsNPC_ReviewExactSequence::
# 5979 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to view the exact move sequence?$"

HintsNPC15minAddedMessage::
# 5984 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "15 minutes were added to your clock.$"

HintsNPC30minAddedMessage::
# 5988 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "30 minutes were added to your clock.$"

HintsNPC60minAddedMessage::
# 5992 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1 hour was added to your clock.$"

HintsNPC120minAddedMessage::
# 5996 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "2 hours were added to your clock.$"

HintsNPC_AnnihilapeSpawn_SmallHint::
# 6001 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Those gravestones seem to be placed in\n"
	.string "an interesting pattern...$"

HintsNPC_ZeraCatchPredamage_SmallHint::
# 6006 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block is what you need,\n"
	.string "but how to get the speed?\p"
	.string "At the graveyard fight the ape.\n"
	.string "Do ghosts always escape?$"

HintsNPC_ZeraoraCatch_SmallHint::
# 6013 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sometimes Zeraora blends in a little too\n"
	.string "well with its environment.\p"
	.string "Ferrothorn can take advantage of that.$"

HintsNPC_Trainer0_SmallHint::
# 6019 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sticky Barbs are annoying.\p"
	.string "If only Florges had an item to carry.$"

HintsNPC_SafetyGoggles_SmallHint::
# 6024 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "An item you're missing may finally be\n"
	.string "within reach.$"

HintsNPC_Trainer1_SmallHint::
# 6029 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora can take out Marowak but needs\n"
	.string "to absorb some additional HP.\p"
	.string "Can both Pokémon carry the Goggles?$"

HintsNPC_MarangaBerry_SmallHint::
# 6035 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Double battles can be difficult.\n"
	.string "Is there a way to avoid them?$"

HintsNPC_Trainer2_SmallHint::
# 6040 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use Cut?$"

HintsNPC_Trainer3_SmallHint::
# 6044 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala is asleep?\n"
	.string "There's gotta be a way to use that.$"

HintsNPC_EggSkip_SmallHint::
# 6049 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Why would you need an egg?$"

HintsNPC_SunStone_SmallHint::
# 6053 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Sun Stone - small hint)$"

HintsNPC_Trainer4_SmallHint::
# 6058 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer4 - small hint)$"

HintsNPC_TauntHerb_SmallHint::
# 6062 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Taunt Herb - small hint)$"

HintsNPC_MoonStone_SmallHint::
# 6066 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Moon Stone - small hint)$"

HintsNPC_BerryJuice_SmallHint::
# 6070 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Berry Juice - small hint)$"

HintsNPC_Trainer5_SmallHint::
# 6074 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer5 - small hint)$"

HintsNPC_TrapinchRun_SmallHint::
# 6078 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trapinch Run - small hint)$"

HintsNPC_RareCandyRevive_SmallHint::
# 6082 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Rare Candy revive - small hint)$"

HintsNPC_Trainer6_SmallHint::
# 6086 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer6 - small hint)$"

HintsNPC_MapSwitches_SmallHint::
# 6090 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Map Switches - small hint)$"

HintsNPC_Trainer7A_SmallHint::
# 6094 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer7A - small hint)$"

HintsNPC_Trainer8_SmallHint::
# 6098 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer8 - small hint)$"

HintsNPC_IcePuzzleRareCandy_SmallHint::
# 6102 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Ice puzzle rare candy - small hint)$"

HintsNPC_Trainer9_SmallHint::
# 6106 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer9 - small hint)$"

HintsNPC_ToxicOrbSteal_SmallHint::
# 6110 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Toxic Orb - small hint)$"

HintsNPC_SecretPower_SmallHint::
# 6114 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Secret Power - small hint)$"

HintsNPC_RareCandy3_SmallHint::
# 6118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Rare Candy3 - small hint)$"

HintsNPC_Trainer10_SmallHint::
# 6122 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer10 - small hint)$"

HintsNPC_Trainer11_SmallHint::
# 6126 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer11 - small hint)$"

HintsNPC_AnnihilapeSpawn_LargeHint::
# 6132 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones represent a numpad.\n"
	.string "Maybe there's a code written somewhere\l"
	.string "for you to enter.$"

HintsNPC_ZeraCatchPredamage_LargeHint::
# 6138 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "How to pre-damage Ferrothorn for\n"
	.string "Custap Berry use?\p"
	.string "Grass Knot is great, but Florges is so\n"
	.string "heavy...\p"
	.string "Florges can run?\n"
	.string "That's so spooky!$"

HintsNPC_ZeraoraCatch_LargeHint::
# 6147 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Block, Ingrain, Zeraora will stay.\n"
	.string "The Electric type stands in your way.\p"
	.string "1 PP was all you need, now Ferrothorn\n"
	.string "rolls away the weed.\p"
	.string "That's when you'll catch it!$"

HintsNPC_Trainer0_LargeHint::
# 6155 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Struggling against Rhyperior?\n"
	.string "TM Skill Swap is really useful!\p"
	.string "Consider giving it to Florges.$"

HintsNPC_SafetyGoggles_LargeHint::
# 6161 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One of the gravestones is a little\n"
	.string "mysterious.\p"
	.string "Can Zeraora help you out?$"

HintsNPC_Trainer1_LargeHint::
# 6167 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Cut Guy is very tough!\p"
	.string "Zeraora can beat the Marowak, but you\n"
	.string "must use Volt Absorb to keep it alive.\p"
	.string "Start the fight with Grassy Terrain,\n"
	.string "then share the Goggles with Zeraora\l"
	.string "once Lightningrod is removed.$"

HintsNPC_MarangaBerry_LargeHint::
# 6178 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.$"

HintsNPC_Trainer2_LargeHint::
# 6184 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Nature Power won't cut it?\n"
	.string "Just remove the grass.$"

HintsNPC_Trainer3_LargeHint::
# 6189 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Komala's type keeps Hex from landing.\n"
	.string "Maybe it needs a different held item.\p"
	.string "Magicians never reveal their secret,\n"
	.string "but a little sharing doesn't hurt.\p"
	.string "Why is Komala holding a Snowball?$"

HintsNPC_EggSkip_LargeHint::
# 6197 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins will have a difficult time\n"
	.string "fighting you when one of your Pokémon\l"
	.string "has already fainted.\p"
	.string "...\p"
	.string "Or when you only have one Pokémon.$"

HintsNPC_SunStone_LargeHint::
# 6205 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Sun Stone - large hint)$"

HintsNPC_Trainer4_LargeHint::
# 6210 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer4 - large hint)$"

HintsNPC_TauntHerb_LargeHint::
# 6214 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Taunt Herb - large hint)$"

HintsNPC_MoonStone_LargeHint::
# 6218 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Moon Stone - large hint)$"

HintsNPC_BerryJuice_LargeHint::
# 6222 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Berry Juice - large hint)$"

HintsNPC_Trainer5_LargeHint::
# 6226 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer5 - large hint)$"

HintsNPC_TrapinchRun_LargeHint::
# 6230 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trapinch Run - large hint)$"

HintsNPC_RareCandyRevive_LargeHint::
# 6234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Rare Candy revive - large hint)$"

HintsNPC_Trainer6_LargeHint::
# 6238 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer6 - large hint)$"

HintsNPC_MapSwitches_LargeHint::
# 6242 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Map Switches - large hint)$"

HintsNPC_Trainer7A_LargeHint::
# 6246 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer7A - large hint)$"

HintsNPC_Trainer8_LargeHint::
# 6250 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer8 - large hint)$"

HintsNPC_IcePuzzleRareCandy_LargeHint::
# 6254 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Ice puzzle rare candy - large hint)$"

HintsNPC_Trainer9_LargeHint::
# 6258 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer9 - large hint)$"

HintsNPC_ToxicOrbSteal_LargeHint::
# 6262 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Toxic Orb - large hint)$"

HintsNPC_SecretPower_LargeHint::
# 6266 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Secret Power - large hint)$"

HintsNPC_RareCandy3_LargeHint::
# 6270 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Rare Candy3 - large hint)$"

HintsNPC_Trainer10_LargeHint::
# 6274 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer10 - large hint)$"

HintsNPC_Trainer11_LargeHint::
# 6278 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer11 - large hint)$"

HintsNPC_AnnihilapeSpawn_Solution::
# 6284 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The gravestones form a numpad pattern:\n"
	.string "1 2 3, 4 5 6, 7 8 9, 0.\p"
	.string "Interact with them in the following\n"
	.string "order: 1 8 3 7.$"

HintsNPC_ZeraCatchPredamage_Solution::
# 6291 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 6303 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Pre-damage Ferrothorn by letting the\n"
	.string "Annihilape use Grass Knot.\p"
	.string "Give Florges a Float Stone and use\n"
	.string "Camouflage to run away.$"

HintsNPC_ZeraoraCatch_Solution::
# 6310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "1. Use Custap Berry Block vs Zeraora\n"
	.string "and let it Snatch Ingrain.\p"
	.string "2. Switch to Florges, use the Ether on\n"
	.string "Camouflage, and let Zeraora copy both\l"
	.string "Grassy Terrain and Camouflage.\p"
	.string "3. Switch to Ferrothorn and use Steel\n"
	.string "Roller.\p"
	.string "You can now catch Zeraora (using the\n"
	.string "Ultra Ball given by the NPC).$"

HintsNPC_Trainer0_Solution::
# 6322 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have to beat the Pincurchin\n"
	.string "trainer.\p"
	.string "1. Give TM Skill Swap to Florges as\n"
	.string "held item.\p"
	.string "2. Sack Ferrothorn and Zeraora to the\n"
	.string "Selfdestructing Pincurchin.\p"
	.string "3. Use Grass Knot.$"

HintsNPC_SafetyGoggles_Solution::
# 6332 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Exp Candy on Zeraora to reach\n"
	.string "level 43.\p"
	.string "Go to the graveyard and interact with\n"
	.string "the bottom-left gravestone to obtain\l"
	.string "the Safety Goggles.$"

HintsNPC_Trainer1_Solution::
# 6340 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You have to defeat the Toedscruel and\n"
	.string "Marowak trainer.\p"
	.string "First replace Grass Knot for Skill Swap,\n"
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

intsNPC_Trainer1_Solution_ExactSequence::
# 6363 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Florges (Safety Goggles) and\n"
	.string "Zeroara (Electric Seed).\p"
	.string "Turn 1: Grassy Terrain + X.\n"
	.string "Turn 2: Skill Swap (Marowak) + X.\l"
	.string "Turn 3: Switch to Ferrothorn + X.\l"
	.string "Turn 4: Camouflage + Plasma Fists\l"
	.string "(redirected into Toedscruel).\p"
	.string "Turn 5: Nature Power (Zeraora) +\n"
	.string "Electric Terrain.\p"
	.string "Turn 6: Nature Power (Zeraora) +\n"
	.string "Plasma Fists (Marowak).\p"
	.string "Turn 7: X + Plasma Fists (Marowak).\n"
	.string "Repeat untill Marowak faints.$"

HintsNPC_MarangaBerry_Solution::
# 6383 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fight the Annihilape and let it copy\n"
	.string "Steel Roller.\p"
	.string "Set up Grassy Terrain, switch out and\n"
	.string "sack Ferrothorn, use Camouflage, and\l"
	.string "run from battle.\p"
	.string "You can now walk past the Twins and\n"
	.string "pick the Maranga Berry.$"

HintsNPC_Trainer2_Solution::
# 6393 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Give Florges the Maranga Berry, then\n"
	.string "use Cut to remove the Grass tiles next\l"
	.string "to the Dracozolt trainer.\p"
	.string "Start the battle on a regular tile and\n"
	.string "use Nature Power to win.$"

HintsNPC_Trainer3_Solution::
# 6401 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let Klefki steal your Ring Target with\n"
	.string "Magician, give it Symbiosis, activate\l"
	.string "Komala's Snowball, and you're now able\l"
	.string "to beat it with Trump Card and Hex.$"

intsNPC_Trainer3_Solution_ExactSequence::
# 6408 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Lead: Florges (Ring Target) and\n"
	.string "Dunsparce.\p"
	.string "Turn 1: Grassy Terrain + Trump Card.\n"
	.string "Turn 2: Skill Swap + Trump Card.\l"
	.string "Turn 3: Ice Beam (Komala).\l"
	.string "Turn 4-6: Trump Card.\l"
	.string "Turn 7: Hex.\l"
	.string "Repeat untill Komala faints.$"

HintsNPC_EggSkip_Solution::
# 6419 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Twins cannot fight you when one of\n"
	.string "your Pokémon is an egg.\p"
	.string "Buy an Escape Rope, exit and re-enter\n"
	.string "the cave from where the Liepard Collar\l"
	.string "was located.\p"
	.string "Trade your Florges for the Pokémon egg,\n"
	.string "use the Escape Rope, and you can now\l"
	.string "walk past the Twins again.$"

HintsNPC_SunStone_Solution::
# 6431 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Sun Stone solution)$"

HintsNPC_Trainer4_Solution::
# 6437 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer4 solution)$"

HintsNPC_TauntHerb_Solution::
# 6442 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Taunt Herb solution)$"

HintsNPC_MoonStone_Solution::
# 6447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Moon Stone solution)$"

HintsNPC_BerryJuice_Solution::
# 6452 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Berry Juice solution)$"

HintsNPC_Trainer5_Solution::
# 6457 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer5 solution)$"

HintsNPC_TrapinchRun_Solution::
# 6462 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trapinch Run solution)$"

HintsNPC_RareCandyRevive_Solution::
# 6468 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Rare Candy revive solution)$"

HintsNPC_Trainer6_Solution::
# 6473 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer6 solution)$"

HintsNPC_MapSwitches_Solution::
# 6478 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Map Switches solution)$"

HintsNPC_Trainer7A_Solution::
# 6483 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer7A solution)$"

HintsNPC_Trainer8_Solution::
# 6488 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer8 solution)$"

HintsNPC_IcePuzzleRareCandy_Solution::
# 6493 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Ice puzzle rare candy solution)$"

HintsNPC_Trainer9_Solution::
# 6498 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer9 solution)$"

HintsNPC_ToxicOrbSteal_Solution::
# 6504 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Toxic Orb solution)$"

HintsNPC_SecretPower_Solution::
# 6509 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Secret Power solution)$"

HintsNPC_RareCandy3_Solution::
# 6514 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Rare Candy3 solution)$"

HintsNPC_Trainer10_Solution::
# 6519 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer10 solution)$"

HintsNPC_Trainer11_Solution::
# 6524 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (Trainer11 solution)$"

AntiSoftlockIntroMessage::
# 6535 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 6545 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 6549 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 6555 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 6560 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 6564 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 6568 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 6574 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 6579 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 6583 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoSecretPower::
# 6586 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Secret Power$"

OptionUndoCut::
# 6589 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 6592 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 6595 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 6598 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 6602 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 6607 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "used on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 6612 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 6617 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 6621 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 6626 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 6631 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 6635 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 6639 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 6643 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 6649 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 6654 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 6661 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 6665 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 6670 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 6677 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 6687 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 6694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 6705 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 6709 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 6716 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 6720 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 6724 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your energy trying to catch\n"
	.string "or beat her.$"

FourTabletsHintMessage1::
# 6736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 6742 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?$"

FourTabletsHintMessage3::
# 6747 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake???$"

StonesBuyNPCInitialMessage_no_item::
# 6754 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 6762 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 6768 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 6776 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 6780 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 6784 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 6788 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 6792 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 6799 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 6803 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 6807 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 6811 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 6818 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 6822 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretPowerTmReturned::
# 6829 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TM43 Secret Power was returned to its\n"
	.string "previous location.$"

RareCandy2Returned::
# 6834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Rare Candy was returned to its\n"
	.string "previous location.$"

MonForgotSecretPower::
# 6839 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MartNPC_AskToShop::
# 6845 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 6851 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

ChoiceItemsFirstMessage::
# 6857 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Impressive, you saw right through my\n"
	.string "facade!\p"
	.string "I think you've earned a reward!\n"
	.string "Take your pick of my Choice items.\p"
	.string "You can always return if you'd like to\n"
	.string "try a different one.$"

ChoiceItemsNoLongerAvailable::
# 6866 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It seems you've made the right choice.$"

ChoiceItemsWhichOne::
# 6870 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Which item would you like to have?$"

ChoiceItemsComeAgain::
# 6874 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back anytime.$"

ChoiceItemsSwapped::
# 6878 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You returned the other Choice item.$"

ChoiceItemsAlreadyHaveThis::
# 6882 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You already have this one.$"

OptionChoiceBand::
# 6886 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Band$"

OptionChoiceSpecs::
# 6890 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Specs$"

OptionChoiceScarf::
# 6894 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Scarf$"

PrimeapeObtainMessage::
# 6900 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 6904 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

RescueBellExplainMessage::
# 6910 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Use the Rescue Bell to teleport out of\n"
	.string "the ice puzzle if you're stuck.\p"
	.string "When used, newly obtained items will be\n"
	.string "placed back inside the ice puzzle.$"

AskDeleteMove::
# 6919 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 6925 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 6931 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 6935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 6939 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 6945 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 6949 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 6953 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 6960 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 6965 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 6970 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 6976 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 6982 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 6987 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 6991 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 6995 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 6999 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 7003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 7008 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 7013 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 7018 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 7024 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 7028 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 7032 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 7036 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 7040 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 7045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 7049 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 7054 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 7060 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 7066 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 7070 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 7076 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 7083 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You think you are ready?\n"
	.string "You really need three.\l"
	.string "One of them might hold the key.$"

Trainer0_Outro::
# 7092 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go!$"

Trainer0_PostBattle::
# 7096 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?$"

Trainer1_Intro::
# 7103 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 7109 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 7113 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 7118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 7125 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 7131 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 7136 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love writing in 686578!$"

Trainer2_PostBattle::
# 7140 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 7146 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 7151 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 7155 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 7160 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 7166 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 7171 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 7175 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know 5(A->L) + 2(L->O) = 525?$"

Trainer5_Intro::
# 7182 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 7187 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 7191 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 7195 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 7202 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 7209 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 7213 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My birds have traveled through all\n"
	.string "sorts of areas.\p"
	.string "Your Pokédex would be full by now if\n"
	.string "you'd done the same!$"

Trainer7A_Intro::
# 7222 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 7229 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 7233 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "fwuenqru? uwu.$"

Trainer7B_Intro::
# 7240 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 7245 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 7249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 7256 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Ghost type mons are everywhere,\n"
	.string "you still haven't seen mine.$"

Trainer8_Outro::
# 7268 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 7272 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "$"

Trainer9_Intro::
# 7278 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 7283 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Try hard in every fight!$"

Trainer9_PostBattle::
# 7287 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is this your last time passing through?$"

Trainer10_Intro::
# 7293 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Darwinism?\n"
	.string "More like Schmarminism...\p"
	.string "Kecleon doesn't need any changes!$"

Trainer10_Outro::
# 7299 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a struggle!$"

Trainer10_PostBattle::
# 7303 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So Kecleon isn't the only Pokémon with\n"
	.string "the ability to change?$"

Trainer11_Intro::
# 7310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So you've finally made it to the end...\p"
	.string "No more hints.\p"
	.string "No more clues.\p"
	.string "It's time for your final test.$"

Trainer11_Outro::
# 7317 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

Trainer11_PostBattle_A::
# 7321 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please read the sign first.$"

Trainer11_PostBattle_B::
# 7325 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This game has been a true passion\n"
	.string "project of mine.\p"
	.string "An absurd amount of time, effort, and\n"
	.string "care was put into every minor detail\l"
	.string "of the game.\p"
	.string "If you enjoyed the experience, please\n"
	.string "let me know by commenting on the game's\l"
	.string "PokéCommunity forum post.\p"
	.string "It really does mean lot to me.\p"
	.string "Thank you so much for playing.\n"
	.string " - Ketch.$"
