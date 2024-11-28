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
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_RAWST, 0, EscapeRoom_MapScripts_CheckAfterBattleRawst
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
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_RAWST, 0
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


EscapeRoom_MapScripts_CheckAfterBattleRawst::
# 61 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 62 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindRawstBerryAferUse
# 63 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_RAWST, 1
	return


EscapeRoom_MapScripts_FindRawstBerryAferUse::
# 68 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_RAWST_BERRY_USED, EscapeRoom_MapScripts_FindRawstBerryAferUse_2
	return

EscapeRoom_MapScripts_FindRawstBerryAferUse_1:
# 69 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_RAWST_BERRY_USED
# 72 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_RAWST_BERRY
# 73 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_FindRawstBerryAferUse_5
	return

EscapeRoom_MapScripts_FindRawstBerryAferUse_2:
# 68 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindRawstBerryAferUse_1
	return

EscapeRoom_MapScripts_FindRawstBerryAferUse_5:
# 76 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 77 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_RAWST_BERRY
	goto_if_ne EscapeRoom_MapScripts_FindRawstBerryAferUse_7
	return

EscapeRoom_MapScripts_FindRawstBerryAferUse_7:
# 80 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 81 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewRawstBerryMessage, MSGBOX_AUTOCLOSE
# 82 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 83 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RAWST_BERRY
# 84 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 85 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 86 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 93 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 94 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 95 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 100 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_FindGreatBallAferUse_2
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_1:
# 101 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 102 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 103 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 104 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 105 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 106 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_2:
# 100 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindGreatBallAferUse_1
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 111 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 112 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 116 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 117 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 121 "data/maps/EscapeRoom/scripts.pory"
	turnobject 5, DIR_EAST
# 122 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_SOUTH
# 123 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 124 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 125 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 126 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_NORTH
# 127 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_EAST
# 128 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 129 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_NORTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 134 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 135 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 136 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 141 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 142 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 143 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 144 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 148 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_SWOOBAT, 64, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 1, move1 = MOVE_THIEF, move2 = MOVE_PSYCHO_SHIFT, move3 = MOVE_NONE, move4 = MOVE_NONE, atkEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 168 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 169 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 173 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 174 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 175 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 176 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 177 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 178 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 179 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 180 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 181 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 182 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 183 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 184 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 185 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 186 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 187 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 188 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 190 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 195 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 196 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 201 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 202 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 206 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 209 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 207 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 216 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 217 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 218 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 219 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 223 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 224 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 225 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 226 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 227 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 228 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 229 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 230 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 231 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 235 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 236 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 237 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 238 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 239 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 243 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 244 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 245 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 246 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 247 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 251 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 252 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 253 "data/maps/EscapeRoom/scripts.pory"
	removeobject 7
# 254 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 255 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 259 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 260 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 261 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 267 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 268 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 299 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 300 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 307 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 308 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 316 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 317 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
# 340 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 341 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 343 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 262 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 263 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 264 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 269 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 270 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 276 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 277 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 283 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 284 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_39
EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 290 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 291 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_43
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 318 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 319 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_EventScript_GoodSmeargle_NPC_22
# 335 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 336 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 271 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 272 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 273 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 270 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 301 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 302 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 303 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 304 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 300 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 320 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 321 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_34
# 326 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 327 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 328 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 329 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 330 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 331 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 278 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 279 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 280 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 277 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 309 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 310 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 311 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 312 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 308 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_30
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_34:
# 322 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 323 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_38:
# 285 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 286 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 287 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_39:
# 284 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_38
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_37

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 292 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 293 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 294 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_43:
# 291 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 348 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 379 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 349 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_GOTHITA
# 350 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 372 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 373 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 374 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 375 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 376 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 384 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 390 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 391 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 396 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 402 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 403 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 408 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 409 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 415 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 421 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_FLAME_ORB_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 425 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 427 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 456 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 457 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 422 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 428 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 429 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 430 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 433 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 436 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 439 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_FLAME_ORB_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_8
	return

EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 441 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 442 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_11
EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 445 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 446 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_14
EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 449 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
# 452 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_FLAME_ORB_STOLEN
	return

EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 443 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_10

EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 447 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_13


EscapeRoom_EventScript_DoubleBattle1::
# 462 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 470 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 471 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 476 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 477 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 478 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 479 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 480 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 481 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 482 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 483 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 484 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 485 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 486 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 490 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 491 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 491 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 491 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 492 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 497 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 502 "data/maps/EscapeRoom/scripts.pory"
	lock
# 503 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 504 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 505 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 506 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 507 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 508 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 512 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 513 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 517 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 518 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 519 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 522 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 528 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 601 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 603 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 604 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 636 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 637 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 640 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 523 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 524 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 525 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 530 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 531 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 535 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 537 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 538 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 596 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 597 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 528 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 522 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 532 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 531 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 605 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 606 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 609 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 630 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 631 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 541 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 542 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 543 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 591 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 592 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 610 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 611 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 612 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 613 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 616 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 622 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 623 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 624 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 625 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 546 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 547 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 548 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 551 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 567 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 568 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 571 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 572 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 573 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 574 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 577 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 586 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 587 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 617 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 618 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 552 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 553 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 556 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 559 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 578 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 579 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 582 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 554 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 557 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 560 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 561 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 562 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 645 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 649 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 653 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_itemHintNPC::
# 657 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 661 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 665 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 669 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_getOutOfHereNPC::
# 673 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 677 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 678 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 685 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 686 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 688 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 689 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 690 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 679 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 680 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 681 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 682 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 694 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 695 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 696 "data/maps/EscapeRoom/scripts.pory"
	removeobject 19
# 697 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 698 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


StartMessage::
# 704 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 708 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 712 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 717 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "Do you have the skill to find a way?$"

Double1Puzzle_Outro::
# 725 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 730 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 734 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 738 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 742 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 747 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "Do you want to release this SMEARGLE\n"
	.string "and get your ball back?$"

SmeargleReleaseHealSecondMonMessage::
# 754 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 758 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 762 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 766 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 770 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 778 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did your GOTHITA go?$"

TradeAcceptedMessage::
# 786 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 790 "data/maps/EscapeRoom/scripts.pory"
	.string "Player received a Gardevoir!$"

TradeDeclinedMessage::
# 794 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 798 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 803 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
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
	.string "Good luck.$"

Single2Puzzle_Intro::
# 829 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 835 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 839 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 843 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide!$"

Single3Puzzle_Outro::
# 847 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 851 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money and TM, I'll throw\n"
	.string "you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 858 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you return my money, I'll throw you\n"
	.string "back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 865 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool cool cool.\n"
	.string "Let's battle again when you're ready!\p"
	.string "YEET!!$"

NoTeleportPleaseMessage::
# 871 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 875 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 881 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 885 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 892 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I can only teach moves to very a\n"
	.string "specific POKéMON.$"

MoveTutorTradeDeclined::
# 896 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 900 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 905 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 911 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 917 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 922 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 926 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 931 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 935 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 940 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 944 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 948 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET?$"

itemHintNPCmessage::
# 952 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "TRAINER battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 958 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 964 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 969 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 975 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

NewGreatBallMessage::
# 979 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 983 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewRawstBerryMessage::
# 988 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 993 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"
