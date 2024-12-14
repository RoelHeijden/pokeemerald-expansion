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
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_1
	return

EscapeRoom_MapScript_OnResumeScripts_1:
# 51 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
# 57 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_setNPCfacing
# 60 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_checkHMRockSmash
# 63 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	return


EscapeRoom_MapScript_checkHMRockSmash::
# 67 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HM_ROCK_SMASH_STOLEN, EscapeRoom_MapScript_checkHMRockSmash_1
	return

EscapeRoom_MapScript_checkHMRockSmash_1:
# 68 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HM06_STEAL_SUCCES
	return


EscapeRoom_MapScripts_CheckAfterBattleHeal::
# 74 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 75 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattleHeal_2
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_1:
# 76 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_2:
# 75 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, EscapeRoom_MapScripts_CheckAfterBattleHeal_1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 81 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 82 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 83 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 88 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1:
# 90 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2:
# 88 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1
	return


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 96 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_CheckAfterBattlePecha_2
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_1:
# 98 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 99 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattlePecha_5
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_2:
# 96 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattlePecha_1
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_5:
# 101 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 102 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_CheckAfterBattlePecha_7
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_7:
# 104 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 111 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 112 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 113 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 114 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 115 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 116 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
# 117 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 118 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 119 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 123 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 124 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 125 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 126 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 127 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 128 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 129 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_HealTo1hp::
# 133 "data/maps/EscapeRoom/scripts.pory"
	setparty1hp
# 134 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 0
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 138 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 139 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 143 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 144 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 148 "data/maps/EscapeRoom/scripts.pory"
	turnobject 8, DIR_SOUTH
# 149 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_EAST
# 150 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 151 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_SOUTH
# 152 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 153 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 154 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_EAST
# 155 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
	return


EscapeRoom_MapScript_KeepDouble1Moved::
# 159 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 160 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 161 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 166 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 167 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 168 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 169 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 173 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, gender = 0, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_SUNNY_DAY, move4 = MOVE_NONE, hpEv = 8, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 0, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 196 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 197 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 201 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 202 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 203 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 204 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 205 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 206 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 207 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 208 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 209 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 210 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 211 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 212 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 213 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 214 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 215 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 216 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 218 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 223 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 224 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 228 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HM04
# 229 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 230 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 234 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 237 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 235 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 244 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 245 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 246 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 247 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 251 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 252 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 253 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 254 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 255 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 256 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 257 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 258 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 259 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 263 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 264 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 265 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 266 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 267 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 271 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 272 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 273 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 274 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 275 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 279 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 280 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 281 "data/maps/EscapeRoom/scripts.pory"
	removeobject 6
# 282 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 283 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 287 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 288 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 289 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 297 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 298 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 307 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 308 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 309 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 312 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 313 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 318 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 319 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 320 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 325 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 334 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 342 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 345 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 290 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 291 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 292 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 299 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 300 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 301 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 310 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 309 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 314 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 313 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 321 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 326 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 327 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 328 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 329 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 325 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 335 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 336 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 337 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 334 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 343 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 351 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 382 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 352 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 353 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 5, gender = 1, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 375 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 376 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 377 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 378 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 379 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GARDEVOIR_TRADE_SUCCESS
	return


EscapeRoom_EventScript_SingleBattle1::
# 387 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_Single1PostMatch
# 393 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 394 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 399 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_Single2PostMatch
# 405 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 406 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 411 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 412 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_Single3PostMatch
# 418 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_SingleBattle4::
# 423 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 424 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE4, Single4IntroMessage, Single4OutroMessage, event_script = EscapeRoom_EventScript_SetSingle4Rematch
	return


EscapeRoom_EventScript_Single1PostMatch::
# 433 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_ROEL_DEFEATED
# 434 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Single2PostMatch::
# 438 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DS_ABEL_DEFEATED
# 439 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Single3PostMatch::
# 443 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 444 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_Single3PostMatch_1
	return

EscapeRoom_EventScript_Single3PostMatch_1:
# 445 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_SetSingle4Rematch::
# 450 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE4
# 451 "data/maps/EscapeRoom/scripts.pory"
	msgbox single4PostMatchMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TeleportBackOverLedge::
# 455 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 456 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_YESNO
# 457 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_2
# 522 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 523 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 525 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 459 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 460 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 463 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 466 "data/maps/EscapeRoom/scripts.pory"
	removemoney 99999
# 469 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 472 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_FINAL_GAMBIT
# 473 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_6
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 480 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_MIMIC
# 481 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_9
EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 488 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM06_STEAL_SUCCES, EscapeRoom_EventScript_TeleportBackOverLedge_12
# 502 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HM06
# 503 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_18
EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 516 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_HM_ROCK_SMASH_STOLEN
# 519 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 474 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_FINAL_GAMBIT
# 475 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 476 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 482 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_MIMIC
# 483 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 484 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_8

EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 490 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 491 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_16
EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 494 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 495 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_21
EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 498 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HM06
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 492 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_15

EscapeRoom_EventScript_TeleportBackOverLedge_18:
# 504 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 505 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_24
EscapeRoom_EventScript_TeleportBackOverLedge_23:
# 508 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 509 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_21:
# 496 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_20

EscapeRoom_EventScript_TeleportBackOverLedge_24:
# 506 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_23

EscapeRoom_EventScript_TeleportBackOverLedge_26:
# 510 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11


EscapeRoom_EventScript_DoubleBattle1::
# 529 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 537 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 538 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_DoubleBattle2::
# 543 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE2, Double2IntroMessage, Double2OutroMessage, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 550 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double2PostMatchMessage, MSGBOX_AUTOCLOSE
# 551 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 557 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 558 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 559 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 560 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 561 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 562 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 563 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 564 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 565 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 566 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 567 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 571 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 572 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 572 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 572 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 573 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 577 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 581 "data/maps/EscapeRoom/scripts.pory"
	lock
# 582 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 583 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 584 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 585 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 586 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 587 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 591 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 592 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 596 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 597 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 598 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 601 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 607 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 680 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 682 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 683 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 715 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 716 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 719 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 602 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 603 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 604 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 609 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 610 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 614 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 616 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 617 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 675 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 676 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 607 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 601 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 611 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 610 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 684 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 685 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 688 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 709 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 710 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 620 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 621 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 622 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 670 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 671 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 689 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 690 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 691 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 692 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 695 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 701 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 702 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 703 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 704 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 625 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 626 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 627 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 630 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 646 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 647 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 650 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 651 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 652 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 653 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 656 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 665 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 666 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 696 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 697 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 631 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 632 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 635 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 638 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 657 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 658 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 661 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 633 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 636 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 639 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 640 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 641 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_QuietTurnNPC::
# 724 "data/maps/EscapeRoom/scripts.pory"
	msgbox QuietTurnNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 728 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 732 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_GetUsOutNPC::
# 736 "data/maps/EscapeRoom/scripts.pory"
	msgbox GetUsOutNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 740 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 744 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 748 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 752 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_catchSalazzleNPC::
# 756 "data/maps/EscapeRoom/scripts.pory"
	msgbox SalazzleCatchingHint, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 760 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 761 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 768 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 769 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 771 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 772 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 773 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 762 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 763 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 764 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 765 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 777 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 778 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 779 "data/maps/EscapeRoom/scripts.pory"
	removeobject 15
# 780 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 781 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindToxicOrb::
# 785 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 786 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TOXIC_ORB
# 787 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 788 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
# 789 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_PressStartSign::
# 793 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 794 "data/maps/EscapeRoom/scripts.pory"
	msgbox PressStartSignMessage
# 795 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 796 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_ExitCloseNPC::
# 800 "data/maps/EscapeRoom/scripts.pory"
	msgbox ExitCloseNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PainSplitHintNPC::
# 804 "data/maps/EscapeRoom/scripts.pory"
	msgbox PainSplitHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_BerryTreeHintNPC::
# 808 "data/maps/EscapeRoom/scripts.pory"
	msgbox BerryTreeHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TormentHintNPC::
# 812 "data/maps/EscapeRoom/scripts.pory"
	msgbox TormentHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_SketchHintNPC::
# 816 "data/maps/EscapeRoom/scripts.pory"
	msgbox SketchHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_Question1Sign::
# 820 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 821 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question1Message
# 822 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 823 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question2Sign::
# 827 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 828 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question2Message
# 829 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 830 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question3Sign::
# 834 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 835 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question3Message
# 836 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 837 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question4Sign::
# 841 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 842 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question4Message
# 843 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 844 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTFSign::
# 848 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 849 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTFSign_Text_0
# 850 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 851 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTFSign::
# 855 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 856 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTFSign_Text_0
# 857 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 858 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFFSign::
# 862 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 863 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFFSign_Text_0
# 864 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 865 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTFSign::
# 869 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 870 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTFSign_Text_0
# 871 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 872 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFFFSign::
# 876 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 877 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFFFSign_Text_0
# 878 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 879 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFFSign::
# 883 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 884 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFFSign_Text_0
# 885 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 886 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTTSign::
# 890 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 891 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTTSign_Text_0
# 892 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 893 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTTSign::
# 897 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 898 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTTSign_Text_0
# 899 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 900 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFTTSign::
# 904 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 905 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFTTSign_Text_0
# 906 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 907 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFTSign::
# 911 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 912 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFTSign_Text_0
# 913 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 914 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTTSign::
# 918 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 919 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTTSign_Text_0
# 920 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 921 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFTSign::
# 925 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 926 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFTSign_Text_0
# 927 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 928 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_HintsNPC::
# 932 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 936 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 937 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 941 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_POKEMON_CAUGHT, EscapeRoom_EventScript_AntiSoftlockGuy_2
EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 952 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_RARE_CANDY_USED, EscapeRoom_EventScript_AntiSoftlockGuy_5
EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 975 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 976 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_11
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1008 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 1009 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 1010 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 943 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_7
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_5:
# 953 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 956 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 957 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_15
EscapeRoom_EventScript_AntiSoftlockGuy_14:
# 961 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonlevel 31
# 962 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_20
EscapeRoom_EventScript_AntiSoftlockGuy_19:
# 966 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
# 966 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
	goto EscapeRoom_EventScript_AntiSoftlockGuy_4

EscapeRoom_EventScript_AntiSoftlockGuy_7:
# 944 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSmeargleCatch
# 945 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 977 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 980 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 981 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_17
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_11:
# 976 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_10
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_15:
# 958 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_AntiSoftlockGuy_14

EscapeRoom_EventScript_AntiSoftlockGuy_17:
# 984 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonmoves VAR_TEMP_0
# 985 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_22
# 995 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_23
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_20:
# 963 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto EscapeRoom_EventScript_AntiSoftlockGuy_19

EscapeRoom_EventScript_AntiSoftlockGuy_22:
# 988 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DS_ABEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_30
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_23:
# 998 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_ROEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_32
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_26:
# 967 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
# 968 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_30:
# 989 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch1
# 990 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_32:
# 999 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch2
# 1000 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_UndoSmeargleCatch::
# 1014 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskReleaseSmeargleMessage, MSGBOX_YESNO
# 1017 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_1
# 1072 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1073 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_1:
# 1020 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1021 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_5
# 1029 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 1030 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_8
EscapeRoom_EventScript_UndoSmeargleCatch_7:
# 1035 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 1036 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_UndoSmeargleCatch_10
# 1042 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 1043 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 1044 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 1047 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1048 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 1049 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_14
EscapeRoom_EventScript_UndoSmeargleCatch_13:
# 1053 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 1054 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_17
EscapeRoom_EventScript_UndoSmeargleCatch_16:
# 1060 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_20
EscapeRoom_EventScript_UndoSmeargleCatch_19:
# 1065 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 1066 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 1067 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_5:
# 1022 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseBringSmeargleMessage, MSGBOX_AUTOCLOSE
# 1023 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1024 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_UndoSmeargleCatch_8:
# 1031 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 1032 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_7

EscapeRoom_EventScript_UndoSmeargleCatch_10:
# 1037 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 1038 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_14:
# 1050 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1051 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_UndoSmeargleCatch_13

EscapeRoom_EventScript_UndoSmeargleCatch_17:
# 1055 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1056 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoSmeargleCatch_16

EscapeRoom_EventScript_UndoSmeargleCatch_20:
# 1061 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 1062 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_19


EscapeRoom_EventScript_UndoRareCandy::
# 1078 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoRareCandyMessage, MSGBOX_YESNO
# 1081 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_1
# 1093 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1094 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1082 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_5
# 1085 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_6
EscapeRoom_EventScript_UndoRareCandy_4:
# 1088 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_RARE_CANDY_USED
# 1089 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
	return

EscapeRoom_EventScript_UndoRareCandy_5:
# 1083 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_SMEARGLE
	goto EscapeRoom_EventScript_UndoRareCandy_4

EscapeRoom_EventScript_UndoRareCandy_6:
# 1086 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_GARDEVOIR
	goto EscapeRoom_EventScript_UndoRareCandy_4


EscapeRoom_EventScript_UndoSketch1::
# 1099 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1102 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch1_1
# 1117 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1118 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch1_1:
# 1103 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1104 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1106 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1107 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1111 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1112 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1113 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return


EscapeRoom_EventScript_UndoSketch2::
# 1123 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1126 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_1
# 1148 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1149 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch2_1:
# 1128 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1129 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1132 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_PROTECT
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_5
EscapeRoom_EventScript_UndoSketch2_4:
# 1137 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1138 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1142 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1143 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1144 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return

EscapeRoom_EventScript_UndoSketch2_5:
# 1133 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 1134 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_UndoSketch2_4


EscapeRoom_EventScript_FFTFSign_Text_0:
# 849 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTF$"

EscapeRoom_EventScript_TTTFSign_Text_0:
# 856 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTF$"

EscapeRoom_EventScript_TTFFSign_Text_0:
# 863 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFF$"

EscapeRoom_EventScript_FTTFSign_Text_0:
# 870 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTF$"

EscapeRoom_EventScript_TFFFSign_Text_0:
# 877 "data/maps/EscapeRoom/scripts.pory"
	.string "TFFF$"

EscapeRoom_EventScript_FFFFSign_Text_0:
# 884 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFF$"

EscapeRoom_EventScript_TTTTSign_Text_0:
# 891 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTT$"

EscapeRoom_EventScript_FTTTSign_Text_0:
# 898 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTT$"

EscapeRoom_EventScript_TFTTSign_Text_0:
# 905 "data/maps/EscapeRoom/scripts.pory"
	.string "TFTT$"

EscapeRoom_EventScript_TTFTSign_Text_0:
# 912 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFT$"

EscapeRoom_EventScript_FFTTSign_Text_0:
# 919 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTT$"

EscapeRoom_EventScript_FFFTSign_Text_0:
# 926 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFT$"

StartMessage::
# 1157 "data/maps/EscapeRoom/scripts.pory"
	.string "Welcome to Pokémon Cave Escape!\p"
	.string "You'll have to navigate tough battles\n"
	.string "and find creative solutions in order to\l"
	.string "progress through the map, with the\l"
	.string "ultimate goal of escaping this cave.\p"
	.string "READ CAREFULLY\p"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "3) There is no need for grinding of any\n"
	.string "kind. You won't gain EXP from battling.\p"
	.string "4) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "5) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "6) You won't get softlocked unless you\n"
	.string "toss away items, release Pokémon, or\l"
	.string "REALLY mess up the strength puzzle.\p"
	.string "7) Try to avoid using speed up.\n"
	.string "There are many clues, like NPC dialogue,\l"
	.string "that you might otherwise miss.\p"
	.string "That's all.\n"
	.string "Good luck!$"

SignMessage1::
# 1197 "data/maps/EscapeRoom/scripts.pory"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "3) There is no need for grinding of any\n"
	.string "kind. You won't gain EXP from battling.\p"
	.string "4) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "5) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "6) You won't get softlocked unless you\n"
	.string "toss away items, release Pokémon, or\l"
	.string "REALLY mess up the strength puzzle.\p"
	.string "7) Try to avoid using speed up.\n"
	.string "There are many clues, like NPC dialogue,\l"
	.string "that you might otherwise miss.$"

EscapeRoomEndCongratz::
# 1225 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 1230 "data/maps/EscapeRoom/scripts.pory"
	.string "Thank you for playing <3\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 1235 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 1240 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "There's one path that always wins."
	.string "Can you figure it out?$"

Double1Puzzle_Outro::
# 1249 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 1254 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 1258 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 1262 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 1266 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\n"
	.string "Have you got one??\p"
	.string "Come to me when you do and I might offer\n"
	.string "you my GARDEVOIR.$"

SmeargleMessageBad::
# 1273 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "You should probably have a chat with\n"
	.string "the anti-softlock guy.$"

TakeFlameOrbMessage::
# 1280 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it anywhere)$"

SmeargleReleaseHealSecondMonMessage::
# 1285 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseBringSmeargleMessage::
# 1289 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back with the SMEARGLE in\n"
	.string "your party.$"

SmeargleReleaseGetSecondMonMessage::
# 1293 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 1297 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleMessagePerfect::
# 1301 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 1310 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 1319 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 1323 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 1327 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 1331 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 1336 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 1346 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 1353 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single2Puzzle_Intro::
# 1357 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 1363 "data/maps/EscapeRoom/scripts.pory"
	.string "Shut up and take my money.$"

Single3Puzzle_Intro::
# 1367 "data/maps/EscapeRoom/scripts.pory"
	.string "It looks like you're stuck!\p"
	.string "A real thief would've known when to run.$"

Single3Puzzle_Outro::
# 1372 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattle::
# 1376 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I can throw you back down, but I'll have\n"
	.string "to set a few things back to the way\l"
	.string "they were before.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 1385 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1391 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1395 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1401 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1405 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1412 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I only teach moves a GARDEVOIR\n"
	.string "could learn.$"

MoveTutorTradeDeclined::
# 1416 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1420 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1425 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1431 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1437 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1442 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1446 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1451 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

QuietTurnNPCMessage::
# 1455 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "one quiet turn could set you free.$"

NuggetNPCmessage::
# 1460 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET???\p"
	.string "I guess not...\n"
	.string "I'll leaf it be.$"

GetUsOutNPCMessage::
# 1466 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

SalazzleCatchingHint::
# 1470 "data/maps/EscapeRoom/scripts.pory"
	.string "Every time I've tried to catch SALAZZLE\n"
	.string "it managed to escape.\p"
	.string "It's just mocking me at this point.$"

someoneLockedUsUpNPCmessage::
# 1477 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1483 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing, right?$"

icePuzzleHintNPCmessage::
# 1488 "data/maps/EscapeRoom/scripts.pory"
	.string "That ice puzzle looks tough!\n"
	.string "Don't expect to solve it right away.$"

StopWinningNPCmessage::
# 1495 "data/maps/EscapeRoom/scripts.pory"
	.string "Haha you suck. Just give up!$"

NewGreatBallMessage::
# 1499 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1503 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1508 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1513 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"

PressStartSignMessage::
# 1517 "data/maps/EscapeRoom/scripts.pory"
	.string "Press START during a double battle to\n"
	.string "view your POKéMON's exact HP.$"

Single4IntroMessage::
# 1522 "data/maps/EscapeRoom/scripts.pory"
	.string "Oops, I picked the last berries.\n"
	.string "Why don't you come and take them?$"

Single4OutroMessage::
# 1527 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you really win?$"

single4PostMatchMessage::
# 1531 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm ready for a rematch whenever you\n"
	.string "want!$"

Single2Puzzle_PostBattle::
# 1536 "data/maps/EscapeRoom/scripts.pory"
	.string "CURSOLA is a great singer, don't you\n"
	.string "agree?\p"
	.string "Maybe SMEARGLE should follow her lead.$"

Single1Puzzle_PostBattle::
# 1542 "data/maps/EscapeRoom/scripts.pory"
	.string "Remember turning your POKéMON into a\n"
	.string "ghost type?\p"
	.string "That was fun.$"

ExitCloseNPCMessage::
# 1548 "data/maps/EscapeRoom/scripts.pory"
	.string "We're so close, the exit is right there!$"

PainSplitHintNPCMessage::
# 1552 "data/maps/EscapeRoom/scripts.pory"
	.string "Time is not for sale, but generosity can\n"
	.string "earn you a moment.\p"
	.string "Sharing is caring.$"

BerryTreeHintNPCMessage::
# 1558 "data/maps/EscapeRoom/scripts.pory"
	.string "What happened to that berry tree?\p"
	.string "Such a shame, it could have been so\n"
	.string "useful against the old timers.$"

TormentHintNPCMessage::
# 1564 "data/maps/EscapeRoom/scripts.pory"
	.string "I used to get tormented by my brothers.\p"
	.string "I tried to avoid it at first, but after a\n"
	.string "while you just accept it and play along.$"

SketchHintNPCMessage::
# 1570 "data/maps/EscapeRoom/scripts.pory"
	.string "You can learn so much by copying those\n"
	.string "with experience.$"

Question1Message::
# 1574 "data/maps/EscapeRoom/scripts.pory"
	.string "1. Exactly one of statement 2 and 4 is\n"
	.string "false.$"

Question2Message::
# 1578 "data/maps/EscapeRoom/scripts.pory"
	.string "2. Both statements 1 and 3 are true.$"

Question3Message::
# 1582 "data/maps/EscapeRoom/scripts.pory"
	.string "3. At least two statements are false.$"

Question4Message::
# 1586 "data/maps/EscapeRoom/scripts.pory"
	.string "4. GARDEVOIR must use DISABLE to beat\n"
	.string "Expert Roel.$"

HintsIntroMessage::
# 1591 "data/maps/EscapeRoom/scripts.pory"
	.string "You can come to me for hints,\n"
	.string "but not yet because Roel still has to\l"
	.string "implement my script.$"

AntiSoftlockIntroMessage::
# 1597 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 1605 "data/maps/EscapeRoom/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

AntiSoftlockDeclinedMessage::
# 1610 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright.$"

AskReleaseSmeargleMessage::
# 1614 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Catching a 'wrong' SMEARGLE could leave\n"
	.string "you softlocked.\p"
	.string "Should I release this SMEARGLE and give\n"
	.string "back your GREAT BALL?$"

UndoRareCandyMessage::
# 1622 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Giving the RARE CANDY to the wrong\n"
	.string "POKéMON could leave you softlocked.\p"
	.string "Should I undo the level-up and give back\n"
	.string "your RARE CANDY?$"

UndoSketchMessage::
# 1630 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Sketching the wrong move with SMEARGLE\n"
	.string "could leave you softlocked.\p"
	.string "Should I revert your latest SKETCH?$"

SmeargleForgotMove::
# 1637 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle forgot its latest move...$"

SmeargleLearnedSketch::
# 1641 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle learned Sketch!$"

Double2IntroMessage::
# 1645 "data/maps/EscapeRoom/scripts.pory"
	.string "We really appreciate your out-of-the-\n"
	.string "box approach.$"

Double2OutroMessage::
# 1651 "data/maps/EscapeRoom/scripts.pory"
	.string "Ehhh... What.$"

Double2PostMatchMessage::
# 1655 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think you were supposed to win\n"
	.string "this battle.$"
