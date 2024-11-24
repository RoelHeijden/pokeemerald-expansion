EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 7 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 10 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_setNPCfacing
	.2byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScripts_PlayStartMessage
# 12 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1, EscapeRoom_MapScripts_GetFirstPokemon
# 13 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2, EscapeRoom_MapScripts_GetBadges
# 14 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3, EscapeRoom_MapScripts_SetRespawn
# 15 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4, EscapeRoom_MapScripts_GetItems
# 16 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5, EscapeRoom_MapScripts_TurnOfBagUse
# 17 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6, EscapeRoom_MapScripts_FixCrackedGround
# 18 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
# 19 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0, EscapeRoom_MapScripts_CheckAfterBattle
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 24 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 25 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_OnResumeScripts::
# 29 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
# 30 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpawnSitrusTree
# 31 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
	return


EscapeRoom_MapScripts_CheckSpawnSitrusTree::
# 36 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY, 4
# 37 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckSpawnSitrusTree_1
	return

EscapeRoom_MapScripts_CheckSpawnSitrusTree_1:
# 38 "data/maps/EscapeRoom/scripts.pory"
	setberrytree BERRY_TREE_ESCAPE_ROOM_SITRUS, ITEM_TO_BERRY ( ITEM_SITRUS_BERRY ), BERRY_STAGE_BERRIES
	return


EscapeRoom_MapScripts_CheckAfterBattle::
# 43 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 44 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindGreatBallAferUse
# 45 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 49 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 50 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 51 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 56 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_FindGreatBallAferUse_2
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_1:
# 57 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 58 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_GREAT_BALL
# 59 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 60 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 61 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 62 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_2:
# 56 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindGreatBallAferUse_1
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 67 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 68 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 72 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 73 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 77 "data/maps/EscapeRoom/scripts.pory"
	turnobject 7, DIR_SOUTH
# 78 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_EAST
# 79 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_NORTH
# 80 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_WEST
# 81 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 82 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_EAST
# 83 "data/maps/EscapeRoom/scripts.pory"
	turnobject 18, DIR_NORTH
# 84 "data/maps/EscapeRoom/scripts.pory"
	turnobject 19, DIR_WEST
# 85 "data/maps/EscapeRoom/scripts.pory"
	turnobject 20, DIR_SOUTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 90 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 91 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 92 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 97 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 98 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 99 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 100 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 104 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 124 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 125 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 129 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 130 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 131 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 132 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 133 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 134 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 135 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 136 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 137 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 138 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 139 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 140 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 141 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 142 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 143 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 144 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 146 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 151 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 152 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 156 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 157 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 13
# 158 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 162 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 165 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 163 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 172 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 173 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 174 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 175 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 179 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 180 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 181 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 182 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 183 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 184 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 185 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 186 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 187 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 191 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 194 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 215 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 216 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 192 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 220 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 223 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 234 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 235 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 221 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_FindRareCandy::
# 239 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 240 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 241 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 242 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 243 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 247 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 248 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 249 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 250 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 251 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 255 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 256 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 257 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 258 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 259 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 263 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 264 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 265 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 266 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 267 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 271 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 272 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 273 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 279 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 280 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 311 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 312 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 319 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 320 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 328 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 329 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
# 352 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 353 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 355 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 274 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 275 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 276 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 281 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 282 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 288 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 289 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 295 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 296 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_39
EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 302 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 303 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_43
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 330 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 331 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_EventScript_GoodSmeargle_NPC_22
# 347 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 348 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 283 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 284 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 285 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 282 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 313 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 314 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 315 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 316 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 312 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 332 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 333 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_34
# 338 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 339 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 340 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 341 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 342 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 343 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 290 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 291 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 292 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 289 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 321 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 322 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 323 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 324 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 320 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_30
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_34:
# 334 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 335 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_38:
# 297 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 298 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 299 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_39:
# 296 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_38
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_37

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 304 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 305 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 306 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_43:
# 303 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 360 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 391 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 361 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_GOTHITA
# 362 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 384 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 385 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 386 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 387 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 388 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 396 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 402 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 403 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 408 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 414 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 415 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 420 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 421 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 427 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 433 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 437 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 439 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 484 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 485 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 434 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 440 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 441 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 442 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 445 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 448 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 451 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_8
	return

EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 453 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 454 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_11
EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 457 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 458 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_14
EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 461 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TM18
# 464 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_RAIN_DANCE
# 465 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_17
EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 480 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TM_18_STOLEN
	return

EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 455 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_10

EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 459 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_13

EscapeRoom_EventScript_TeleportBackOverLedge_17:
# 466 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_19
# 472 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_20
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_19:
# 467 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 468 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 469 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 470 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 473 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 0, MOVE_THIEF
# 474 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 1, MOVE_HELPING_HAND
# 475 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_NONE
# 476 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16


EscapeRoom_EventScript_DoubleBattle1::
# 490 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 498 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 499 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 504 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 505 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 506 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 507 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 508 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 509 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 510 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 511 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 512 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 513 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 514 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 518 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 519 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 519 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 519 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 520 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 525 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 530 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 531 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 532 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 533 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 534 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 535 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_AUTOCLOSE
# 536 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 537 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


	.align 2
# 541 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 542 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 546 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 547 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 548 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 551 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 557 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 610 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 612 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 613 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_14
# 644 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 645 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 648 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 552 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 553 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 554 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 558 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
# 559 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 560 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_11
# 605 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 606 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 557 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 551 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_11:
# 563 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 564 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 565 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 600 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 601 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_14:
# 614 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 615 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 618 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 638 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 639 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_17:
# 568 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 569 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 570 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 575 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 576 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 579 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 580 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 581 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 582 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 585 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 595 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 596 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 619 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 620 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 621 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 624 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_26
# 630 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 631 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 632 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 633 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 586 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 587 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 590 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 625 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 626 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1


EscapeRoom_EventScript_CreepySilentNPC::
# 653 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 654 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 655 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_AUTOCLOSE
# 656 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 657 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_PerishExplain_NPC::
# 662 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 663 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 664 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_AUTOCLOSE
# 665 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 666 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 671 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 672 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 673 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_AUTOCLOSE
# 674 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 675 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_itemHintNPC::
# 680 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 681 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 682 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_AUTOCLOSE
# 683 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 684 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_NuggetNPC::
# 689 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 690 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 691 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_AUTOCLOSE
# 692 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 693 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 698 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 699 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 700 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_AUTOCLOSE
# 701 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 702 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_icePuzzleHintNPC::
# 707 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 708 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 709 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_AUTOCLOSE
# 710 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 711 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_getOutOfHereNPC::
# 716 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 717 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 718 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_AUTOCLOSE
# 719 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 720 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EndEscapeRoomSign::
# 725 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 726 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 733 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 734 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 736 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 737 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 738 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 727 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 728 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 729 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 730 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


StartMessage::
# 744 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 748 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 752 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 757 "data/maps/EscapeRoom/scripts.pory"
	.string "Sharing is caring. Didn't you know?\n"
	.string "It's not as painful as it seems.\p"
	.string "Everyone wins!$"

Double1Puzzle_Outro::
# 763 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 768 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 772 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 776 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 780 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 785 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "Do you want to release this SMEARGLE\n"
	.string "and get your ball back?$"

SmeargleReleaseHealSecondMonMessage::
# 792 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 796 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 800 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 804 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, good luck.$"

SmeargleMessagePerfect::
# 808 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 816 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did your GOTHITA go?$"

TradeAcceptedMessage::
# 824 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

GardevoirObtainedMessage::
# 828 "data/maps/EscapeRoom/scripts.pory"
	.string "Player received a Gardevoir!$"

TradeDeclinedMessage::
# 832 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 836 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 841 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 850 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 857 "data/maps/EscapeRoom/scripts.pory"
	.string "You should be able to defeat that\n"
	.string "elderly couple and get out of here!$"

Single1Puzzle_PostBattle::
# 861 "data/maps/EscapeRoom/scripts.pory"
	.string "It might be worth it to revisit your\n"
	.string "items and tutor moves.$"

Single2Puzzle_Intro::
# 866 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "learning battle strategy!$"

Single2Puzzle_Outro::
# 872 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 876 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 880 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 884 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 888 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money and item, I'll\n"
	.string "throw you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 895 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money, I'll throw you\n"
	.string "back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 902 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool cool! Come back again whenever you\n"
	.string "want to battle.$"

NoTeleportPleaseMessage::
# 907 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 915 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 921 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 925 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want me to teach your GARDEVOIR\n"
	.string "a new move?$"

MoveTutorNoSuitablePokemonMessage::
# 929 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I can only teach moves to very a\n"
	.string "specific POKéMON.$"

MoveTutorTradeDeclined::
# 933 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 937 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.\p"
	.string "I will replace the move free of charge!$"

MoveTutorReplaceMove::
# 943 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorBringReplaceMonMessage::
# 949 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

BikeShopHelloMessage::
# 958 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 963 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 967 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 972 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 976 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 980 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGETS?$"

itemHintNPCmessage::
# 984 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "trainer battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 990 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 996 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 1001 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 1007 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

NewGreatBallMessage::
# 1011 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1015 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"
