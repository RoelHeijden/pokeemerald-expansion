EscapeRoom_Main_MapScripts::
# 46 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 47 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 49 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 53 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 50 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 54 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 55 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 56 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 57 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_REMOVE_HELD_ITEM, 1, EscapeRoom_MapScripts_RemoveHeldItem
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 64 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_1
	return

EscapeRoom_MapScript_OnTransitionScripts_1:
# 65 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	return


EscapeRoom_MapScript_OnResumeScripts::
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScript_OnResumeScripts_3
EscapeRoom_MapScript_OnResumeScripts_1:
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_8
EscapeRoom_MapScript_OnResumeScripts_6:
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScript_OnResumeScripts_12
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScript_OnResumeScripts_12
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScript_OnResumeScripts_12
EscapeRoom_MapScript_OnResumeScripts_11:
# 93 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_STARDUST_STOLEN, EscapeRoom_MapScript_OnResumeScripts_19
EscapeRoom_MapScript_OnResumeScripts_18:
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_21
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_FERRO_CUSTAP
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_3:
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_7:
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_8:
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_7
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_12:
# 89 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_11

EscapeRoom_MapScript_OnResumeScripts_19:
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStardustStolen
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_21:
# 99 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 111 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 112 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 118 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 121 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScripts_RetrievedItemMessage_5
EscapeRoom_MapScripts_RetrievedItemMessage_4:
# 135 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScripts_RetrievedItemMessage_8
EscapeRoom_MapScripts_RetrievedItemMessage_7:
# 141 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox WhiteHerbRecoveredMessage, MSGBOX_AUTOCLOSE
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1

EscapeRoom_MapScripts_RetrievedItemMessage_5:
# 129 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CustapBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 131 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
	goto EscapeRoom_MapScripts_RetrievedItemMessage_4

EscapeRoom_MapScripts_RetrievedItemMessage_8:
# 136 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MarangaBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 137 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 138 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
	goto EscapeRoom_MapScripts_RetrievedItemMessage_7


EscapeRoom_MapScripts_RemoveHeldItem::
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_FERRO_CUSTAP, EscapeRoom_MapScripts_RemoveHeldItem_2
EscapeRoom_MapScripts_RemoveHeldItem_1:
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 0
	return

EscapeRoom_MapScripts_RemoveHeldItem_2:
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_FERRO_CUSTAP
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveFerroCustap
	goto EscapeRoom_MapScripts_RemoveHeldItem_1


EscapeRoom_MapScripts_RemoveFerroCustap::
# 156 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 157 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 158 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveFerroCustap_1
	return

EscapeRoom_MapScripts_RemoveFerroCustap_1:
# 159 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveFerroCustap_3
	return

EscapeRoom_MapScripts_RemoveFerroCustap_3:
# 161 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_CheckStardustStolen::
# 167 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STARDUST
# 168 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_2
EscapeRoom_MapScripts_CheckStardustStolen_1:
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_5
EscapeRoom_MapScripts_CheckStardustStolen_4:
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 176 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_8
EscapeRoom_MapScripts_CheckStardustStolen_7:
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_10
	return

EscapeRoom_MapScripts_CheckStardustStolen_2:
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_1

EscapeRoom_MapScripts_CheckStardustStolen_5:
# 173 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_4

EscapeRoom_MapScripts_CheckStardustStolen_8:
# 177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_7

EscapeRoom_MapScripts_CheckStardustStolen_10:
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	return


EscapeRoom_MapScript_GameStartScripts::
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 204 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 205 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_WHITE_HERB, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 1, defIv = 3, speedIv = 31, spAtkIv = 0, spDefIv = 30
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SLEEP_TALK, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 284 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 285 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 289 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 292 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 293 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 294 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 296 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 297 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 298 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 299 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 300 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 301 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 302 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
	return


EscapeRoom_MapScripts_GetItems::
# 312 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_EXP_CANDY_S
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 316 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_MainInfoSign::
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 332 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndSignMessage, MSGBOX_AUTOCLOSE
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 367 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 369 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 381 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 383 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 395 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 411 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LostGlassesNPC::
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCmainMessage, MSGBOX_AUTOCLOSE
# 420 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_WISE_GLASSES
# 421 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_2
EscapeRoom_EventScript_LostGlassesNPC_1:
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LostGlassesNPC_2:
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 425 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_5
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCGlassesFoundMessage, MSGBOX_AUTOCLOSE
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 441 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 443 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_WISE_GLASSES
# 444 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCendMessage, MSGBOX_AUTOCLOSE
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, EscapeRoom_Movement_LostGlassesNPC
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LostGlassesNPC_1

EscapeRoom_EventScript_LostGlassesNPC_5:
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_ObtainLiepard::
# 464 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 50, abilityNum = 2, nature = 17, gender = 0, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_ECHOED_VOICE, atkEv = 140, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 18, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	return


# 492 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_LostGlassesNPC:
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_EventScript_RelocateNurseNPC::
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 511 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 525 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 529 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 533 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_up
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 540 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 545 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 562 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 563 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 564 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 565 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 571 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 572 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

	.align 2
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM12
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_DEFAULT
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_MoveDeleterNPC_Text_0, EscapeRoom_MoveDeleterNPC_Text_1
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_2
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_3
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
EscapeRoom_MoveDeleterNPC_1:
# 608 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 598 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_1

EscapeRoom_MoveDeleterNPC_3:
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
	goto EscapeRoom_MoveDeleterNPC_1


EscapeRoom_ChooseMoveToDelete::
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EscapeRoom_ChooseMoveToDelete_2
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	special GetNumMovesSelectedMonHas
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_ChooseMoveToDelete_5
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
	goto_if_eq EscapeRoom_ChooseMoveToDelete_8
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_MOVE_DELETER_CHOSEN_SLOT
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	special MoveDeleterForgetMove
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterMoveDeleted, MSGBOX_AUTOCLOSE
	end

EscapeRoom_ChooseMoveToDelete_2:
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_5:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOnlyOneMove, MSGBOX_AUTOCLOSE
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_8:
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_RestoreMoveset::
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 656 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_3
EscapeRoom_RestoreMoveset_1:
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_6:
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_16
EscapeRoom_RestoreMoveset_14:
# 752 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_27
EscapeRoom_RestoreMoveset_25:
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_39
	return

EscapeRoom_RestoreMoveset_2:
# 659 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ICE_FANG_DELETED, EscapeRoom_RestoreMoveset_12
EscapeRoom_RestoreMoveset_11:
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SLEEP_TALK_DELETED, EscapeRoom_RestoreMoveset_23
EscapeRoom_RestoreMoveset_22:
# 669 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ENDEAVOR_DELETED, EscapeRoom_RestoreMoveset_37
EscapeRoom_RestoreMoveset_36:
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TAUNT_DELETED, EscapeRoom_RestoreMoveset_51
EscapeRoom_RestoreMoveset_50:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochMovesRestoredMessage, MSGBOX_DEFAULT
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_POOCH_MOVE_DELETED
# 684 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_3:
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_MOVE_DELETED, EscapeRoom_RestoreMoveset_2
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_7:
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ASSIST_DELETED, EscapeRoom_RestoreMoveset_20
EscapeRoom_RestoreMoveset_19:
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_DELETED, EscapeRoom_RestoreMoveset_34
EscapeRoom_RestoreMoveset_33:
# 701 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ECHOED_VOICE_DELETED, EscapeRoom_RestoreMoveset_48
EscapeRoom_RestoreMoveset_47:
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRICK_DELETED, EscapeRoom_RestoreMoveset_60
EscapeRoom_RestoreMoveset_59:
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardMovesRestoredMessage, MSGBOX_DEFAULT
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_6

EscapeRoom_RestoreMoveset_8:
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_MOVE_DELETED, EscapeRoom_RestoreMoveset_7
	goto EscapeRoom_RestoreMoveset_6

EscapeRoom_RestoreMoveset_12:
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_ICE_FANG
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ICE_FANG_DELETED
	goto EscapeRoom_RestoreMoveset_11

EscapeRoom_RestoreMoveset_15:
# 723 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRUMP_CARD_DELETED, EscapeRoom_RestoreMoveset_31
EscapeRoom_RestoreMoveset_30:
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HEX_DELETED, EscapeRoom_RestoreMoveset_45
EscapeRoom_RestoreMoveset_44:
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_COUNTER_DELETED, EscapeRoom_RestoreMoveset_57
EscapeRoom_RestoreMoveset_56:
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIR_SLASH_DELETED, EscapeRoom_RestoreMoveset_66
EscapeRoom_RestoreMoveset_65:
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceMovesRestoredMessage, MSGBOX_DEFAULT
# 746 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 747 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_14

EscapeRoom_RestoreMoveset_16:
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_MOVE_DELETED, EscapeRoom_RestoreMoveset_15
	goto EscapeRoom_RestoreMoveset_14

EscapeRoom_RestoreMoveset_20:
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ASSIST
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ASSIST_DELETED
	goto EscapeRoom_RestoreMoveset_19

EscapeRoom_RestoreMoveset_23:
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_SLEEP_TALK
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SLEEP_TALK_DELETED
	goto EscapeRoom_RestoreMoveset_22

EscapeRoom_RestoreMoveset_26:
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SURF_DELETED, EscapeRoom_RestoreMoveset_42
EscapeRoom_RestoreMoveset_41:
# 760 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SWITCHEROO_DELETED, EscapeRoom_RestoreMoveset_54
EscapeRoom_RestoreMoveset_53:
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UPROAR_DELETED, EscapeRoom_RestoreMoveset_63
EscapeRoom_RestoreMoveset_62:
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CONVERSION_2_DELETED, EscapeRoom_RestoreMoveset_69
EscapeRoom_RestoreMoveset_68:
# 776 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 777 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SmeargleMovesRestoredMessage, MSGBOX_DEFAULT
# 778 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SMEARGLE_MOVE_DELETED
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	goto EscapeRoom_RestoreMoveset_25

EscapeRoom_RestoreMoveset_27:
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SMEARGLE_MOVE_DELETED, EscapeRoom_RestoreMoveset_26
	goto EscapeRoom_RestoreMoveset_25

EscapeRoom_RestoreMoveset_31:
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_TRUMP_CARD
# 726 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRUMP_CARD_DELETED
	goto EscapeRoom_RestoreMoveset_30

EscapeRoom_RestoreMoveset_34:
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ROCK_SMASH
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ROCK_SMASH_DELETED
	goto EscapeRoom_RestoreMoveset_33

EscapeRoom_RestoreMoveset_37:
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_ENDEAVOR
# 672 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ENDEAVOR_DELETED
	goto EscapeRoom_RestoreMoveset_36

EscapeRoom_RestoreMoveset_39:
# 786 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return

EscapeRoom_RestoreMoveset_42:
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_SURF
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SURF_DELETED
	goto EscapeRoom_RestoreMoveset_41

EscapeRoom_RestoreMoveset_45:
# 730 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_HEX
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HEX_DELETED
	goto EscapeRoom_RestoreMoveset_44

EscapeRoom_RestoreMoveset_48:
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ECHOED_VOICE
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ECHOED_VOICE_DELETED
	goto EscapeRoom_RestoreMoveset_47

EscapeRoom_RestoreMoveset_51:
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_TAUNT
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TAUNT_DELETED
	goto EscapeRoom_RestoreMoveset_50

EscapeRoom_RestoreMoveset_54:
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_SWITCHEROO
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SWITCHEROO_DELETED
	goto EscapeRoom_RestoreMoveset_53

EscapeRoom_RestoreMoveset_57:
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_COUNTER
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_COUNTER_DELETED
	goto EscapeRoom_RestoreMoveset_56

EscapeRoom_RestoreMoveset_60:
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_TRICK
# 709 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRICK_DELETED
	goto EscapeRoom_RestoreMoveset_59

EscapeRoom_RestoreMoveset_63:
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_UPROAR
# 768 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UPROAR_DELETED
	goto EscapeRoom_RestoreMoveset_62

EscapeRoom_RestoreMoveset_66:
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_AIR_SLASH
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIR_SLASH_DELETED
	goto EscapeRoom_RestoreMoveset_65

EscapeRoom_RestoreMoveset_69:
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_CONVERSION_2
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CONVERSION_2_DELETED
	goto EscapeRoom_RestoreMoveset_68


EscapeRoom_MoveRestoredSound::
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_UltraBallNPC::
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 803 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 805 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_NPC
EscapeRoom_UltraBallNPC_1:
# 820 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_AnnihilapeHintNPC::
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessagePostScript, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 849 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 852 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 837 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 864 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 870 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 874 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage, MSGBOX_NPC
EscapeRoom_ZeraoraHintNPC_1:
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 880 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_SPECS_OBTAINED, EscapeRoom_TabletsHintNPC_4
# 891 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage4, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 885 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_4:
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 910 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 958 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 964 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer6::
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7::
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7, Trainer7_Intro, Trainer7_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7_PostBattle, MSGBOX_AUTOCLOSE
# 990 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 1023 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1036 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_TradeZeraForHMCut::
# 1051 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 1075 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 1066 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 1069 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1060 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1061 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 50, abilityNum = 2, nature = 8, gender = 0, move1 = MOVE_TRUMP_CARD, move2 = MOVE_AIR_SLASH, move3 = MOVE_HEX, move4 = MOVE_COUNTER, hpEv = 0, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 10, spDefIv = 31
# 1125 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 1128 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1129 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 1096 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1150 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 1156 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 1187 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 1171 "data/maps/EscapeRoom_Main/scripts.pory"
	givepoochegg
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 1202 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_NPC
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 5000
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceivedMessage
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1223 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeAccepted, MSGBOX_AUTOCLOSE
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 1208 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1209 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradePoochForSmeargle::
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_TRADE_ACCEPTED, EscapeRoom_EventScript_TradePoochForSmeargle_2
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskPoochSmeargleTrade, MSGBOX_YESNO
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_5
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeDeclined, MSGBOX_AUTOCLOSE
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradePoochForSmeargle_1:
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradePoochForSmeargle_2:
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradePostTrade, MSGBOX_NPC
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_5:
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1251 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_9
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TradePoochForSmeargle_12
EscapeRoom_EventScript_TradePoochForSmeargle_11:
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_POOCHYENA
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1277 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 30, abilityNum = 0, nature = 15, gender = 0, move1 = MOVE_SWITCHEROO, move2 = MOVE_UPROAR, move3 = MOVE_SURF, move4 = MOVE_CONVERSION_2, hpEv = 0, spAtkEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 28
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POOCH_TRADE_ACCEPTED
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeAccepted, MSGBOX_AUTOCLOSE
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_9:
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradePoochForSmeargle_12:
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_14
	goto EscapeRoom_EventScript_TradePoochForSmeargle_11

EscapeRoom_EventScript_TradePoochForSmeargle_14:
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HealBeforeTradeMessage, MSGBOX_DEFAULT
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1266 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1267 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1269 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HealedBeforeTradeMessage, MSGBOX_AUTOCLOSE
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_11


EscapeRoom_EventScript_FindRareCandy::
# 1321 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1322 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1324 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindLostGlasses::
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_WISE_GLASSES
# 1331 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LOST_GLASSES_OBTAINED
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1355 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1366 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1388 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1396 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1464 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1473 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1501 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 1512 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1533 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1537 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GraveStone1::
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1603 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1610 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1611 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1615 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1623 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1637 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1646 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1647 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1670 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1679 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1687 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1702 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1713 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1745 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 1753 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 1760 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1764 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 1789 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 1797 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 1791 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 1799 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1800 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1801 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1815 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1819 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 1822 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 1823 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 1831 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1832 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1833 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 1839 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 1847 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 1848 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 1851 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1852 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1869 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 1878 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 1907 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 1900 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1916 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 1924 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_HAZE
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1931 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_MoveDeleterNPC_Text_0:
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete a move$"

EscapeRoom_MoveDeleterNPC_Text_1:
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Restore deleted moves$"

SomethingsGoneWrongMessage::
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EndSignMessage::
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The end.\p"
	.string "...\p"
	.string "For now.$"

MysteriousWallSign::
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice paralysis?$"

MoveDeleterSignMessage::
# 1983 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "Please note that a restored move will\n"
	.string "get 0 pp if:\l"
	.string "a) it had 0 pp when deleted.\l"
	.string "b) all current moves have 0 pp.$"

AnnihilapeStatueMessage::
# 1997 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A spirit stirs.\nYou sense a presence.$"

GravestoneClick3Message::
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void.$"

GravestoneAnnihilapesRoar::
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 2037 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 2045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 2050 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 2062 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 2081 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 2168 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello, should I heal your Pokémon?$"

Nurse_Heal_End::
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 2210 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Thanks for playing)$"

ZeraoraHintMessage::
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people trying to catch it\n"
	.string "but no one's been able to get its HP\l"
	.string "below 50%.\p"
	.string "It kind of just gives up after a while.$"

ZeraoraHintPostCatchMessage::
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!$"

AnnihilapeHintNoMessage1::
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 2257 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Defeating her won't do much good,\n"
	.string "and catching her?\l"
	.string "Impossible.$"

AnnihilapeHintMessagePostScript::
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Defeating Annihilape won't do much\n"
	.string "good, and catching her?\l"
	.string "Impossible.$"

FourTabletsHintMessage1::
# 2272 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 2278 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\p"
	.string "You've found all four!$"

FourTabletsHintMessage3::
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did something just open?$"

FourTabletsHintMessage4::
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Enjoy your Choice Scarf I guess...$"

LostGlassesNPCmainMessage::
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen my glasses?\n"
	.string "I can't see without them!$"

LostGlassesNPCGlassesFoundMessage::
# 2298 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found them!\p"
	.string "I guess I no longer need this\n"
	.string "seeing-eye leopard...\p"
	.string "...$"

LiepardObtainMessage::
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LostGlassesNPCendMessage::
# 2309 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See you around!$"

MartNPC_AskToShop::
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, welcome to my shop.\p"
	.string "Don't worry, each item can be sold back\n"
	.string "for same price.$"

MartNPC_SayGoodbye::
# 2321 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2327 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterComeAgain::
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MoveDeleterMoveDeleted::
# 2337 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s {STR_VAR_2} was removed!$"

MoveDeleterOnlyOneMove::
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That Pokémon has only one move left.$"

PoochMovesRestoredMessage::
# 2345 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Poochyena's moves were restored!$"

LiepardMovesRestoredMessage::
# 2349 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Liepard's moves were restored!$"

DunsparceMovesRestoredMessage::
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce's moves were restored!$"

SmeargleMovesRestoredMessage::
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Smeargle's moves were restored!$"

NoMovesRestoredMessage::
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

WhiteHerbRecoveredMessage::
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your White Herb was restored.$"

CustapBerryRecoveredMessage::
# 2377 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Custap Berry was restored.$"

MarangaBerryRecoveredMessage::
# 2381 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Maranga Berry was restored.$"

AskFerroDunsparceTrade::
# 2387 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\n"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2396 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright. Some other time maybe.$"

FerroTradePostTrade::
# 2404 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges. Do you want to\n"
	.string "trade it for my Pokémon egg?$"

EggReceivedMessage::
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2419 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD - allow to retrade Florges$"

AskDunsparceMoneyTrade::
# 2433 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I collect rare Pokémon as a hobby!\p"
	.string "Your Dunsparce looks quite valuable,\n"
	.string "would you sell it to me for ¥5.000?$"

MoneyReceivedMessage::
# 2439 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥5.000!$"

DunsparceTradeAccepted::
# 2443 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Dunsparce.$"

DunsparceTradeDeclined::
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2451 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My collection grows bigger and bigger!$"

AskPoochSmeargleTrade::
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to trade dogs?$"

SmeargleReceivedMessage::
# 2461 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

PoochTradeAccepted::
# 2465 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Poochyena.$"

PoochTradeDeclined::
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

PoochTradePostTrade::
# 2473 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks a lot.$"

HealBeforeTradeMessage::
# 2477 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "First let me heal your Pokémon.$"

HealedBeforeTradeMessage::
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, let's trade!$"

DoubleBattle_NotEnoughMons::
# 2486 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2493 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring!\p"
	.string "That's what mom used to say.$"

Trainer1_Outro::
# 2498 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2502 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2513 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2517 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2523 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 2530 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2534 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2540 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2549 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer4_Intro::
# 2555 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2563 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2569 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My birds are amazing!\n"
	.string "They always find their way back.$"

Trainer5_Outro::
# 2576 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer5_PostBattle::
# 2580 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer6_Intro::
# 2586 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "We're starting to get bored...\n"
	.string "Show us a trick!$"

Trainer6_Outro::
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2595 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7_Intro::
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many options.\n"
	.string "Where do I start?\l"
	.string "Making a decision feels really hard.$"

Trainer7_Outro::
# 2607 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7_PostBattle::
# 2611 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
