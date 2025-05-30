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


EscapeRoom_EventScript_EndSign::
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndSignMessage, MSGBOX_AUTOCLOSE
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 371 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 372 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 373 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 381 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 374 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 376 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 388 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 395 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 389 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 404 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LostGlassesNPC::
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 411 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCmainMessage, MSGBOX_AUTOCLOSE
# 414 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_WISE_GLASSES
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_2
EscapeRoom_EventScript_LostGlassesNPC_1:
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LostGlassesNPC_2:
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_5
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 431 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCGlassesFoundMessage, MSGBOX_AUTOCLOSE
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_WISE_GLASSES
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCendMessage, MSGBOX_AUTOCLOSE
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 442 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, EscapeRoom_Movement_LostGlassesNPC
# 443 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 444 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LostGlassesNPC_1

EscapeRoom_EventScript_LostGlassesNPC_5:
# 421 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_ObtainLiepard::
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 50, abilityNum = 2, nature = 17, gender = 0, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_ECHOED_VOICE, atkEv = 140, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 18, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	return


# 486 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_LostGlassesNPC:
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_EventScript_RelocateNurseNPC::
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 497 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 507 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 523 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 524 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 527 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 529 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_up
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 534 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 539 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 559 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 562 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 565 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 566 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

	.align 2
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM12
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 577 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_YESNO
# 590 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_UltraBallNPC::
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 595 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 609 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_NPC
EscapeRoom_UltraBallNPC_1:
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 604 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_AnnihilapeHintNPC::
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 622 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessagePostScript, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 627 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 628 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 629 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 656 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 657 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage, MSGBOX_NPC
EscapeRoom_ZeraoraHintNPC_1:
# 668 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 672 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_SPECS_OBTAINED, EscapeRoom_TabletsHintNPC_4
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage4, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_4:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 724 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 725 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 732 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 738 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer6::
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7::
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7, Trainer7_Intro, Trainer7_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7_PostBattle, MSGBOX_AUTOCLOSE
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 797 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 805 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 806 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 815 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 816 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 829 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_TradeZeraForHMCut::
# 843 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 865 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 849 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 852 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 875 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 877 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 885 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 895 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 50, abilityNum = 2, nature = 8, gender = 0, move1 = MOVE_TRUMP_CARD, move2 = MOVE_AIR_SLASH, move3 = MOVE_HEX, move4 = MOVE_COUNTER, hpEv = 0, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 10, spDefIv = 31
# 917 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 921 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 948 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 943 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 944 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 963 "data/maps/EscapeRoom_Main/scripts.pory"
	givepoochegg
# 964 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 955 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 993 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 988 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_NPC
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 997 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 6000
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 1011 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceivedMessage
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeAccepted, MSGBOX_AUTOCLOSE
# 1016 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 1000 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1001 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradePoochForSmeargle::
# 1028 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_TRADE_ACCEPTED, EscapeRoom_EventScript_TradePoochForSmeargle_2
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskPoochSmeargleTrade, MSGBOX_YESNO
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_5
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeDeclined, MSGBOX_AUTOCLOSE
# 1086 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradePoochForSmeargle_1:
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradePoochForSmeargle_2:
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradePostTrade, MSGBOX_NPC
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_5:
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_9
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_POOCHYENA
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 30, abilityNum = 0, nature = 15, gender = 0, move1 = MOVE_SWITCHEROO, move2 = MOVE_UPROAR, move3 = MOVE_SURF, move4 = MOVE_CONVERSION_2, hpEv = 0, spAtkEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 28
# 1074 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POOCH_TRADE_ACCEPTED
# 1076 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeAccepted, MSGBOX_AUTOCLOSE
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_9:
# 1045 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1046 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindRareCandy::
# 1096 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindLostGlasses::
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_WISE_GLASSES
# 1106 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1107 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LOST_GLASSES_OBTAINED
# 1108 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1118 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1129 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1140 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1173 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1194 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1218 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1267 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1273 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1278 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 1279 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1292 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1291 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1305 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GraveStone1::
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1369 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1381 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1400 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1415 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1433 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1434 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1449 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1465 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1467 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1473 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1483 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1478 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 1498 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1537 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 1551 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1552 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1553 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 1567 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 1568 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 1562 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 1563 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 1570 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1571 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1586 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1587 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1603 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1604 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 1610 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1611 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1615 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1623 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1647 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1687 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1691 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1692 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 1695 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1697 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1698 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_HAZE
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1702 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1710 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 1713 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


SomethingsGoneWrongMessage::
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EndSignMessage::
# 1738 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The end.\p"
	.string "...\p"
	.string "For now.$"

MysteriousWallSign::
# 1744 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice paralysis?$"

AnnihilapeStatueMessage::
# 1756 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 1770 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A spirit stirs.\nYou sense a presence.$"

GravestoneClick3Message::
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void.$"

GravestoneAnnihilapesRoar::
# 1783 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 1825 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 1834 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 1840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 1852 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello, should I heal your Pokémon?$"

Nurse_Heal_End::
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 1943 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 1958 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 1985 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Thanks for playing)$"

ZeraoraHintMessage::
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people trying to catch it\n"
	.string "but no one's been able to get its HP\l"
	.string "below 50%.\p"
	.string "It kind of just gives up after a while.$"

ZeraoraHintPostCatchMessage::
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!$"

AnnihilapeHintNoMessage1::
# 2009 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Defeating her won't do much good,\n"
	.string "she always comes back.\p"
	.string "I also wouldn't waste any Poké Balls on\n"
	.string "her if I were you.$"

AnnihilapeHintMessagePostScript::
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Defeating Annihilape won't do much\n"
	.string "good, she always comes back.\p"
	.string "I also wouldn't waste any Poké Balls on\n"
	.string "her if I were you.$"

FourTabletsHintMessage1::
# 2034 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\p"
	.string "You've found all four!$"

FourTabletsHintMessage3::
# 2045 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did something just open?$"

FourTabletsHintMessage4::
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Enjoy your Choice Scarf I guess...$"

LostGlassesNPCmainMessage::
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen my glasses?\n"
	.string "I can't see without them!$"

LostGlassesNPCGlassesFoundMessage::
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found them!\p"
	.string "I guess I no longer need this\n"
	.string "seeing-eye leopard...\p"
	.string "...$"

LiepardObtainMessage::
# 2067 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LostGlassesNPCendMessage::
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See you around!$"

MartNPC_AskToShop::
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, welcome to my shop.\p"
	.string "Don't worry, each item can be sold back\n"
	.string "for same price.$"

MartNPC_SayGoodbye::
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete move plz?$"

NewBallMessage::
# 2095 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

WhiteHerbRecoveredMessage::
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your White Herb was restored.$"

CustapBerryRecoveredMessage::
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Custap Berry was restored.$"

MarangaBerryRecoveredMessage::
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Maranga Berry was restored.$"

AskFerroDunsparceTrade::
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\n"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2122 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright. Some other time maybe.$"

FerroTradePostTrade::
# 2130 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2136 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges. Do you want to\n"
	.string "trade it for my Pokémon egg?$"

EggReceivedMessage::
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2149 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD - allow to retrade Florges$"

AskDunsparceMoneyTrade::
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I collect rare Pokémon as a hobby.\p"
	.string "Your Dunsparce looks quite valuable,\n"
	.string "would you sell it to me for 6.000?$"

MoneyReceivedMessage::
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥20.000!$"

DunsparceTradeAccepted::
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Dunsparce.$"

DunsparceTradeDeclined::
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My collection grows bigger and bigger!$"

AskPoochSmeargleTrade::
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to trade dogs?$"

SmeargleReceivedMessage::
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

PoochTradeAccepted::
# 2191 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Poochyena.$"

PoochTradeDeclined::
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

PoochTradePostTrade::
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks a lot.$"

DoubleBattle_NotEnoughMons::
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something something I've got HM Cut!$"

Trainer1_Outro::
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2220 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I hate grass.$"

Trainer2_Outro::
# 2245 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2264 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer4_Intro::
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2278 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Back for more?\n"
	.string "Thought you'd escaped your ghosts.$"

Trainer5_Outro::
# 2290 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer5_PostBattle::
# 2294 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer6_Intro::
# 2300 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You can't steal our item.\p"
	.string "Wanna borrow it?$"

Trainer6_Outro::
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2309 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7_Intro::
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Too many options?\n"
	.string "Be careful or you might freeze up.$"

Trainer7_Outro::
# 2320 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7_PostBattle::
# 2324 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
