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
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 90 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 95 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 96 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 97 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 103 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfSecretPowerObtained
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_14
EscapeRoom_MapScript_OnResumeScripts_12:
# 127 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_18
EscapeRoom_MapScript_OnResumeScripts_17:
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_21
EscapeRoom_MapScript_OnResumeScripts_20:
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_24
EscapeRoom_MapScript_OnResumeScripts_23:
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 151 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_26
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 115 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_14:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_13
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_18:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_17

EscapeRoom_MapScript_OnResumeScripts_21:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStickyBarbStolen
	goto EscapeRoom_MapScript_OnResumeScripts_20

EscapeRoom_MapScript_OnResumeScripts_24:
# 139 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_23

EscapeRoom_MapScript_OnResumeScripts_26:
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 174 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 177 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 187 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 188 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 189 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 200 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 200 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 202 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 216 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 217 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 225 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 222 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckStickyBarbStolen::
# 231 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_2
EscapeRoom_MapScripts_CheckStickyBarbStolen_1:
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_5
EscapeRoom_MapScripts_CheckStickyBarbStolen_4:
# 239 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 240 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_8
EscapeRoom_MapScripts_CheckStickyBarbStolen_7:
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 244 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_10
	return

EscapeRoom_MapScripts_CheckStickyBarbStolen_2:
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_1

EscapeRoom_MapScripts_CheckStickyBarbStolen_5:
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_4

EscapeRoom_MapScripts_CheckStickyBarbStolen_8:
# 241 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_7

EscapeRoom_MapScripts_CheckStickyBarbStolen_10:
# 245 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_8
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 260 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_11
EscapeRoom_MapScripts_CheckIfAskPreDamage_10:
# 267 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 262 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 265 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_10


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 283 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 287 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 292 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 307 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 284 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 283 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 293 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 309 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_CheckIfAskWarpBack::
# 315 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskWarpBack_3
EscapeRoom_MapScripts_CheckIfAskWarpBack_1:
# 322 "data/maps/EscapeRoom_Main/scripts.pory"
Equal:
	return

EscapeRoom_MapScripts_CheckIfAskWarpBack_2:
# 318 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_LOCATED_AT_SECTION_X, VAR_RESPAWN_AT_SECTION_X
# 319 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_eq Equal
# 320 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 1
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1

EscapeRoom_MapScripts_CheckIfAskWarpBack_3:
# 315 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_MapScripts_CheckIfAskWarpBack_2
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1


EscapeRoom_MapScripts_CheckIfSecretPowerObtained::
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2
	return

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1:
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6
# 344 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6
# 345 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6
EscapeRoom_MapScripts_CheckIfSecretPowerObtained_5:
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_THIEF
	return

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_2:
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_MapScripts_CheckIfSecretPowerObtained_1
	return

EscapeRoom_MapScripts_CheckIfSecretPowerObtained_6:
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_SOMETHING_WRONG_MESSAGE, 1
	goto EscapeRoom_MapScripts_CheckIfSecretPowerObtained_5


EscapeRoom_MapScripts_FindBallAferUse::
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 373 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 374 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 375 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 396 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 397 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 402 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 407 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 413 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 421 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 425 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 477 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 484 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 511 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 524 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScript_GameStartScripts::
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 543 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 610 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 620 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 621 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 622 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 629 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 654 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 668 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 686 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 684 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 717 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 729 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 730 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MainSignWhatToRead, MSGBOX_MAIN_SIGN
# 754 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_3
EscapeRoom_EventScript_MainInfoSign_1:
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_MainInfoSign_6
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_MainInfoSign_7
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetGameCompletion
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessage, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_3:
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 771 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_11
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_6:
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageInitial, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_7:
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GameCompletionMessageFinal, MSGBOX_DEFAULT
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_11:
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_GetGameCompletion::
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 0
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANNIHILAPE_SPAWNED, EscapeRoom_EventScript_GetGameCompletion_2
EscapeRoom_EventScript_GetGameCompletion_1:
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_GetGameCompletion_5
EscapeRoom_EventScript_GetGameCompletion_4:
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_8
EscapeRoom_EventScript_GetGameCompletion_7:
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_11
EscapeRoom_EventScript_GetGameCompletion_10:
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MARANGA_BERRY_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_14
EscapeRoom_EventScript_GetGameCompletion_13:
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_17
EscapeRoom_EventScript_GetGameCompletion_16:
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_20
EscapeRoom_EventScript_GetGameCompletion_19:
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_23
EscapeRoom_EventScript_GetGameCompletion_22:
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SUN_STONE_SOLD, EscapeRoom_EventScript_GetGameCompletion_26
EscapeRoom_EventScript_GetGameCompletion_25:
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_29
EscapeRoom_EventScript_GetGameCompletion_28:
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_GetGameCompletion_32
EscapeRoom_EventScript_GetGameCompletion_31:
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SPACE_ITEM_STOLEN, EscapeRoom_EventScript_GetGameCompletion_35
EscapeRoom_EventScript_GetGameCompletion_34:
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_38
EscapeRoom_EventScript_GetGameCompletion_37:
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_GetGameCompletion_41
EscapeRoom_EventScript_GetGameCompletion_40:
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_GetGameCompletion_44
EscapeRoom_EventScript_GetGameCompletion_43:
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_47
EscapeRoom_EventScript_GetGameCompletion_46:
# 870 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_GetGameCompletion_50
EscapeRoom_EventScript_GetGameCompletion_49:
# 878 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7A_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_53
EscapeRoom_EventScript_GetGameCompletion_52:
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_56
EscapeRoom_EventScript_GetGameCompletion_55:
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_59
EscapeRoom_EventScript_GetGameCompletion_58:
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_EventScript_GetGameCompletion_62
EscapeRoom_EventScript_GetGameCompletion_61:
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RARE_CANDY3_OBTAINED, EscapeRoom_EventScript_GetGameCompletion_65
EscapeRoom_EventScript_GetGameCompletion_64:
# 903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_68
EscapeRoom_EventScript_GetGameCompletion_67:
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_GetGameCompletion_70
	return

EscapeRoom_EventScript_GetGameCompletion_2:
# 788 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 2
	goto EscapeRoom_EventScript_GetGameCompletion_1

EscapeRoom_EventScript_GetGameCompletion_5:
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 8
	goto EscapeRoom_EventScript_GetGameCompletion_4

EscapeRoom_EventScript_GetGameCompletion_8:
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 12
	goto EscapeRoom_EventScript_GetGameCompletion_7

EscapeRoom_EventScript_GetGameCompletion_11:
# 803 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 18
	goto EscapeRoom_EventScript_GetGameCompletion_10

EscapeRoom_EventScript_GetGameCompletion_14:
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 20
	goto EscapeRoom_EventScript_GetGameCompletion_13

EscapeRoom_EventScript_GetGameCompletion_17:
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 23
	goto EscapeRoom_EventScript_GetGameCompletion_16

EscapeRoom_EventScript_GetGameCompletion_20:
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 28
	goto EscapeRoom_EventScript_GetGameCompletion_19

EscapeRoom_EventScript_GetGameCompletion_23:
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 33
	goto EscapeRoom_EventScript_GetGameCompletion_22

EscapeRoom_EventScript_GetGameCompletion_26:
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 35
	goto EscapeRoom_EventScript_GetGameCompletion_25

EscapeRoom_EventScript_GetGameCompletion_29:
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 41
	goto EscapeRoom_EventScript_GetGameCompletion_28

EscapeRoom_EventScript_GetGameCompletion_32:
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 44
	goto EscapeRoom_EventScript_GetGameCompletion_31

EscapeRoom_EventScript_GetGameCompletion_35:
# 846 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 46
	goto EscapeRoom_EventScript_GetGameCompletion_34

EscapeRoom_EventScript_GetGameCompletion_38:
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 49
	goto EscapeRoom_EventScript_GetGameCompletion_37

EscapeRoom_EventScript_GetGameCompletion_41:
# 856 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 55
	goto EscapeRoom_EventScript_GetGameCompletion_40

EscapeRoom_EventScript_GetGameCompletion_44:
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 57
	goto EscapeRoom_EventScript_GetGameCompletion_43

EscapeRoom_EventScript_GetGameCompletion_47:
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 63
	goto EscapeRoom_EventScript_GetGameCompletion_46

EscapeRoom_EventScript_GetGameCompletion_50:
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 68
	goto EscapeRoom_EventScript_GetGameCompletion_49

EscapeRoom_EventScript_GetGameCompletion_53:
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 73
	goto EscapeRoom_EventScript_GetGameCompletion_52

EscapeRoom_EventScript_GetGameCompletion_56:
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 78
	goto EscapeRoom_EventScript_GetGameCompletion_55

EscapeRoom_EventScript_GetGameCompletion_59:
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 84
	goto EscapeRoom_EventScript_GetGameCompletion_58

EscapeRoom_EventScript_GetGameCompletion_62:
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 89
	goto EscapeRoom_EventScript_GetGameCompletion_61

EscapeRoom_EventScript_GetGameCompletion_65:
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 91
	goto EscapeRoom_EventScript_GetGameCompletion_64

EscapeRoom_EventScript_GetGameCompletion_68:
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 95
	goto EscapeRoom_EventScript_GetGameCompletion_67

EscapeRoom_EventScript_GetGameCompletion_70:
# 909 "data/maps/EscapeRoom_Main/scripts.pory"
	buffernumberstring STR_VAR_1, 100
	return


EscapeRoom_EventScript_MoveDeleterSign::
# 916 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 917 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 943 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 928 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 948 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Heal_Pokemon_Nurse1::
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 964 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 993 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_HINTNPC
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 1001 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_3
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_HintsNPC_4
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 1016 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_SmallHint
	goto EscapeRoom_EventScript_HintsNPC_1

EscapeRoom_EventScript_HintsNPC_3:
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_LargeHint
	goto EscapeRoom_EventScript_HintsNPC_1

EscapeRoom_EventScript_HintsNPC_4:
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPC_Solution
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 1045 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 1064 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 1065 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1066 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1075 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1049 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 1096 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 1122 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 1123 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_30
EscapeRoom_EventScript_ReturnLostItems_29:
# 1166 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 1167 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_35
EscapeRoom_EventScript_ReturnLostItems_34:
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_42:
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_49
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_49
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1278 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 1092 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 1108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 1124 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 1109 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_25
EscapeRoom_EventScript_ReturnLostItems_23:
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1139 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 1140 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_32
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_22:
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_24:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_22
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_25:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_24
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_30:
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_29

EscapeRoom_EventScript_ReturnLostItems_32:
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_35:
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_38:
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_47
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_43:
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_54:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_68
EscapeRoom_EventScript_ReturnLostItems_67:
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_79
EscapeRoom_EventScript_ReturnLostItems_78:
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_83
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_44:
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_47:
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 1180 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 1181 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_49:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_63
EscapeRoom_EventScript_ReturnLostItems_61:
# 1252 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_59
EscapeRoom_EventScript_ReturnLostItems_57:
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_70
	return

EscapeRoom_EventScript_ReturnLostItems_55:
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_54

EscapeRoom_EventScript_ReturnLostItems_58:
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_72
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_59:
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_62:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_58
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_63:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_62
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_68:
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_67

EscapeRoom_EventScript_ReturnLostItems_70:
# 1267 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_72:
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1233 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_73:
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_81
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_76:
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_79:
# 1204 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_78

EscapeRoom_EventScript_ReturnLostItems_81:
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_83:
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 1213 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_42


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 1317 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 1331 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 1336 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 1337 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 1356 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_29
EscapeRoom_EventScript_UndoUsedItems_28:
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_32
EscapeRoom_EventScript_UndoUsedItems_31:
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
EscapeRoom_EventScript_UndoUsedItems_34:
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_42
EscapeRoom_EventScript_UndoUsedItems_41:
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SECRET_POWER
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_44
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_ANNIHILAPE
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1327 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_29:
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_28

EscapeRoom_EventScript_UndoUsedItems_32:
# 1366 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_31

EscapeRoom_EventScript_UndoUsedItems_35:
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_34

EscapeRoom_EventScript_UndoUsedItems_42:
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_41

EscapeRoom_EventScript_UndoUsedItems_44:
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38:
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 1415 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21:
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13
# 1468 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1479 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45:
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66:
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72:
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSecretPower, OptionUndoRareCandy
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 1449 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13:
# 1464 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14:
# 1469 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 1415 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37:
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41:
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 1498 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70:
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73:
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76:
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79:
# 1523 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 1537 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_5
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_6
EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_10
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_11
EscapeRoom_EventScript_AskUndoMoveTeach_9:
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_18
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_5:
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_14
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_6:
# 1551 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 1552 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_16
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_10:
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_20
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_11:
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 1566 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_22
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_14:
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_16:
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_18:
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_AskUndoMoveTeach_20:
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_22:
# 1567 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9


EscapeRoom_EventScript_UndoMoveTeach::
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 1604 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_10:
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
# 1658 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
# 1661 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_32:
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1667 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_46
EscapeRoom_EventScript_UndoMoveTeach_45:
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 1680 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_57
EscapeRoom_EventScript_UndoMoveTeach_55:
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_53:
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_65
EscapeRoom_EventScript_UndoMoveTeach_64:
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_74
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_23
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, VAR_0x8008
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 1621 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, VAR_0x8008
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_23:
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_26:
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_41
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_33:
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM43
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_35:
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_39:
# 1632 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_40:
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 1646 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_41:
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_40
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_46:
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_45

EscapeRoom_EventScript_UndoMoveTeach_49:
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_56:
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_57:
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_56
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_62:
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_69
EscapeRoom_EventScript_UndoMoveTeach_67:
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_85
EscapeRoom_EventScript_UndoMoveTeach_83:
# 1723 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_94
EscapeRoom_EventScript_UndoMoveTeach_93:
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_99
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_65:
# 1741 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_80
EscapeRoom_EventScript_UndoMoveTeach_78:
# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_90
EscapeRoom_EventScript_UndoMoveTeach_88:
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 1756 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_97
EscapeRoom_EventScript_UndoMoveTeach_96:
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_101
	goto EscapeRoom_EventScript_UndoMoveTeach_64

EscapeRoom_EventScript_UndoMoveTeach_68:
# 1713 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_69:
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_68
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_72:
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_73:
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_72
	return

EscapeRoom_EventScript_UndoMoveTeach_74:
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_73
	return

EscapeRoom_EventScript_UndoMoveTeach_79:
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1745 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_80:
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_79
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_84:
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_85:
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_84
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_89:
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_90:
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_89
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_94:
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_93

EscapeRoom_EventScript_UndoMoveTeach_97:
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_96

EscapeRoom_EventScript_UndoMoveTeach_99:
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_101:
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_64


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 1788 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 1801 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 1797 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 1815 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 1831 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 1819 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 1834 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_31
EscapeRoom_EventScript_UndoRareCandy_30:
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 1897 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
EscapeRoom_EventScript_UndoRareCandy_27:
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_36
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_38
EscapeRoom_EventScript_UndoRareCandy_35:
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_48
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1862 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1863 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 1848 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_33
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_43
EscapeRoom_EventScript_UndoRareCandy_42:
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_51
EscapeRoom_EventScript_UndoRareCandy_50:
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_59
EscapeRoom_EventScript_UndoRareCandy_58:
# 1946 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 1954 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 1955 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_68
EscapeRoom_EventScript_UndoRareCandy_66:
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_77
EscapeRoom_EventScript_UndoRareCandy_75:
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_31:
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_30

EscapeRoom_EventScript_UndoRareCandy_33:
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_36:
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_37:
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_38:
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_43:
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_42

EscapeRoom_EventScript_UndoRareCandy_46:
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_48:
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_55
EscapeRoom_EventScript_UndoRareCandy_54:
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_64
	return

EscapeRoom_EventScript_UndoRareCandy_51:
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_50

EscapeRoom_EventScript_UndoRareCandy_53:
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_61
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_73
	return

EscapeRoom_EventScript_UndoRareCandy_55:
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_53
	goto EscapeRoom_EventScript_UndoRareCandy_54

EscapeRoom_EventScript_UndoRareCandy_59:
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_58

EscapeRoom_EventScript_UndoRareCandy_61:
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_71
	return

EscapeRoom_EventScript_UndoRareCandy_64:
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_67:
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1961 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_68:
# 1955 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_67
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_71:
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2016 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_73:
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return

EscapeRoom_EventScript_UndoRareCandy_76:
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 1974 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1975 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1976 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_75

EscapeRoom_EventScript_UndoRareCandy_77:
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_76
	goto EscapeRoom_EventScript_UndoRareCandy_75


EscapeRoom_EventScript_UndoExpCandy::
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 2057 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 2063 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 2067 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2069 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 2081 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 2084 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 2092 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2120 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 2123 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 2124 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2129 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 2136 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2172 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2192 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_LiepardNPC::
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 2294 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2219 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2220 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2230 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2234 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2242 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2252 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 2258 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 2271 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2272 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 2273 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 2277 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 2289 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 2304 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 2308 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 2311 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2342 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 2343 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2344 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 2367 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 2374 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 2375 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 2378 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2380 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 2381 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2382 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 2383 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2386 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 2387 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2389 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 2393 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 2396 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 2401 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 2404 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 2405 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2406 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2407 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 2411 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2412 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2424 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 2425 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 2428 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2429 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 2434 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 2435 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 2436 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 2438 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 2445 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2449 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 2456 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 2450 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 2451 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2452 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 2460 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 2461 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 2478 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 2482 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 2483 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 2488 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 2491 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 2492 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 2507 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 2521 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 2522 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 2536 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2495 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 2498 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 2499 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2500 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2501 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2502 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 2508 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2509 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 2513 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 2514 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2516 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2517 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2525 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2530 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2531 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2532 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 2538 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 2539 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 2546 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2547 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 2548 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 2550 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 2557 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 2573 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2563 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2564 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 2600 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 2608 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2609 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2611 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 2615 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2618 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2626 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 2627 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2630 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 2631 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2632 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 2638 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 2648 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2650 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2651 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2653 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 2654 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2656 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 2657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2660 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2664 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 2670 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 2671 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 2673 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 2676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2677 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2681 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 2688 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 2704 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 2705 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 2711 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 2692 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 2693 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 2699 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 2706 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 2719 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2720 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 2722 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 2737 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 2723 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2728 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2729 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2731 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SUN_STONE_SOLD
# 2733 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2744 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 2755 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2756 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 2747 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 2748 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 2749 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 2751 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 2752 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_SecretGarden_GateEntryNPC_KeepOut::
# 2764 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2767 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2770 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_left
# 2771 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 25
# 2775 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardKeepOut, MSGBOX_AUTOCLOSE
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2779 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2780 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_SecretGarden_GateEntryNPC_KickOut::
# 2786 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2789 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2790 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2791 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_down
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2794 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2796 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_down
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2799 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2802 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardSpotted, MSGBOX_AUTOCLOSE
# 2803 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2806 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_up
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveUp
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2809 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2812 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_OBTAINED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2812 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1:
# 2850 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2853 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2:
# 2813 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardStayOut, MSGBOX_AUTOCLOSE
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3:
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardRemoveSecretPower, MSGBOX_AUTOCLOSE
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2819 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 2824 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8:
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_15
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13:
# 2834 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM43
# 2835 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_18:
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_21:
# 2845 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_OBTAINED
# 2846 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9:
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 2827 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10:
# 2825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14:
# 2831 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 2832 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_15:
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19:
# 2836 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM43
# 2837 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_18

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22:
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoSecretPowerTeach
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_21


EscapeRoom_EventScript_UndoSecretPowerTeach::
# 2859 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2860 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_2
EscapeRoom_EventScript_UndoSecretPowerTeach_1:
# 2870 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2871 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_5
EscapeRoom_EventScript_UndoSecretPowerTeach_4:
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2876 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_10
EscapeRoom_EventScript_UndoSecretPowerTeach_9:
# 2886 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 2887 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_13
EscapeRoom_EventScript_UndoSecretPowerTeach_12:
# 2894 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_SECRET_POWER
# 2895 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_SECRET_POWER, VAR_0x8004
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_SECRET_POWER
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
EscapeRoom_EventScript_UndoSecretPowerTeach_17:
# 2903 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
# 2903 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
EscapeRoom_EventScript_UndoSecretPowerTeach_22:
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
EscapeRoom_EventScript_UndoSecretPowerTeach_27:
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
EscapeRoom_EventScript_UndoSecretPowerTeach_32:
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
EscapeRoom_EventScript_UndoSecretPowerTeach_43:
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2961 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2962 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 2963 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSecretPowerTeach_2:
# 2861 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_7
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_5:
# 2872 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_4

EscapeRoom_EventScript_UndoSecretPowerTeach_7:
# 2866 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_10:
# 2877 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 2880 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_15
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_13:
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_12

EscapeRoom_EventScript_UndoSecretPowerTeach_15:
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_18:
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_17

EscapeRoom_EventScript_UndoSecretPowerTeach_23:
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2905 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_22

EscapeRoom_EventScript_UndoSecretPowerTeach_28:
# 2912 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_37
# 2918 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_39
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_33:
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_49
EscapeRoom_EventScript_UndoSecretPowerTeach_48:
# 2941 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_59
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_37:
# 2915 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_38:
# 2921 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_52
# 2925 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_53
EscapeRoom_EventScript_UndoSecretPowerTeach_51:
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_39:
# 2918 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_38
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_44:
# 2948 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 2949 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_57
EscapeRoom_EventScript_UndoSecretPowerTeach_56:
# 2952 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2953 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_61
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43

EscapeRoom_EventScript_UndoSecretPowerTeach_49:
# 2939 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_48

EscapeRoom_EventScript_UndoSecretPowerTeach_52:
# 2922 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2923 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_53:
# 2926 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2927 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_57:
# 2950 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_56

EscapeRoom_EventScript_UndoSecretPowerTeach_59:
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_61:
# 2954 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43


# 2966 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_down:
# 2967 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2967 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2970 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_up:
# 2971 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2972 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2972 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2973 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2975 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveUp:
# 2976 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2977 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2977 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2978 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2980 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveLeft:
# 2981 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
# 2982 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_AnnihilapeHintNPC::
# 2989 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2992 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 3005 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 3007 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 2994 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2995 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2996 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2999 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 3000 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 3011 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3012 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 3015 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 3019 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 3021 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 3013 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 3016 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer0::
# 3028 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 3035 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 3036 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer1::
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 3052 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 3061 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 3067 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 3068 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 3073 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3074 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 3081 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 3082 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 3087 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 3093 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 3094 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 3101 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 3110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 3126 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 3127 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3104 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 3111 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 3112 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 3113 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 3114 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 3132 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 3139 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 3140 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 3145 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 3152 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 3153 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 3165 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 3166 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 3171 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 3179 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_Trainer8_2
EscapeRoom_EventScript_Trainer8_1:
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 3185 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer8_2:
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 3182 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8_1


EscapeRoom_EventScript_Trainer9::
# 3190 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 3198 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 3203 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 3210 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER11_DEFEATED, EscapeRoom_EventScript_Trainer11_2
EscapeRoom_EventScript_Trainer11_1:
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 3231 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3232 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3233 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_Trainer11_5
# 3238 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_B, MSGBOX_AUTOCLOSE
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_Trainer11_4:
# 3241 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer11_2:
# 3218 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
	goto EscapeRoom_EventScript_Trainer11_1

EscapeRoom_EventScript_Trainer11_5:
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle_A, MSGBOX_AUTOCLOSE
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer11_4


EscapeRoom_EventScript_PostMatchHeal::
# 3248 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 3253 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3256 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 3272 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 3257 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3258 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 3261 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3262 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 3265 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 3266 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 3259 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 3277 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3281 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 3290 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 3293 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 3299 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3300 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3301 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3302 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3303 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 3304 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 3305 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 3306 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 3307 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 3308 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 3320 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 3283 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3284 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 3310 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3311 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3312 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 3307 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 3307 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 3285 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3286 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 3327 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3331 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3332 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 3339 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3343 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 3350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 3352 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 3353 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 3333 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3334 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 3356 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 3335 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3336 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3369 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 3372 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3382 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 3383 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3384 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 3385 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 3386 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 3389 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 3392 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 3395 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3402 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 3404 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 3405 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 3406 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 3412 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 3377 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 3408 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 3417 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 3418 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3418 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 3423 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 3424 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3429 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3430 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3431 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 3434 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 3435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 3444 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3438 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3439 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 3435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3452 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 3464 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 3476 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 3488 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 3500 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 3511 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 3512 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 3453 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3454 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 3457 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3458 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 3465 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3466 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 3477 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3478 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 3467 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 3459 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 3489 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3490 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 3493 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3494 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 3479 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 3471 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 3501 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3502 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 3505 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3506 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 3483 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 3495 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 3507 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 3517 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3520 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 3523 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3524 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3525 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3534 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3535 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 3543 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 3545 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3548 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 3555 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3556 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3558 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3560 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 3561 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3562 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 3565 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3566 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3568 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 3570 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 3571 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3572 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 3573 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3574 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 3575 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 3576 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 3577 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 3579 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 3580 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 3581 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3582 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 3584 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3585 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3586 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 3587 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 3588 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 3589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 3590 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3591 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3592 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3593 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3595 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3596 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3598 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3599 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 3526 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3527 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 3536 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3537 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 3528 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 3601 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3602 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3603 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3604 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 3538 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 3609 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 3610 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3615 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 3616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 3623 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 3619 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3620 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 3627 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 3628 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3630 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3632 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3633 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 3638 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 3639 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3646 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 3647 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3648 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 3649 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 3650 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 3651 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 3652 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 3660 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_CUT
# 3663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 3664 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 3667 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3656 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 3672 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3675 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 3683 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3684 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3685 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3686 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 3687 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 3688 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 3689 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 3696 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 3692 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3693 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 3701 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 3713 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3715 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3716 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 35
# 3718 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3718 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_BAGON
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 3719 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3720 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 3722 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 3723 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 3729 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 3725 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3726 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3727 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 3733 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 3734 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3737 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3740 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_FINAL_BATTLE_REACHED, 1
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer11End
# 3744 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 3745 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
	return


# 3748 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer11End:
# 3749 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 3752 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 3753 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

EscapeRoom_EventScript_TradeZeraForHMCut::
# 3760 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3761 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 3762 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 3789 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 3791 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 3766 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3767 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 3777 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 3780 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3785 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 3786 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 3770 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3771 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3772 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3799 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 3824 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 3825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 3882 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 3883 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 3886 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 3802 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 3819 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 3803 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 3804 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3805 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 3812 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3813 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 3828 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 3829 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3830 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 3839 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 3842 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3844 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3846 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3849 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3850 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3854 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 3855 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 3877 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 3806 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 3808 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3809 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 3832 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3834 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 3891 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3892 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3895 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 3920 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 3921 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 3955 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 3956 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 3959 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 3898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 3914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 3915 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 3899 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 3900 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3901 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 3908 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3909 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 3924 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3925 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3926 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 3935 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 3938 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 3939 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3940 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3941 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3944 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3949 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 3902 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 3904 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3905 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 3928 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3929 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3930 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 3963 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3964 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3967 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 3973 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 3974 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 4003 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 4004 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 4007 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 3968 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 3969 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 3977 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3978 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3979 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 3988 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 3989 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3990 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 3993 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3994 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3995 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3998 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 3999 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 3981 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3983 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_GetChoiceItem::
# 4015 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_GetChoiceItem_1
# 4060 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsNoLongerAvailable, MSGBOX_DEFAULT
# 4061 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_1:
# 4018 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsWhichOne, MSGBOX_DEFAULT
# 4019 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4022 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionChoiceBand, OptionChoiceSpecs, OptionChoiceScarf
# 4025 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_5
# 4028 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_6
# 4031 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_7
# 4035 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsComeAgain, MSGBOX_DEFAULT
# 4036 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_4:
# 4041 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem
# 4044 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RemoveChoiceItem
# 4047 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem VAR_0x8006
# 4050 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_GetChoiceItem_12
# 4055 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CHOICE_ITEM_OBTAINED
	return

EscapeRoom_EventScript_GetChoiceItem_5:
# 4026 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_BAND
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_6:
# 4029 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SPECS
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_7:
# 4032 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SCARF
	goto EscapeRoom_EventScript_GetChoiceItem_4

EscapeRoom_EventScript_GetChoiceItem_12:
# 4051 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsSwapped, MSGBOX_DEFAULT
# 4052 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem::
# 4066 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 4069 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem VAR_0x8006
# 4070 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1:
# 4074 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4075 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4:
# 4082 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4083 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7:
# 4092 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10
	return

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2:
# 4071 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5:
# 4076 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4077 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual1
# 4078 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4080 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual1:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8:
# 4084 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 4085 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual2
# 4086 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 4088 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual2:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10:
# 4093 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsAlreadyHaveThis, MSGBOX_DEFAULT
# 4094 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4095 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_RemoveChoiceItem::
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_BAND
# 4102 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SPECS
# 4103 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SCARF
# 4105 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 4106 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_3
EscapeRoom_EventScript_RemoveChoiceItem_1:
# 4113 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 4114 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_11
	return

EscapeRoom_EventScript_RemoveChoiceItem_2:
# 4110 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_3:
# 4107 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 4108 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 4109 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_10:
# 4118 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	return

EscapeRoom_EventScript_RemoveChoiceItem_11:
# 4115 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 4116 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 4117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 4126 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4127 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 4128 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 4129 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 4130 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 4134 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4135 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 4136 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 4137 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 4138 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 4142 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4143 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 4144 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 4145 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 4146 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPrimeape::
# 4150 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4153 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_RARE_CANDY, abilityNum = 2, nature = NATURE_CALM, gender = MON_FEMALE, move1 = MOVE_RAGE_FIST, move2 = MOVE_TAUNT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 252, defEv = 0, spDefEv = 8 hpIv = 31, atkIv = 0, defIv = 0, spAtkIv = 31, spDefIv = 31, speedIv = 10
# 4179 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 4180 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 4183 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 4186 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 4187 "data/maps/EscapeRoom_Main/scripts.pory"
	message PrimeapeObtainMessage
# 4188 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 4189 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4192 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 4193 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_FindPrimeape_2
EscapeRoom_EventScript_FindPrimeape_1:
# 4197 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4198 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_FindPrimeape_2:
# 4194 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 4195 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_FindPrimeape_1


EscapeRoom_EventScript_FindTMSecretPower::
# 4202 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4203 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_TM43
# 4204 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 4205 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_OBTAINED
# 4206 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 4213 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 4224 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 4227 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 4230 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 4233 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 4238 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 4253 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 4217 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4218 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4219 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 4225 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 4228 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 4231 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 4239 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4240 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 4241 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4242 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4245 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 4250 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 4246 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 4257 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4260 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 4271 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 4274 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 4277 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 4282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 4296 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4262 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4263 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 4269 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 4272 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 4275 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 4278 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 4283 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4284 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4286 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4289 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 4290 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 4300 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4303 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 4311 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 4314 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 4317 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 4320 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 4325 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 4339 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 4304 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4305 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4306 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 4312 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 4315 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 4318 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 4321 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 4326 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4327 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 4328 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4329 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4332 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 4337 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 4333 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 4343 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4346 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 4354 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 4362 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 4365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 4368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 4373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 4387 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 4347 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4348 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4349 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 4355 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 4360 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 4363 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 4366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 4369 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 4374 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4375 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 4376 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4377 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4380 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 4385 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 4381 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 4392 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 4397 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 4398 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 4394 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 4393 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 4395 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 4403 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4404 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 4405 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 4406 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 4407 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4408 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 4410 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 4411 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4412 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 4413 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 4415 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 4422 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4425 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 4428 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 4433 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 4456 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 4457 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 4429 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 4461 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4462 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4463 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4466 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 4470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 4480 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4481 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4482 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 4486 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4487 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4490 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 4473 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 4474 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4476 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 4472 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 4471 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 4494 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4495 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4496 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4499 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 4502 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 4503 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 4504 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 4511 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4512 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4513 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4515 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 4506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4507 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 4519 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4521 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4524 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 4528 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 4535 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 4536 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 4543 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 4546 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4547 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4549 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 4530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 4531 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4533 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 4538 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4539 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4540 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 4553 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4554 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4555 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4558 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 4561 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 4562 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 4563 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 4570 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4571 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4572 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 4565 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4566 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 4578 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4579 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4580 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4583 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 4586 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 4587 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 4588 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 4595 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4596 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4597 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4599 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4591 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 4603 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4604 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4605 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4608 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 4611 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 4612 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 4613 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 4620 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4621 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4622 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4624 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 4615 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4616 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4629 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4630 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4633 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 4637 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 4644 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 4645 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 4656 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4657 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4658 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 4660 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 4641 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 4642 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 4647 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4648 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4650 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4651 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4652 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 4664 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4665 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4669 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 4673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 4680 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 4681 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 4688 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 4691 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4692 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4694 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 4675 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 4676 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4678 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 4683 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4684 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4685 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 4698 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4699 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4700 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4703 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 4706 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 4707 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 4708 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 4715 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4716 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4717 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4719 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 4710 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4711 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 4723 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4724 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4725 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 4731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 4732 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 4733 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 4740 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4741 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4742 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4744 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 4735 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4736 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 4748 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4749 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 4751 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 4752 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4753 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4754 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4755 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4756 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4757 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4758 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 4761 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 4762 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4763 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 4765 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_SPAWNED
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 4769 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4772 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 4812 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 4813 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 4816 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 4774 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 4775 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 4806 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 4807 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 4778 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4779 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4780 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4783 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 4784 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 4775 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 4791 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 4792 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 4797 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4798 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4799 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 4800 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 4793 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 4794 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 4821 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4822 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4823 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4824 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 4825 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4826 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4827 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 4841 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


SomethingsGoneWrongMessage::
# 4855 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 4862 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 4866 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 4873 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 4896 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 4919 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to check?$"

GameCompletionMessage::
# 4923 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed roughly {STR_VAR_1}% of the\n"
	.string "game so far.$"

GameCompletionMessageInitial::
# 4928 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've completed 0% of the game so far.$"

GameCompletionMessageFinal::
# 4932 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've fully completed the game!$"

SignMessageReadInfoAgain::
# 4936 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

MoveDeleterSignMessage::
# 4942 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

EscapeRoomEndCongratz::
# 4957 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 4962 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.$"

AnnihilapeStatueMessage::
# 4969 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 4975 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 4979 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 4983 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 4988 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 4993 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 4997 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 5001 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 5010 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 5018 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 5023 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 5028 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 5035 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 5044 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 5048 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 5052 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 5057 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 5063 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 5069 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 5075 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 5082 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 5088 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 5094 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 5100 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 5107 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 5113 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 5119 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 5125 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 5132 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 5138 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 5144 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 5150 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 5158 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 5162 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 5166 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 5172 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "What kind of hint would you like to get?$"

HintsNPCNoHintMessage::
# 5181 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPC_SmallHint::
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (small hint)$"

HintsNPC_LargeHint::
# 5189 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (large hint)$"

HintsNPC_Solution::
# 5193 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (solution)$"

AntiSoftlockIntroMessage::
# 5199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 5209 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 5213 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 5219 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 5224 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 5228 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 5232 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 5238 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 5243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 5247 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoSecretPower::
# 5250 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Secret Power$"

OptionUndoCut::
# 5253 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 5256 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 5259 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 5262 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 5266 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 5271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "used on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 5276 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 5281 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 5285 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 5290 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 5295 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 5299 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 5303 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 5307 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 5313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 5318 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 5325 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 5329 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 5334 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 5341 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 5351 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 5358 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 5369 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 5373 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 5380 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 5384 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 5388 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your energy trying to catch\n"
	.string "or beat her.$"

FourTabletsHintMessage1::
# 5400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 5406 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop searching\n"
	.string "and get back to my job.\p"
	.string "Not sure what I'm serving today,\n"
	.string "I'll have to look through the menus.$"

FourTabletsHintMessage3::
# 5415 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake!?$"

StonesBuyNPCInitialMessage_no_item::
# 5422 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 5430 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 5436 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 5444 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 5448 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 5452 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 5456 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 5460 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 5467 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 5471 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 5475 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 5479 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 5486 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 5490 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretGardenGuardKeepOut::
# 5497 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found our secret garden!\p"
	.string "I cannot let you enter, sorry.$"

SecretGardenGuardSpotted::
# 5502 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "How did you get in there!?$"

SecretGardenGuardStayOut::
# 5506 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Stay out of our garden!$"

SecretGardenGuardRemoveSecretPower::
# 5510 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I cannot let you leave with that what\n"
	.string "belongs to the garden.\p"
	.string "I'll have to take TM43 away from you.$"

MonForgotSecretPower::
# 5516 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MartNPC_AskToShop::
# 5522 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 5528 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

ChoiceItemsFirstMessage::
# 5534 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Impressive, you saw right through my\n"
	.string "facade!\p"
	.string "I think you've earned a reward!\n"
	.string "Take your pick of my Choice items.\p"
	.string "You can always return if you'd like to\n"
	.string "try a different one.$"

ChoiceItemsNoLongerAvailable::
# 5543 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It seems you've made the right choice.$"

ChoiceItemsWhichOne::
# 5547 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Which item would you like to have?$"

ChoiceItemsComeAgain::
# 5551 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back anytime.$"

ChoiceItemsSwapped::
# 5555 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You returned the other Choice item.$"

ChoiceItemsAlreadyHaveThis::
# 5559 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You already have this one.$"

OptionChoiceBand::
# 5563 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Band$"

OptionChoiceSpecs::
# 5567 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Specs$"

OptionChoiceScarf::
# 5571 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Scarf$"

PrimeapeObtainMessage::
# 5577 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 5581 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

AskDeleteMove::
# 5588 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 5594 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 5600 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 5604 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 5608 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 5614 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 5618 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 5622 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 5629 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 5634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 5639 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 5645 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 5651 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 5656 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 5660 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 5664 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 5668 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 5672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 5677 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 5682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 5687 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 5693 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 5697 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 5701 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 5705 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 5709 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 5714 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 5718 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 5723 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 5729 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 5735 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 5739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 5745 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 5752 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You think you are ready?\n"
	.string "You really need three.\l"
	.string "One of them might hold the key.$"

Trainer0_Outro::
# 5761 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "But sharing is caring!$"

Trainer0_PostBattle::
# 5765 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go.$"

Trainer1_Intro::
# 5771 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 5777 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 5781 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 5786 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 5793 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 5799 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 5804 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love writing in 686578!$"

Trainer2_PostBattle::
# 5808 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 5814 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 5819 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 5823 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 5828 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 5834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 5839 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 5843 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know 5(A->L) + 2(L->O) = 525?$"

Trainer5_Intro::
# 5850 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 5855 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 5859 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 5863 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 5870 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 5877 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 5881 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you know where I can find a cook?\n"
	.string "My birds deliver goods, not dinner.$"

Trainer7A_Intro::
# 5888 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 5895 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 5899 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "fwuenqru? uwu.$"

Trainer7B_Intro::
# 5906 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 5911 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 5915 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 5922 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Ghost type mons are everywhere,\n"
	.string "you still haven't seen mine.$"

Trainer8_Outro::
# 5934 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 5938 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "$"

Trainer9_Intro::
# 5944 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 5949 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks. Only real battles.$"

Trainer9_PostBattle::
# 5953 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is this your last time passing through?$"

Trainer10_Intro::
# 5959 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Darwinism?\n"
	.string "More like Schmarminism...\p"
	.string "Kecleon doesn't need any changes!$"

Trainer10_Outro::
# 5965 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a struggle!$"

Trainer10_PostBattle::
# 5969 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So Kecleon isn't the only Pokémon with\n"
	.string "the ability to change?$"

Trainer11_Intro::
# 5976 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So you've finally made it to the end...\p"
	.string "No more hints.\p"
	.string "No more clues.\p"
	.string "It's time for your final test.$"

Trainer11_Outro::
# 5983 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

Trainer11_PostBattle_A::
# 5987 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please read the sign first.$"

Trainer11_PostBattle_B::
# 5991 "data/maps/EscapeRoom_Main/scripts.pory"
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
