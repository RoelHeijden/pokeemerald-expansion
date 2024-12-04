EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 8 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 12 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 9 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScripts_PlayStartMessage
# 14 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1, EscapeRoom_MapScripts_GetFirstPokemon
# 15 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2, EscapeRoom_MapScripts_GetBadges
# 16 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3, EscapeRoom_MapScripts_SetRespawn
# 17 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4, EscapeRoom_MapScripts_GetItems
# 18 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5, EscapeRoom_MapScripts_TurnOfBagUse
# 19 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6, EscapeRoom_MapScripts_FixCrackedGround
# 20 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
# 21 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindGreatBallAferUse
# 22 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1, EscapeRoom_MapScripts_FindPechaBerryAferUse
# 23 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1, EscapeRoom_MapScripts_HealTo1hp
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 29 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 30 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_OnResumeScripts::
# 35 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
# 38 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 41 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 44 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattlePecha
# 47 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleHeal
# 50 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpawnSitrusTree
# 53 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_1
	return

EscapeRoom_MapScript_OnResumeScripts_1:
# 54 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
# 60 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_setNPCfacing
# 63 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_checkHMRockSmash
# 66 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	return


EscapeRoom_MapScript_checkHMRockSmash::
# 70 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HM_ROCK_SMASH_STOLEN, EscapeRoom_MapScript_checkHMRockSmash_1
	return

EscapeRoom_MapScript_checkHMRockSmash_1:
# 71 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HM06_STEAL_SUCCES
	return


EscapeRoom_MapScripts_CheckSpawnSitrusTree::
# 77 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY, 4
# 78 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckSpawnSitrusTree_1
	return

EscapeRoom_MapScripts_CheckSpawnSitrusTree_1:
# 79 "data/maps/EscapeRoom/scripts.pory"
	setberrytree BERRY_TREE_ESCAPE_ROOM_SITRUS, ITEM_TO_BERRY ( ITEM_SITRUS_BERRY ), BERRY_STAGE_BERRIES
	return


EscapeRoom_MapScripts_CheckAfterBattleHeal::
# 85 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 86 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattleHeal_1
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_1:
# 87 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 92 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 93 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 94 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 99 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1:
# 101 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2:
# 99 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1
	return


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 107 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_CheckAfterBattlePecha_2
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_1:
# 109 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 110 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattlePecha_5
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_2:
# 107 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattlePecha_1
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_5:
# 112 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 113 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_CheckAfterBattlePecha_7
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_7:
# 115 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 122 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 123 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 124 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 125 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 126 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 127 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
# 128 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 129 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 130 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 134 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 135 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 136 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 137 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 138 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 139 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 140 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_HealTo1hp::
# 144 "data/maps/EscapeRoom/scripts.pory"
	setparty1hp
# 145 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 0
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 149 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 150 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 154 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 155 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 159 "data/maps/EscapeRoom/scripts.pory"
	turnobject 5, DIR_EAST
# 160 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_SOUTH
# 161 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 162 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 163 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 164 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_NORTH
# 165 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_EAST
# 166 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 167 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_NORTH
# 168 "data/maps/EscapeRoom/scripts.pory"
	turnobject 20, DIR_EAST
	return


EscapeRoom_MapScript_KeepDouble1Moved::
# 172 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 173 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 174 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 179 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 180 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 181 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 182 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 186 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_SUNNY_DAY, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 30, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 207 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 208 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 212 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 213 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 214 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 215 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 216 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 217 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 218 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 219 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 220 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 221 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 222 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 223 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 224 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 225 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 226 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 227 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 229 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 234 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 235 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 239 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HM04
# 240 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 241 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 245 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 248 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 246 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 255 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 256 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 257 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 258 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 262 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 263 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 264 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 265 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 266 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 267 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 268 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 269 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 270 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 274 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 275 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 276 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 277 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 278 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 282 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 283 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 284 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 285 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 286 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 290 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 291 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 292 "data/maps/EscapeRoom/scripts.pory"
	removeobject 7
# 293 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 294 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 298 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 299 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 300 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 308 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 309 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 318 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 319 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 320 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 323 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 324 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 329 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 330 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 331 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 336 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 345 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 353 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 406 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 301 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 302 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 303 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 310 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 311 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 312 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 321 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 320 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 325 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 324 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 332 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 337 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 338 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 339 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 340 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 336 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 346 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 347 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 348 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 345 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 354 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 357 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_33
# 402 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 403 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 360 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 361 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_36
# 366 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_37
# 372 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 373 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 374 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 377 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 378 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 379 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
EscapeRoom_EventScript_GoodSmeargle_NPC_41:
# 383 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 384 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_45
EscapeRoom_EventScript_GoodSmeargle_NPC_44:
# 390 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_48
EscapeRoom_EventScript_GoodSmeargle_NPC_47:
# 395 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 396 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 397 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_36:
# 362 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 363 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 367 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 368 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 380 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 381 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_41

EscapeRoom_EventScript_GoodSmeargle_NPC_45:
# 385 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 386 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_44

EscapeRoom_EventScript_GoodSmeargle_NPC_48:
# 391 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 392 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_47


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 412 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 443 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 413 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 414 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 436 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 437 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 438 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 439 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 440 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 448 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 454 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 455 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 460 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 466 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 467 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 472 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 473 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro
# 479 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 484 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 485 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_YESNO
# 486 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_2
# 551 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 552 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 554 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 488 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 489 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 492 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 495 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 498 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 501 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_FINAL_GAMBIT
# 502 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_6
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 509 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_MIMIC
# 510 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_9
EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 517 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM06_STEAL_SUCCES, EscapeRoom_EventScript_TeleportBackOverLedge_12
# 531 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HM06
# 532 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_18
EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 545 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_HM_ROCK_SMASH_STOLEN
# 548 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 25
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 503 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_FINAL_GAMBIT
# 504 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 505 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 511 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_MIMIC
# 512 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 513 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_8

EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 519 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 520 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_16
EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 523 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 524 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_21
EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 527 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HM06
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 521 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_15

EscapeRoom_EventScript_TeleportBackOverLedge_18:
# 533 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 534 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_24
EscapeRoom_EventScript_TeleportBackOverLedge_23:
# 537 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 538 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_21:
# 525 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_20

EscapeRoom_EventScript_TeleportBackOverLedge_24:
# 535 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_23

EscapeRoom_EventScript_TeleportBackOverLedge_26:
# 539 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11


EscapeRoom_EventScript_DoubleBattle1::
# 558 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 566 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 567 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 572 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 573 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 574 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 575 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 576 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 577 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 578 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 579 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 580 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 581 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 582 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 586 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 587 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 587 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 587 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 588 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 592 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 596 "data/maps/EscapeRoom/scripts.pory"
	lock
# 597 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 598 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 599 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 600 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 601 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 602 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 606 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 607 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 611 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 612 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 613 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 616 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 622 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 695 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 697 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 698 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 730 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 731 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 734 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 617 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 618 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 619 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 624 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 625 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 629 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 631 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 632 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 690 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 691 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 622 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 616 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 626 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 625 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 699 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 700 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 703 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 724 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 725 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 635 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 636 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 637 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 685 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 686 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 704 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 705 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 706 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 707 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 710 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 716 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 717 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 718 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 719 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 640 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 641 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 642 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 645 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 661 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 662 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 665 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 666 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 667 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 668 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 671 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 680 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 681 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 711 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 712 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 646 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 647 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 650 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 653 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 672 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 673 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 676 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 648 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 651 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 654 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 655 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 656 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 739 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 743 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 747 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_misdirectionHintNPC::
# 751 "data/maps/EscapeRoom/scripts.pory"
	msgbox misdirectionHintMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 755 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 759 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 763 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 767 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_catchSalazzleNPC::
# 771 "data/maps/EscapeRoom/scripts.pory"
	msgbox SalazzleCatchingHint, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 775 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 776 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 783 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 784 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 786 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 787 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 788 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 777 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 778 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 779 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 780 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 792 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 793 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 794 "data/maps/EscapeRoom/scripts.pory"
	removeobject 19
# 795 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 796 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindToxicOrb::
# 800 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 801 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TOXIC_ORB
# 802 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 803 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
# 804 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


StartMessage::
# 810 "data/maps/EscapeRoom/scripts.pory"
	.string "Welcome to the Escape Room!\p"
	.string "You'll have to navigate tough battles\n"
	.string "and find creative solutions in order to\l"
	.string "progress through the map.\p"
	.string "READ CAREFULLY\p"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "3) There is no need for grinding of any\n"
	.string "kind.\p"
	.string "4) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "5) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "6) It is possible to softlock yourself\n"
	.string "during play, so using save states is\l"
	.string "highly recommended.\p"
	.string "Good luck!$"

SignMessage1::
# 844 "data/maps/EscapeRoom/scripts.pory"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "3) There is no need for grinding of any\n"
	.string "kind.\p"
	.string "4) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "5) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "6) It is possible to softlock yourself\n"
	.string "during play, so using save states is\l"
	.string "highly recommended.$"

EscapeRoomEndCongratz::
# 868 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 873 "data/maps/EscapeRoom/scripts.pory"
	.string "Thanks for playing.\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 878 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 883 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "Do you have the skill to find a way?$"

Double1Puzzle_Outro::
# 891 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 896 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 900 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 904 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 908 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\n"
	.string "Have you got one?\l"
	.string "Come to me when you do!$"

SmeargleMessageBad::
# 914 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "To avoid getting softlocked, should I\n"
	.string "release this SMEARGLE and give back\l"
	.string "your GREAT BALL?$"

TakeFlameOrbMessage::
# 922 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it anywhere)$"

SmeargleReleaseHealSecondMonMessage::
# 927 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 931 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 935 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 939 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 943 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 952 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 961 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 965 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 969 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 973 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 978 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 988 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 995 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single1Puzzle_PostBattle::
# 999 "data/maps/EscapeRoom/scripts.pory"
	.string "...\p"
	.string "Good luck.$"

Single2Puzzle_Intro::
# 1004 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 1010 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 1014 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 1018 "data/maps/EscapeRoom/scripts.pory"
	.string "It looks like you're stuck!\p"
	.string "A real thief would've known when to run.$"

Single3Puzzle_Outro::
# 1023 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattle::
# 1027 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I can throw you back down, but I'll have\n"
	.string "to set a few things back to the way\l"
	.string "they were before.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 1036 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1042 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1046 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1052 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1056 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1063 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I only teach moves a GARDEVOIR\n"
	.string "could learn.$"

MoveTutorTradeDeclined::
# 1067 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1071 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1076 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1082 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1088 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1093 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1097 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1102 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

SilentNPCMessage::
# 1106 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "one quiet turn could set you free.$"

NuggetNPCmessage::
# 1111 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET?\p"
	.string "I guess not...\n"
	.string "I'll leaf it be.$"

misdirectionHintMessage::
# 1117 "data/maps/EscapeRoom/scripts.pory"
	.string "I love a good misdirection!$"

SalazzleCatchingHint::
# 1121 "data/maps/EscapeRoom/scripts.pory"
	.string "Everytime I've tried to catch SALAZZLE\n"
	.string "it managed to escape.\p"
	.string "That's some ability, huh?$"

someoneLockedUsUpNPCmessage::
# 1128 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1134 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 1139 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

StopWinningNPCmessage::
# 1145 "data/maps/EscapeRoom/scripts.pory"
	.string "Aren't you tired of winning?\n"
	.string "Try giving up instead!$"

NewGreatBallMessage::
# 1150 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1154 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1159 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1164 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"

ResetRocksMessage::
# 1168 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want to reset the boulders?$"
