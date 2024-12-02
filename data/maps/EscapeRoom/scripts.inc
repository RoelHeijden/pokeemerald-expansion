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
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0, EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 22 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0, EscapeRoom_MapScripts_CheckAfterBattlePecha
# 23 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 0, EscapeRoom_MapScripts_CheckAfterBattleHeal
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 28 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 29 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_OnResumeScripts::
# 34 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
# 37 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpawnSitrusTree
# 40 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 41 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
# 42 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 0
# 45 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_1
	return

EscapeRoom_MapScript_OnResumeScripts_1:
# 46 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
# 52 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_setNPCfacing
# 55 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_checkHMStrength
	return


EscapeRoom_MapScript_checkHMStrength::
# 59 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HM_STRENGTH_STOLEN, EscapeRoom_MapScript_checkHMStrength_1
	return

EscapeRoom_MapScript_checkHMStrength_1:
# 60 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HM04_STEAL_SUCCES
	return


EscapeRoom_MapScripts_CheckSpawnSitrusTree::
# 66 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY, 4
# 67 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckSpawnSitrusTree_1
	return

EscapeRoom_MapScripts_CheckSpawnSitrusTree_1:
# 68 "data/maps/EscapeRoom/scripts.pory"
	setberrytree BERRY_TREE_ESCAPE_ROOM_SITRUS, ITEM_TO_BERRY ( ITEM_SITRUS_BERRY ), BERRY_STAGE_BERRIES
	return


EscapeRoom_MapScripts_CheckAfterBattleHeal::
# 74 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 75 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattleHeal_2
EscapeRoom_MapScripts_CheckAfterBattleHeal_1:
# 79 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_2:
# 77 "data/maps/EscapeRoom/scripts.pory"
	setparty1hp
	goto EscapeRoom_MapScripts_CheckAfterBattleHeal_1


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 83 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 84 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindGreatBallAferUse
# 85 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 89 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 90 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindPechaBerryAferUse
# 91 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 96 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_FindPechaBerryAferUse_2
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_1:
# 97 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 100 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 101 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_FindPechaBerryAferUse_5
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_2:
# 96 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindPechaBerryAferUse_1
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_5:
# 104 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 105 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_FindPechaBerryAferUse_7
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_7:
# 108 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 109 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 110 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 111 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 112 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 113 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 114 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 121 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 122 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 123 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 128 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_FindGreatBallAferUse_2
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_1:
# 129 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 130 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 131 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 132 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 133 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 134 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_2:
# 128 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindGreatBallAferUse_1
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 139 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 140 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 144 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 145 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 149 "data/maps/EscapeRoom/scripts.pory"
	turnobject 5, DIR_EAST
# 150 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_SOUTH
# 151 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 152 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 153 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 154 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_NORTH
# 155 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_EAST
# 156 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 157 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_NORTH
# 158 "data/maps/EscapeRoom/scripts.pory"
	turnobject 22, DIR_EAST
	return


EscapeRoom_MapScript_KeepDouble1Moved::
# 162 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 163 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 164 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 169 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 170 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 171 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 172 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 176 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_SUNNY_DAY, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 30, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 197 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 198 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 202 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 203 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 204 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 205 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 206 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 207 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 208 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 209 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 210 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 211 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 212 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 213 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 214 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 215 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 216 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 217 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 219 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 224 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 225 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 230 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 231 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 235 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 238 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 236 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 245 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 246 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 247 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 248 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 252 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 253 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 254 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 255 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 256 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 257 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 258 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 259 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 260 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 264 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 265 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 266 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 267 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 268 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 272 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 273 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 274 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 275 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 276 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 280 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 281 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 282 "data/maps/EscapeRoom/scripts.pory"
	removeobject 7
# 283 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 284 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 288 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 289 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 290 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 298 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 299 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 308 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 309 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 310 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 313 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 314 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 319 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 320 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 321 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 326 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 335 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 343 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 396 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 291 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 292 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 293 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 300 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 301 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 302 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 311 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 310 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 315 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 314 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 322 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 327 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 328 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 329 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 330 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 326 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 336 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 337 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 338 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 335 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 344 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 347 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_33
# 392 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 393 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 350 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 351 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_36
# 356 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_37
# 362 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 363 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 364 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 367 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 368 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 369 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
EscapeRoom_EventScript_GoodSmeargle_NPC_41:
# 373 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 374 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_45
EscapeRoom_EventScript_GoodSmeargle_NPC_44:
# 380 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_48
EscapeRoom_EventScript_GoodSmeargle_NPC_47:
# 385 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 386 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 387 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_36:
# 352 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 353 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 357 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 358 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 370 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 371 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_41

EscapeRoom_EventScript_GoodSmeargle_NPC_45:
# 375 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 376 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_44

EscapeRoom_EventScript_GoodSmeargle_NPC_48:
# 381 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 382 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_47


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 402 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 433 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 403 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 404 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 426 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 427 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 428 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 429 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 430 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 438 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 444 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 445 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 450 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 456 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 457 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 462 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 463 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro
# 469 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 474 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 475 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_YESNO
# 476 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_2
# 541 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 542 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 544 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 478 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 479 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 482 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 485 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 488 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 491 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_FINAL_GAMBIT
# 492 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_6
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 499 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_MIMIC
# 500 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_9
EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 507 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM04_STEAL_SUCCES, EscapeRoom_EventScript_TeleportBackOverLedge_12
# 521 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HM04
# 522 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_18
EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 535 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_HM_STRENGTH_STOLEN
# 538 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 25
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 493 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_FINAL_GAMBIT
# 494 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 495 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 501 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_MIMIC
# 502 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 503 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_8

EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 509 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 510 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM04
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_16
EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 513 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 514 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM04
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_21
EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 517 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HM04
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 511 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_15

EscapeRoom_EventScript_TeleportBackOverLedge_18:
# 523 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 524 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM04
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_24
EscapeRoom_EventScript_TeleportBackOverLedge_23:
# 527 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 528 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM04
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_21:
# 515 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_20

EscapeRoom_EventScript_TeleportBackOverLedge_24:
# 525 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_23

EscapeRoom_EventScript_TeleportBackOverLedge_26:
# 529 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11


EscapeRoom_EventScript_DoubleBattle1::
# 548 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 556 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 557 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 562 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 563 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 564 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 565 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 566 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 567 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 568 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 569 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 570 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 571 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 572 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 576 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 577 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 577 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 577 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 578 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 582 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 586 "data/maps/EscapeRoom/scripts.pory"
	lock
# 587 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 588 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 589 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 590 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 591 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 592 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 596 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 597 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 601 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 602 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 603 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 606 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 612 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 685 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 687 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 688 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 720 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 721 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 724 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 607 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 608 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 609 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 614 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 615 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 619 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 621 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 622 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 680 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 681 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 612 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 606 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 616 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 615 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 689 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 690 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 693 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 714 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 715 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 625 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 626 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 627 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 675 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 676 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 694 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 695 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 696 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 697 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 700 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 706 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 707 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 708 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 709 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 630 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 631 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 632 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 635 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 651 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 652 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 655 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 656 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 657 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 658 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 661 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 670 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 671 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 701 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 702 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 636 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 637 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 640 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 643 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 662 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 663 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 666 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 638 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 641 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 644 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 645 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 646 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 729 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 733 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 737 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_misdirectionHintNPC::
# 741 "data/maps/EscapeRoom/scripts.pory"
	msgbox misdirectionHintMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 745 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 749 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 753 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 757 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_catchSalazzleNPC::
# 761 "data/maps/EscapeRoom/scripts.pory"
	msgbox SalazzleCatchingHint, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 766 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 767 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 774 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 775 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 777 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 778 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 779 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 768 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 769 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 770 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 771 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 783 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 784 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 785 "data/maps/EscapeRoom/scripts.pory"
	removeobject 19
# 786 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 787 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindToxicOrb::
# 791 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 792 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TOXIC_ORB
# 793 "data/maps/EscapeRoom/scripts.pory"
	removeobject 21
# 794 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
# 795 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


StartMessage::
# 801 "data/maps/EscapeRoom/scripts.pory"
	.string "Welcome to the Escape Room!\p"
	.string "You'll have to navigate tough battles\n"
	.string "and find creative solutions in order to\l"
	.string "progress through the map.\p"
	.string "READ CAREFULLY:\p"
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
# 835 "data/maps/EscapeRoom/scripts.pory"
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
# 859 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 864 "data/maps/EscapeRoom/scripts.pory"
	.string "Thanks for playing.\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 869 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 874 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "Do you have the skill to find a way?$"

Double1Puzzle_Outro::
# 882 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 887 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 891 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 895 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 899 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\n"
	.string "Have you got one?\l"
	.string "Come to me when you do!$"

SmeargleMessageBad::
# 905 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "I assume you never intended to get\n"
	.string "softlocked like this, so do you want me\l"
	.string "to release this SMEARGLE and give back\l"
	.string "your GREAT BALL?$"

TakeFlameOrbMessage::
# 914 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it)$"

SmeargleReleaseHealSecondMonMessage::
# 919 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 923 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 927 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 931 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 935 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 944 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 953 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 957 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 961 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 965 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 970 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 980 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 987 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single1Puzzle_PostBattle::
# 991 "data/maps/EscapeRoom/scripts.pory"
	.string "...\p"
	.string "Good luck.$"

Single2Puzzle_Intro::
# 996 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 1002 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 1006 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 1010 "data/maps/EscapeRoom/scripts.pory"
	.string "It looks like you're stuck!\p"
	.string "A real thief would've known when to run.$"

Single3Puzzle_Outro::
# 1015 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattle::
# 1019 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I can throw you back down, but I'll have\n"
	.string "to set a few things back to the way they\l"
	.string "were before.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 1028 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1034 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1038 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1044 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1048 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1055 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I only teach moves a GARDEVOIR\n"
	.string "could learn.$"

MoveTutorTradeDeclined::
# 1059 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1063 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1068 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1074 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1080 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1085 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1089 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1094 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

SilentNPCMessage::
# 1098 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "One quiet turn could set you free.$"

NuggetNPCmessage::
# 1103 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET?\p"
	.string "I guess not...\n"
	.string "I'll leaf it be.$"

misdirectionHintMessage::
# 1110 "data/maps/EscapeRoom/scripts.pory"
	.string "I love a good misdirection!$"

SalazzleCatchingHint::
# 1119 "data/maps/EscapeRoom/scripts.pory"
	.string "Every time I've tried to catch SALAZZLE\n"
	.string "it managed to escape.\p"
	.string "That's some ability, huh?$"

someoneLockedUsUpNPCmessage::
# 1126 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1132 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 1137 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

StopWinningNPCmessage::
# 1143 "data/maps/EscapeRoom/scripts.pory"
	.string "Aren't you tired of winning?\n"
	.string "Try giving up instead!$"

NewGreatBallMessage::
# 1148 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1152 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1157 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1162 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"
