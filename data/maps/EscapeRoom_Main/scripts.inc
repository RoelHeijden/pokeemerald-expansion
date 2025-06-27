EscapeRoom_Main_MapScripts::
# 49 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 50 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 52 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 56 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 53 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 57 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 58 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 59 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 60 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_REMOVE_HELD_ITEM, 1, EscapeRoom_MapScripts_RemoveHeldItem
# 61 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 62 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 70 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 75 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 76 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScript_OnResumeScripts_3
EscapeRoom_MapScript_OnResumeScripts_1:
# 100 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_7
EscapeRoom_MapScript_OnResumeScripts_6:
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScript_OnResumeScripts_11
EscapeRoom_MapScript_OnResumeScripts_9:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_18
EscapeRoom_MapScript_OnResumeScripts_16:
# 127 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_22
EscapeRoom_MapScript_OnResumeScripts_21:
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_STARDUST_STOLEN, EscapeRoom_MapScript_OnResumeScripts_25
EscapeRoom_MapScript_OnResumeScripts_24:
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_28
EscapeRoom_MapScript_OnResumeScripts_27:
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_31
EscapeRoom_MapScript_OnResumeScripts_30:
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScript_OnResumeScripts_34
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 85 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 89 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 90 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_FERRO_CUSTAP
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_3:
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_7:
# 102 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 103 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_14
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_10:
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_USED_FOR_SACK
# 112 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MENTAL_HERB
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_LIEPARD_MENTAL_HERB
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 118 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_FLUNG_ITEM
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_11:
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MENTAL_HERB_USED_FOR_SACK, EscapeRoom_MapScript_OnResumeScripts_10
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_14:
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_17:
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_16

EscapeRoom_MapScript_OnResumeScripts_18:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_17
	goto EscapeRoom_MapScript_OnResumeScripts_16

EscapeRoom_MapScript_OnResumeScripts_22:
# 129 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_21

EscapeRoom_MapScript_OnResumeScripts_25:
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStardustStolen
	goto EscapeRoom_MapScript_OnResumeScripts_24

EscapeRoom_MapScript_OnResumeScripts_28:
# 139 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_27

EscapeRoom_MapScript_OnResumeScripts_31:
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 145 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_38
EscapeRoom_MapScript_OnResumeScripts_37:
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	goto EscapeRoom_MapScript_OnResumeScripts_30

EscapeRoom_MapScript_OnResumeScripts_33:
# 153 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_41
EscapeRoom_MapScript_OnResumeScripts_40:
# 157 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScript_OnResumeScripts_34:
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_33
	return

EscapeRoom_MapScript_OnResumeScripts_38:
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScript_OnResumeScripts_37

EscapeRoom_MapScript_OnResumeScripts_41:
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScript_OnResumeScripts_40


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 173 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 174 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 188 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 189 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 183 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 184 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 185 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_RemoveHeldItem::
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_FERRO_CUSTAP, EscapeRoom_MapScripts_RemoveHeldItem_2
EscapeRoom_MapScripts_RemoveHeldItem_1:
# 200 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_LIEPARD_MENTAL_HERB, EscapeRoom_MapScripts_RemoveHeldItem_5
EscapeRoom_MapScripts_RemoveHeldItem_4:
# 205 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 0
	return

EscapeRoom_MapScripts_RemoveHeldItem_2:
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_FERRO_CUSTAP
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveFerroCustap
	goto EscapeRoom_MapScripts_RemoveHeldItem_1

EscapeRoom_MapScripts_RemoveHeldItem_5:
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_LIEPARD_MENTAL_HERB
# 202 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveLiepardMentalHerb
	goto EscapeRoom_MapScripts_RemoveHeldItem_4


EscapeRoom_MapScripts_RemoveLiepardMentalHerb::
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveLiepardMentalHerb_1
	return

EscapeRoom_MapScripts_RemoveLiepardMentalHerb_1:
# 212 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MapScripts_RemoveLiepardMentalHerb_3
	return

EscapeRoom_MapScripts_RemoveLiepardMentalHerb_3:
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_RemoveFerroCustap::
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveFerroCustap_1
	return

EscapeRoom_MapScripts_RemoveFerroCustap_1:
# 223 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveFerroCustap_3
	return

EscapeRoom_MapScripts_RemoveFerroCustap_3:
# 225 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_CheckStardustStolen::
# 231 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STARDUST
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_2
EscapeRoom_MapScripts_CheckStardustStolen_1:
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_5
EscapeRoom_MapScripts_CheckStardustStolen_4:
# 239 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 240 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_8
EscapeRoom_MapScripts_CheckStardustStolen_7:
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 244 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_10
	return

EscapeRoom_MapScripts_CheckStardustStolen_2:
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_1

EscapeRoom_MapScripts_CheckStardustStolen_5:
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_4

EscapeRoom_MapScripts_CheckStardustStolen_8:
# 241 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_7

EscapeRoom_MapScripts_CheckStardustStolen_10:
# 245 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	return


EscapeRoom_MapScripts_AskResetPredamage::
# 250 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
EscapeRoom_MapScripts_AskResetPredamage_1:
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 257 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 261 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 262 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScript_GameStartScripts::
# 269 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 274 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 275 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 283 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 284 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 285 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_EXP_CANDY_S, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 1, defIv = 3, speedIv = 31, spAtkIv = 0, spDefIv = 30
# 313 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SUNNY_DAY, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 344 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 345 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
	return


EscapeRoom_MapScripts_GetItems::
# 365 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 366 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 371 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_MainInfoSign::
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 383 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 389 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 395 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 396 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 413 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 402 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 404 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 425 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 426 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 431 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 432 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 452 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 471 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 476 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 479 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage, MSGBOX_DEFAULT
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LiepardNPC::
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_NORMAL
# 492 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 498 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 565 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 511 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 532 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_NORMAL
# 533 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 543 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 559 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 563 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 569 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 572 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 575 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 578 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 581 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 584 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 585 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 590 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, ball = ITEM_FRIEND_BALL, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_COPYCAT, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 620 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 670 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 674 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 681 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 686 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 700 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 709 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 710 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 711 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 717 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

	.align 2
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 724 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM27
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 732 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_DEFAULT
# 737 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_MoveDeleterNPC_Text_0, EscapeRoom_MoveDeleterNPC_Text_1
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_2
# 746 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_3
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
EscapeRoom_MoveDeleterNPC_1:
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_1

EscapeRoom_MoveDeleterNPC_3:
# 747 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
	goto EscapeRoom_MoveDeleterNPC_1


EscapeRoom_ChooseMoveToDelete::
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 761 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_MOVE_DELETE_MONSLOT_BACKUP
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EscapeRoom_ChooseMoveToDelete_2
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	special GetNumMovesSelectedMonHas
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_ChooseMoveToDelete_5
# 783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
	goto_if_eq EscapeRoom_ChooseMoveToDelete_8
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmonmoveset VAR_0x8004
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_MOVE_DELETER_CHOSEN_SLOT
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	special MoveDeleterForgetMove
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterMoveDeleted, MSGBOX_AUTOCLOSE
	end

EscapeRoom_ChooseMoveToDelete_2:
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_5:
# 777 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOnlyOneMove, MSGBOX_AUTOCLOSE
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_8:
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 785 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_RestoreMoveset::
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_SMEARGLE
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_11
EscapeRoom_RestoreMoveset_10:
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_13
	return

EscapeRoom_RestoreMoveset_2:
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 815 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 816 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardMovesRestoredMessage, MSGBOX_DEFAULT
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 825 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomMovesRestoredMessage, MSGBOX_DEFAULT
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceMovesRestoredMessage, MSGBOX_DEFAULT
# 837 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_11:
# 843 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SMEARGLE_MOVE_DELETED
# 846 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SmeargleMovesRestoredMessage, MSGBOX_DEFAULT
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_10

EscapeRoom_RestoreMoveset_13:
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 864 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_UltraBallNPC::
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_DEFAULT
EscapeRoom_UltraBallNPC_1:
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_RockSmashNPC::
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, face_npc_up
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 909 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 910 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 936 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_SOLD_OUT
	return


# 940 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 943 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 946 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 948 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 951 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_AnnihilapeHintNPC::
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 981 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 972 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 973 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 997 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 1017 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage3, MSGBOX_DEFAULT
# 1018 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_DEFAULT
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_DEFAULT
# 1010 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1011 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage2, MSGBOX_DEFAULT
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER9_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_3
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_4
# 1036 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage4, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 1027 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_4:
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_DusknoirStoleMyMailNPC::
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DusknoirStoleMyMailMsg, MSGBOX_NPC
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer1::
# 1051 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 1061 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 1065 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 1066 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 1092 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 1113 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1114 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1


EscapeRoom_EventScript_Trainer6::
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 1139 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer9::
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1180 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1173 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1188 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1193 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 1194 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 1208 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1223 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ETHER_SOLD_OUT
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer5PostBattle::
# 1234 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_FLUNG_ITEM
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_BERRY_JUICE
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_Trainer6PostBattle::
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_FLUNG_ITEM
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_GOGGLES
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1273 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 1282 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 1277 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer9PostBattle::
# 1287 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 1297 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 1317 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1327 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 1337 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 1347 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 50, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_AIR_SLASH, move3 = MOVE_HEX, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 10, spDefIv = 31
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1424 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 1464 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 1465 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeAipomForSmeargle::
# 1478 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1479 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeAipomForSmeargle_2
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskAipomSmeargleTrade, MSGBOX_YESNO
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeAipomForSmeargle_5
# 1537 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomTradeDeclined, MSGBOX_AUTOCLOSE
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeAipomForSmeargle_1:
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeAipomForSmeargle_2:
# 1483 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomTradePostTrade, MSGBOX_NPC
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeAipomForSmeargle_1

EscapeRoom_EventScript_TradeAipomForSmeargle_5:
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeAipomForSmeargle_9
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 5, abilityNum = 0, nature = 18, gender = 0, move1 = MOVE_SURF, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, spAtkEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AIPOM_TRADE_ACCEPTED
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomTradeAccepted, MSGBOX_AUTOCLOSE
# 1533 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeAipomForSmeargle_1

EscapeRoom_EventScript_TradeAipomForSmeargle_9:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1497 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindCustapBerry::
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1551 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_CUSTAP_BERRY
# 1552 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 12
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_BERRY_OBTAINED
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindLiepardCollar::
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1561 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 1562 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1569 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1646 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1667 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1673 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1676 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1661 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1683 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1702 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1716 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1722 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 1741 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1753 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1760 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 1783 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 1788 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1825 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1836 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1837 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1842 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1831 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1850 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1854 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1866 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1862 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1913 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1951 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1954 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 1966 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 1975 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1976 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 1983 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1984 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1985 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1988 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 2000 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 1997 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 2019 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2021 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 2030 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 2031 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 2038 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 2062 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 2063 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2072 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2074 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 2065 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2080 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 2088 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2096 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2097 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2104 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2115 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 2122 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 2140 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2160 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2166 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_SWEET_SCENT
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2172 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_MoveDeleterNPC_Text_0:
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete a move$"

EscapeRoom_MoveDeleterNPC_Text_1:
# 739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Restore deleted moves$"

SomethingsGoneWrongMessage::
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 2196 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 2200 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 2210 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MysteriousWallSign::
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "bliep bloop (TBD)$"

MoveDeleterSignMessage::
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 2257 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "You feel a spirit nearby.$"

GravestoneClick3Message::
# 2262 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 2267 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 2271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 2275 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 2302 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 2309 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 2313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 2322 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 2328 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 2340 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 2347 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 2359 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 2372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 2378 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 2384 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 2390 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 2403 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 2437 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2450 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 2472 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 2476 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks for playing!$"

ZeraoraHintMessage::
# 2482 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people try to catch it but no\n"
	.string "one's been able to get its HP below 50%.\p"
	.string "Will you show me the Zeraora if you do\n"
	.string "manage to capture it?\p"
	.string "I've always wanted to see one up close.$"

ZeraoraHintPostCatchMessage1::
# 2491 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!\p"
	.string "I can't believe my eyes!\n"
	.string "You've made a dream come true...\p"
	.string "Here, take this!$"

ZeraoraHintPostCatchMessage2::
# 2499 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's the least I can do.$"

ZeraoraHintPostCatchMessage3::
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll never forget this day.$"

AnnihilapeHintNoMessage1::
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 2514 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 2518 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.\p"
	.string "She'll always be back.$"

FourTabletsHintMessage1::
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 2534 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm so done with this search...\p"
	.string "Maybe it's time to just kick back and\n"
	.string "stare at the waves for a while.$"

FourTabletsHintMessage3::
# 2540 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to look through the menus.$"

FourTabletsHintMessage4::
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you feel that earthquake?$"

DusknoirStoleMyMailMsg::
# 2555 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A Dusknoir stole my mail!\p"
	.string "To be honest, I don't really mind.\n"
	.string "It's just a bit strange.$"

LiepardObtainMessage::
# 2564 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 2568 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 2576 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 2583 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 2587 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

MartNPC_AskToShop::
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2604 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterComeAgain::
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MoveDeleterMoveDeleted::
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s {STR_VAR_2} was removed!$"

MoveDeleterOnlyOneMove::
# 2618 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That Pokémon has only one move left.$"

AipomMovesRestoredMessage::
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Aipom's moves were restored!$"

LiepardMovesRestoredMessage::
# 2626 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Liepard's moves were restored!$"

DunsparceMovesRestoredMessage::
# 2630 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce's moves were restored!$"

SmeargleMovesRestoredMessage::
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Smeargle's moves were restored!$"

NoMovesRestoredMessage::
# 2638 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 2644 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 2648 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

AskResetPredamageMessage::
# 2654 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

PreDamagedStateRestoredMessage::
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2670 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2674 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 2682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2688 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 2694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2702 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2706 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I sense regret?$"

AskDunsparceMoneyTrade::
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2728 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

AskAipomSmeargleTrade::
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (start trade)$"

SmeargleReceivedMessage::
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

AipomTradeAccepted::
# 2742 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Aipom.$"

AipomTradeDeclined::
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

AipomTradePostTrade::
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (post trade)$"

DoubleBattle_NotEnoughMons::
# 2756 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\p"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 2769 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2777 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2784 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2788 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2794 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2805 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2811 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2820 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3FinalWords::
# 2824 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 2834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2838 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2844 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you have enough?$"

Trainer5_PostBattle::
# 2853 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_RemoveAssistMessage::
# 2857 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They always find their way back.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 2871 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2875 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer9_Intro::
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer9_Outro::
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer9_PostBattle::
# 2889 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
