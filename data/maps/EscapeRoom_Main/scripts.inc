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
	map_script_2 VAR_DO_STICKY_BARB_RETURN, 1, EscapeRoom_MapScripts_ReturnStickyBarb
# 76 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 87 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 92 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 93 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 100 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 116 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_14
EscapeRoom_MapScript_OnResumeScripts_12:
# 121 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_18
EscapeRoom_MapScript_OnResumeScripts_17:
# 127 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_21
EscapeRoom_MapScript_OnResumeScripts_20:
# 132 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_24
EscapeRoom_MapScript_OnResumeScripts_23:
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 145 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_26
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 112 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_14:
# 116 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_13
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_18:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_17

EscapeRoom_MapScript_OnResumeScripts_21:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStickyBarbStolen
	goto EscapeRoom_MapScript_OnResumeScripts_20

EscapeRoom_MapScript_OnResumeScripts_24:
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_23

EscapeRoom_MapScript_OnResumeScripts_26:
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 163 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 164 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 165 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 168 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 174 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 183 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 184 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 186 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 187 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 189 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 200 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 215 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 219 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 208 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 216 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckStickyBarbStolen::
# 225 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_2
EscapeRoom_MapScripts_CheckStickyBarbStolen_1:
# 229 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 230 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_5
EscapeRoom_MapScripts_CheckStickyBarbStolen_4:
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_8
EscapeRoom_MapScripts_CheckStickyBarbStolen_7:
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 238 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_10
	return

EscapeRoom_MapScripts_CheckStickyBarbStolen_2:
# 227 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_1

EscapeRoom_MapScripts_CheckStickyBarbStolen_5:
# 231 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_4

EscapeRoom_MapScripts_CheckStickyBarbStolen_8:
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_7

EscapeRoom_MapScripts_CheckStickyBarbStolen_10:
# 239 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 245 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 246 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_8
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 255 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_11
EscapeRoom_MapScripts_CheckIfAskPreDamage_10:
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 259 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_10


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 281 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 285 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 301 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 287 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_CheckIfAskWarpBack::
# 309 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskWarpBack_3
EscapeRoom_MapScripts_CheckIfAskWarpBack_1:
# 316 "data/maps/EscapeRoom_Main/scripts.pory"
Equal:
	return

EscapeRoom_MapScripts_CheckIfAskWarpBack_2:
# 312 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_LOCATED_AT_SECTION_X, VAR_RESPAWN_AT_SECTION_X
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_eq Equal
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 1
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1

EscapeRoom_MapScripts_CheckIfAskWarpBack_3:
# 309 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_MapScripts_CheckIfAskWarpBack_2
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1


EscapeRoom_MapScripts_FindBallAferUse::
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 324 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 325 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 359 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 371 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 414 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 397 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 390 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 426 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 432 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 467 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 485 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScript_GameStartScripts::
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 498 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 564 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 595 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 596 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 600 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 603 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 604 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 608 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
# 621 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_TM43
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 659 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 684 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 701 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 709 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 737 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_4
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_4:
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 749 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 771 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 760 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Heal_Pokemon_Nurse1::
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 805 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 806 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 815 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 825 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 849 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 856 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 868 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 880 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 864 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 887 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 945 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 973 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_30
EscapeRoom_EventScript_ReturnLostItems_29:
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 982 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_35
EscapeRoom_EventScript_ReturnLostItems_34:
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_42:
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_49
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_49
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 913 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_25
EscapeRoom_EventScript_ReturnLostItems_23:
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 954 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 955 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 958 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_32
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_22:
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_24:
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_22
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_25:
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_24
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_30:
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_29

EscapeRoom_EventScript_ReturnLostItems_32:
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_35:
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_38:
# 993 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_47
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_43:
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_54:
# 1011 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_68
EscapeRoom_EventScript_ReturnLostItems_67:
# 1018 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_79
EscapeRoom_EventScript_ReturnLostItems_78:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_83
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_44:
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_47:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_49:
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_63
EscapeRoom_EventScript_ReturnLostItems_61:
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_59
EscapeRoom_EventScript_ReturnLostItems_57:
# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_70
	return

EscapeRoom_EventScript_ReturnLostItems_55:
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_54

EscapeRoom_EventScript_ReturnLostItems_58:
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_72
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_59:
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_62:
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_58
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_63:
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_62
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_68:
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_67

EscapeRoom_EventScript_ReturnLostItems_70:
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_72:
# 1045 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_73:
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_81
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_76:
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_79:
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_78

EscapeRoom_EventScript_ReturnLostItems_81:
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1061 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_83:
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1027 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 1028 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_42


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 1113 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_THIEF
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_CUT
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 1167 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_23
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_23
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_30
EscapeRoom_EventScript_UndoUsedItems_29:
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_32
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 1117 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1122 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 1123 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1128 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 1129 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_CACNEA
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 1148 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 1149 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_CACNEA
# 1155 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_30:
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_29

EscapeRoom_EventScript_UndoUsedItems_32:
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 1204 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 1209 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_20:
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_19
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_18:
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 1252 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_39:
# 1277 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_43
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_42:
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 1291 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1233 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_19:
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_18

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_20

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 1209 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 1204 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_39

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_43:
# 1278 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 1282 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_42

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 1292 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 1321 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_4
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return


EscapeRoom_EventScript_UndoMoveTeach::
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 1336 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_12
EscapeRoom_EventScript_UndoMoveTeach_10:
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1381 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 1414 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_23:
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_32
EscapeRoom_EventScript_UndoMoveTeach_31:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_34:
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_44
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 1337 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_21
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_12:
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_21:
# 1347 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_24:
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_23

EscapeRoom_EventScript_UndoMoveTeach_26:
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_24
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_32:
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1424 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
EscapeRoom_EventScript_UndoMoveTeach_37:
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_55
EscapeRoom_EventScript_UndoMoveTeach_53:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_64
EscapeRoom_EventScript_UndoMoveTeach_63:
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_69
	goto EscapeRoom_EventScript_UndoMoveTeach_31

EscapeRoom_EventScript_UndoMoveTeach_35:
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_60
EscapeRoom_EventScript_UndoMoveTeach_58:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 1468 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_67
EscapeRoom_EventScript_UndoMoveTeach_66:
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_71
	goto EscapeRoom_EventScript_UndoMoveTeach_34

EscapeRoom_EventScript_UndoMoveTeach_38:
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_37

EscapeRoom_EventScript_UndoMoveTeach_39:
# 1424 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_38
	goto EscapeRoom_EventScript_UndoMoveTeach_37

EscapeRoom_EventScript_UndoMoveTeach_42:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_43:
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_42
	return

EscapeRoom_EventScript_UndoMoveTeach_44:
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_43
	return

EscapeRoom_EventScript_UndoMoveTeach_49:
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_55:
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_59:
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_58

EscapeRoom_EventScript_UndoMoveTeach_60:
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_59
	goto EscapeRoom_EventScript_UndoMoveTeach_58

EscapeRoom_EventScript_UndoMoveTeach_64:
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_63

EscapeRoom_EventScript_UndoMoveTeach_67:
# 1469 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_66

EscapeRoom_EventScript_UndoMoveTeach_69:
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_31

EscapeRoom_EventScript_UndoMoveTeach_71:
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_34


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 1497 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 1513 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 1527 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1542 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_CACNEA
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 1569 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_35
EscapeRoom_EventScript_UndoRareCandy_34:
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_42
EscapeRoom_EventScript_UndoRareCandy_41:
# 1604 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
# 1615 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_29
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_30
EscapeRoom_EventScript_UndoRareCandy_27:
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_39
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 1561 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_29:
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_30:
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_35:
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_CACNEA
# 1591 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_CACTURNE, SPECIES_CACNEA
	goto EscapeRoom_EventScript_UndoRareCandy_34

EscapeRoom_EventScript_UndoRareCandy_37:
# 1563 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_39:
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 1661 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_52
	return

EscapeRoom_EventScript_UndoRareCandy_42:
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_41

EscapeRoom_EventScript_UndoRareCandy_44:
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 1632 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_49
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_56
	return

EscapeRoom_EventScript_UndoRareCandy_46:
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_44
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_49:
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_54
	return

EscapeRoom_EventScript_UndoRareCandy_52:
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_54:
# 1637 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_56:
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return


EscapeRoom_EventScript_UndoExpCandy::
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 1680 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1683 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 1692 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 1753 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1790 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1798 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 1783 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_LiepardNPC::
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1832 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 1833 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 1834 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 1839 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1852 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1862 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 1863 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1869 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1878 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 1880 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 1881 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 1887 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 1897 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 1899 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 1924 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 1936 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 1944 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1972 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 1984 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 1974 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1994 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 2004 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2008 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 2018 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 2019 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 2030 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 2031 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 2034 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 2037 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 2048 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2050 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 2059 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 2062 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 2063 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 2064 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2072 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 2076 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 2088 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 2092 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2120 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 2124 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2136 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 2140 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2171 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 2172 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2185 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 2198 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 2194 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 2234 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2252 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 2257 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2258 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2263 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 2264 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 2267 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2276 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2277 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2282 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2285 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2286 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 2288 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2289 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2290 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2291 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 2296 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2303 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2316 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 2324 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 2330 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 2331 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 2337 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 2338 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 2332 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 2349 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 2350 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 2351 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2352 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2354 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2355 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 2367 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2380 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 2371 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 2372 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 2375 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 2376 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_SecretGarden_SecretPowerNPC::
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2389 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_SecretGarden_SecretPowerNPC_2
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_SecretPowerNPC_2
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_AskLovePlants, MSGBOX_YESNO
# 2401 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_7
# 2407 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_THIEF
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_10
# 2421 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes, MSGBOX_DEFAULT
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes_Thief, MSGBOX_YESNO
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_SecretGarden_SecretPowerNPC_13
# 2435 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_TeachDeclinedMessage, MSGBOX_AUTOCLOSE
# 2436 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_SecretGarden_SecretPowerNPC_6:
# 2440 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_SecretPowerNPC_2:
# 2393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_EndOfScriptMessage, MSGBOX_AUTOCLOSE
# 2394 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2395 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_SecretGarden_SecretPowerNPC_7:
# 2402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_No, MSGBOX_DEFAULT
# 2403 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_6

EscapeRoom_SecretGarden_SecretPowerNPC_10:
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PlantLove_Yes, MSGBOX_DEFAULT
# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2411 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_SecretGarden_TeachSecretPower
# 2416 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PostTeachMessage, MSGBOX_AUTOCLOSE
# 2417 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_6

EscapeRoom_SecretGarden_SecretPowerNPC_13:
# 2429 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_SecretGarden_TeachSecretPower
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenNPC_PostTeachMessage, MSGBOX_AUTOCLOSE
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_SecretPowerNPC_6


EscapeRoom_SecretGarden_TeachSecretPower::
# 2445 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_THIEF
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_2
EscapeRoom_SecretGarden_TeachSecretPower_1:
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACNEA
# 2458 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_5
EscapeRoom_SecretGarden_TeachSecretPower_4:
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_TeachSecretPower_13
EscapeRoom_SecretGarden_TeachSecretPower_12:
# 2468 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonLearnedSecretPower, MSGBOX_DEFAULT
# 2471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_LEARNED
	return

EscapeRoom_SecretGarden_TeachSecretPower_2:
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_SecretGarden_TeachSecretPower_8
# 2450 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_SecretGarden_TeachSecretPower_9
EscapeRoom_SecretGarden_TeachSecretPower_7:
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_THIEF_REPLACED
	goto EscapeRoom_SecretGarden_TeachSecretPower_1

EscapeRoom_SecretGarden_TeachSecretPower_5:
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2460 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACNEA, MOVE_SECRET_POWER
	goto EscapeRoom_SecretGarden_TeachSecretPower_4

EscapeRoom_SecretGarden_TeachSecretPower_8:
# 2448 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 0, MOVE_THIEF, MOVE_NONE
	goto EscapeRoom_SecretGarden_TeachSecretPower_7

EscapeRoom_SecretGarden_TeachSecretPower_9:
# 2451 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 1, MOVE_THIEF, MOVE_NONE
	goto EscapeRoom_SecretGarden_TeachSecretPower_7

EscapeRoom_SecretGarden_TeachSecretPower_13:
# 2464 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACTURNE, MOVE_SECRET_POWER
	goto EscapeRoom_SecretGarden_TeachSecretPower_12


EscapeRoom_SecretGarden_GateEntryNPC_KeepOut::
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2484 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2486 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2487 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_left
# 2488 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2489 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 25
# 2492 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardKeepOut, MSGBOX_AUTOCLOSE
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2496 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2497 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2499 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_SecretGarden_GateEntryNPC_KickOut::
# 2503 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2507 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2508 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2509 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_down
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2513 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_down
# 2514 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2516 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2519 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardSpotted, MSGBOX_AUTOCLOSE
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_up
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveUp
# 2525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_LEARNED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2533 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1:
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2585 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2587 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2:
# 2530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardStayOut, MSGBOX_AUTOCLOSE
# 2531 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3:
# 2534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardRemoveSecretPower, MSGBOX_AUTOCLOSE
# 2535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2536 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2539 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SECRET_POWER
# 2540 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8:
# 2546 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_LEARNED
# 2550 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 2551 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_THIEF_REPLACED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13:
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACNEA
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_GateEntryNPC_KickOut_17
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_16:
# 2563 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_CACTURNE
# 2564 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_SecretGarden_GateEntryNPC_KickOut_20
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19:
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2570 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2571 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_DEFAULT
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2573 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2576 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9:
# 2541 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 0, MOVE_SECRET_POWER, MOVE_NONE
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10:
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove 1, MOVE_SECRET_POWER, MOVE_NONE
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14:
# 2552 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACNEA, MOVE_THIEF
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_CACTURNE, MOVE_THIEF
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_THIEF_REPLACED
# 2555 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_17:
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_16

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_20:
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22:
# 2577 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonThiefRestored, MSGBOX_AUTOCLOSE
# 2578 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2579 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1


# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_down:
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2594 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_up:
# 2595 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveUp:
# 2600 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2602 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveLeft:
# 2605 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
# 2606 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_AnnihilapeHintNPC::
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2616 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 2628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 2629 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 2631 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 2618 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2620 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2621 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 2624 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 2635 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2636 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 2639 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 2643 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 2645 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 2640 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 2652 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2653 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 2666 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 2663 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2685 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 2692 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 2693 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 2704 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 2705 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 2721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 2730 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 2737 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 2714 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 2722 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2723 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 2751 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 2756 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 2764 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 2777 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 2789 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer8_PostBattle, MSGBOX_AUTOCLOSE
# 2790 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer9::
# 2795 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 2802 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 2803 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 2815 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 2821 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 2828 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle, MSGBOX_AUTOCLOSE
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer0::
# 2834 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 2850 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 2874 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 2859 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2860 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 2863 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 2867 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 2861 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 2879 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2883 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2884 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 2892 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 2895 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2902 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2903 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2905 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 2906 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 2907 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 2908 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 2910 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 2919 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2920 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 2922 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2886 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 2912 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 2887 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2932 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 2934 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 2941 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2945 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 2952 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 2953 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 2954 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 2955 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 2956 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 2962 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 2935 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 2958 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 2971 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 2974 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2975 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 2978 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 2983 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2984 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 2985 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2986 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 2987 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 2988 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 2991 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 2994 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3005 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 3006 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 3007 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 3008 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 3014 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 2976 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 3010 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3011 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3012 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 3019 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 3020 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3020 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3021 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 3025 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 3026 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3031 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3032 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3033 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3034 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3035 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 3036 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 3043 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 3046 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 3039 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3040 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 3037 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3054 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 3066 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 3078 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 3090 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 3113 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 3114 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 3055 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 3059 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3060 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 3067 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3068 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 3071 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3072 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 3057 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 3079 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3080 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 3083 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3084 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 3069 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 3061 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 3091 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3092 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 3095 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3096 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 3081 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 3073 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3104 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 3107 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3108 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 3093 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 3085 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 3097 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 3109 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3122 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 3125 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3126 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3127 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 3135 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3136 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3137 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 3145 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 3147 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3150 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3159 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3160 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3162 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 3163 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3164 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 3165 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 3167 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3168 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3170 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 3172 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 3173 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3174 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 3175 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3176 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 3177 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 3178 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 3179 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 3182 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 3183 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3184 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 3186 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3187 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3188 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 3189 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 3190 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 3191 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 3192 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3195 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3196 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3198 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3199 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3200 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3201 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 3128 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3129 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 3138 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3139 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 3130 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 3203 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3205 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3206 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 3140 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3141 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 3211 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 3212 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 3218 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 3225 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 3221 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3222 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 3229 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 3230 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3232 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3233 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3235 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 3240 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 3241 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3248 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 3249 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3250 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_CACNEA, MOVE_CUT
# 3251 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 3252 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 3253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 3254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 3260 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_CACNEA, MOVE_CUT
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 3256 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3257 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3258 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 3268 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 3279 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3281 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 3283 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 3284 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 3285 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 3286 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 3292 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 3288 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3289 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3290 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 3296 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 3297 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3300 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3310 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3311 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3312 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3313 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 42
# 3314 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3314 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_CACNEA
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 3315 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3316 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 3319 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 3325 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 3321 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3323 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 3329 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 3337 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3338 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 3339 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 3368 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 3343 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3344 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3359 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3362 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 3363 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 3347 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3348 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3349 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 3372 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 3401 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 3402 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 3459 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 3460 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 3463 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 3379 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 3395 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 3396 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 3380 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3382 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 3389 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3390 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 3405 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 3406 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3407 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 3419 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 3420 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3423 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3426 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3428 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3431 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 3454 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 3383 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 3385 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3386 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 3409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3411 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 3468 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3472 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 3497 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 3498 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 3532 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 3536 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 3475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 3491 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 3492 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 3476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 3477 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3478 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 3485 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3486 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 3501 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3502 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 3512 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 3515 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 3516 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3517 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3518 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3521 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3523 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3526 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 3527 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 3528 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 3479 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3482 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 3505 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3506 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3507 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 3540 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3541 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3544 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 3550 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 3551 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 3580 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 3581 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 3584 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 3545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 3546 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 3554 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3555 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3556 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 3565 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 3566 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 3570 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3571 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3572 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3575 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 3576 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 3558 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3559 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3560 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindLiepardCollar::
# 3591 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3592 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 3593 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 3594 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 3595 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 3599 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 3601 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 3602 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 3603 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 3607 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3608 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 3609 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 17
# 3610 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 3611 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPrimeape::
# 3615 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3625 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_RARE_CANDY, abilityNum = 2, nature = 15, gender = MON_FEMALE, move1 = MOVE_TAUNT, move2 = MOVE_RAGE_FIST, move3 = MOVE_COUNTER, move4 = MOVE_NONE, atkEv = 0, spAtkEv = 0, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 3651 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 3652 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 3655 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 3658 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3659 "data/maps/EscapeRoom_Main/scripts.pory"
	message PrimeapeObtainMessage
# 3660 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3661 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_FindPrimeape_2
EscapeRoom_EventScript_FindPrimeape_1:
# 3669 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_FindPrimeape_2:
# 3666 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3667 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_FindPrimeape_1


EscapeRoom_EventScript_MapSwitch1::
# 3677 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3680 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 3688 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 3691 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 3697 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 3702 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 3681 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3682 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3683 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 3689 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 3692 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 3695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 3698 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 3703 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3706 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3709 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 3721 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 3732 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 3735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 3738 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 3741 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 3746 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 3760 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 3725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3726 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3727 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 3733 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 3736 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 3739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 3742 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3748 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 3749 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3750 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3753 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 3758 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 3754 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 3764 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3767 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 3775 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 3778 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 3784 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 3789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 3803 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 3768 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3769 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3770 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 3776 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 3779 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 3785 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 3790 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3791 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 3792 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3793 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 3801 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 3797 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 3807 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3810 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 3823 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 3826 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 3829 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 3832 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 3837 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 3851 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 3811 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3812 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3813 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 3819 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 3824 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 3827 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 3830 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 3838 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 3839 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 3840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 3841 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3844 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 3849 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 3845 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 3856 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 3861 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 3862 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 3858 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 3857 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 3867 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 3868 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 3869 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 3870 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 3871 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3872 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3873 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 3874 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 3876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 3877 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3878 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 3879 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 3886 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3889 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 3892 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 3897 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 3920 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 3921 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 3893 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 3925 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3926 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3930 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 3934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 3944 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3945 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3946 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3954 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 3937 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 3938 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3940 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 3936 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 3935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 3958 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3959 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 3966 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 3967 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 3968 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 3975 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 3976 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 3977 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 3979 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 3970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 3971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 3983 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3984 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 3985 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3988 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 3992 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 3999 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 4000 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 4007 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 4010 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4011 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4013 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 3994 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 3995 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3997 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 4002 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4003 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4004 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 4017 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4018 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4019 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4022 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 4025 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 4026 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 4027 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 4034 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4035 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4036 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4038 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 4029 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4030 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 4042 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4043 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4047 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 4050 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 4051 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 4052 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 4059 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4060 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4061 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4063 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 4054 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4055 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 4067 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4069 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4072 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 4075 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 4076 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 4077 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 4084 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4085 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4086 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4088 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 4079 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4080 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 4092 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4093 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4094 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4097 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 4108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 4109 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 4120 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4121 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4122 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 4124 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 4105 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 4106 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 4111 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4112 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4114 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4115 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4116 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 4128 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4129 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4130 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 4137 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 4144 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 4145 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 4152 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 4155 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4156 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4158 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 4139 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 4140 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4142 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 4147 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4148 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4149 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 4162 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4163 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4164 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4167 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 4170 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 4171 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 4172 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 4179 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4180 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4181 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4183 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 4174 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4175 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 4187 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4188 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4189 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4192 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 4195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 4196 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 4197 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 4204 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4205 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4206 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4208 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 4199 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4200 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 4212 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4213 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 4215 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 4216 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4217 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4218 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4219 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4220 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4221 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4222 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4224 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 4225 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 4226 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4227 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 4231 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 4274 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 4275 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 4278 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 4236 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 4237 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 4269 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 4240 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4241 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4242 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4245 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 4246 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 4237 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 4253 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4260 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4261 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 4262 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 4255 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 4256 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 4283 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4284 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4286 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 4287 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4288 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4289 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 4303 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


SomethingsGoneWrongMessage::
# 4317 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 4324 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 4328 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 4335 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 4358 "data/maps/EscapeRoom_Main/scripts.pory"
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

SignMessageReadInfoAgain::
# 4382 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 4387 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 4392 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MoveDeleterSignMessage::
# 4399 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 4415 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 4421 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 4425 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 4429 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 4434 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 4439 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 4443 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 4447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 4456 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 4464 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 4469 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 4474 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 4481 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 4490 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 4494 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 4498 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 4503 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 4509 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 4515 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 4521 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 4528 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 4534 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 4540 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 4546 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 4553 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 4559 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 4565 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 4571 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 4578 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 4584 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 4590 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 4596 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 4604 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 4608 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 4612 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 4618 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 4627 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 4631 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 4638 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 4648 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 4652 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 4658 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 4663 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 4667 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 4671 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 4677 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 4682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 4686 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoCut::
# 4689 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 4692 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 4695 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 4698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 4702 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 4707 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "use on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 4712 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 4717 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 4721 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 4726 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 4731 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 4735 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 4739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 4743 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 4749 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 4754 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 4761 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 4765 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 4770 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 4777 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 4787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 4794 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 4805 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 4809 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 4816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 4820 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 4824 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.$"

FourTabletsHintMessage1::
# 4834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 4840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to go through the menus.$"

FourTabletsHintMessage3::
# 4849 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake!?$"

StonesBuyNPCInitialMessage_no_item::
# 4856 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 4864 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 4870 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 4878 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 4882 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 4886 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 4890 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 4894 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 4901 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 4905 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 4909 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 4913 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 4920 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 4924 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretGardenNPC_AskLovePlants::
# 4931 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love plants!\p"
	.string "Do you love plants?$"

SecretGardenNPC_PlantLove_No::
# 4936 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Aw, that's too bad.$"

SecretGardenNPC_PlantLove_Yes::
# 4940 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Of course you do!\p"
	.string "Let me teach your cactus how to use\n"
	.string "the power of its surroundings.\p"
	.string "It's a gift from the secret garden.$"

SecretGardenNPC_PlantLove_Yes_Thief::
# 4949 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh... your Pokémon knows Thief.\p"
	.string "The garden usually doesn't share its\n"
	.string "secrets with those who steal.\p"
	.string "I could make an exception, but Thief\n"
	.string "will be forgotten.\p"
	.string "Is that alright?$"

SecretGardenNPC_TeachDeclinedMessage::
# 4962 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's up to you.$"

SecretGardenNPC_PostTeachMessage::
# 4966 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't tell anyone I taught you this\n"
	.string "move!$"

SecretGardenNPC_EndOfScriptMessage::
# 4971 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's our little secret.$"

MonLearnedSecretPower::
# 4975 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} learned Secret Power!$"

SecretGardenGuardKeepOut::
# 4980 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found our secret garden!\p"
	.string "I cannot let you enter, sorry.$"

SecretGardenGuardSpotted::
# 4985 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "How did you get in there!?$"

SecretGardenGuardStayOut::
# 4989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Stay out of our garden!$"

SecretGardenGuardRemoveSecretPower::
# 4993 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I cannot let you leave with that what\n"
	.string "belongs to the garden.\p"
	.string "I will have to take Secret Power away\n"
	.string "from your Pokémon.$"

MonForgotSecretPower::
# 5000 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MonThiefRestored::
# 5004 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Thief was restored.$"

MartNPC_AskToShop::
# 5010 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 5016 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

PrimeapePokeballMessage::
# 5022 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a Primeape inside the Poke Ball.\p"
	.string "Do you want to take it?$"

PrimeapeObtainMessage::
# 5027 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 5031 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

AskDeleteMove::
# 5038 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 5044 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 5050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 5054 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 5058 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 5064 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 5068 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 5072 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 5079 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 5084 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 5089 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 5095 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 5101 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 5106 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 5110 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 5114 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 5118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 5122 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 5127 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 5132 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 5137 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 5143 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 5147 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 5151 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 5155 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 5159 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 5164 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 5168 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 5173 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 5179 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 5189 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 5195 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 5202 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You may think you are ready,\n"
	.string "but you really need three.\l"
	.string "Which of your Pokémon holds the key?$"

Trainer0_Outro::
# 5210 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go.$"

Trainer0_PostBattle::
# 5214 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?$"

Trainer1_Intro::
# 5221 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 5227 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 5231 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 5236 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 5243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 5249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 5254 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Call me a maniac, but I love writing in\n"
	.string "686578.$"

Trainer2_PostBattle::
# 5259 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 5265 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 5270 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 5274 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 5279 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 5285 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 5290 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 5294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know that 5A + 2L = 525?$"

Trainer5_Intro::
# 5300 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 5305 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 5309 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 5313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 5320 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 5327 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 5331 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you know where I can find a cook?\n"
	.string "My birds deliver letters, not lunch.$"

Trainer7A_Intro::
# 5338 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 5345 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 5349 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "fwuenqru? uwu.$"

Trainer7B_Intro::
# 5356 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 5361 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 5365 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 5372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Everyone's got ghost-type mons,\n"
	.string "but you haven't yet fought mine.$"

Trainer8_Outro::
# 5379 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 5383 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you been to the secret garden?\p"
	.string "There's an easy way in, but what's the\n"
	.string "easy way out?$"

Trainer9_Intro::
# 5391 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 5396 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks. Only real battles.$"

Trainer9_PostBattle::
# 5400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Somehow I doubt this was your last time\n"
	.string "passing through.$"

Trainer10_Intro::
# 5407 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've decided to let my anger run free\n"
	.string "and have it push me toward change.\p"
	.string "I call it character development, but\n"
	.string "perhaps it's not for everyone.$"

Trainer10_Outro::
# 5414 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Whatever happened to Cacturne?$"

Trainer10_PostBattle::
# 5418 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't stop now.\n"
	.string "You're almost there!$"

Trainer11_Intro::
# 5425 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_Outro::
# 5429 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_PostBattle::
# 5433 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"
