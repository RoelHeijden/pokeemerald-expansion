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
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_LUM, 0, EscapeRoom_MapScripts_CheckAfterBattleLum
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 25 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 26 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_OnResumeScripts::
# 31 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
# 34 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpawnSitrusTree
# 37 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 38 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_LUM, 0
# 41 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_1
	return

EscapeRoom_MapScript_OnResumeScripts_1:
# 42 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScripts_CheckSpawnSitrusTree::
# 48 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY, 4
# 49 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckSpawnSitrusTree_1
	return

EscapeRoom_MapScripts_CheckSpawnSitrusTree_1:
# 50 "data/maps/EscapeRoom/scripts.pory"
	setberrytree BERRY_TREE_ESCAPE_ROOM_SITRUS, ITEM_TO_BERRY ( ITEM_SITRUS_BERRY ), BERRY_STAGE_BERRIES
	return


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 55 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 56 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindGreatBallAferUse
# 57 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return


EscapeRoom_MapScripts_CheckAfterBattleLum::
# 61 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 62 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindLumBerryAferUse
# 63 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_LUM, 1
	return


EscapeRoom_MapScripts_FindLumBerryAferUse::
# 67 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_LUM_BERRY_USED, EscapeRoom_MapScripts_FindLumBerryAferUse_2
	return

EscapeRoom_MapScripts_FindLumBerryAferUse_1:
# 68 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 69 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewLumBerryMessage, MSGBOX_AUTOCLOSE
# 70 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 71 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_LUM_BERRY
# 72 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_LUM_BERRY_USED
# 73 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 74 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 75 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindLumBerryAferUse_2:
# 67 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindLumBerryAferUse_1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 80 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 81 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 82 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 87 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_FindGreatBallAferUse_2
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_1:
# 88 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 89 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 90 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 91 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 92 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 93 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_2:
# 87 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindGreatBallAferUse_1
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 98 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 99 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 103 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 104 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 108 "data/maps/EscapeRoom/scripts.pory"
	turnobject 5, DIR_SOUTH
# 109 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_SOUTH
# 110 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 111 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 112 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_SOUTH
# 113 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_EAST
# 114 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_NORTH
# 115 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_WEST
# 116 "data/maps/EscapeRoom/scripts.pory"
	turnobject 18, DIR_SOUTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 121 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 122 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 123 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 128 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 129 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 130 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 131 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 135 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 155 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 156 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 160 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 161 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 162 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 163 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 164 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 165 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 166 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 167 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 168 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 169 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 170 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 171 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 172 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 173 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 174 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 175 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 177 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 182 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 183 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 187 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 188 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 13
# 189 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 193 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 196 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 194 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 203 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 204 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 205 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 206 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 210 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 211 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 212 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 213 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 214 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 215 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 216 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 217 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 218 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 222 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 223 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 224 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 225 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 226 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 230 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 231 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 232 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 233 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 234 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 238 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 239 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 240 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 241 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 242 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 246 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 247 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 248 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 249 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 250 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 254 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 255 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 256 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 262 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 263 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 294 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 295 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 302 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 303 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 311 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 312 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
# 335 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 336 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 338 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 257 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 258 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 259 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 264 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 265 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 271 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 272 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 278 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 279 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_39
EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 285 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 286 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_43
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 313 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 314 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_EventScript_GoodSmeargle_NPC_22
# 330 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 331 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 266 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 267 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 268 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 265 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 296 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 297 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 298 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 299 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 295 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 315 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 316 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_34
# 321 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 322 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 323 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 324 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 325 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 326 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 273 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 274 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 275 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 272 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 304 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 305 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 306 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 307 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 303 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_30
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_34:
# 317 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 318 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_38:
# 280 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 281 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 282 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_39:
# 279 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_38
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_37

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 287 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 288 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 289 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_43:
# 286 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 343 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 374 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 344 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_GOTHITA
# 345 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 367 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 368 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 369 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 370 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 371 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 379 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 385 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 386 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 391 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 397 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 398 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 403 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 404 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 410 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 416 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 420 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 422 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 467 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 468 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 417 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 423 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 424 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 425 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 428 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 431 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 434 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_8
	return

EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 436 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 437 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_11
EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 440 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 441 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_14
EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 444 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TM18
# 447 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_RAIN_DANCE
# 448 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_17
EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 463 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TM_18_STOLEN
	return

EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 438 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_10

EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 442 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_13

EscapeRoom_EventScript_TeleportBackOverLedge_17:
# 449 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_19
# 455 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_20
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_19:
# 450 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 451 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 452 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 453 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 456 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 0, MOVE_THIEF
# 457 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 1, MOVE_HELPING_HAND
# 458 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_NONE
# 459 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16


EscapeRoom_EventScript_DoubleBattle1::
# 473 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 481 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 482 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 487 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 488 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 489 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 490 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 491 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 492 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 493 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 494 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 495 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 496 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 497 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 501 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 502 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 502 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 502 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 503 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 508 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 513 "data/maps/EscapeRoom/scripts.pory"
	lock
# 514 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 515 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 516 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 517 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 518 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 519 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 523 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 524 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 528 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 529 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 530 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 533 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 539 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 612 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 614 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 615 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 647 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 648 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 651 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 534 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 535 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 536 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 541 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 542 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 546 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 548 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 549 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 607 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 608 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 539 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 533 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 543 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 542 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 616 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 617 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 620 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 641 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 642 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 552 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 553 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 554 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 602 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 603 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 621 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 622 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 623 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 624 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 627 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 633 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 634 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 635 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 636 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 557 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 558 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 559 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 562 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 578 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 579 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 582 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 583 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 584 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 585 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 588 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 597 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 598 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 628 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 629 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 563 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 564 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 567 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 570 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 589 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 590 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 593 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 565 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 568 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 571 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 572 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 573 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 656 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 660 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 664 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_itemHintNPC::
# 668 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 672 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 676 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 680 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_getOutOfHereNPC::
# 684 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 688 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 689 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 696 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 697 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 699 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 700 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 701 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 690 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 691 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 692 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 693 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


StartMessage::
# 707 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 711 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 715 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 720 "data/maps/EscapeRoom/scripts.pory"
	.string "Sharing is caring. Didn't you know?\n"
	.string "It's not as painful as it seems.\p"
	.string "Everyone wins!$"

Double1Puzzle_Outro::
# 726 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 731 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 735 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 739 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 743 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 748 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "Do you want to release this SMEARGLE\n"
	.string "and get your ball back?$"

SmeargleReleaseHealSecondMonMessage::
# 755 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 759 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 763 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 767 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 771 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 779 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did your GOTHITA go?$"

TradeAcceptedMessage::
# 787 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 791 "data/maps/EscapeRoom/scripts.pory"
	.string "Player received a Gardevoir!$"

TradeDeclinedMessage::
# 795 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 799 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 804 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 813 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 820 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single1Puzzle_PostBattle::
# 824 "data/maps/EscapeRoom/scripts.pory"
	.string "...\p"
	.string "It might be worth it to revisit your\n"
	.string "items and tutor moves.\p"
	.string "Good luck.$"

Single2Puzzle_Intro::
# 831 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 837 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 841 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 845 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide!$"

Single3Puzzle_Outro::
# 849 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 853 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money and item, I'll\n"
	.string "throw you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 860 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money, I'll throw you\n"
	.string "back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 867 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool cool! Come back again whenever you\n"
	.string "want to battle.$"

NoTeleportPleaseMessage::
# 872 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 876 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 882 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 886 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 893 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I can only teach moves to very a\n"
	.string "specific POKéMON.$"

MoveTutorTradeDeclined::
# 897 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 901 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 906 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 912 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 918 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 923 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 927 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 932 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 936 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 941 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 945 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 949 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGETS?$"

itemHintNPCmessage::
# 953 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "trainer battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 959 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 965 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 970 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 976 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

NewGreatBallMessage::
# 980 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 984 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewLumBerryMessage::
# 989 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another Lum Berry in\n"
	.string "your pocket.$"

ThanksMomMessage::
# 994 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"
