# 48 "data/maps/EscapeRoom_Main/scripts.pory"
_face_down:
# 49 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 51 "data/maps/EscapeRoom_Main/scripts.pory"
_face_up:
# 52 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 54 "data/maps/EscapeRoom_Main/scripts.pory"
_face_right:
# 55 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 57 "data/maps/EscapeRoom_Main/scripts.pory"
_face_left:
# 58 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_Main_MapScripts::
# 65 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 66 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 68 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 69 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 75 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 76 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_STICKY_BARB_RETURN, 1, EscapeRoom_MapScripts_ReturnStickyBarb
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_WARP_BACK, 1, EscapeRoom_MapScripts_AskWarpBack
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 80 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 93 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 89 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 95 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 111 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_MapScript_OnResumeScripts_14
EscapeRoom_MapScript_OnResumeScripts_12:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_18
EscapeRoom_MapScript_OnResumeScripts_17:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER0_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_21
EscapeRoom_MapScript_OnResumeScripts_20:
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_24
EscapeRoom_MapScript_OnResumeScripts_23:
# 139 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskWarpBack
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_26
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 102 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 118 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_14:
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScript_OnResumeScripts_13
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_18:
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_17

EscapeRoom_MapScript_OnResumeScripts_21:
# 129 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStickyBarbStolen
	goto EscapeRoom_MapScript_OnResumeScripts_20

EscapeRoom_MapScript_OnResumeScripts_24:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_23

EscapeRoom_MapScript_OnResumeScripts_26:
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 164 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 165 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 166 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 183 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 184 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 185 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 187 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 188 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_ETHER
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 208 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 215 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 216 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 219 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 217 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckStickyBarbStolen::
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 227 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_2
EscapeRoom_MapScripts_CheckStickyBarbStolen_1:
# 230 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 231 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_5
EscapeRoom_MapScripts_CheckStickyBarbStolen_4:
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_8
EscapeRoom_MapScripts_CheckStickyBarbStolen_7:
# 238 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 239 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_CheckStickyBarbStolen_10
	return

EscapeRoom_MapScripts_CheckStickyBarbStolen_2:
# 228 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_1

EscapeRoom_MapScripts_CheckStickyBarbStolen_5:
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_4

EscapeRoom_MapScripts_CheckStickyBarbStolen_8:
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	goto EscapeRoom_MapScripts_CheckStickyBarbStolen_7

EscapeRoom_MapScripts_CheckStickyBarbStolen_10:
# 240 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 1
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 246 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_8
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 255 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_11
EscapeRoom_MapScripts_CheckIfAskPreDamage_10:
# 262 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 249 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 257 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 260 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_10


EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed::
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1:
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8:
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_SACKED
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6:
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 287 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_IS_LOST
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12:
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19
EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16:
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_LIEPARD
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_2:
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_1

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7:
# 279 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_6

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_9:
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_7
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_8

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_13:
# 288 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_IS_LOST
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_12

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17:
# 298 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SACK_ACTIVE
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18:
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_17
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_19:
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_IS_LOST, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_18
	goto EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_16

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23:
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SACK_ACTIVE
	return

EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_24:
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_MapScripts_CheckIfMentalHerbSackUsed_23
	return


EscapeRoom_MapScripts_CheckIfAskWarpBack::
# 310 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskWarpBack_3
EscapeRoom_MapScripts_CheckIfAskWarpBack_1:
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
Equal:
	return

EscapeRoom_MapScripts_CheckIfAskWarpBack_2:
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_LOCATED_AT_SECTION_X, VAR_RESPAWN_AT_SECTION_X
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_eq Equal
# 315 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 1
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1

EscapeRoom_MapScripts_CheckIfAskWarpBack_3:
# 310 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_MapScripts_CheckIfAskWarpBack_2
	goto EscapeRoom_MapScripts_CheckIfAskWarpBack_1


EscapeRoom_MapScripts_FindBallAferUse::
# 324 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 325 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 334 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 344 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_ReturnStickyBarb::
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_STICKY_BARB_RETURN, 0
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STICKY_BARB
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_2
EscapeRoom_MapScripts_ReturnStickyBarb_1:
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_5
EscapeRoom_MapScripts_ReturnStickyBarb_4:
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_8
EscapeRoom_MapScripts_ReturnStickyBarb_7:
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STICKY_BARB
	goto_if_eq EscapeRoom_MapScripts_ReturnStickyBarb_11
EscapeRoom_MapScripts_ReturnStickyBarb_10:
# 371 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldStickyBarbReturnedMessage, MSGBOX_AUTOCLOSE
# 372 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_MapScripts_ReturnStickyBarb_2:
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_STICKY_BARB
	goto EscapeRoom_MapScripts_ReturnStickyBarb_1

EscapeRoom_MapScripts_ReturnStickyBarb_5:
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_MapScripts_ReturnStickyBarb_4

EscapeRoom_MapScripts_ReturnStickyBarb_8:
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_MapScripts_ReturnStickyBarb_7

EscapeRoom_MapScripts_ReturnStickyBarb_11:
# 367 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_MapScripts_ReturnStickyBarb_10


EscapeRoom_MapScripts_AskResetPredamage::
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 383 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_ASK_WARP_BACK, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 404 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_8
EscapeRoom_MapScripts_AskResetPredamage_1:
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 389 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_5
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_5:
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_8:
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_ResetPredamage
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_10
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_10:
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 411 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_ResetPredamage::
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 420 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_3
EscapeRoom_MapScripts_ResetPredamage_1:
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EscapeRoom_MapScripts_ResetPredamage_8
EscapeRoom_MapScripts_ResetPredamage_6:
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_MapScripts_ResetPredamage_11
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_MapScripts_ResetPredamage_12
	return

EscapeRoom_MapScripts_ResetPredamage_2:
# 425 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_3:
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_2
	goto EscapeRoom_MapScripts_ResetPredamage_1

EscapeRoom_MapScripts_ResetPredamage_7:
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_8:
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_ResetPredamage_7
	goto EscapeRoom_MapScripts_ResetPredamage_6

EscapeRoom_MapScripts_ResetPredamage_11:
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 0
	return

EscapeRoom_MapScripts_ResetPredamage_12:
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_MOON_STONE, 1
	return


EscapeRoom_MapScripts_AskWarpBack::
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_WARP_BACK, 0
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskWarpBackMessage, MSGBOX_YESNO
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskWarpBack_2
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationToSpawn
EscapeRoom_MapScripts_AskWarpBack_1:
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskWarpBack_2:
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToPreviousLocation
	goto EscapeRoom_MapScripts_AskWarpBack_1


EscapeRoom_MapScripts_RemoveDuplicateCustap::
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_2
EscapeRoom_MapScripts_RemoveDuplicateCustap_1:
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateCustap_4
	return

EscapeRoom_MapScripts_RemoveDuplicateCustap_2:
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateCustap_1

EscapeRoom_MapScripts_RemoveDuplicateCustap_4:
# 476 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScript_GameStartScripts::
# 498 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
	return


EscapeRoom_MapScript_GetPokedex::
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = NATURE_NAUGHTY, gender = MON_MALE, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_NONE, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, ball = ITEM_HEAVY_BALL, item = ITEM_ELECTRIC_SEED, abilityNum = 2, nature = 21, gender = MON_FEMALE, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 577 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 578 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 584 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 585 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 586 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return


EscapeRoom_MapScripts_GetItems::
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_WarpToPreviousLocation::
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_1
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_2
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_WarpToPreviousLocation_3
	return

EscapeRoom_EventScript_WarpToPreviousLocation_1:
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection1
	return

EscapeRoom_EventScript_WarpToPreviousLocation_2:
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return

EscapeRoom_EventScript_WarpToPreviousLocation_3:
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection3
	return


EscapeRoom_EventScript_SetLocationToSpawn::
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_1
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 2
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_2
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_AT_SECTION_X, 3
	goto_if_eq EscapeRoom_EventScript_SetLocationToSpawn_3
	return

EscapeRoom_EventScript_SetLocationToSpawn_1:
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
	return

EscapeRoom_EventScript_SetLocationToSpawn_2:
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
	return

EscapeRoom_EventScript_SetLocationToSpawn_3:
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
	return


EscapeRoom_EventScript_SetLocationSection1::
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 1
	return


EscapeRoom_EventScript_SetLocationSection2::
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 2
	return


EscapeRoom_EventScript_SetLocationSection3::
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_LOCATED_AT_SECTION_X, 3
# 669 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECTION_3_SPAWN_UNLOCKED, EscapeRoom_EventScript_SetLocationSection3_1
	return

EscapeRoom_EventScript_SetLocationSection3_1:
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECTION_3_SPAWN_UNLOCKED
	return


EscapeRoom_EventScript_SetRespawnSection1::
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 1
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
	return


EscapeRoom_EventScript_SetRespawnSection2::
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 2
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawnSection3::
# 686 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_AT_SECTION_X, 3
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_WarpToSection1::
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection1
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection2::
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 20, 11
# 700 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_WarpToSection3::
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection3
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_HIDDEN_DUNGEON, 10, 8
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_EventScript_MainInfoSign::
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 729 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part1, MSGBOX_YESNO
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_4
	goto EscapeRoom_EventScript_MainInfoSign_1

EscapeRoom_EventScript_MainInfoSign_4:
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1_part2, MSGBOX_DEFAULT
# 726 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 749 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 766 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Heal_Pokemon_Nurse1::
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection1
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse2::
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse3::
# 785 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection3
# 786 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_Heal_Pokemon_Nurse_Script
	return


EscapeRoom_Heal_Pokemon_Nurse_Script::
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Heal_Pokemon_Nurse_Script_2
EscapeRoom_Heal_Pokemon_Nurse_Script_1:
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Heal_Pokemon_Nurse_Script_2:
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Heal_Pokemon_Nurse_Script_1


EscapeRoom_EventScript_HintsNPC::
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 815 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AT_SOFTLOCK_GUY_1
# 825 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AT_SOFTLOCK_GUY_1
	return


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
OptionMenuStart:
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage2, MSGBOX_SOFTLOCK_GUY
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 864 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ANTI_SOFTLOCK_LOOP, EscapeRoom_EventScript_AntiSoftlockGuy_10
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 875 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 849 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ANTI_SOFTLOCK_LOOP
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	goto OptionMenuStart
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9


EscapeRoom_EventScript_ReturnLostItems::
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_4
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ETHER, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_20
EscapeRoom_EventScript_ReturnLostItems_19:
# 958 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_30
EscapeRoom_EventScript_ReturnLostItems_29:
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_SAFETY_GOGGLES
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_35
EscapeRoom_EventScript_ReturnLostItems_34:
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER0_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_39
EscapeRoom_EventScript_ReturnLostItems_37:
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_44
EscapeRoom_EventScript_ReturnLostItems_42:
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_49
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_49
# 1074 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 1075 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 891 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 892 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ETHER
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ETHER
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAMOUFLAGE_ETHER_USED, EscapeRoom_EventScript_ReturnLostItems_14
EscapeRoom_EventScript_ReturnLostItems_13:
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_4
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_14:
# 909 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAMOUFLAGE_ETHER_USED
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	removemovepp SPECIES_FLORGES, MOVE_CAMOUFLAGE, 1
	goto EscapeRoom_EventScript_ReturnLostItems_13

EscapeRoom_EventScript_ReturnLostItems_17:
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AT_SOFTLOCK_GUY_1, EscapeRoom_EventScript_ReturnLostItems_25
EscapeRoom_EventScript_ReturnLostItems_23:
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MENTAL_HERB_SACK_ACTIVE, EscapeRoom_EventScript_ReturnLostItems_32
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_20:
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 954 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_19

EscapeRoom_EventScript_ReturnLostItems_22:
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_24:
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_ReturnLostItems_22
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_25:
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_ReturnLostItems_24
	goto EscapeRoom_EventScript_ReturnLostItems_23

EscapeRoom_EventScript_ReturnLostItems_30:
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_29

EscapeRoom_EventScript_ReturnLostItems_32:
# 944 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_35:
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_SAFETY_GOGGLES
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_34

EscapeRoom_EventScript_ReturnLostItems_38:
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_47
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_39:
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_38
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_43:
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_54:
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_68
EscapeRoom_EventScript_ReturnLostItems_67:
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_79
EscapeRoom_EventScript_ReturnLostItems_78:
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_83
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_44:
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_43
	goto EscapeRoom_EventScript_ReturnLostItems_42

EscapeRoom_EventScript_ReturnLostItems_47:
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ELECTRIC_SEED_CONSUMED
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ELECTRIC_SEED
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_37

EscapeRoom_EventScript_ReturnLostItems_49:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_63
EscapeRoom_EventScript_ReturnLostItems_61:
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_59
EscapeRoom_EventScript_ReturnLostItems_57:
# 1065 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_4, EscapeRoom_EventScript_ReturnLostItems_70
	return

EscapeRoom_EventScript_ReturnLostItems_55:
# 990 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_54

EscapeRoom_EventScript_ReturnLostItems_58:
# 1028 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_ReturnLostItems_72
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_73
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_59:
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_76
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_62:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_58
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_63:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_62
	goto EscapeRoom_EventScript_ReturnLostItems_61

EscapeRoom_EventScript_ReturnLostItems_68:
# 997 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_67

EscapeRoom_EventScript_ReturnLostItems_70:
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPpRemovedMessage, MSGBOX_DEFAULT
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_72:
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_73:
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_81
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_76:
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_79:
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_78

EscapeRoom_EventScript_ReturnLostItems_81:
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1046 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_ReturnLostItems_57

EscapeRoom_EventScript_ReturnLostItems_83:
# 1011 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_42


EscapeRoom_EventScript_AntiSoftlockPartyHeal::
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1086 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoUsedItems::
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_2
EscapeRoom_EventScript_UndoUsedItems_1:
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_5
EscapeRoom_EventScript_UndoUsedItems_4:
# 1110 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_THIEF
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_8
EscapeRoom_EventScript_UndoUsedItems_7:
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_THIEF
# 1117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_11
EscapeRoom_EventScript_UndoUsedItems_10:
# 1124 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_14
EscapeRoom_EventScript_UndoUsedItems_13:
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_17
EscapeRoom_EventScript_UndoUsedItems_16:
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_20
EscapeRoom_EventScript_UndoUsedItems_19:
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_23
EscapeRoom_EventScript_UndoUsedItems_22:
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_LIEPARD, MOVE_CUT
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_26
EscapeRoom_EventScript_UndoUsedItems_25:
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_29
EscapeRoom_EventScript_UndoUsedItems_28:
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_FLORGES, MOVE_SKILL_SWAP
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_32
EscapeRoom_EventScript_UndoUsedItems_31:
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 1173 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_35
EscapeRoom_EventScript_UndoUsedItems_34:
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoUsedItems_42
EscapeRoom_EventScript_UndoUsedItems_41:
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_THIEF
# 1188 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SECRET_POWER
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_CUT
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_SKILL_SWAP
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_EXP_CANDY
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CAN_UNDO_RARE_CANDY
# 1193 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UNDOING_MOVE_THIEF
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_WARP, EscapeRoom_EventScript_UndoUsedItems_44
	return

EscapeRoom_EventScript_UndoUsedItems_2:
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_DUNSPARCE
# 1102 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_1

EscapeRoom_EventScript_UndoUsedItems_5:
# 1106 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1107 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_AIPOM
# 1108 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_4

EscapeRoom_EventScript_UndoUsedItems_8:
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1113 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_LIEPARD
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_7

EscapeRoom_EventScript_UndoUsedItems_11:
# 1118 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_THIEF
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_ANNIHILAPE
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, MOVE_THIEF
	goto EscapeRoom_EventScript_UndoUsedItems_10

EscapeRoom_EventScript_UndoUsedItems_14:
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1128 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_13

EscapeRoom_EventScript_UndoUsedItems_17:
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_16

EscapeRoom_EventScript_UndoUsedItems_20:
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1139 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 1140 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_19

EscapeRoom_EventScript_UndoUsedItems_23:
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SECRET_POWER
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoUsedItems_22

EscapeRoom_EventScript_UndoUsedItems_26:
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_LIEPARD
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_25

EscapeRoom_EventScript_UndoUsedItems_29:
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_CUT
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_CUT
	goto EscapeRoom_EventScript_UndoUsedItems_28

EscapeRoom_EventScript_UndoUsedItems_32:
# 1166 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_SKILL_SWAP
# 1167 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_FLORGES
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SKILL_SWAP
	goto EscapeRoom_EventScript_UndoUsedItems_31

EscapeRoom_EventScript_UndoUsedItems_35:
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_RARE_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_34

EscapeRoom_EventScript_UndoUsedItems_42:
# 1180 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CAN_UNDO_EXP_CANDY
	goto EscapeRoom_EventScript_UndoUsedItems_41

EscapeRoom_EventScript_UndoUsedItems_44:
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_WARP
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_WarpToSection2
	return


EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice::
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38:
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32:
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26:
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23:
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21:
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_DEFAULT
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	goto SetPromptOptionsAgain
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1:
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
DecodeMultiChoice:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_THIEF, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45:
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SECRET_POWER, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48:
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54:
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_SKILL_SWAP, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60:
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66:
# 1321 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73
EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72:
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
SetPromptOptionsAgain:
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2:
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut, OptionUndoRareCandy
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3:
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoCut
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4:
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoRareCandy
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoCut, OptionUndoRareCandy
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6:
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoThief, OptionUndoExpCandy
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7:
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSkillSwap, OptionUndoExpCandy
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8:
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 8, FALSE, 6, 0, 0, OptionUndoSecretPower, OptionUndoRareCandy
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	goto DecodeMultiChoice
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_1

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_9:
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_10:
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_11:
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_12:
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_13:
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_14:
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_22:
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_8
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_21

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_25:
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_7
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_23

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_28:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_EXP_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_6
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_26

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_31:
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_5
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_29

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_34:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_4
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_32

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_37:
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_3
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_35

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40:
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_RARE_CANDY, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_2
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_41:
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CAN_UNDO_CUT, EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_40
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_38

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_46:
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52
# 1291 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_45

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_49:
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_48

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_52:
# 1287 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_UNDOING_MOVE_THIEF
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_55:
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_54

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_58:
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_61:
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_60

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_64:
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_67:
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_66

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_70:
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AskUndoMoveTeach
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_73:
# 1322 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	subvar VAR_RESULT, 1
	goto EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_72

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_76:
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
	return

EscapeRoom_EventScript_UndoUsedItems_CreateMultichoice_79:
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoExpCandy
	return


EscapeRoom_EventScript_AskUndoMoveTeach::
# 1337 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_AskUndoMoveTeach_2
EscapeRoom_EventScript_AskUndoMoveTeach_1:
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_5
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_6
EscapeRoom_EventScript_AskUndoMoveTeach_4:
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_10
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_11
EscapeRoom_EventScript_AskUndoMoveTeach_9:
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoMoveTeachDynamic, MSGBOX_YESNO
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_AskUndoMoveTeach_18
	return

EscapeRoom_EventScript_AskUndoMoveTeach_2:
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8006
	goto EscapeRoom_EventScript_AskUndoMoveTeach_1

EscapeRoom_EventScript_AskUndoMoveTeach_5:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_14
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_6:
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_16
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_10:
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_20
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_11:
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 1366 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AskUndoMoveTeach_22
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_14:
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_16:
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
	goto EscapeRoom_EventScript_AskUndoMoveTeach_4

EscapeRoom_EventScript_AskUndoMoveTeach_18:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	return

EscapeRoom_EventScript_AskUndoMoveTeach_20:
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9

EscapeRoom_EventScript_AskUndoMoveTeach_22:
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_AskUndoMoveTeach_9


EscapeRoom_EventScript_UndoMoveTeach::
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset VAR_0x8007
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_2
EscapeRoom_EventScript_UndoMoveTeach_1:
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UNDOING_MOVE_THIEF, EscapeRoom_EventScript_UndoMoveTeach_5
EscapeRoom_EventScript_UndoMoveTeach_4:
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, VAR_0x8008
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, VAR_0x8008, VAR_0x8004
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, VAR_0x8008
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_11
EscapeRoom_EventScript_UndoMoveTeach_10:
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_19
EscapeRoom_EventScript_UndoMoveTeach_18:
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_27
EscapeRoom_EventScript_UndoMoveTeach_25:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_33
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_34
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SKILL_SWAP
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_35
EscapeRoom_EventScript_UndoMoveTeach_32:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1468 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_46
EscapeRoom_EventScript_UndoMoveTeach_45:
# 1478 "data/maps/EscapeRoom_Main/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8008
# 1479 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveTeachUndoneMessage, MSGBOX_DEFAULT
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoMoveTeach_57
EscapeRoom_EventScript_UndoMoveTeach_55:
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
EscapeRoom_EventScript_UndoMoveTeach_53:
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_62
EscapeRoom_EventScript_UndoMoveTeach_61:
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_THIEF
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_65
EscapeRoom_EventScript_UndoMoveTeach_64:
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_CUT
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_74
	return

EscapeRoom_EventScript_UndoMoveTeach_2:
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_8
EscapeRoom_EventScript_UndoMoveTeach_7:
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_AIPOM
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_16
EscapeRoom_EventScript_UndoMoveTeach_15:
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_DUNSPARCE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_23
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_5:
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase
	goto EscapeRoom_EventScript_UndoMoveTeach_4

EscapeRoom_EventScript_UndoMoveTeach_8:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_7

EscapeRoom_EventScript_UndoMoveTeach_11:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, VAR_0x8008
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_10

EscapeRoom_EventScript_UndoMoveTeach_16:
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_15

EscapeRoom_EventScript_UndoMoveTeach_19:
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, VAR_0x8008
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, VAR_0x8008
	goto EscapeRoom_EventScript_UndoMoveTeach_18

EscapeRoom_EventScript_UndoMoveTeach_23:
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
	goto EscapeRoom_EventScript_UndoMoveTeach_1

EscapeRoom_EventScript_UndoMoveTeach_26:
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_39
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_41
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_27:
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_26
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_33:
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM46
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_34:
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM43
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_35:
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM48
	goto EscapeRoom_EventScript_UndoMoveTeach_32

EscapeRoom_EventScript_UndoMoveTeach_39:
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_40:
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_49
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_50
EscapeRoom_EventScript_UndoMoveTeach_48:
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_41:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_40
	goto EscapeRoom_EventScript_UndoMoveTeach_25

EscapeRoom_EventScript_UndoMoveTeach_46:
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1473 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_45

EscapeRoom_EventScript_UndoMoveTeach_49:
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_50:
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoMoveTeach_48

EscapeRoom_EventScript_UndoMoveTeach_54:
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_53

EscapeRoom_EventScript_UndoMoveTeach_56:
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_54
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_57:
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoMoveTeach_56
	goto EscapeRoom_EventScript_UndoMoveTeach_55

EscapeRoom_EventScript_UndoMoveTeach_62:
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_69
EscapeRoom_EventScript_UndoMoveTeach_67:
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_85
EscapeRoom_EventScript_UndoMoveTeach_83:
# 1523 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveSnowball:
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SNOWBALL
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_94
EscapeRoom_EventScript_UndoMoveTeach_93:
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_99
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_65:
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_3
# 1542 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_80
EscapeRoom_EventScript_UndoMoveTeach_78:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_90
EscapeRoom_EventScript_UndoMoveTeach_88:
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
CheckRemoveToxicOrb:
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TOXIC_ORB
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_97
EscapeRoom_EventScript_UndoMoveTeach_96:
# 1563 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_3, EscapeRoom_EventScript_UndoMoveTeach_101
	goto EscapeRoom_EventScript_UndoMoveTeach_64

EscapeRoom_EventScript_UndoMoveTeach_68:
# 1513 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_69:
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_68
	goto EscapeRoom_EventScript_UndoMoveTeach_67

EscapeRoom_EventScript_UndoMoveTeach_72:
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 21
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ESCAPEROOM_TREE_CUT
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoTreeGrewBack, MSGBOX_DEFAULT
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoMoveTeach_73:
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ESCAPEROOM_TREE_CUT, EscapeRoom_EventScript_UndoMoveTeach_72
	return

EscapeRoom_EventScript_UndoMoveTeach_74:
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_FERROTHORN
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_73
	return

EscapeRoom_EventScript_UndoMoveTeach_79:
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_80:
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_79
	goto EscapeRoom_EventScript_UndoMoveTeach_78

EscapeRoom_EventScript_UndoMoveTeach_84:
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_85:
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SNOWBALL
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_84
	goto EscapeRoom_EventScript_UndoMoveTeach_83

EscapeRoom_EventScript_UndoMoveTeach_89:
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_90:
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_89
	goto EscapeRoom_EventScript_UndoMoveTeach_88

EscapeRoom_EventScript_UndoMoveTeach_94:
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1527 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SNOWBALL, 1
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveSnowball
	goto EscapeRoom_EventScript_UndoMoveTeach_93

EscapeRoom_EventScript_UndoMoveTeach_97:
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_3
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TOXIC_ORB, 1
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	goto CheckRemoveToxicOrb
	goto EscapeRoom_EventScript_UndoMoveTeach_96

EscapeRoom_EventScript_UndoMoveTeach_99:
# 1533 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoSnowballsRemoved, MSGBOX_DEFAULT
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoMoveTeach_61

EscapeRoom_EventScript_UndoMoveTeach_101:
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ItemUndoToxicOrbsRemoved, MSGBOX_DEFAULT
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1568 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOXIC_ORB_OBTAINED
	goto EscapeRoom_EventScript_UndoMoveTeach_64


EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase::
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_THIEF
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_1:
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonmove VAR_0x8007, MOVE_CUT
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_3:
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_CUT
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6
EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5:
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_THIEF
	return

EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_6:
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_CUT, MOVE_THIEF
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_CUT
	goto EscapeRoom_EventScript_UndoMoveTeach_CutThiefEdgeCase_5


EscapeRoom_EventScript_UndoRareCandy::
# 1608 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_2
# 1615 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_3
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_4
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoRareCandyDynamic, MSGBOX_YESNO
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_9
	return

EscapeRoom_EventScript_UndoRareCandy_2:
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_1_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_3:
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_2_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_4:
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_RARE_CANDY_3_USED_ON
	goto EscapeRoom_EventScript_UndoRareCandy_1

EscapeRoom_EventScript_UndoRareCandy_9:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_12
EscapeRoom_EventScript_UndoRareCandy_11:
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_15
EscapeRoom_EventScript_UndoRareCandy_14:
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_22
EscapeRoom_EventScript_UndoRareCandy_21:
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_UndoRareCandy_31
EscapeRoom_EventScript_UndoRareCandy_30:
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_46
EscapeRoom_EventScript_UndoRareCandy_45:
# 1692 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneUnevolveMessage, MSGBOX_DEFAULT
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_UndoRareCandy_19:
# 1697 "data/maps/EscapeRoom_Main/scripts.pory"
	levelDownMon VAR_0x8005
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_28
EscapeRoom_EventScript_UndoRareCandy_27:
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_1_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_36
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_2_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_37
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RARE_CANDY_3_USED_ON, VAR_0x8005
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_38
EscapeRoom_EventScript_UndoRareCandy_35:
# 1798 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyfullhp
# 1799 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_48
	return

EscapeRoom_EventScript_UndoRareCandy_12:
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_17
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_15:
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_25
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_17:
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_UndoRareCandy_11

EscapeRoom_EventScript_UndoRareCandy_20:
# 1661 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RareCandyUndoneMessage, MSGBOX_DEFAULT
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoRareCandy_19

EscapeRoom_EventScript_UndoRareCandy_22:
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_2, EscapeRoom_EventScript_UndoRareCandy_20
	goto EscapeRoom_EventScript_UndoRareCandy_21

EscapeRoom_EventScript_UndoRareCandy_25:
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 45
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_33
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_28:
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_43
EscapeRoom_EventScript_UndoRareCandy_42:
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 1722 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_FLAMETHROWER
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_51
EscapeRoom_EventScript_UndoRareCandy_50:
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 1734 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_59
EscapeRoom_EventScript_UndoRareCandy_58:
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, MOVE_NONE
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_68
EscapeRoom_EventScript_UndoRareCandy_66:
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoRareCandy_77
EscapeRoom_EventScript_UndoRareCandy_75:
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8005, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_27

EscapeRoom_EventScript_UndoRareCandy_31:
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1676 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BAGON
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_SHELGON, SPECIES_BAGON
	goto EscapeRoom_EventScript_UndoRareCandy_30

EscapeRoom_EventScript_UndoRareCandy_33:
# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_UndoRareCandy_14

EscapeRoom_EventScript_UndoRareCandy_36:
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_37:
# 1790 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_38:
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
	goto EscapeRoom_EventScript_UndoRareCandy_35

EscapeRoom_EventScript_UndoRareCandy_43:
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_42

EscapeRoom_EventScript_UndoRareCandy_46:
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1687 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_PRIMEAPE
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	unEvolveMonTo SPECIES_ANNIHILAPE, SPECIES_PRIMEAPE
	goto EscapeRoom_EventScript_UndoRareCandy_45

EscapeRoom_EventScript_UndoRareCandy_48:
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_UndoRareCandy_55
EscapeRoom_EventScript_UndoRareCandy_54:
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp VAR_0x8005
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_64
	return

EscapeRoom_EventScript_UndoRareCandy_51:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_50

EscapeRoom_EventScript_UndoRareCandy_53:
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_61
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockPartyHeal
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_LOCATED_AT_SECTION_X, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_73
	return

EscapeRoom_EventScript_UndoRareCandy_55:
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_UndoRareCandy_53
	goto EscapeRoom_EventScript_UndoRareCandy_54

EscapeRoom_EventScript_UndoRareCandy_59:
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoRareCandy_58

EscapeRoom_EventScript_UndoRareCandy_61:
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonfullhp SPECIES_AIPOM
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_71
	return

EscapeRoom_EventScript_UndoRareCandy_64:
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon VAR_0x8005
# 1839 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_67:
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_68:
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_67
	goto EscapeRoom_EventScript_UndoRareCandy_66

EscapeRoom_EventScript_UndoRareCandy_71:
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_73:
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DO_WARP
	return

EscapeRoom_EventScript_UndoRareCandy_76:
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_SECRET_POWER, VAR_0x8004
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_SECRET_POWER
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8004, MOVE_NONE
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_SECRET_POWER
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	special Special_AddTaughtMove
	goto EscapeRoom_EventScript_UndoRareCandy_75

EscapeRoom_EventScript_UndoRareCandy_77:
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_76
	goto EscapeRoom_EventScript_UndoRareCandy_75


EscapeRoom_EventScript_UndoExpCandy::
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_EXP_CANDY_USED_ON
# 1854 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskUndoExpCandyDynamic, MSGBOX_YESNO
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoExpCandy_1
	return

EscapeRoom_EventScript_UndoExpCandy_1:
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	removeExpFromMon VAR_0x8005, 800
# 1863 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_EXP_CANDY_S
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon VAR_0x8005
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 1869 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ExpCandyUndoneMessage, MSGBOX_DEFAULT
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_EXP_CANDY_USED_ON, SPECIES_NONE
	return


EscapeRoom_EventScript_UndoOtherActions::
# 1881 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmoney 1025
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_12
EscapeRoom_EventScript_UndoOtherActions_9:
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 1907 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_DEFAULT
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANTI_SOFTLOCK_LOOP
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 1899 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_20
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_12:
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_11
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_16:
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_20:
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_DEFAULT
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_JABOCA_BERRY
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_14
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_SetTrainer5Rematch_14
EscapeRoom_EventScript_SetTrainer5Rematch_13:
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 1924 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MOON_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 1936 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM38
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10

EscapeRoom_EventScript_SetTrainer5Rematch_14:
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1944 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_13


EscapeRoom_EventScript_UndoFerroTrade::
# 1955 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 1956 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFerroTrade_2
EscapeRoom_EventScript_UndoFerroTrade_1:
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1972 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFerroTrade_2:
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_DUNSPARCE
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFerroTrade_1


EscapeRoom_EventScript_UndoFlorgesTrade::
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_AIPOM, MOVE_THIEF
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoFlorgesTrade_2
EscapeRoom_EventScript_UndoFlorgesTrade_1:
# 1985 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 1991 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return

EscapeRoom_EventScript_UndoFlorgesTrade_2:
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_AIPOM
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8008, MOVE_THIEF
# 1981 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoMoveTeach
	goto EscapeRoom_EventScript_UndoFlorgesTrade_1


EscapeRoom_EventScript_LiepardNPC::
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 2008 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 2094 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2016 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 2018 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2019 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 2025 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2030 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 2031 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2034 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 2037 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2042 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2045 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 2048 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 2059 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2072 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 2073 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 2074 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 2076 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 2092 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2080 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_COPYCAT, move3 = MOVE_ROCK_SMASH, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2182 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 2192 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 2193 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 2196 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawnSection2
# 2197 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetLocationSection2
# 2200 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


# 2204 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 2210 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 2214 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 2228 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 2233 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 2234 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 2237 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM46
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2246 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
EscapeRoom_MoveDeleterNPC_4:
# 2272 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 2273 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 2250 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 2251 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2252 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_IN_MOVE_DELETER_SCRIPT
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
# 2262 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_IN_MOVE_DELETER_SCRIPT
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 2266 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
# 2267 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_ChooseMoveToDelete::
# 2278 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, 4
# 2282 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
	return


EscapeRoom_RestoreMoveset::
# 2288 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 2291 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 2307 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 2321 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 2322 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 2336 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_10
	return

EscapeRoom_RestoreMoveset_2:
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2294 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2295 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 2299 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2300 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 2308 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2309 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2316 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 2324 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 2328 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 2329 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 2330 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2331 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MovesRestoredMessage, MSGBOX_DEFAULT
# 2332 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_10:
# 2338 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 2339 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 2344 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2349 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 2350 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_ZeraoraHintNPC::
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2359 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 2372 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_NPC
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 2389 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 2360 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 2368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage2, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage1, MSGBOX_NPC
# 2362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2363 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2364 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_RockSmashNPC::
# 2396 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 2398 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2399 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, _face_up
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2401 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 2408 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2411 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2414 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2418 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 2419 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 2430 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 2432 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 2434 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 2438 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 2448 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2449 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2450 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2451 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2456 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2458 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 2460 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2464 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 2471 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 2476 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2477 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 2480 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2480 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2480 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 2488 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2490 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 2497 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 2498 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 2505 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 2512 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 2492 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 2499 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 2519 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 2522 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 2535 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2536 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 3000
# 2525 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived3000
# 2527 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2531 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 2532 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 2541 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2542 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 2546 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 2547 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 2550 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_SecretGarden_GateEntryNPC_KeepOut::
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2567 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_left
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2570 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 25
# 2573 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardKeepOut, MSGBOX_AUTOCLOSE
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2577 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2578 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2580 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_SecretGarden_GateEntryNPC_KickOut::
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2587 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, Common_Movement_ExclamationMark
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, _face_down
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 2594 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_down
# 2595 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, _face_right
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2600 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardSpotted, MSGBOX_AUTOCLOSE
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, SecretGarden_NPC_move_up
# 2605 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveUp
# 2606 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2607 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_OBTAINED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1:
# 2648 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretGarden_PlayerMoveLeft
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2651 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_2:
# 2611 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardStayOut, MSGBOX_AUTOCLOSE
# 2612 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_3:
# 2615 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SecretGardenGuardRemoveSecretPower, MSGBOX_AUTOCLOSE
# 2616 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2617 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8:
# 2627 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2628 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_15
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13:
# 2632 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM43
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_18:
# 2639 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TEMP_1, EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22
EscapeRoom_SecretGarden_GateEntryNPC_KickOut_21:
# 2643 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SECRET_POWER_OBTAINED
# 2644 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_1

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9:
# 2624 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
# 2625 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_10:
# 2623 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_9
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_8

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14:
# 2629 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
# 2630 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_15:
# 2628 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM43
	goto_if_eq EscapeRoom_SecretGarden_GateEntryNPC_KickOut_14
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_13

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_19:
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_TM43
# 2635 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_18

EscapeRoom_SecretGarden_GateEntryNPC_KickOut_22:
# 2640 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoSecretPowerTeach
	goto EscapeRoom_SecretGarden_GateEntryNPC_KickOut_21


EscapeRoom_EventScript_UndoSecretPowerTeach::
# 2657 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_SECRET_POWER
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_2
EscapeRoom_EventScript_UndoSecretPowerTeach_1:
# 2668 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_SHELGON, MOVE_SECRET_POWER
# 2669 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_5
EscapeRoom_EventScript_UndoSecretPowerTeach_4:
# 2673 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2674 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_10
EscapeRoom_EventScript_UndoSecretPowerTeach_9:
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
# 2685 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_13
EscapeRoom_EventScript_UndoSecretPowerTeach_12:
# 2692 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent VAR_0x8007, MOVE_SECRET_POWER
# 2693 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 VAR_0x8007, MOVE_SECRET_POWER, VAR_0x8004
# 2694 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove VAR_0x8007, MOVE_SECRET_POWER
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_18
EscapeRoom_EventScript_UndoSecretPowerTeach_17:
# 2701 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
# 2701 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_23
EscapeRoom_EventScript_UndoSecretPowerTeach_22:
# 2707 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
# 2707 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_28
EscapeRoom_EventScript_UndoSecretPowerTeach_27:
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_33
EscapeRoom_EventScript_UndoSecretPowerTeach_32:
# 2745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_PRIMEAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
# 2745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_ANNIHILAPE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_44
EscapeRoom_EventScript_UndoSecretPowerTeach_43:
# 2757 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 2758 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2759 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 2760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MonForgotSecretPower, MSGBOX_AUTOCLOSE
# 2761 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSecretPowerTeach_2:
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_BAGON
# 2662 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2663 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_7
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_5:
# 2670 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_4

EscapeRoom_EventScript_UndoSecretPowerTeach_7:
# 2664 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_SHELGON
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_1

EscapeRoom_EventScript_UndoSecretPowerTeach_10:
# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_PRIMEAPE
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_15
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_13:
# 2686 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_12

EscapeRoom_EventScript_UndoSecretPowerTeach_15:
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8007, SPECIES_ANNIHILAPE
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_9

EscapeRoom_EventScript_UndoSecretPowerTeach_18:
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_PRIMEAPE, MOVE_SECRET_POWER
# 2699 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_ANNIHILAPE, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_17

EscapeRoom_EventScript_UndoSecretPowerTeach_23:
# 2702 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_SECRET_POWER
# 2703 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_SHELGON, MOVE_SECRET_POWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_22

EscapeRoom_EventScript_UndoSecretPowerTeach_28:
# 2710 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_FLAMETHROWER
# 2711 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_SECRET_POWER
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_37
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_39
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_33:
# 2735 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_BAGON
# 2736 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_49
EscapeRoom_EventScript_UndoSecretPowerTeach_48:
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SHELGON
# 2740 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_59
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_37:
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_38:
# 2719 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_BAGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_52
# 2723 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, SPECIES_SHELGON
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_53
EscapeRoom_EventScript_UndoSecretPowerTeach_51:
# 2727 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_39:
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSecretPowerTeach_38
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_27

EscapeRoom_EventScript_UndoSecretPowerTeach_44:
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_PRIMEAPE
# 2747 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_57
EscapeRoom_EventScript_UndoSecretPowerTeach_56:
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 2751 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_UndoSecretPowerTeach_61
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43

EscapeRoom_EventScript_UndoSecretPowerTeach_49:
# 2737 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_48

EscapeRoom_EventScript_UndoSecretPowerTeach_52:
# 2720 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_BAGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2721 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_BAGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_53:
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove2 SPECIES_SHELGON, MOVE_FLAMETHROWER, VAR_0x8004
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SHELGON, MOVE_FLAMETHROWER
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_51

EscapeRoom_EventScript_UndoSecretPowerTeach_57:
# 2748 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_56

EscapeRoom_EventScript_UndoSecretPowerTeach_59:
# 2741 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_32

EscapeRoom_EventScript_UndoSecretPowerTeach_61:
# 2752 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
	goto EscapeRoom_EventScript_UndoSecretPowerTeach_43


# 2767 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_down:
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2771 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_NPC_move_up:
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2774 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveUp:
# 2777 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
# 2778 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2778 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 2779 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
SecretGarden_PlayerMoveLeft:
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
# 2783 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_AnnihilapeHintNPC::
# 2790 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_2
# 2805 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 2806 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_AnnihilapeHintNPC_1:
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 2794 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 2795 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2796 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 2799 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2800 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, _face_up
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


EscapeRoom_TabletsHintNPC::
# 2812 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2813 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 2822 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 2817 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 2839 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 2844 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 2840 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 2855 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 2856 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 2861 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2862 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 2870 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 2882 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 2889 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 2890 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 2898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 2907 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 2915 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2892 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 2893 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 2890 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 2899 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MOON_STONE_CONSUMED
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 2902 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 2903 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TM_TRICK_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 2920 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 2927 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 2928 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 2940 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 2941 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 2953 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 2954 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 2959 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 2967 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2968 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_Trainer8_2
EscapeRoom_EventScript_Trainer8_1:
# 2972 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 2973 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer8_2:
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 2970 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8_1


EscapeRoom_EventScript_Trainer9::
# 2978 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 2985 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 2986 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 2991 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 2999 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 3011 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle, MSGBOX_AUTOCLOSE
# 3012 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer0::
# 3017 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER0, Trainer0_Intro, Trainer0_Outro, event_script = EscapeRoom_EventScript_Trainer0PostBattle
# 3024 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer0_PostBattle, MSGBOX_AUTOCLOSE
# 3025 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 3033 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer0PostBattle::
# 3038 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3041 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ELECTRIC_SEED_CONSUMED, EscapeRoom_EventScript_Trainer0PostBattle_2
EscapeRoom_EventScript_Trainer0PostBattle_1:
# 3056 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER0_DEFEATED
# 3057 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer0PostBattle_2:
# 3042 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3043 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_5
EscapeRoom_EventScript_Trainer0PostBattle_4:
# 3046 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3047 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_8
EscapeRoom_EventScript_Trainer0PostBattle_7:
# 3050 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer0PostBattle_10
	goto EscapeRoom_EventScript_Trainer0PostBattle_1

EscapeRoom_EventScript_Trainer0PostBattle_5:
# 3044 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer0PostBattle_4

EscapeRoom_EventScript_Trainer0PostBattle_8:
# 3048 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer0PostBattle_7

EscapeRoom_EventScript_Trainer0PostBattle_10:
# 3052 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 2
	goto EscapeRoom_EventScript_Trainer0PostBattle_1


EscapeRoom_EventScript_Trainer1PostBattle::
# 3062 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3065 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3066 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3067 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 3075 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 3078 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FLORGES, MOVE_SKILL_SWAP
# 3084 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3085 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3086 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3087 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3088 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 3089 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 3090 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 3091 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 3092 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 3093 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ELECTRIC_SEED_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 3102 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3103 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 3068 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3069 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_ELECTRIC_SEED
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 3095 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3096 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3097 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 3092 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 3092 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 3070 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3071 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ELECTRIC_SEED_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 3112 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3115 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3116 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3117 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 3124 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 3125 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3128 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_FERROTHORN, MOVE_CUT
# 3135 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3136 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 3137 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 3138 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 3139 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 3145 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 3118 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3119 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 3141 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3143 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 3120 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3121 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 3151 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3154 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 3157 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 3161 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 3166 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3167 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 3168 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3169 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 3170 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 3171 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 3174 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 3177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 3180 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3187 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3188 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 3189 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 3190 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 3191 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 3197 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 3159 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 3162 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3194 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3195 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 3201 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 3202 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 3203 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3203 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 3204 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 3208 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 3209 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3214 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3215 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3216 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3217 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3218 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_DUNSPARCE, MOVE_THIEF
# 3219 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
# 3220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_5
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 3226 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
# 3229 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_DUNSPARCE, MOVE_THIEF
	return

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 3222 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3223 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_5:
# 3220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 3234 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3237 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 3249 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MOON_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 3261 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 3273 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 3285 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TM_TRICK_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 3296 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 3297 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 3238 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3239 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 3242 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3243 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 3250 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3251 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 3254 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3255 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 3240 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 3262 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3263 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 3266 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3267 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_32
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 3252 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 3244 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 3274 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3275 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_30
EscapeRoom_EventScript_Trainer5PostBattle_29:
# 3278 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3279 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_37
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 3264 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 3256 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 3286 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3287 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_35
EscapeRoom_EventScript_Trainer5PostBattle_34:
# 3290 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3291 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_TM38
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_39
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_30:
# 3276 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_29

EscapeRoom_EventScript_Trainer5PostBattle_32:
# 3268 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_35:
# 3288 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_34

EscapeRoom_EventScript_Trainer5PostBattle_37:
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_39:
# 3292 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_26


EscapeRoom_EventScript_Trainer6PostBattle::
# 3302 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 3305 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 3308 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3310 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 3318 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 3319 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3320 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 3328 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 3330 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3333 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_1_USED_ON, SPECIES_NONE
# 3340 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3341 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 3342 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3343 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 3345 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 3346 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 3347 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 3348 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 3350 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 3351 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 3352 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 3353 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 3355 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_TM46
# 3356 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3357 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_ETHER
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3359 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 3360 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
# 3361 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 3362 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_7, VAR_RESULT
# 3364 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_RING_TARGET
# 3365 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_8, VAR_RESULT
# 3366 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 3367 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_9, VAR_RESULT
# 3369 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3370 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3371 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 3372 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 3374 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_NONE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_9
# 3375 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3376 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3377 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3378 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3379 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3380 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_6, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3382 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_7, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3383 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_8, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 3384 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_9, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 3311 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3312 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 3321 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_39
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 3313 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 3386 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3387 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3388 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3389 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_39:
# 3323 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 3324 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 3394 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 3395 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3400 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 3401 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer7APostBattle_2
# 3402 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer7APostBattle_2
EscapeRoom_EventScript_Trainer7APostBattle_1:
# 3408 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer7APostBattle_2:
# 3404 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3405 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3406 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer7APostBattle_1


EscapeRoom_EventScript_Trainer7BPostBattle::
# 3412 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 3413 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3415 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3417 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3418 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 3423 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 3424 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3431 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3433 "data/maps/EscapeRoom_Main/scripts.pory"
	istaughtmovepresent SPECIES_BAGON, MOVE_CUT
# 3434 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 3435 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer8PostBattle_2
# 3436 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
# 3437 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer8PostBattle_2
EscapeRoom_EventScript_Trainer8PostBattle_1:
# 3445 "data/maps/EscapeRoom_Main/scripts.pory"
	removetaughtmove SPECIES_BAGON, MOVE_CUT
# 3448 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsFirstMessage, MSGBOX_DEFAULT
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3450 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_GetChoiceItem
# 3452 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer8PostBattle_2:
# 3439 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3440 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer8PostBattle_1


EscapeRoom_EventScript_Trainer9PostBattle::
# 3456 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 3457 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3460 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_2_USED_ON, SPECIES_NONE
# 3468 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3470 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3471 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 3472 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer9PostBattle_2
# 3473 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 3474 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
# 3475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER10_DEFEATED, EscapeRoom_EventScript_Trainer9PostBattle_2
EscapeRoom_EventScript_Trainer9PostBattle_1:
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer9PostBattle_2:
# 3477 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3478 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3479 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer9PostBattle_1


EscapeRoom_EventScript_Trainer10PostBattle::
# 3485 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 3486 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 3489 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RARE_CANDY_3_USED_ON, SPECIES_NONE
# 3498 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 3499 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 3500 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ANNIHILAPE
# 3501 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 3502 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 35
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3503 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_BAGON
	goto_if_ne EscapeRoom_EventScript_Trainer10PostBattle_2
# 3504 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3505 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_Trainer10PostBattle_2
# 3506 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER7B_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 3507 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER8_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
# 3508 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_EventScript_Trainer10PostBattle_2
EscapeRoom_EventScript_Trainer10PostBattle_1:
# 3514 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer10PostBattle_2:
# 3510 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3511 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3512 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer10PostBattle_1


EscapeRoom_EventScript_Trainer11PostBattle::
# 3518 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 3519 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 3526 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3527 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 3528 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 3555 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 3557 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 3532 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3534 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 3543 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 3546 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3547 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3548 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3551 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 3552 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 3536 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3537 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3538 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 3561 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3562 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3565 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 3590 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 3591 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 3648 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 3649 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 3652 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 3568 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 3584 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 3585 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 3569 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 3570 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3571 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 3578 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3579 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 3594 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 3595 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3596 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 3605 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 3608 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 3609 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3610 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3612 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3615 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3620 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 3643 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 3572 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 3574 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3575 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 3598 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3599 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3600 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 3657 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3658 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3661 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 3686 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 3687 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 3721 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 3722 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 3725 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 3664 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 3680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 3681 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 3665 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 3666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3667 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 3674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 3675 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 3691 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3692 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 3701 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 3705 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3706 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3707 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3711 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3712 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3715 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 3716 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 3717 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 3668 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 3671 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 3694 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3695 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3696 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 3729 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 3730 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 3733 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 3739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 3740 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 3769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 3770 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 3773 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 3734 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 3735 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 3743 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 3744 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 3745 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 3754 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 3755 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3756 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 3759 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 3760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeMonDynamic, MSGBOX_AUTOCLOSE
# 3761 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3764 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 3765 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 3748 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3749 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_GetChoiceItem::
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsWhichOne, MSGBOX_DEFAULT
# 3782 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3785 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 30, 6, FALSE, 6, 0, 0, OptionChoiceBand, OptionChoiceSpecs, OptionChoiceScarf
# 3788 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_2
# 3791 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_3
# 3794 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_GetChoiceItem_4
# 3798 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsComeAgain, MSGBOX_DEFAULT
# 3799 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_GetChoiceItem_1:
# 3804 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem
# 3807 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RemoveChoiceItem
# 3810 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem VAR_0x8006
# 3813 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CHOICE_ITEM_OBTAINED, EscapeRoom_EventScript_GetChoiceItem_9
# 3818 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CHOICE_ITEM_OBTAINED
	return

EscapeRoom_EventScript_GetChoiceItem_2:
# 3789 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_BAND
	goto EscapeRoom_EventScript_GetChoiceItem_1

EscapeRoom_EventScript_GetChoiceItem_3:
# 3792 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SPECS
	goto EscapeRoom_EventScript_GetChoiceItem_1

EscapeRoom_EventScript_GetChoiceItem_4:
# 3795 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8006, ITEM_CHOICE_SCARF
	goto EscapeRoom_EventScript_GetChoiceItem_1

EscapeRoom_EventScript_GetChoiceItem_9:
# 3814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsSwapped, MSGBOX_DEFAULT
# 3815 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem::
# 3823 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 3826 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem VAR_0x8006
# 3827 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1:
# 3831 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3832 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4:
# 3839 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3840 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8
EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7:
# 3849 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10
	return

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_2:
# 3828 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_1

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_5:
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 3834 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual1
# 3835 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 3837 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual1:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_4

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_8:
# 3841 "data/maps/EscapeRoom_Main/scripts.pory"
	compare_var_to_var VAR_0x8005, VAR_0x8006
# 3842 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_ne NotEqual2
# 3843 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
# 3845 "data/maps/EscapeRoom_Main/scripts.pory"
NotEqual2:
	goto EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_7

EscapeRoom_EventScript_EndIfAlreadyHasChoiceItem_10:
# 3850 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ChoiceItemsAlreadyHaveThis, MSGBOX_DEFAULT
# 3851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3852 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_RemoveChoiceItem::
# 3858 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_BAND
# 3859 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SPECS
# 3860 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_CHOICE_SCARF
# 3862 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 3863 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_3
EscapeRoom_EventScript_RemoveChoiceItem_1:
# 3870 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 3871 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_11
	return

EscapeRoom_EventScript_RemoveChoiceItem_2:
# 3867 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_3:
# 3864 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 3865 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
# 3866 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_2
	goto EscapeRoom_EventScript_RemoveChoiceItem_1

EscapeRoom_EventScript_RemoveChoiceItem_10:
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	return

EscapeRoom_EventScript_RemoveChoiceItem_11:
# 3872 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_BAND
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 3873 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SPECS
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
# 3874 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CHOICE_SCARF
	goto_if_eq EscapeRoom_EventScript_RemoveChoiceItem_10
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 3883 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3884 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 3885 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 3886 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 3887 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy3::
# 3891 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3892 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 3893 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 3894 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY3_OBTAINED
# 3895 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindSolidBoard::
# 3899 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3900 "data/maps/EscapeRoom_Main/scripts.pory"
	givedecoration DECOR_SOLID_BOARD
# 3901 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 16
# 3902 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SOLID_BOARD_OBTAINED
# 3903 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPrimeape::
# 3907 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3917 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_RARE_CANDY, abilityNum = 2, nature = NATURE_CALM, gender = MON_FEMALE, move1 = MOVE_RAGE_FIST, move2 = MOVE_TAUNT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 252, defEv = 0, spDefEv = 8 hpIv = 31, atkIv = 0, defIv = 31, spAtkIv = 31, spDefIv = 31, speedIv = 10
# 3943 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 33
# 3944 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 3947 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY2_OBTAINED
# 3950 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 3951 "data/maps/EscapeRoom_Main/scripts.pory"
	message PrimeapeObtainMessage
# 3952 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 3953 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3956 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 3957 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_FindPrimeape_2
EscapeRoom_EventScript_FindPrimeape_1:
# 3961 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 3962 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_FindPrimeape_2:
# 3958 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 3959 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_FindPrimeape_1


EscapeRoom_EventScript_FindTMSecretPower::
# 3966 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3967 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_TM43
# 3968 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 8
# 3969 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SECRET_POWER_OBTAINED
# 3970 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 3977 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 3980 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 3988 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 3991 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 3994 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 3997 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 4002 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 4017 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 3981 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 3982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3983 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 3989 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 3992 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 3995 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 3998 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 4003 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4004 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 4005 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4006 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4009 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 4014 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 4010 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 4021 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 4032 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 4035 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 4038 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 4041 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 4046 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 4060 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 4025 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4026 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4027 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 4033 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 4036 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 4039 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 4042 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 4047 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4048 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 4049 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4050 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4053 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 4058 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 4054 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 4064 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4067 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 4075 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 4078 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 4081 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 4084 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 4089 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 4103 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 4068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4069 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4070 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 4076 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 4079 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 4082 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 4085 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 4090 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4091 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 4092 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4093 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4096 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 4101 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 4097 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 4107 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 4118 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 4123 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 4126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 4129 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 4132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 4137 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 4151 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 4111 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 4112 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4113 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 4119 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 4124 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 4127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 4130 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 4133 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 4138 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 4139 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 4140 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 4141 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4144 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 4149 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 4145 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 4156 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 4161 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 4162 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 4158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 4157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 4159 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 4167 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4168 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 4169 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 4170 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 4171 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4172 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4173 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 4174 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 4175 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 4177 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4178 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 4179 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 4186 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4189 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 4192 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 4197 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = MON_FEMALE, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 4220 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 4221 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 4193 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 4225 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4226 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4227 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4230 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 4234 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 4244 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4245 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4246 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 4250 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4251 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4254 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 4237 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 4238 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4240 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 4236 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 4235 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 4258 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4259 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4260 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4263 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 4266 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 4267 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 4268 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 4275 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4276 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4277 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4279 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 4270 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4271 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 4283 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4284 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4288 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 4292 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 4299 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 4300 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 4307 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 4310 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4311 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4313 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 4294 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 4295 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4297 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 4302 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4303 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4304 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 4317 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4318 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4319 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4322 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 4325 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 4326 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 4327 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 4334 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4335 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4336 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4338 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 4329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4330 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 4342 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4343 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4344 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4347 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 4350 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 4351 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 4352 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 4359 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4360 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4361 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4363 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 4354 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4355 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 4367 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4369 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4372 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 4375 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 4376 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 4377 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 4384 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4385 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4386 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4388 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 4379 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4380 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 4392 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4394 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4397 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 4401 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 4408 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 4409 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 4420 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4421 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4422 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 4424 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 4405 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 4406 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 4411 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4412 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4414 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4415 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4416 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 4428 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4429 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4430 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4433 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 4437 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 4444 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 4445 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 4452 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 4455 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4456 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4458 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 4439 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 4440 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4442 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 4447 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4448 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4449 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 4462 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4464 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4467 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 4470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 4471 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 4472 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 4479 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4480 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4481 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4483 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 4474 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 4487 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4488 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 4489 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4492 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 4495 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 4496 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 4497 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 4504 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 4505 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 4506 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 4508 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 4499 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 4500 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 4512 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4513 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 4515 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 4516 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4517 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4518 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4519 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4520 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4521 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4522 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 4524 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 4525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 4526 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4527 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 4531 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 4534 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 4574 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 4575 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 4578 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 4536 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 4537 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 4568 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 4569 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 4540 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 4541 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 4542 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMonNickname
# 4545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 4546 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 4537 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 4553 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymonlevel 43
# 4554 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_12
# 4559 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4560 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4561 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_ZeraNotReady, MSGBOX_DEFAULT
# 4562 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_12:
# 4555 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 4556 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 4583 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 4584 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 4585 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 4586 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 4587 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 4588 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 4589 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 4603 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


SomethingsGoneWrongMessage::
# 4617 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 4624 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

ByeByeMonDynamic::
# 4628 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye, {STR_VAR_1}.$"

SignMessage1_part1::
# 4635 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 4658 "data/maps/EscapeRoom_Main/scripts.pory"
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
# 4682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 4687 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 4692 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MoveDeleterSignMessage::
# 4699 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 4715 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 4721 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 4725 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 4729 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 4734 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 4739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 4743 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 4747 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 4756 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want {STR_VAR_1} to try and\n"
	.string "snatch the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 4764 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 4769 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} carefully detaches the\n"
	.string "goggles from the gravestone.$"

GogglesCurseHappens::
# 4774 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon {STR_VAR_1}!\p"
	.string "Snatch was forgotten.$"

Goggles_Statue_ZeraNotReady::
# 4781 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} nearly succeeded,\n"
	.string "but a strange force held the goggles\l"
	.string "in place.\p"
	.string "Perhaps {STR_VAR_1} isn't strong\n"
	.string "enough just yet.$"

RotatedSwitchSoundMessage::
# 4790 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 4794 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 4798 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 4803 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 4809 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 4815 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 4821 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 4828 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 4834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 4840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 4846 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 4853 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 4859 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 4865 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 4871 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 4878 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 4884 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 4890 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 4896 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 4904 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 4908 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 4912 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 4918 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 4927 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 4931 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 4938 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Certain rollbacks may also include\n"
	.string "resetting your Pokémon's HP, move PP,\l"
	.string "or even your location.$"

AntiSoftlockIntroMessage2::
# 4948 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 4952 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 4958 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 4963 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 4967 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockPpRemovedMessage::
# 4971 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your PP may have been lowered.$"

AntiSoftlockNoItemToUndo::
# 4977 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockItemUndoWhichItem::
# 4982 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What would you like to undo?$"

OptionUndoThief::
# 4986 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Thief$"

OptionUndoSecretPower::
# 4989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Secret Power$"

OptionUndoCut::
# 4992 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo HM Cut$"

OptionUndoSkillSwap::
# 4995 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo TM Skill Swap$"

OptionUndoRareCandy::
# 4998 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Rare Candy$"

OptionUndoExpCandy::
# 5001 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Undo Exp. Candy$"

AskUndoMoveTeachDynamic::
# 5005 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo teaching\n"
	.string "{STR_VAR_2} to {STR_VAR_1}?$"

AskUndoRareCandyDynamic::
# 5010 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Rare Candy\n"
	.string "used on {STR_VAR_1}?$"

MoveTeachUndoneMessage::
# 5015 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Teaching {STR_VAR_2} to {STR_VAR_1}\n"
	.string "has been undone.$"

RareCandyUndoneMessage::
# 5020 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down.$"

RareCandyUndoneUnevolveMessage::
# 5024 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} was leveled down and\n"
	.string "reverted back to a {STR_VAR_2}.$"

AskUndoExpCandyDynamic::
# 5029 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo the Exp. Candy\n"
	.string "use on {STR_VAR_1}?$"

ExpCandyUndoneMessage::
# 5034 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1} lost 800 Exp. Points.$"

ItemUndoSnowballsRemoved::
# 5038 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Snowball(s).$"

ItemUndoToxicOrbsRemoved::
# 5042 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You lost your Toxic Orb(s).$"

ItemUndoTreeGrewBack::
# 5046 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The cut tree grew back.$"

AntiSoftlockNoActionsToUndo::
# 5052 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 5057 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 5064 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 5068 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 5073 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

ZeraoraHintMessage1::
# 5080 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love catching rare Pokémon!\p"
	.string "You'll never know when the opportunity\n"
	.string "presents itself.\p"
	.string "Better be ready, take this.$"

ZeraoraHintMessage2::
# 5090 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You know, Pokémon become much easier\n"
	.string "to catch if their HP drops below 50%.$"

ZeraoraHintPostCatchMessage1::
# 5097 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You managed to get a Zeraora!?\n"
	.string "What an incredible catch.\p"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

ZeraoraHintPostCatchMessage2::
# 5108 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something tells me it'll come in handy.$"

ZeraoraHintPostCatchMessage3::
# 5112 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Pokédex must be looking pretty\n"
	.string "good by now.$"

AnnihilapeHintNoMessage1::
# 5119 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 5123 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 5127 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.$"

FourTabletsHintMessage1::
# 5137 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\p"
	.string "I'm looking for more of them!\n"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 5143 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop searching\n"
	.string "and get back to my job.\p"
	.string "Not sure what I'm serving today,\n"
	.string "I'll have to look through the menus.$"

FourTabletsHintMessage3::
# 5152 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake!?$"

StonesBuyNPCInitialMessage_no_item::
# 5159 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 5167 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥3000?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 5173 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 5181 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 5185 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 5189 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 5193 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived3000::
# 5197 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥3000!$"

LiepardObtainMessage::
# 5204 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 5208 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 5212 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 5216 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 5223 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 5227 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

SecretGardenGuardKeepOut::
# 5234 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found our secret garden!\p"
	.string "I cannot let you enter, sorry.$"

SecretGardenGuardSpotted::
# 5239 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "How did you get in there!?$"

SecretGardenGuardStayOut::
# 5243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Stay out of our garden!$"

SecretGardenGuardRemoveSecretPower::
# 5247 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I cannot let you leave with that what\n"
	.string "belongs to the garden.\p"
	.string "I'll have to take TM43 away from you.$"

MonForgotSecretPower::
# 5253 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s Secret Power was removed.$"

MartNPC_AskToShop::
# 5259 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 5265 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

ChoiceItemsFirstMessage::
# 5271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Impressive, you saw right through my\n"
	.string "facade!\p"
	.string "I think you've earned a reward!\n"
	.string "Take your pick of my Choice items.\p"
	.string "You can always return if you'd like to\n"
	.string "try a different one.$"

ChoiceItemsWhichOne::
# 5280 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Which item would you like to have?$"

ChoiceItemsComeAgain::
# 5284 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back anytime.$"

ChoiceItemsSwapped::
# 5288 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You returned the other Choice item.$"

ChoiceItemsAlreadyHaveThis::
# 5292 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You already have this one.$"

OptionChoiceBand::
# 5296 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Band$"

OptionChoiceSpecs::
# 5300 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Specs$"

OptionChoiceScarf::
# 5304 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice Scarf$"

PrimeapePokeballMessage::
# 5310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a Primeape inside the Poke Ball.\p"
	.string "Do you want to take it?$"

PrimeapeObtainMessage::
# 5315 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} found a Primeape!$"

NicknameThisPokemonMessage2::
# 5319 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Primeape?$"

AskDeleteMove::
# 5326 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 5332 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sorry, my service is not available\n"
	.string "anymore.\p"
	.string "I can no longer assist you.$"

MoveDeleterComeAgain::
# 5338 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MovesRestoredMessage::
# 5342 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s moves were restored!$"

NoMovesRestoredMessage::
# 5346 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 5352 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 5356 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

HeldStickyBarbReturnedMessage::
# 5360 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Sticky Barb was given back to the\n"
	.string "trainer.$"

AskWarpBackMessage::
# 5367 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to return to the previous\n"
	.string "location?$"

AskResetPredamageMessage::
# 5372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 5377 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 5383 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 5389 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 5394 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeDeclined::
# 5398 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 5402 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 5406 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 5410 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 5415 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 5420 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 5425 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 5431 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeDeclined::
# 5435 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 5439 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You're doing great.$"

PlayerObtainedFlorgesMessage::
# 5443 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 5447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 5452 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 5456 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 5461 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 5467 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 5473 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 5477 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

DoubleBattle_NotEnoughMons::
# 5483 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer0_Intro::
# 5490 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You think you are ready?\n"
	.string "You really need three.\l"
	.string "One of them might hold the key.$"

Trainer0_Outro::
# 5499 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "But sharing is caring!$"

Trainer0_PostBattle::
# 5503 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "One down, eleven to go.$"

Trainer1_Intro::
# 5509 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\l"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 5515 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's make a deal!$"

Trainer1_PostBattle::
# 5519 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sacrificing Pokémon is never easy, but\n"
	.string "that's the price of progress.$"

AskZeraCutTradeMessage::
# 5524 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 5531 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

Trainer2_Intro::
# 5537 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 5542 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love writing in 686578!$"

Trainer2_PostBattle::
# 5546 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Cut the illusion, clear the path!$"

Trainer3_Intro::
# 5552 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and recognize good easy tactics.$"

Trainer3_Outro::
# 5557 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Right on, pretty exciting!$"

Trainer3_PostBattle::
# 5561 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Every good gamer sometimes cheats a\n"
	.string "puzzle exit.$"

Trainer3FinalWords::
# 5566 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 5572 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?\n"
	.string "We're just getting started!$"

Trainer4_Outro::
# 5577 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh, just leave already.$"

Trainer4_PostBattle::
# 5581 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you know 5(A->L) + 2(L->O) = 525?$"

Trainer5_Intro::
# 5588 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 5593 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that enough?$"

Trainer5_PostBattle::
# 5597 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's never do that again.$"

Trainer5_RemoveAssistMessage::
# 5601 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 5608 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They can bring all sorts of items.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 5615 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Oh how the tablets have turned.$"

Trainer6_PostBattle::
# 5619 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you know where I can find a cook?\n"
	.string "My birds deliver goods, not dinner.$"

Trainer7A_Intro::
# 5626 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That old lady makes a move on nearly\n"
	.string "everyone who walks by.\p"
	.string "Honestly, I can't take it anymore.\n"
	.string "I'm barely holding it together.$"

Trainer7A_Outro::
# 5633 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't you think she's two forward?$"

Trainer7A_PostBattle::
# 5637 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "fwuenqru? uwu.$"

Trainer7B_Intro::
# 5644 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello handsome.\n"
	.string "Aren't you a sight for sore eyes?$"

Trainer7B_Outro::
# 5649 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 5653 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I don't think I was meant to be\n"
	.string "beatable...$"

Trainer8_Intro::
# 5660 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Spooky, scary skeletons,\n"
	.string "send shivers down your spine.\p"
	.string "Ghost type mons are everywhere,\n"
	.string "you still haven't seen mine.$"

Trainer8_Outro::
# 5672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is there anyone you can't beat?$"

Trainer8_PostBattle::
# 5676 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "$"

Trainer9_Intro::
# 5682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many trainers, but battles are rare.\n"
	.string "Many pretend like we're not even there.$"

Trainer9_Outro::
# 5687 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks. Only real battles.$"

Trainer9_PostBattle::
# 5691 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Is this your last time passing through?$"

Trainer10_Intro::
# 5699 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Darwinism?\n"
	.string "More like Schmarminism...\p"
	.string "Kecleon doesn't need any changes!$"

Trainer10_Outro::
# 5705 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What happened to Shelgon?$"

Trainer10_PostBattle::
# 5709 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't stop now.\n"
	.string "You're almost there!$"

Trainer11_Intro::
# 5716 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_Outro::
# 5720 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_PostBattle::
# 5724 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"
