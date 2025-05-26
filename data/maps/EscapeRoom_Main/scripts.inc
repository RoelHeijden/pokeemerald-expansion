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
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_18
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

EscapeRoom_MapScript_OnResumeScripts_18:
# 94 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 103 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 105 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 116 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScripts_RetrievedItemMessage_5
EscapeRoom_MapScripts_RetrievedItemMessage_4:
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScripts_RetrievedItemMessage_8
EscapeRoom_MapScripts_RetrievedItemMessage_7:
# 136 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 137 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox WhiteHerbRecoveredMessage, MSGBOX_AUTOCLOSE
# 118 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1

EscapeRoom_MapScripts_RetrievedItemMessage_5:
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CustapBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 125 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 126 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
	goto EscapeRoom_MapScripts_RetrievedItemMessage_4

EscapeRoom_MapScripts_RetrievedItemMessage_8:
# 131 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MarangaBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 132 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 133 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
	goto EscapeRoom_MapScripts_RetrievedItemMessage_7


EscapeRoom_MapScripts_RemoveHeldItem::
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_FERRO_CUSTAP, EscapeRoom_MapScripts_RemoveHeldItem_2
EscapeRoom_MapScripts_RemoveHeldItem_1:
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 0
	return

EscapeRoom_MapScripts_RemoveHeldItem_2:
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_FERRO_CUSTAP
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveFerroCustap
	goto EscapeRoom_MapScripts_RemoveHeldItem_1


EscapeRoom_MapScripts_RemoveFerroCustap::
# 151 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 153 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveFerroCustap_1
	return

EscapeRoom_MapScripts_RemoveFerroCustap_1:
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveFerroCustap_3
	return

EscapeRoom_MapScripts_RemoveFerroCustap_3:
# 156 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScript_GameStartScripts::
# 164 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 165 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 166 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 167 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 168 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 173 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 178 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 185 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_WHITE_HERB, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 1, defIv = 3, speedIv = 31, spAtkIv = 0, spDefIv = 30
# 208 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SLEEP_TALK, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 258 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 259 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 263 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 264 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 265 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 266 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 267 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 268 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 269 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 274 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 275 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 277 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
	return


EscapeRoom_MapScripts_GetItems::
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_EXP_CANDY_S
# 287 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_HM01
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 292 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_MainInfoSign::
# 303 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 304 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 305 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 310 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 307 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_EndSign::
# 314 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 315 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndSignMessage, MSGBOX_AUTOCLOSE
# 316 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 321 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 322 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 324 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 330 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 331 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 345 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 360 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 368 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 370 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 374 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 375 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 379 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LostGlassesNPC::
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCmainMessage, MSGBOX_AUTOCLOSE
# 389 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_WISE_GLASSES
# 390 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_2
EscapeRoom_EventScript_LostGlassesNPC_1:
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LostGlassesNPC_2:
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_5
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 404 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCGlassesFoundMessage, MSGBOX_AUTOCLOSE
# 409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 411 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 412 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_WISE_GLASSES
# 413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCendMessage, MSGBOX_AUTOCLOSE
# 414 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, EscapeRoom_Movement_LostGlassesNPC
# 418 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 419 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 420 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 426 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LostGlassesNPC_1

EscapeRoom_EventScript_LostGlassesNPC_5:
# 396 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 397 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_ObtainLiepard::
# 433 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 434 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 50, abilityNum = 2, nature = 16, gender = 0, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_ECHOED_VOICE, atkEv = 148, spAtkEv = 252, speedEv = 108, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 458 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	return


# 461 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_LostGlassesNPC:
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_EventScript_RelocateNurseNPC::
# 466 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 472 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 475 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 476 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 477 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 483 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 484 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 485 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 498 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 502 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_up
# 506 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 509 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 511 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 514 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 524 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 532 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 533 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 543 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 545 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

	.align 2
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM12
# 550 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_YESNO
# 565 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_UltraBallNPC::
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 572 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 584 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_NPC
EscapeRoom_UltraBallNPC_1:
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_AnnihilapeHintNPC::
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessagePostScript, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 628 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 599 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 615 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 620 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 600 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 603 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 604 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 607 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 631 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage, MSGBOX_NPC
EscapeRoom_ZeraoraHintNPC_1:
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_NPC
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 677 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 683 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer6::
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 727 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7::
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7, Trainer7_Intro, Trainer7_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7_PostBattle, MSGBOX_AUTOCLOSE
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 754 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 756 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 757 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 771 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 785 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 786 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 788 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_TradeZeraForHMCut::
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 803 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 804 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 826 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 807 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 820 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 888 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 892 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 835 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 50, abilityNum = 2, nature = 8, gender = 0, move1 = MOVE_TRUMP_CARD, move2 = MOVE_AIR_SLASH, move3 = MOVE_HEX, move4 = MOVE_COUNTER, hpEv = 0, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 10, spDefIv = 31
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 878 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 880 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 849 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 935 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 902 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 903 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 921 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	givepoochegg
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 925 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 928 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 916 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 943 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 953 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 947 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_NPC
# 948 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 21000
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 970 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceivedMessage
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 972 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 973 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeAccepted, MSGBOX_AUTOCLOSE
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradePoochForSmeargle::
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 988 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_TRADE_ACCEPTED, EscapeRoom_EventScript_TradePoochForSmeargle_2
# 997 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskPoochSmeargleTrade, MSGBOX_YESNO
# 998 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_5
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeDeclined, MSGBOX_AUTOCLOSE
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradePoochForSmeargle_1:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradePoochForSmeargle_2:
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradePostTrade, MSGBOX_NPC
# 993 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_5:
# 1001 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_9
# 1011 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_POOCHYENA
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 20, abilityNum = 0, nature = 12, gender = 0, move1 = MOVE_FOLLOW_ME, move2 = MOVE_UPROAR, move3 = MOVE_SURF, move4 = MOVE_CONVERSION_2, hpEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POOCH_TRADE_ACCEPTED
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1036 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1037 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeAccepted, MSGBOX_AUTOCLOSE
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_9:
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindRareCandy::
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_RARE_CANDY
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindLostGlasses::
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_WISE_GLASSES
# 1064 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1065 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LOST_GLASSES_OBTAINED
# 1066 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1076 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1084 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1087 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1085 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1088 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1109 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1105 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1136 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1120 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1122 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1128 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1143 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1148 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1158 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1173 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1184 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1194 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1214 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1218 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_19


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1260 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1264 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1273 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1297 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GraveStone1::
# 1301 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1306 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1310 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1320 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1321 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1322 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1327 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1336 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1351 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1352 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1355 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1346 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1347 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1360 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1375 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1389 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1370 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1373 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1403 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1410 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1411 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1414 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1419 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 1452 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 1453 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1464 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 1468 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1469 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1473 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1497 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1498 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1491 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1492 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1505 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 1513 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 1523 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1539 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1551 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 1563 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1564 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1568 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 1571 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 1572 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 1591 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1594 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1595 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1600 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1603 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1610 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 1612 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1651 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 1652 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_HAZE
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1654 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 1658 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1659 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


SomethingsGoneWrongMessage::
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EndSignMessage::
# 1691 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The end.\p"
	.string "...\p"
	.string "For now.$"

MysteriousWallSign::
# 1697 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There are four mysterious markings that\n"
	.string "seem to point in various directions.\p"
	.string "What a strange wall.$"

MysteriousWallBackroomSign::
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice paralysis?$"

AnnihilapeStatueMessage::
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 1719 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 1723 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A spirit stirs.\nYou sense a presence.$"

GravestoneClick3Message::
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void.$"

GravestoneAnnihilapesRoar::
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 1799 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 1818 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 1837 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 1843 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 1855 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 1862 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 1880 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hello, should I heal your Pokémon?$"

Nurse_Heal_End::
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(Thanks for playing)$"

ZeraoraHintMessage::
# 1948 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora that lives\n"
	.string "in this area?\p"
	.string "I've seen people attempt to catch it,\n"
	.string "but no one's been able to get its HP\l"
	.string "below 50%.\p"
	.string "It kind of just gives up after a while.$"

ZeraoraHintPostCatchMessage::
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!$"

AnnihilapeHintNoMessage1::
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Defeating her won't do much good,\n"
	.string "she always comes back.\p"
	.string "I also wouldn't waste any Poké Balls on\n"
	.string "her if I were you.$"

AnnihilapeHintMessagePostScript::
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Defeating Annihilape won't do much\n"
	.string "good, she always comes back.\p"
	.string "I also wouldn't waste any Poké Balls on\n"
	.string "her if I were you.$"

LostGlassesNPCmainMessage::
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen my glasses?\n"
	.string "I can't see without them!$"

LostGlassesNPCGlassesFoundMessage::
# 1994 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found them!\p"
	.string "I guess I no longer need this\n"
	.string "seeing-eye leopard...\p"
	.string "...$"

LiepardObtainMessage::
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LostGlassesNPCendMessage::
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See you around!$"

MartNPC_AskToShop::
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, welcome to my shop.\p"
	.string "Don't worry, each item can be sold back\n"
	.string "for same price.$"

MartNPC_SayGoodbye::
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete move plz?$"

NewBallMessage::
# 2029 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

WhiteHerbRecoveredMessage::
# 2033 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your White Herb was restored.$"

CustapBerryRecoveredMessage::
# 2037 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Custap Berry was restored.$"

MarangaBerryRecoveredMessage::
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Maranga Berry was restored.$"

AskFerroDunsparceTrade::
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\n"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2056 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright. Some other time maybe.$"

FerroTradePostTrade::
# 2064 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges. Do you want to\n"
	.string "trade it for my Pokémon egg?$"

EggReceivedMessage::
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD - allow to retrade Florges$"

AskDunsparceMoneyTrade::
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I collect rare Pokémon as a hobby.\p"
	.string "Your Dunsparce looks quite valuable,\n"
	.string "would you sell it to me for ¥20.000?$"

MoneyReceivedMessage::
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥20.000!$"

DunsparceTradeAccepted::
# 2103 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Dunsparce.$"

DunsparceTradeDeclined::
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My collection grows bigger and bigger!$"

AskPoochSmeargleTrade::
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to trade dogs?$"

SmeargleReceivedMessage::
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

PoochTradeAccepted::
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Poochyena.$"

PoochTradeDeclined::
# 2129 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

PoochTradePostTrade::
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks a lot.$"

DoubleBattle_NotEnoughMons::
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something something I have HM Cut.$"

Trainer1_Outro::
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Doesn't the beach look beautiful?\n"
	.string "I love nature.$"

Trainer2_Outro::
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer4_Intro::
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Only the exhausted could defeat me.$"

Trainer4_Outro::
# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2219 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Still being haunted by ghosts from\n"
	.string "your past?\p"
	.string "Yeah me too.$"

Trainer5_Outro::
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer5_PostBattle::
# 2229 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer6_Intro::
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "We share a FOCUS SASH!$"

Trainer6_Outro::
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7_Intro::
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Too many options?\n"
	.string "Be careful or you might freeze up.\p"
	.string "There's a word for that, isn't there?\n"
	.string "Ah well, I guess it's not important.$"

Trainer7_Outro::
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7_PostBattle::
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
