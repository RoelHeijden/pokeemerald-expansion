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
	setobjectxyperm 1, 6, 12
# 161 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 11
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
# 556 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 557 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 558 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 559 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 560 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 561 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 562 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 563 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 564 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 565 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 566 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 570 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 571 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 571 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 571 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 572 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 576 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 580 "data/maps/EscapeRoom/scripts.pory"
	lock
# 581 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 582 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 583 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 584 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 585 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 586 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 590 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 591 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 595 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 596 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 597 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 600 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 606 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 679 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 681 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 682 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 714 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 715 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 718 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 601 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 602 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 603 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 608 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 609 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 613 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 615 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 616 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 674 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 675 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 606 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 600 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 610 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 609 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 683 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 684 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 687 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 708 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 709 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 619 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 620 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 621 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 669 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 670 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 688 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 689 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 690 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 691 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 694 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 700 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 701 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 702 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 703 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 624 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 625 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 626 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 629 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 645 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 646 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 649 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 650 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 651 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 652 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 655 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 664 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 665 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 695 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 696 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 630 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 631 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 634 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 637 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 656 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 657 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 660 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 632 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 635 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 638 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 639 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 640 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_QuietTurnNPC::
# 723 "data/maps/EscapeRoom/scripts.pory"
	msgbox QuietTurnNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 727 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 731 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_GetUsOutNPC::
# 735 "data/maps/EscapeRoom/scripts.pory"
	msgbox GetUsOutNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 739 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 743 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 747 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 751 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_catchSalazzleNPC::
# 755 "data/maps/EscapeRoom/scripts.pory"
	msgbox SalazzleCatchingHint, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 759 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 760 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 767 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 768 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 770 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_CalcHintsUsed
# 771 "data/maps/EscapeRoom/scripts.pory"
	bufferplaytimeandhints
# 772 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 773 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 774 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 761 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 762 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 763 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 764 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_CalcHintsUsed::
# 778 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 779 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GREAT_BALL, EscapeRoom_EventScript_CalcHintsUsed_2
EscapeRoom_EventScript_CalcHintsUsed_1:
# 782 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_NUGGET, EscapeRoom_EventScript_CalcHintsUsed_5
EscapeRoom_EventScript_CalcHintsUsed_4:
# 785 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_8
EscapeRoom_EventScript_CalcHintsUsed_7:
# 788 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_11
EscapeRoom_EventScript_CalcHintsUsed_10:
# 791 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENTS_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_14
EscapeRoom_EventScript_CalcHintsUsed_13:
# 794 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_CATCHING_SMEARGLE, EscapeRoom_EventScript_CalcHintsUsed_17
EscapeRoom_EventScript_CalcHintsUsed_16:
# 797 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROSE_UN, EscapeRoom_EventScript_CalcHintsUsed_20
EscapeRoom_EventScript_CalcHintsUsed_19:
# 800 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_DS_ABEL, EscapeRoom_EventScript_CalcHintsUsed_23
EscapeRoom_EventScript_CalcHintsUsed_22:
# 803 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROEL, EscapeRoom_EventScript_CalcHintsUsed_26
EscapeRoom_EventScript_CalcHintsUsed_25:
# 806 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_C_TRISH, EscapeRoom_EventScript_CalcHintsUsed_29
EscapeRoom_EventScript_CalcHintsUsed_28:
# 809 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_PEE_SEA, EscapeRoom_EventScript_CalcHintsUsed_32
EscapeRoom_EventScript_CalcHintsUsed_31:
# 812 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_JAN_NAN, EscapeRoom_EventScript_CalcHintsUsed_34
	return

EscapeRoom_EventScript_CalcHintsUsed_2:
# 780 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_1

EscapeRoom_EventScript_CalcHintsUsed_5:
# 783 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_4

EscapeRoom_EventScript_CalcHintsUsed_8:
# 786 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_7

EscapeRoom_EventScript_CalcHintsUsed_11:
# 789 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_10

EscapeRoom_EventScript_CalcHintsUsed_14:
# 792 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_13

EscapeRoom_EventScript_CalcHintsUsed_17:
# 795 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_16

EscapeRoom_EventScript_CalcHintsUsed_20:
# 798 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_19

EscapeRoom_EventScript_CalcHintsUsed_23:
# 801 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_22

EscapeRoom_EventScript_CalcHintsUsed_26:
# 804 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_25

EscapeRoom_EventScript_CalcHintsUsed_29:
# 807 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_28

EscapeRoom_EventScript_CalcHintsUsed_32:
# 810 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_31

EscapeRoom_EventScript_CalcHintsUsed_34:
# 813 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	return


EscapeRoom_EventScript_FindIronBall::
# 818 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 819 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 820 "data/maps/EscapeRoom/scripts.pory"
	removeobject 15
# 821 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 822 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindToxicOrb::
# 826 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 827 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TOXIC_ORB
# 828 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 829 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
# 830 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_PressStartSign::
# 834 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 835 "data/maps/EscapeRoom/scripts.pory"
	msgbox PressStartSignMessage
# 836 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 837 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_ExitCloseNPC::
# 841 "data/maps/EscapeRoom/scripts.pory"
	msgbox ExitCloseNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PainSplitHintNPC::
# 845 "data/maps/EscapeRoom/scripts.pory"
	msgbox PainSplitHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_BerryTreeHintNPC::
# 849 "data/maps/EscapeRoom/scripts.pory"
	msgbox BerryTreeHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TormentHintNPC::
# 853 "data/maps/EscapeRoom/scripts.pory"
	msgbox TormentHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_SketchHintNPC::
# 857 "data/maps/EscapeRoom/scripts.pory"
	msgbox SketchHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_Question1Sign::
# 861 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 862 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question1Message
# 863 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 864 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question2Sign::
# 868 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 869 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question2Message
# 870 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 871 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question3Sign::
# 875 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 876 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question3Message
# 877 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 878 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question4Sign::
# 882 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 883 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question4Message
# 884 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 885 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTFSign::
# 889 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 890 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTFSign_Text_0
# 891 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 892 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTFSign::
# 896 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 897 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTFSign_Text_0
# 898 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 899 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFFSign::
# 903 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 904 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFFSign_Text_0
# 905 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 906 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTFSign::
# 910 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 911 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTFSign_Text_0
# 912 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 913 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFFFSign::
# 917 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 918 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFFFSign_Text_0
# 919 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 920 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFFSign::
# 924 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 925 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFFSign_Text_0
# 926 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 927 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTTSign::
# 931 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 932 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTTSign_Text_0
# 933 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 934 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTTSign::
# 938 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 939 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTTSign_Text_0
# 940 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 941 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFTTSign::
# 945 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 946 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFTTSign_Text_0
# 947 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 948 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFTSign::
# 952 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 953 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFTSign_Text_0
# 954 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 955 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTTSign::
# 959 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 960 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTTSign_Text_0
# 961 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 962 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFTSign::
# 966 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 967 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFTSign_Text_0
# 968 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 969 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 973 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 974 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 978 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_POKEMON_CAUGHT, EscapeRoom_EventScript_AntiSoftlockGuy_2
EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 989 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_RARE_CANDY_USED, EscapeRoom_EventScript_AntiSoftlockGuy_5
EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1012 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1013 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_11
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1045 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 1046 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 1047 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 980 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_7
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_5:
# 990 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 993 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 994 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_15
EscapeRoom_EventScript_AntiSoftlockGuy_14:
# 998 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonlevel 31
# 999 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_20
EscapeRoom_EventScript_AntiSoftlockGuy_19:
# 1003 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
# 1003 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
	goto EscapeRoom_EventScript_AntiSoftlockGuy_4

EscapeRoom_EventScript_AntiSoftlockGuy_7:
# 981 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSmeargleCatch
# 982 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1014 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1017 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 1018 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_17
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_11:
# 1013 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_10
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_15:
# 995 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_AntiSoftlockGuy_14

EscapeRoom_EventScript_AntiSoftlockGuy_17:
# 1021 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonmoves VAR_TEMP_0
# 1022 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_22
# 1032 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_23
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_20:
# 1000 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto EscapeRoom_EventScript_AntiSoftlockGuy_19

EscapeRoom_EventScript_AntiSoftlockGuy_22:
# 1025 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DS_ABEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_30
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_23:
# 1035 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_ROEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_32
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_26:
# 1004 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
# 1005 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_30:
# 1026 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch1
# 1027 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_32:
# 1036 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch2
# 1037 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_UndoSmeargleCatch::
# 1051 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskReleaseSmeargleMessage, MSGBOX_YESNO
# 1054 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_1
# 1109 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1110 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_1:
# 1057 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1058 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_5
# 1066 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 1067 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_8
EscapeRoom_EventScript_UndoSmeargleCatch_7:
# 1072 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 1073 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_UndoSmeargleCatch_10
# 1079 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 1080 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 1081 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 1084 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1085 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 1086 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_14
EscapeRoom_EventScript_UndoSmeargleCatch_13:
# 1090 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 1091 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_17
EscapeRoom_EventScript_UndoSmeargleCatch_16:
# 1097 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_20
EscapeRoom_EventScript_UndoSmeargleCatch_19:
# 1102 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 1103 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 1104 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_5:
# 1059 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseBringSmeargleMessage, MSGBOX_AUTOCLOSE
# 1060 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1061 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_UndoSmeargleCatch_8:
# 1068 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 1069 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_7

EscapeRoom_EventScript_UndoSmeargleCatch_10:
# 1074 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 1075 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_14:
# 1087 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1088 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_UndoSmeargleCatch_13

EscapeRoom_EventScript_UndoSmeargleCatch_17:
# 1092 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1093 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoSmeargleCatch_16

EscapeRoom_EventScript_UndoSmeargleCatch_20:
# 1098 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 1099 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_19


EscapeRoom_EventScript_UndoRareCandy::
# 1115 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoRareCandyMessage, MSGBOX_YESNO
# 1118 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_1
# 1130 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1131 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1119 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_5
# 1122 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_6
EscapeRoom_EventScript_UndoRareCandy_4:
# 1125 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_RARE_CANDY_USED
# 1126 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
	return

EscapeRoom_EventScript_UndoRareCandy_5:
# 1120 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_SMEARGLE
	goto EscapeRoom_EventScript_UndoRareCandy_4

EscapeRoom_EventScript_UndoRareCandy_6:
# 1123 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_GARDEVOIR
	goto EscapeRoom_EventScript_UndoRareCandy_4


EscapeRoom_EventScript_UndoSketch1::
# 1136 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1139 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch1_1
# 1154 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1155 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch1_1:
# 1140 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1141 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1143 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1144 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1148 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1149 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1150 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return


EscapeRoom_EventScript_UndoSketch2::
# 1160 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1163 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_1
# 1185 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1186 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch2_1:
# 1165 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1166 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1169 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_PROTECT
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_5
EscapeRoom_EventScript_UndoSketch2_4:
# 1174 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1175 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1179 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1180 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1181 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return

EscapeRoom_EventScript_UndoSketch2_5:
# 1170 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 1171 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_UndoSketch2_4


EscapeRoom_EventScript_HintsNPC::
# 1191 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 1192 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1193 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 1194 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 1199 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 1201 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1195 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
# 1196 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_part2
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_HintsNPC_part2::
# 1205 "data/maps/EscapeRoom/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_EventScript_HintsNPC_part2_Text_0, EscapeRoom_EventScript_HintsNPC_part2_Text_1
# 1209 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_part2_1
# 1212 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_part2_2
# 1216 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoHintMessage
	return

EscapeRoom_EventScript_HintsNPC_part2_1:
# 1210 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_WhereToLookHint
	return

EscapeRoom_EventScript_HintsNPC_part2_2:
# 1213 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_SpecificStepHint
	return


EscapeRoom_EventScript_WhereToLookHint::
# 1221 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_WhereToLookHint_Text_0
	return


EscapeRoom_EventScript_SpecificStepHint::
# 1225 "data/maps/EscapeRoom/scripts.pory"
	dynmultichoice 20, 2, FALSE, 5, 0, 0, EscapeRoom_EventScript_SpecificStepHint_Text_0, EscapeRoom_EventScript_SpecificStepHint_Text_1, EscapeRoom_EventScript_SpecificStepHint_Text_2, EscapeRoom_EventScript_SpecificStepHint_Text_3, EscapeRoom_EventScript_SpecificStepHint_Text_4, EscapeRoom_EventScript_SpecificStepHint_Text_5, EscapeRoom_EventScript_SpecificStepHint_Text_6, EscapeRoom_EventScript_SpecificStepHint_Text_7, EscapeRoom_EventScript_SpecificStepHint_Text_8, EscapeRoom_EventScript_SpecificStepHint_Text_9, EscapeRoom_EventScript_SpecificStepHint_Text_10, EscapeRoom_EventScript_SpecificStepHint_Text_11
# 1240 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_1
# 1244 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_2
# 1248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_3
# 1252 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_4
# 1256 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_5
# 1260 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_6
# 1264 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_7
# 1268 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_8
# 1272 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_9
# 1276 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_10
# 1280 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_11
# 1284 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_12
# 1289 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_part2
	return

EscapeRoom_EventScript_SpecificStepHint_1:
# 1241 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_GreatBall
# 1242 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_GREAT_BALL
	return

EscapeRoom_EventScript_SpecificStepHint_2:
# 1245 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_Nugget
# 1246 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_NUGGET
	return

EscapeRoom_EventScript_SpecificStepHint_3:
# 1249 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_IcePuzzle
# 1250 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ICE_PUZZLE
	return

EscapeRoom_EventScript_SpecificStepHint_4:
# 1253 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_StrengthPuzzle
# 1254 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STRENGTH_PUZZLE
	return

EscapeRoom_EventScript_SpecificStepHint_5:
# 1257 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_StatementsPuzzle
# 1258 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STATEMENTS_PUZZLE
	return

EscapeRoom_EventScript_SpecificStepHint_6:
# 1261 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_CatchingSmeargle
# 1262 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_CATCHING_SMEARGLE
	return

EscapeRoom_EventScript_SpecificStepHint_7:
# 1265 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerRoseUn
# 1266 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_ROSE_UN
	return

EscapeRoom_EventScript_SpecificStepHint_8:
# 1269 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerDSAbel
# 1270 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_DS_ABEL
	return

EscapeRoom_EventScript_SpecificStepHint_9:
# 1273 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerRoel
# 1274 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_ROEL
	return

EscapeRoom_EventScript_SpecificStepHint_10:
# 1277 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerCTrish
# 1278 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_C_TRISH
	return

EscapeRoom_EventScript_SpecificStepHint_11:
# 1281 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainersPeeSea
# 1282 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINERS_PEE_SEA
	return

EscapeRoom_EventScript_SpecificStepHint_12:
# 1285 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainersJanNan
# 1286 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINERS_JAN_NAN
	return


EscapeRoom_EventScript_FFTFSign_Text_0:
# 890 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTF$"

EscapeRoom_EventScript_TTTFSign_Text_0:
# 897 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTF$"

EscapeRoom_EventScript_TTFFSign_Text_0:
# 904 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFF$"

EscapeRoom_EventScript_FTTFSign_Text_0:
# 911 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTF$"

EscapeRoom_EventScript_TFFFSign_Text_0:
# 918 "data/maps/EscapeRoom/scripts.pory"
	.string "TFFF$"

EscapeRoom_EventScript_FFFFSign_Text_0:
# 925 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFF$"

EscapeRoom_EventScript_TTTTSign_Text_0:
# 932 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTT$"

EscapeRoom_EventScript_FTTTSign_Text_0:
# 939 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTT$"

EscapeRoom_EventScript_TFTTSign_Text_0:
# 946 "data/maps/EscapeRoom/scripts.pory"
	.string "TFTT$"

EscapeRoom_EventScript_TTFTSign_Text_0:
# 953 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFT$"

EscapeRoom_EventScript_FFTTSign_Text_0:
# 960 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTT$"

EscapeRoom_EventScript_FFFTSign_Text_0:
# 967 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFT$"

EscapeRoom_EventScript_HintsNPC_part2_Text_0:
# 1206 "data/maps/EscapeRoom/scripts.pory"
	.string "Where should I be looking now?$"

EscapeRoom_EventScript_HintsNPC_part2_Text_1:
# 1207 "data/maps/EscapeRoom/scripts.pory"
	.string "A hint for a specific step.$"

EscapeRoom_EventScript_WhereToLookHint_Text_0:
# 1221 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

EscapeRoom_EventScript_SpecificStepHint_Text_0:
# 1226 "data/maps/EscapeRoom/scripts.pory"
	.string "Get item: Great Ball.$"

EscapeRoom_EventScript_SpecificStepHint_Text_1:
# 1227 "data/maps/EscapeRoom/scripts.pory"
	.string "Get item: The 15th Nugget.$"

EscapeRoom_EventScript_SpecificStepHint_Text_2:
# 1228 "data/maps/EscapeRoom/scripts.pory"
	.string "Ice Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_3:
# 1229 "data/maps/EscapeRoom/scripts.pory"
	.string "Strength Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_4:
# 1230 "data/maps/EscapeRoom/scripts.pory"
	.string "Statements Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_5:
# 1231 "data/maps/EscapeRoom/scripts.pory"
	.string "Catching the perfect Smeargle$"

EscapeRoom_EventScript_SpecificStepHint_Text_6:
# 1232 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: Rose Un (Kecleon)$"

EscapeRoom_EventScript_SpecificStepHint_Text_7:
# 1233 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: DS. Abel (Slaking)$"

EscapeRoom_EventScript_SpecificStepHint_Text_8:
# 1234 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: Roel (Togedemaru)$"

EscapeRoom_EventScript_SpecificStepHint_Text_9:
# 1235 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: C. Trish (Klefki)$"

EscapeRoom_EventScript_SpecificStepHint_Text_10:
# 1236 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainers: Pee & Sea (Urshifu, Urshifu)$"

EscapeRoom_EventScript_SpecificStepHint_Text_11:
# 1237 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainers: Jan & Nan (Smeargle, Scrafty)$"

StartMessage::
# 1298 "data/maps/EscapeRoom/scripts.pory"
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
# 1338 "data/maps/EscapeRoom/scripts.pory"
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
# 1366 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 1371 "data/maps/EscapeRoom/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 1378 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 1383 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "There's one path that always wins.\n"
	.string "Can you figure it out?$"

Double1Puzzle_Outro::
# 1392 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 1397 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 1401 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 1405 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 1409 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\n"
	.string "Have you got one??\p"
	.string "Come to me when you do and I might offer\n"
	.string "you my GARDEVOIR.$"

SmeargleMessageBad::
# 1416 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "You should probably have a chat with\n"
	.string "the anti-softlock guy.$"

TakeFlameOrbMessage::
# 1423 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it anywhere)$"

SmeargleReleaseHealSecondMonMessage::
# 1428 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseBringSmeargleMessage::
# 1432 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back with the SMEARGLE in\n"
	.string "your party.$"

SmeargleReleaseGetSecondMonMessage::
# 1436 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 1440 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleMessagePerfect::
# 1444 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 1453 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 1462 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 1466 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 1470 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 1474 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 1479 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 1489 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 1496 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single2Puzzle_Intro::
# 1500 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 1506 "data/maps/EscapeRoom/scripts.pory"
	.string "Shut up and take my money.$"

Single3Puzzle_Intro::
# 1510 "data/maps/EscapeRoom/scripts.pory"
	.string "It looks like you're stuck!\p"
	.string "A real thief would've known when to run.$"

Single3Puzzle_Outro::
# 1515 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattle::
# 1519 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I can throw you back down, but I'll have\n"
	.string "to set a few things back to the way\l"
	.string "they were before.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 1528 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1534 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1538 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1544 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1548 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1555 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I only teach moves a GARDEVOIR\n"
	.string "could learn.$"

MoveTutorTradeDeclined::
# 1559 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1563 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1568 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1574 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1580 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1585 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1589 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1594 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

QuietTurnNPCMessage::
# 1598 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "one quiet turn could set you free.$"

NuggetNPCmessage::
# 1603 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET???\p"
	.string "I guess not...\n"
	.string "I'll leaf it be.$"

GetUsOutNPCMessage::
# 1609 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

SalazzleCatchingHint::
# 1613 "data/maps/EscapeRoom/scripts.pory"
	.string "Every time I've tried to catch SALAZZLE\n"
	.string "it managed to escape.\p"
	.string "It's just mocking me at this point.$"

someoneLockedUsUpNPCmessage::
# 1620 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1626 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing, right?$"

icePuzzleHintNPCmessage::
# 1631 "data/maps/EscapeRoom/scripts.pory"
	.string "That ice puzzle looks tough!\n"
	.string "Don't expect to solve it right away.$"

StopWinningNPCmessage::
# 1638 "data/maps/EscapeRoom/scripts.pory"
	.string "Haha you suck. Just give up!$"

NewGreatBallMessage::
# 1642 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1646 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1651 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1656 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"

PressStartSignMessage::
# 1660 "data/maps/EscapeRoom/scripts.pory"
	.string "Press START during a double battle to\n"
	.string "view your POKéMON's exact HP.$"

Single4IntroMessage::
# 1665 "data/maps/EscapeRoom/scripts.pory"
	.string "Oops, I picked the last berries.\n"
	.string "Why don't you come and take them?$"

Single4OutroMessage::
# 1670 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you really win?$"

single4PostMatchMessage::
# 1674 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm ready for a rematch whenever you\n"
	.string "want!$"

Single2Puzzle_PostBattle::
# 1679 "data/maps/EscapeRoom/scripts.pory"
	.string "CURSOLA is a great singer, don't you\n"
	.string "agree?\p"
	.string "Maybe SMEARGLE should follow her lead.$"

Single1Puzzle_PostBattle::
# 1685 "data/maps/EscapeRoom/scripts.pory"
	.string "Remember turning your POKéMON into a\n"
	.string "ghost type?\p"
	.string "That was fun.$"

ExitCloseNPCMessage::
# 1691 "data/maps/EscapeRoom/scripts.pory"
	.string "We're so close, the exit is right there!$"

PainSplitHintNPCMessage::
# 1695 "data/maps/EscapeRoom/scripts.pory"
	.string "Time is not for sale, but generosity can\n"
	.string "earn you a moment.\p"
	.string "Sharing is caring.$"

BerryTreeHintNPCMessage::
# 1701 "data/maps/EscapeRoom/scripts.pory"
	.string "What happened to that berry tree?\p"
	.string "Such a shame, it could have been so\n"
	.string "useful against the old timers.$"

TormentHintNPCMessage::
# 1707 "data/maps/EscapeRoom/scripts.pory"
	.string "I used to get tormented by my brothers.\p"
	.string "I tried to avoid it at first, but after a\n"
	.string "while you just accept it and play along.$"

SketchHintNPCMessage::
# 1713 "data/maps/EscapeRoom/scripts.pory"
	.string "You can learn so much by copying those\n"
	.string "with experience.$"

Question1Message::
# 1717 "data/maps/EscapeRoom/scripts.pory"
	.string "1. Exactly one of statement 2 and 4 is\n"
	.string "false.$"

Question2Message::
# 1721 "data/maps/EscapeRoom/scripts.pory"
	.string "2. Both statements 1 and 3 are true.$"

Question3Message::
# 1725 "data/maps/EscapeRoom/scripts.pory"
	.string "3. At least two statements are false.$"

Question4Message::
# 1729 "data/maps/EscapeRoom/scripts.pory"
	.string "4. GARDEVOIR must use DISABLE to beat\n"
	.string "Expert Roel.$"

AntiSoftlockIntroMessage::
# 1734 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 1742 "data/maps/EscapeRoom/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

AntiSoftlockDeclinedMessage::
# 1747 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright.$"

AskReleaseSmeargleMessage::
# 1751 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Catching a 'wrong' SMEARGLE could leave\n"
	.string "you softlocked.\p"
	.string "Should I release this SMEARGLE and give\n"
	.string "back your GREAT BALL?$"

UndoRareCandyMessage::
# 1759 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Giving the RARE CANDY to the wrong\n"
	.string "POKéMON could leave you softlocked.\p"
	.string "Should I undo the level-up and give back\n"
	.string "your RARE CANDY?$"

UndoSketchMessage::
# 1767 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Sketching the wrong move with SMEARGLE\n"
	.string "could leave you softlocked.\p"
	.string "Should I revert your latest SKETCH?$"

SmeargleForgotMove::
# 1774 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle forgot its latest move...$"

SmeargleLearnedSketch::
# 1778 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle learned Sketch!$"

Double2IntroMessage::
# 1782 "data/maps/EscapeRoom/scripts.pory"
	.string "We really appreciate your out-of-the-\n"
	.string "box approach.$"

Double2OutroMessage::
# 1788 "data/maps/EscapeRoom/scripts.pory"
	.string "Ehhh... What.$"

Double2PostMatchMessage::
# 1792 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think you were supposed to win\n"
	.string "this battle.$"

HintsIntroMessage::
# 1796 "data/maps/EscapeRoom/scripts.pory"
	.string "Hello, I'm the hintman.\n"
	.string "You can come to me for hints whenever\l"
	.string "you're stuck on any of the steps.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 1803 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 1807 "data/maps/EscapeRoom/scripts.pory"
	.string "What kind of hint would you like?$"

HintsNPC_GreatBall::
# 1816 "data/maps/EscapeRoom/scripts.pory"
	.string "This item is accessible from the start.\p"
	.string "You should further explore the room\n"
	.string "with the plants.$"

HintsNPC_Nugget::
# 1822 "data/maps/EscapeRoom/scripts.pory"
	.string "This item is accessible from the start.\p"
	.string "You should further explore the room\n"
	.string "with the plants.$"

HintsNPC_IcePuzzle::
# 1828 "data/maps/EscapeRoom/scripts.pory"
	.string "At the beginning, only the berry tree is\n"
	.string "accessible. The item ball is unreachable\l"
	.string "until the MACH BIKE is obtained.$"

HintsNPC_StrengthPuzzle::
# 1834 "data/maps/EscapeRoom/scripts.pory"
	.string "The puzzle revolves around breaking the\n"
	.string "ROCK SMASH rocks in the correct order.\p"
	.string "1. Break the two center rocks.\n"
	.string "2. Break the two rocks south-west.\l"
	.string "3. Break the last rock on the east.$"

HintsNPC_StatementsPuzzle::
# 1842 "data/maps/EscapeRoom/scripts.pory"
	.string "Solve the puzzle in order to figure out\n"
	.string "if the 4th statement is true or false,\l"
	.string "not the other way around!\p"
	.string "You'll find that only one answer remains\n"
	.string "for statement 4.$"

HintsNPC_CatchingSmeargle::
# 1850 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE will have the move\n"
	.string "SKETCH, which only has 1pp.\p"
	.string "If you stall a turn by not attacking,\n"
	.string "SMEARGLE will no longer be able to copy\l"
	.string "the wrong move.\p"
	.string "SALAZZLE might be part of the solution.$"

HintsNPC_TrainerRoseUn::
# 1859 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to find a way to take the item\n"
	.string "without winning the battle.\p"
	.string "Keep in mind that HIDDEN POWER's typing\n"
	.string "may depend on the POKéMON using it.\p"
	.string "It's okay to give up.$"

HintsNPC_TrainerDSAbel::
# 1867 "data/maps/EscapeRoom/scripts.pory"
	.string "The right moves on SMEARGLE and\n"
	.string "GARDEVOIR will help defeat the SLAKING.\p"
	.string "However, CURSOLA will need to be given a\n"
	.string "hindering ability to slow it down.$"

HintsNPC_TrainerRoel::
# 1874 "data/maps/EscapeRoom/scripts.pory"
	.string "It's key for SMEARGLE to SKETCH the\n"
	.string "correct move before this fight.\p"
	.string "Consider exploring the old couple to see\n"
	.string "what moves their POKéMON are hiding.\p"
	.string "For the actual battle, you might want to\n"
	.string "find a way to control TOGEDEMARU's HP.$"

HintsNPC_TrainerCTrish::
# 1883 "data/maps/EscapeRoom/scripts.pory"
	.string "Can you steal her SITRUS BERRY?\p"
	.string "SKILL SWAP is your friend, and perhaps\n"
	.string "there's a way to render DOUBLE EDGE\l"
	.string "completely useless.\p"
	.string "Two ways actually.$"

HintsNPC_TrainersPeeSea::
# 1891 "data/maps/EscapeRoom/scripts.pory"
	.string "This battle looks impossible to win.\n"
	.string "Can you find a way to skip this battle?\p"
	.string "Try thinking inside the box.$"

HintsNPC_TrainersJanNan::
# 1897 "data/maps/EscapeRoom/scripts.pory"
	.string "PAIN SPLIT can be used to heal, and\n"
	.string "SCRAFTY's ability can be used against\l"
	.string "itself.\p"
	.string "Remember the PERISH tiebreaker.\n"
	.string "Is there an item you haven't used yet?$"
