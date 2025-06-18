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
# 58 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 66 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_5
EscapeRoom_MapScript_OnTransitionScripts_4:
# 77 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FISHERMAN_MOVED, EscapeRoom_MapScript_OnTransitionScripts_7
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 67 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_5:
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	goto EscapeRoom_MapScript_OnTransitionScripts_4

EscapeRoom_MapScript_OnTransitionScripts_7:
# 78 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 19, 13, 22
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_UP
	return


EscapeRoom_MapScript_OnResumeScripts::
# 85 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScript_OnResumeScripts_3
EscapeRoom_MapScript_OnResumeScripts_1:
# 97 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_8
EscapeRoom_MapScript_OnResumeScripts_6:
# 102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScript_OnResumeScripts_12
# 102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScript_OnResumeScripts_12
# 102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScript_OnResumeScripts_12
EscapeRoom_MapScript_OnResumeScripts_11:
# 107 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_STARDUST_STOLEN, EscapeRoom_MapScript_OnResumeScripts_19
EscapeRoom_MapScript_OnResumeScripts_18:
# 112 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_22
EscapeRoom_MapScript_OnResumeScripts_21:
# 117 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_25
EscapeRoom_MapScript_OnResumeScripts_24:
# 125 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScript_OnResumeScripts_28
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 87 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 92 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_FERRO_CUSTAP
# 93 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_3:
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_7:
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_8:
# 97 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_7
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_12:
# 103 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_11

EscapeRoom_MapScript_OnResumeScripts_19:
# 108 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckStardustStolen
	goto EscapeRoom_MapScript_OnResumeScripts_18

EscapeRoom_MapScript_OnResumeScripts_22:
# 113 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_21

EscapeRoom_MapScript_OnResumeScripts_25:
# 118 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_32
EscapeRoom_MapScript_OnResumeScripts_31:
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	goto EscapeRoom_MapScript_OnResumeScripts_24

EscapeRoom_MapScript_OnResumeScripts_27:
# 126 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 127 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_35
EscapeRoom_MapScript_OnResumeScripts_34:
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScript_OnResumeScripts_28:
# 125 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_27
	return

EscapeRoom_MapScript_OnResumeScripts_32:
# 120 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScript_OnResumeScripts_31

EscapeRoom_MapScript_OnResumeScripts_35:
# 128 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScript_OnResumeScripts_34


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 145 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 148 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_WHITE_HERB, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 162 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_CUSTAP, EscapeRoom_MapScripts_RetrievedItemMessage_5
EscapeRoom_MapScripts_RetrievedItemMessage_4:
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RECOVERED_MARANGA, EscapeRoom_MapScripts_RetrievedItemMessage_8
EscapeRoom_MapScripts_RetrievedItemMessage_7:
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 176 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 156 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox WhiteHerbRecoveredMessage, MSGBOX_AUTOCLOSE
# 157 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 158 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1

EscapeRoom_MapScripts_RetrievedItemMessage_5:
# 163 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CustapBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 164 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 165 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
	goto EscapeRoom_MapScripts_RetrievedItemMessage_4

EscapeRoom_MapScripts_RetrievedItemMessage_8:
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MarangaBerryRecoveredMessage, MSGBOX_AUTOCLOSE
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
	goto EscapeRoom_MapScripts_RetrievedItemMessage_7


EscapeRoom_MapScripts_RemoveHeldItem::
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_FERRO_CUSTAP, EscapeRoom_MapScripts_RemoveHeldItem_2
EscapeRoom_MapScripts_RemoveHeldItem_1:
# 186 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 0
	return

EscapeRoom_MapScripts_RemoveHeldItem_2:
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_FERRO_CUSTAP
# 183 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveFerroCustap
	goto EscapeRoom_MapScripts_RemoveHeldItem_1


EscapeRoom_MapScripts_RemoveFerroCustap::
# 190 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveFerroCustap_1
	return

EscapeRoom_MapScripts_RemoveFerroCustap_1:
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 194 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveFerroCustap_3
	return

EscapeRoom_MapScripts_RemoveFerroCustap_3:
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_CheckStardustStolen::
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_STARDUST
# 202 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_2
EscapeRoom_MapScripts_CheckStardustStolen_1:
# 205 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_5
EscapeRoom_MapScripts_CheckStardustStolen_4:
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_8
EscapeRoom_MapScripts_CheckStardustStolen_7:
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_STARDUST
	goto_if_eq EscapeRoom_MapScripts_CheckStardustStolen_10
	return

EscapeRoom_MapScripts_CheckStardustStolen_2:
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_1

EscapeRoom_MapScripts_CheckStardustStolen_5:
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_4

EscapeRoom_MapScripts_CheckStardustStolen_8:
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	goto EscapeRoom_MapScripts_CheckStardustStolen_7

EscapeRoom_MapScripts_CheckStardustStolen_10:
# 215 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_STOLEN
	return


EscapeRoom_MapScripts_AskResetPredamage::
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
EscapeRoom_MapScripts_AskResetPredamage_1:
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 227 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 223 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 224 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScript_GameStartScripts::
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 235 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 238 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 239 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 240 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 241 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 242 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 249 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 250 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 255 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_WHITE_HERB, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 1, defIv = 3, speedIv = 31, spAtkIv = 0, spDefIv = 30
# 278 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SLEEP_TALK, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 328 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 329 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 334 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 337 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 338 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 344 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 345 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
	return


EscapeRoom_MapScripts_GetItems::
# 356 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 357 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_EXP_CANDY_S
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 361 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_MainInfoSign::
# 373 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 374 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 375 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 377 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 378 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndSignMessage, MSGBOX_AUTOCLOSE
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AnnihilapeStatue::
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 407 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 408 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 412 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 414 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 425 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 432 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 426 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 427 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 439 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 444 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 440 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage, MSGBOX_DEFAULT
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LostGlassesNPC::
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCmainMessage, MSGBOX_AUTOCLOSE
# 465 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_WISE_GLASSES
# 466 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_2
EscapeRoom_EventScript_LostGlassesNPC_1:
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LostGlassesNPC_2:
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 470 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LostGlassesNPC_5
# 479 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 482 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 484 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCGlassesFoundMessage, MSGBOX_AUTOCLOSE
# 485 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_WISE_GLASSES
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LostGlassesNPCendMessage, MSGBOX_AUTOCLOSE
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, EscapeRoom_Movement_LostGlassesNPC
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LostGlassesNPC_1

EscapeRoom_EventScript_LostGlassesNPC_5:
# 472 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_ObtainLiepard::
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, abilityNum = 2, nature = 17, gender = 0, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_ECHOED_VOICE, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 556 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	return


# 559 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_LostGlassesNPC:
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
# 560 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_left
	step_end

EscapeRoom_EventScript_RelocateNurseNPC::
# 564 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 567 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 569 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 575 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 578 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 579 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 581 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 582 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 586 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 592 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 593 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 596 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 597 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 600 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 601 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 602 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 603 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_up
# 604 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 607 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 608 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 609 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 612 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 620 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 621 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 622 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 624 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 630 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 635 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 637 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 643 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 644 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

	.align 2
# 648 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 649 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RARE_CANDY
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM27
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_DEFAULT
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_MoveDeleterNPC_Text_0, EscapeRoom_MoveDeleterNPC_Text_1
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_2
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_3
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
EscapeRoom_MoveDeleterNPC_1:
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 671 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_1

EscapeRoom_MoveDeleterNPC_3:
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
	goto EscapeRoom_MoveDeleterNPC_1


EscapeRoom_ChooseMoveToDelete::
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 686 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EscapeRoom_ChooseMoveToDelete_2
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	special GetNumMovesSelectedMonHas
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_ChooseMoveToDelete_5
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
	goto_if_eq EscapeRoom_ChooseMoveToDelete_8
# 711 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_MOVE_DELETER_CHOSEN_SLOT
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	special MoveDeleterForgetMove
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SHOP
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterMoveDeleted, MSGBOX_AUTOCLOSE
	end

EscapeRoom_ChooseMoveToDelete_2:
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_5:
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOnlyOneMove, MSGBOX_AUTOCLOSE
# 699 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_8:
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_RestoreMoveset::
# 726 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 729 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 730 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_3
EscapeRoom_RestoreMoveset_1:
# 788 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_6:
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_16
EscapeRoom_RestoreMoveset_14:
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_RestoreMoveset_27
EscapeRoom_RestoreMoveset_25:
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_43
	return

EscapeRoom_RestoreMoveset_2:
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	monhas0pp SPECIES_POOCHYENA
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_12
EscapeRoom_RestoreMoveset_11:
# 739 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ICE_FANG_DELETED, EscapeRoom_RestoreMoveset_23
EscapeRoom_RestoreMoveset_22:
# 749 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SLEEP_TALK_DELETED, EscapeRoom_RestoreMoveset_37
EscapeRoom_RestoreMoveset_36:
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ENDEAVOR_DELETED, EscapeRoom_RestoreMoveset_59
EscapeRoom_RestoreMoveset_58:
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TAUNT_DELETED, EscapeRoom_RestoreMoveset_83
EscapeRoom_RestoreMoveset_82:
# 779 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochMovesRestoredMessage, MSGBOX_DEFAULT
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_POOCH_MOVE_DELETED
# 783 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_3:
# 730 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_MOVE_DELETED, EscapeRoom_RestoreMoveset_2
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_7:
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	monhas0pp SPECIES_LIEPARD
# 794 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_20
EscapeRoom_RestoreMoveset_19:
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ASSIST_DELETED, EscapeRoom_RestoreMoveset_34
EscapeRoom_RestoreMoveset_33:
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_DELETED, EscapeRoom_RestoreMoveset_52
EscapeRoom_RestoreMoveset_51:
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ECHOED_VOICE_DELETED, EscapeRoom_RestoreMoveset_76
EscapeRoom_RestoreMoveset_75:
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRICK_DELETED, EscapeRoom_RestoreMoveset_104
EscapeRoom_RestoreMoveset_103:
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardMovesRestoredMessage, MSGBOX_DEFAULT
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 843 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_6

EscapeRoom_RestoreMoveset_8:
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_MOVE_DELETED, EscapeRoom_RestoreMoveset_7
	goto EscapeRoom_RestoreMoveset_6

EscapeRoom_RestoreMoveset_12:
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_11

EscapeRoom_RestoreMoveset_15:
# 852 "data/maps/EscapeRoom_Main/scripts.pory"
	monhas0pp SPECIES_DUNSPARCE
# 853 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_31
EscapeRoom_RestoreMoveset_30:
# 857 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRUMP_CARD_DELETED, EscapeRoom_RestoreMoveset_49
EscapeRoom_RestoreMoveset_48:
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HEX_DELETED, EscapeRoom_RestoreMoveset_69
EscapeRoom_RestoreMoveset_68:
# 877 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_COUNTER_DELETED, EscapeRoom_RestoreMoveset_97
EscapeRoom_RestoreMoveset_96:
# 887 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIR_SLASH_DELETED, EscapeRoom_RestoreMoveset_122
EscapeRoom_RestoreMoveset_121:
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceMovesRestoredMessage, MSGBOX_DEFAULT
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 902 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_14

EscapeRoom_RestoreMoveset_16:
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_MOVE_DELETED, EscapeRoom_RestoreMoveset_15
	goto EscapeRoom_RestoreMoveset_14

EscapeRoom_RestoreMoveset_20:
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_19

EscapeRoom_RestoreMoveset_23:
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_ICE_FANG
# 742 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ICE_FANG_DELETED
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_39
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ICE_FANG_DELETED_0_PP, EscapeRoom_RestoreMoveset_39
	goto EscapeRoom_RestoreMoveset_22

EscapeRoom_RestoreMoveset_26:
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	monhas0pp SPECIES_SMEARGLE
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_46
EscapeRoom_RestoreMoveset_45:
# 916 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SURF_DELETED, EscapeRoom_RestoreMoveset_66
EscapeRoom_RestoreMoveset_65:
# 926 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SWITCHEROO_DELETED, EscapeRoom_RestoreMoveset_90
EscapeRoom_RestoreMoveset_89:
# 936 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UPROAR_DELETED, EscapeRoom_RestoreMoveset_115
EscapeRoom_RestoreMoveset_114:
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CONVERSION_2_DELETED, EscapeRoom_RestoreMoveset_133
EscapeRoom_RestoreMoveset_132:
# 956 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SmeargleMovesRestoredMessage, MSGBOX_DEFAULT
# 958 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SMEARGLE_MOVE_DELETED
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 961 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_25

EscapeRoom_RestoreMoveset_27:
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SMEARGLE_MOVE_DELETED, EscapeRoom_RestoreMoveset_26
	goto EscapeRoom_RestoreMoveset_25

EscapeRoom_RestoreMoveset_31:
# 854 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_30

EscapeRoom_RestoreMoveset_34:
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ASSIST
# 801 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ASSIST_DELETED
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_54
# 802 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ASSIST_DELETED_0_PP, EscapeRoom_RestoreMoveset_54
	goto EscapeRoom_RestoreMoveset_33

EscapeRoom_RestoreMoveset_37:
# 751 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_SLEEP_TALK
# 752 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SLEEP_TALK_DELETED
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_61
# 753 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SLEEP_TALK_DELETED_0_PP, EscapeRoom_RestoreMoveset_61
	goto EscapeRoom_RestoreMoveset_36

EscapeRoom_RestoreMoveset_39:
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_POOCHYENA, MOVE_ICE_FANG
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ICE_FANG_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_22

EscapeRoom_RestoreMoveset_43:
# 967 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return

EscapeRoom_RestoreMoveset_46:
# 913 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MON_HAS_0_PP_WHEN_RESTORING
	goto EscapeRoom_RestoreMoveset_45

EscapeRoom_RestoreMoveset_49:
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_TRUMP_CARD
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRUMP_CARD_DELETED
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_71
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRUMP_CARD_DELETED_0_PP, EscapeRoom_RestoreMoveset_71
	goto EscapeRoom_RestoreMoveset_48

EscapeRoom_RestoreMoveset_52:
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ROCK_SMASH
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ROCK_SMASH_DELETED
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_78
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ROCK_SMASH_DELETED_0_PP, EscapeRoom_RestoreMoveset_78
	goto EscapeRoom_RestoreMoveset_51

EscapeRoom_RestoreMoveset_54:
# 803 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_LIEPARD, MOVE_ASSIST
# 804 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ASSIST_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_33

EscapeRoom_RestoreMoveset_59:
# 761 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_ENDEAVOR
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ENDEAVOR_DELETED
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_85
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ENDEAVOR_DELETED_0_PP, EscapeRoom_RestoreMoveset_85
	goto EscapeRoom_RestoreMoveset_58

EscapeRoom_RestoreMoveset_61:
# 754 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_POOCHYENA, MOVE_SLEEP_TALK
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SLEEP_TALK_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_36

EscapeRoom_RestoreMoveset_66:
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_SURF
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SURF_DELETED
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_92
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SURF_DELETED_0_PP, EscapeRoom_RestoreMoveset_92
	goto EscapeRoom_RestoreMoveset_65

EscapeRoom_RestoreMoveset_69:
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_HEX
# 870 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HEX_DELETED
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_99
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HEX_DELETED_0_PP, EscapeRoom_RestoreMoveset_99
	goto EscapeRoom_RestoreMoveset_68

EscapeRoom_RestoreMoveset_71:
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_DUNSPARCE, MOVE_TRUMP_CARD
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRUMP_CARD_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_48

EscapeRoom_RestoreMoveset_76:
# 820 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_ECHOED_VOICE
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ECHOED_VOICE_DELETED
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_106
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ECHOED_VOICE_DELETED_0_PP, EscapeRoom_RestoreMoveset_106
	goto EscapeRoom_RestoreMoveset_75

EscapeRoom_RestoreMoveset_78:
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_LIEPARD, MOVE_ROCK_SMASH
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ROCK_SMASH_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_51

EscapeRoom_RestoreMoveset_83:
# 771 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_POOCHYENA, MOVE_TAUNT
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TAUNT_DELETED
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_110
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TAUNT_DELETED_0_PP, EscapeRoom_RestoreMoveset_110
	goto EscapeRoom_RestoreMoveset_82

EscapeRoom_RestoreMoveset_85:
# 764 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_POOCHYENA, MOVE_ENDEAVOR
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ENDEAVOR_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_58

EscapeRoom_RestoreMoveset_90:
# 928 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_SWITCHEROO
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SWITCHEROO_DELETED
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_117
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SWITCHEROO_DELETED_0_PP, EscapeRoom_RestoreMoveset_117
	goto EscapeRoom_RestoreMoveset_89

EscapeRoom_RestoreMoveset_92:
# 921 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_SMEARGLE, MOVE_SURF
# 922 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SURF_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_65

EscapeRoom_RestoreMoveset_97:
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_COUNTER
# 880 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_COUNTER_DELETED
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_124
# 881 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_COUNTER_DELETED_0_PP, EscapeRoom_RestoreMoveset_124
	goto EscapeRoom_RestoreMoveset_96

EscapeRoom_RestoreMoveset_99:
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_DUNSPARCE, MOVE_HEX
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HEX_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_68

EscapeRoom_RestoreMoveset_104:
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_LIEPARD, MOVE_TRICK
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRICK_DELETED
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_128
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRICK_DELETED_0_PP, EscapeRoom_RestoreMoveset_128
	goto EscapeRoom_RestoreMoveset_103

EscapeRoom_RestoreMoveset_106:
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_LIEPARD, MOVE_ECHOED_VOICE
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ECHOED_VOICE_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_75

EscapeRoom_RestoreMoveset_110:
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_POOCHYENA, MOVE_TAUNT
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TAUNT_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_82

EscapeRoom_RestoreMoveset_115:
# 938 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_UPROAR
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UPROAR_DELETED
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_135
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_UPROAR_DELETED_0_PP, EscapeRoom_RestoreMoveset_135
	goto EscapeRoom_RestoreMoveset_114

EscapeRoom_RestoreMoveset_117:
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_SMEARGLE, MOVE_SWITCHEROO
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SWITCHEROO_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_89

EscapeRoom_RestoreMoveset_122:
# 889 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_DUNSPARCE, MOVE_AIR_SLASH
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIR_SLASH_DELETED
# 891 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_139
# 891 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIR_SLASH_DELETED_0_PP, EscapeRoom_RestoreMoveset_139
	goto EscapeRoom_RestoreMoveset_121

EscapeRoom_RestoreMoveset_124:
# 882 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_DUNSPARCE, MOVE_COUNTER
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_COUNTER_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_96

EscapeRoom_RestoreMoveset_128:
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_LIEPARD, MOVE_TRICK
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRICK_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_103

EscapeRoom_RestoreMoveset_133:
# 948 "data/maps/EscapeRoom_Main/scripts.pory"
	addmonmove SPECIES_SMEARGLE, MOVE_CONVERSION_2
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CONVERSION_2_DELETED
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MON_HAS_0_PP_WHEN_RESTORING, EscapeRoom_RestoreMoveset_143
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_CONVERSION_2_DELETED_0_PP, EscapeRoom_RestoreMoveset_143
	goto EscapeRoom_RestoreMoveset_132

EscapeRoom_RestoreMoveset_135:
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_SMEARGLE, MOVE_UPROAR
# 942 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_UPROAR_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_114

EscapeRoom_RestoreMoveset_139:
# 892 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_DUNSPARCE, MOVE_AIR_SLASH
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIR_SLASH_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_121

EscapeRoom_RestoreMoveset_143:
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	setmonmove0pp SPECIES_SMEARGLE, MOVE_CONVERSION_2
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CONVERSION_2_DELETED_0_PP
	goto EscapeRoom_RestoreMoveset_132


EscapeRoom_MoveRestoredSound::
# 973 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 976 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 977 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_UltraBallNPC::
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 999 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_DEFAULT
EscapeRoom_UltraBallNPC_1:
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 989 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 994 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 995 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_AnnihilapeHintNPC::
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1012 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 1031 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 1032 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 1015 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 1016 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1017 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1018 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 1046 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 1051 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1052 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage, MSGBOX_DEFAULT
EscapeRoom_ZeraoraHintNPC_1:
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_DEFAULT
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1064 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_TabletsHintNPC_2
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_3
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_4
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_CHOICE_SPECS_OBTAINED, EscapeRoom_TabletsHintNPC_5
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage5, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 1065 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_4:
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_5:
# 1074 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage4, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_EventScript_Trainer1::
# 1086 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1087 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 1096 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 1097 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 1106 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 1113 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 1118 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1119 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 1132 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 1138 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 1139 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 1144 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 1151 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer6::
# 1157 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7::
# 1170 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7, Trainer7_Intro, Trainer7_Outro, event_script = EscapeRoom_EventScript_Trainer7PostBattle
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7_PostBattle, MSGBOX_AUTOCLOSE
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 1191 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1193 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 1194 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1208 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1209 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 1212 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 1223 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 1232 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1234 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer5PostBattle::
# 1252 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 1253 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 1263 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_Trainer6PostBattle::
# 1267 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer7PostBattle::
# 1272 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7_DEFEATED
# 1273 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 1280 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 1282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 1297 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1290 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 1371 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 1322 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 1332 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 50, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_AIR_SLASH, move3 = MOVE_HEX, move4 = MOVE_COUNTER, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 10, spDefIv = 31
# 1355 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1359 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1362 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1327 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 1414 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 1381 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 1400 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	givepoochegg
# 1402 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1406 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1407 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 1409 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 1432 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 1449 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradePoochForSmeargle::
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1466 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_POOCH_TRADE_ACCEPTED, EscapeRoom_EventScript_TradePoochForSmeargle_2
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskPoochSmeargleTrade, MSGBOX_YESNO
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_8
# 1566 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeDeclined, MSGBOX_AUTOCLOSE
# 1567 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradePoochForSmeargle_1:
# 1570 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradePoochForSmeargle_2:
# 1469 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ESCAPEROOM_SMACH_ROCK2, EscapeRoom_EventScript_TradePoochForSmeargle_5
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FISHERMAN_MOVED, EscapeRoom_EventScript_TradePoochForSmeargle_11
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HappyDaysMessage, MSGBOX_NPC
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, FishermanLooksUp
# 1496 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_5:
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradePostTrade, MSGBOX_NPC
# 1471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_8:
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_POOCHYENA
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_15
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TradePoochForSmeargle_21
EscapeRoom_EventScript_TradePoochForSmeargle_20:
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_POOCHYENA
# 1532 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1533 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 5, abilityNum = 0, nature = 18, gender = 0, move1 = MOVE_UPROAR, move2 = MOVE_SURF, move3 = MOVE_CONVERSION_2, move4 = MOVE_RAGE_POWDER, hpEv = 0, spAtkEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POOCH_TRADE_ACCEPTED
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1559 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1560 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1561 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PoochTradeAccepted, MSGBOX_AUTOCLOSE
# 1562 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_11:
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ICanGoFishingMessage, MSGBOX_NPC
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1478 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FISHERMAN_MOVED
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_18
EscapeRoom_EventScript_TradePoochForSmeargle_17:
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 19, FishermanMovesDown
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 19
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 19
	goto EscapeRoom_EventScript_TradePoochForSmeargle_1

EscapeRoom_EventScript_TradePoochForSmeargle_15:
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1510 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradePoochForSmeargle_18:
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMovesAwayForFisherman
# 1483 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	goto EscapeRoom_EventScript_TradePoochForSmeargle_17

EscapeRoom_EventScript_TradePoochForSmeargle_21:
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_EventScript_TradePoochForSmeargle_23
	goto EscapeRoom_EventScript_TradePoochForSmeargle_20

EscapeRoom_EventScript_TradePoochForSmeargle_23:
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HealBeforeTradeMessage, MSGBOX_DEFAULT
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 1523 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 1524 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HealedBeforeTradeMessage, MSGBOX_AUTOCLOSE
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradePoochForSmeargle_20


# 1573 "data/maps/EscapeRoom_Main/scripts.pory"
PlayerMovesAwayForFisherman:
# 1574 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
FishermanMovesDown:
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_down
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_down
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_down
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_down
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_down
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_right
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_right
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 1588 "data/maps/EscapeRoom_Main/scripts.pory"
FishermanLooksUp:
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_EventScript_FindStardust::
# 1596 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_CUSTAP_BERRY
# 1599 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1600 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_STARDUST_OBTAINED
# 1601 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindLostGlasses::
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_WISE_GLASSES
# 1607 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1608 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LOST_GLASSES_OBTAINED
# 1609 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1656 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1620 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1621 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1622 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1637 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1643 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1644 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1648 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1680 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1699 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1664 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1665 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1666 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1687 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1692 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1697 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1693 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1723 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1742 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1708 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1709 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1724 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1730 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1731 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1735 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1736 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1771 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1790 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1750 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1751 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1752 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1772 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 1788 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 1784 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1800 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1797 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1796 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1798 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1815 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1816 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1817 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 1835 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1859 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 1831 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 1863 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1868 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1883 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1892 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1878 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1897 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1913 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1914 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1915 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1917 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1921 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1922 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1948 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1951 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1933 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1955 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1956 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1963 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1972 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1974 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1976 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1967 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1968 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1980 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1981 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1985 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1988 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1997 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1999 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 2005 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2006 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2026 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2018 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 2030 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2031 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 2039 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 2058 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2059 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 2062 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2050 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2052 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2053 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2054 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 2066 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2067 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2071 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2094 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2096 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2080 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 2100 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2101 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 2117 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2119 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2113 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 2125 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2126 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2130 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 2133 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 2142 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2146 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 2137 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2138 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2158 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2160 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 2163 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2164 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2165 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2172 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 2192 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 2193 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 2196 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 2186 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 2187 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 2181 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2204 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 2210 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 2214 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_HAZE
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2219 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 2220 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 2227 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 2228 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_MoveDeleterNPC_Text_0:
# 666 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete a move$"

EscapeRoom_MoveDeleterNPC_Text_1:
# 667 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Restore deleted moves$"

SomethingsGoneWrongMessage::
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EndSignMessage::
# 2253 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The end.\p"
	.string "...\p"
	.string "For now.$"

MysteriousWallSign::
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Choice paralysis?$"

MoveDeleterSignMessage::
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "Please note that a restored move will\n"
	.string "get 0 pp if:\l"
	.string "a) it had 0 pp when deleted.\l"
	.string "b) all current moves have 0 pp.$"

AnnihilapeStatueMessage::
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 2289 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A spirit stirs.\nYou sense a presence.$"

GravestoneClick3Message::
# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 2331 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 2336 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 2348 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 2352 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 2356 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 2367 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 2379 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 2386 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 2392 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 2398 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 2404 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 2411 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 2417 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 2429 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 2436 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 2442 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 2448 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 2466 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 2476 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2489 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 2496 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2504 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 2515 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks for playing!$"

ZeraoraHintMessage::
# 2521 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people trying to catch it\n"
	.string "but no one's been able to get its HP\l"
	.string "below 50%.\p"
	.string "It kind of just gives up after a while.$"

ZeraoraHintPostCatchMessage::
# 2529 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!$"

AnnihilapeHintNoMessage1::
# 2535 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 2539 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.\p"
	.string "She'll always be back.$"

FourTabletsHintMessage1::
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm so done with this search...\p"
	.string "Maybe it's time to just kick back and\n"
	.string "stare at the waves for a while.$"

FourTabletsHintMessage3::
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to look through the menus.$"

FourTabletsHintMessage4::
# 2574 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you feel that earthquake?$"

FourTabletsHintMessage5::
# 2578 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Enjoy your Choice Scarf I guess.$"

LostGlassesNPCmainMessage::
# 2585 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen my glasses?\n"
	.string "I can't see without them!$"

LostGlassesNPCGlassesFoundMessage::
# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You've found them!\p"
	.string "I guess I no longer need this\n"
	.string "seeing-eye leopard...\p"
	.string "...$"

LiepardObtainMessage::
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LostGlassesNPCendMessage::
# 2601 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See you around!$"

MartNPC_AskToShop::
# 2607 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold back\n"
	.string "for the same price.$"

MartNPC_SayGoodbye::
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2619 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterComeAgain::
# 2625 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MoveDeleterMoveDeleted::
# 2629 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s {STR_VAR_2} was removed!$"

MoveDeleterOnlyOneMove::
# 2633 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That Pokémon has only one move left.$"

PoochMovesRestoredMessage::
# 2637 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Poochyena's moves were restored!$"

LiepardMovesRestoredMessage::
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Liepard's moves were restored!$"

DunsparceMovesRestoredMessage::
# 2645 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce's moves were restored!$"

SmeargleMovesRestoredMessage::
# 2649 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Smeargle's moves were restored!$"

NoMovesRestoredMessage::
# 2653 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 2660 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

WhiteHerbRecoveredMessage::
# 2664 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your White Herb was restored.$"

CustapBerryRecoveredMessage::
# 2668 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Custap Berry was restored.$"

MarangaBerryRecoveredMessage::
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your Maranga Berry was restored.$"

AskResetPredamageMessage::
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

PreDamagedStateRestoredMessage::
# 2683 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 2689 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2702 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 2706 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2712 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2722 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2726 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2730 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I sense regret?$"

AskDunsparceMoneyTrade::
# 2736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 2742 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 2756 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2760 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

AskPoochSmeargleTrade::
# 2766 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I want to go fishing.\p"
	.string "...\p"
	.string "... ...\p"
	.string "Wanna trade dogs instead?$"

SmeargleReceivedMessage::
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

PoochTradeAccepted::
# 2777 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Poochyena.$"

PoochTradeDeclined::
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

PoochTradePostTrade::
# 2785 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'd still like to go fishing...$"

HealBeforeTradeMessage::
# 2789 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "First let me heal your Pokémon.$"

HealedBeforeTradeMessage::
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, let's trade!$"

ICanGoFishingMessage::
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I CAN GO FISHING!$"

HappyDaysMessage::
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Happy days.$"

DoubleBattle_NotEnoughMons::
# 2809 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2816 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\p"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 2822 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2837 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2847 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 2854 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3FinalWords::
# 2877 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 2883 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Exhausted already?$"

Trainer4_Outro::
# 2887 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2897 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They always find their way back.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer5_Outro::
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer5_PostBattle::
# 2908 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer6_Intro::
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Even twins have their differences.\n"
	.string "In time, you'll understand!$"

Trainer6_Outro::
# 2919 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2923 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7_Intro::
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "So many options.\n"
	.string "Where do I start?\p"
	.string "Making decisions was never this hard.$"

Trainer7_Outro::
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7_PostBattle::
# 2940 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
