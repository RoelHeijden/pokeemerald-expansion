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
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0, EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 20 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0, EscapeRoom_MapScripts_CheckAfterBattlePecha
# 21 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 0, EscapeRoom_MapScripts_CheckAfterBattleHeal
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 26 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 27 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_OnResumeScripts::
# 32 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
# 35 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpawnSitrusTree
# 38 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 39 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
# 40 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 0
# 43 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_1
	return

EscapeRoom_MapScript_OnResumeScripts_1:
# 44 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScripts_CheckSpawnSitrusTree::
# 50 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY, 4
# 51 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckSpawnSitrusTree_1
	return

EscapeRoom_MapScripts_CheckSpawnSitrusTree_1:
# 52 "data/maps/EscapeRoom/scripts.pory"
	setberrytree BERRY_TREE_ESCAPE_ROOM_SITRUS, ITEM_TO_BERRY ( ITEM_SITRUS_BERRY ), BERRY_STAGE_BERRIES
	return


EscapeRoom_MapScripts_CheckAfterBattleHeal::
# 58 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 59 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattleHeal_2
EscapeRoom_MapScripts_CheckAfterBattleHeal_1:
# 63 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_2:
# 61 "data/maps/EscapeRoom/scripts.pory"
	setparty1hp
	goto EscapeRoom_MapScripts_CheckAfterBattleHeal_1


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 67 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 68 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindGreatBallAferUse
# 69 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 73 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 74 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindPechaBerryAferUse
# 75 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 80 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_FindPechaBerryAferUse_2
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_1:
# 81 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 84 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 85 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_FindPechaBerryAferUse_5
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_2:
# 80 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindPechaBerryAferUse_1
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_5:
# 88 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 89 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_FindPechaBerryAferUse_7
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_7:
# 92 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 93 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 94 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 95 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 96 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 97 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 98 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 105 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 106 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 107 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 112 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_FindGreatBallAferUse_2
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_1:
# 113 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 114 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 115 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 116 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 117 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 118 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_2:
# 112 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindGreatBallAferUse_1
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 123 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 124 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 128 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 129 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 133 "data/maps/EscapeRoom/scripts.pory"
	turnobject 5, DIR_EAST
# 134 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_SOUTH
# 135 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 136 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 137 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 138 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_NORTH
# 139 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_EAST
# 140 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 141 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_NORTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 146 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 147 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 148 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 153 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 154 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 155 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 156 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 160 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_CELEBRATE, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 30, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 181 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 182 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 186 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 187 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 188 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 189 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 190 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 191 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 192 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 193 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 194 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 195 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 196 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 197 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 198 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 199 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 200 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 201 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 203 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 208 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 209 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 214 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 215 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 219 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 222 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 220 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 229 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 230 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 231 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 232 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 236 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 237 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 238 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 239 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 240 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 241 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 242 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 243 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 244 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 248 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 249 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 250 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 251 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 252 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 256 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 257 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 258 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 259 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 260 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 264 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 265 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 266 "data/maps/EscapeRoom/scripts.pory"
	removeobject 7
# 267 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 268 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 272 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 273 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 274 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 282 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 283 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 292 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 293 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 294 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 297 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 298 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 303 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 304 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 305 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 310 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 319 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 327 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 380 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 275 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 276 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 277 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 284 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 285 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 286 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 295 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 294 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 299 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 298 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 306 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 311 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 312 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 313 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 314 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 310 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 320 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 321 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 322 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 319 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 328 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 331 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_33
# 376 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 377 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 334 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 335 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_36
# 340 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_37
# 346 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 347 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 348 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 351 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 352 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 353 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
EscapeRoom_EventScript_GoodSmeargle_NPC_41:
# 357 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 358 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_45
EscapeRoom_EventScript_GoodSmeargle_NPC_44:
# 364 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_48
EscapeRoom_EventScript_GoodSmeargle_NPC_47:
# 369 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 370 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 371 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_36:
# 336 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 337 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 341 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 342 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 354 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 355 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_41

EscapeRoom_EventScript_GoodSmeargle_NPC_45:
# 359 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 360 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_44

EscapeRoom_EventScript_GoodSmeargle_NPC_48:
# 365 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 366 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_47


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 386 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 417 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 387 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 388 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 410 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 411 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 412 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 413 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 414 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 422 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro
# 428 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 429 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 434 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro
# 440 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 441 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 446 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 447 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro
# 453 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 459 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 460 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 464 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 466 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_6
# 515 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 516 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 518 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 461 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 468 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 469 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 470 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 25
# 473 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 476 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 479 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 482 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_FINAL_GAMBIT
# 483 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_10
EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 490 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_MIMIC
# 491 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_13
EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 498 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_15
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 484 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_FINAL_GAMBIT
# 485 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 486 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_9

EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 492 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_MIMIC
# 493 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 494 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_12

EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 500 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 501 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_18
EscapeRoom_EventScript_TeleportBackOverLedge_17:
# 504 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 505 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_21
EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 508 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TOXIC_ORB
# 511 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOXIC_ORB_STOLEN
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_18:
# 502 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_17

EscapeRoom_EventScript_TeleportBackOverLedge_21:
# 506 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_20


EscapeRoom_EventScript_DoubleBattle1::
# 522 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 530 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 531 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 536 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 537 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 538 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 539 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 540 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 541 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 542 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 543 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 544 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 545 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 546 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 550 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 551 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 551 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 551 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 552 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 556 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 560 "data/maps/EscapeRoom/scripts.pory"
	lock
# 561 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 562 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 563 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 564 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 565 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 566 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 570 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 571 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 575 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 576 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 577 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 580 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 586 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 659 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 661 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 662 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 694 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 695 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 698 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 581 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 582 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 583 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 588 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 589 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 593 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 595 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 596 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 654 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 655 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 586 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 580 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 590 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 589 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 663 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 664 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 667 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 688 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 689 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 599 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 600 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 601 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 649 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 650 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 668 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 669 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 670 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 671 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 674 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 680 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 681 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 682 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 683 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 604 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 605 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 606 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 609 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 625 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 626 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 629 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 630 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 631 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 632 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 635 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 644 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 645 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 675 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 676 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 610 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 611 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 614 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 617 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 636 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 637 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 640 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 612 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 615 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 618 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 619 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 620 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 703 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 707 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 711 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_HiddenPowerHintNPC::
# 715 "data/maps/EscapeRoom/scripts.pory"
	msgbox hiddenPowerHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 719 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 723 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 727 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 731 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 735 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 736 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 743 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 744 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 746 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 747 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 748 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 737 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 738 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 739 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 740 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 752 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 753 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 754 "data/maps/EscapeRoom/scripts.pory"
	removeobject 19
# 755 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 756 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


StartMessage::
# 762 "data/maps/EscapeRoom/scripts.pory"
	.string "Welcome to the Escape Room!\p"
	.string "You'll have to navigate tough battles\n"
	.string "and find creative solutions in order to\l"
	.string "progress through the map.\p"
	.string "What you need to know:\p"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG is disabled.\n"
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
# 796 "data/maps/EscapeRoom/scripts.pory"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG is disabled.\n"
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
# 820 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 825 "data/maps/EscapeRoom/scripts.pory"
	.string "Thanks for playing.\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 830 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 835 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "Do you have the skill to find a way?$"

Double1Puzzle_Outro::
# 843 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 848 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 852 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 856 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 860 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 865 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "I assume you never intended to get\n"
	.string "softlocked like this, so do you want me\l"
	.string "to release this SMEARGLE and give back\l"
	.string "your GREAT BALL?$"

TakeFlameOrbMessage::
# 874 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it)$"

SmeargleReleaseHealSecondMonMessage::
# 879 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 883 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 887 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 891 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 895 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 904 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 913 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 917 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 921 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 925 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 930 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 940 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 947 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single1Puzzle_PostBattle::
# 951 "data/maps/EscapeRoom/scripts.pory"
	.string "...\p"
	.string "Good luck.$"

Single2Puzzle_Intro::
# 956 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 962 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 966 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 970 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide!$"

Single3Puzzle_Outro::
# 974 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 978 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I'll throw you back down in return for\n"
	.string "my item and money.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 986 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "It looks like you're softlocked.\p"
	.string "I'll throw you back down in return for\n"
	.string "my money.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 994 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1000 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1004 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1010 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1014 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1021 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I can only teach moves to very a\n"
	.string "specific POKéMON.$"

MoveTutorTradeDeclined::
# 1025 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1029 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1034 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1040 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1046 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1051 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1055 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1060 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

SilentNPCMessage::
# 1064 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "One quiet turn could set you free.$"

NuggetNPCmessage::
# 1069 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET?$"

hiddenPowerHintNPCmessage::
# 1073 "data/maps/EscapeRoom/scripts.pory"
	.string "Even copied moves can hold surprises.\n"
	.string "Sometimes they just feel... different.$"

someoneLockedUsUpNPCmessage::
# 1078 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1084 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 1089 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

StopWinningNPCmessage::
# 1095 "data/maps/EscapeRoom/scripts.pory"
	.string "Aren't you tired of winning?\n"
	.string "Try losing instead!$"

NewGreatBallMessage::
# 1100 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1104 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1109 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1114 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"
