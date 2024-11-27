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
	turnobject 5, DIR_EAST
# 109 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_SOUTH
# 110 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 111 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 112 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 113 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_NORTH
# 114 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_EAST
# 115 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 116 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_NORTH
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
# 188 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
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


EscapeRoom_EventScript_FindNugget3::
# 230 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 231 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 232 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 233 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 234 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 238 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 239 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 240 "data/maps/EscapeRoom/scripts.pory"
	removeobject 7
# 241 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 242 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 246 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 247 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 248 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 254 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 286 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 287 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 294 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 295 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 303 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 304 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
# 327 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 328 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 330 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 249 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 250 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 251 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 256 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 257 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 263 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 264 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 270 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_39
EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 277 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 278 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_43
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 305 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 306 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_EventScript_GoodSmeargle_NPC_22
# 322 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 323 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 258 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 259 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 260 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 257 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 288 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 289 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 290 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 291 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 287 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 307 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 308 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_34
# 313 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 314 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 315 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 316 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 317 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 318 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 265 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 266 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 267 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 264 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 296 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 297 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 298 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 299 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 295 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_30
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_34:
# 309 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 310 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_38:
# 272 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 273 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 274 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_39:
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_38
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_37

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 279 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 280 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 281 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_43:
# 278 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 335 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 366 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 336 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_GOTHITA
# 337 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 359 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 360 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 361 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 362 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 363 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 371 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 377 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 378 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 383 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 389 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 390 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 395 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 396 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 402 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 408 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 412 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 414 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 459 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 460 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 409 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 415 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 416 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 417 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 420 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 423 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 426 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_8
	return

EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 428 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 429 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_11
EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 432 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 433 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_14
EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 436 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TM18
# 439 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_RAIN_DANCE
# 440 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_17
EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 455 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TM_18_STOLEN
	return

EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 430 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_10

EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 434 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_13

EscapeRoom_EventScript_TeleportBackOverLedge_17:
# 441 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_19
# 447 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_20
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_19:
# 442 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 443 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 444 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 445 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 448 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 0, MOVE_THIEF
# 449 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 1, MOVE_HELPING_HAND
# 450 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_NONE
# 451 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16


EscapeRoom_EventScript_DoubleBattle1::
# 465 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 473 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 474 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 479 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 480 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 481 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 482 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 483 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 484 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 485 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 486 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 487 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 488 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 489 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 493 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 494 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 494 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 494 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 495 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 500 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 505 "data/maps/EscapeRoom/scripts.pory"
	lock
# 506 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 507 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 508 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 509 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 510 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 511 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 515 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 516 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 520 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 521 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 522 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 525 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 531 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 604 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 606 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 607 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 639 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 640 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 643 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 526 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 527 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 528 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 533 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 534 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 538 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 540 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 541 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 599 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 600 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 531 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 525 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 535 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 534 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 608 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 609 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 612 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 633 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 634 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 544 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 545 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 546 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 594 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 595 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 613 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 614 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 615 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 616 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 619 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 625 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 626 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 627 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 628 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 549 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 550 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 551 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 554 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 570 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 571 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 574 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 575 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 576 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 577 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 580 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 589 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 590 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 620 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 621 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 555 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 556 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 559 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 562 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 581 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 582 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 585 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 557 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 560 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 563 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 564 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 565 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 648 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 652 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 656 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_itemHintNPC::
# 660 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 664 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 668 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 672 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_getOutOfHereNPC::
# 676 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 680 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 681 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 688 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 689 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 691 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 692 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 693 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 682 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 683 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 684 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 685 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 697 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 698 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 699 "data/maps/EscapeRoom/scripts.pory"
	removeobject 19
# 700 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 701 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


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
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "Do you have the skill to find a way?$"

Double1Puzzle_Outro::
# 728 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 733 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 737 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 741 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 745 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 750 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "Do you want to release this SMEARGLE\n"
	.string "and get your ball back?$"

SmeargleReleaseHealSecondMonMessage::
# 757 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 761 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 765 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 769 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 773 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 781 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did your GOTHITA go?$"

TradeAcceptedMessage::
# 789 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 793 "data/maps/EscapeRoom/scripts.pory"
	.string "Player received a Gardevoir!$"

TradeDeclinedMessage::
# 797 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 801 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 806 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 816 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 823 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single1Puzzle_PostBattle::
# 827 "data/maps/EscapeRoom/scripts.pory"
	.string "...\p"
	.string "Good luck.$"

Single2Puzzle_Intro::
# 832 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 838 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 842 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 846 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide!$"

Single3Puzzle_Outro::
# 850 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 854 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money and TM, I'll throw\n"
	.string "you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 861 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money, I'll throw you\n"
	.string "back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 868 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool cool! Come back again whenever you\n"
	.string "want to battle.$"

NoTeleportPleaseMessage::
# 873 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 877 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 883 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 887 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 894 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I can only teach moves to very a\n"
	.string "specific POKéMON.$"

MoveTutorTradeDeclined::
# 898 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 902 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 907 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 913 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 919 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 924 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 928 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 933 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 937 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 942 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 946 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 950 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET?$"

itemHintNPCmessage::
# 954 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "TRAINER battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 960 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 966 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 971 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 977 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

NewGreatBallMessage::
# 981 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 985 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewLumBerryMessage::
# 990 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another Lum Berry in\n"
	.string "your pocket.$"

ThanksMomMessage::
# 995 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"
