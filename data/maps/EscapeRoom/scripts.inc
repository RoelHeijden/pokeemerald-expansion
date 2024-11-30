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
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
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


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 61 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 62 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindPechaBerryAferUse
# 63 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 68 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_FindPechaBerryAferUse_2
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_1:
# 69 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 72 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 73 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_FindPechaBerryAferUse_5
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_2:
# 68 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindPechaBerryAferUse_1
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_5:
# 76 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 77 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_FindPechaBerryAferUse_7
	return

EscapeRoom_MapScripts_FindPechaBerryAferUse_7:
# 80 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 81 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 82 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 83 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
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
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_CELEBRATE, move4 = MOVE_NONE, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 30, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 169 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 170 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 174 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 175 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 176 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 177 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 178 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 179 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 180 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 181 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 182 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 183 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 184 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 185 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 186 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 187 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 188 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 189 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 191 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 196 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 197 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 202 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 203 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 207 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 210 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 208 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 217 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 218 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 219 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 220 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 224 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 225 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 226 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 227 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 228 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 229 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 230 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 231 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 232 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 236 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 237 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 238 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 239 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 240 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 244 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 245 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 246 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 247 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 248 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 252 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 253 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 254 "data/maps/EscapeRoom/scripts.pory"
	removeobject 7
# 255 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 256 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 260 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 261 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 262 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 270 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 280 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 281 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 282 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 285 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 286 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 291 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 292 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 293 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 298 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 307 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 315 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 355 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 263 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 264 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 265 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 272 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 273 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 274 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 283 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 282 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 287 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 286 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 294 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 299 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 300 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 301 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 302 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 298 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 308 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 309 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 310 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 307 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 316 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad, MSGBOX_YESNO
# 319 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_33
# 351 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseDeclinedMessage, MSGBOX_AUTOCLOSE
# 352 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 322 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 323 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_36
# 328 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_37
# 334 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 335 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 336 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 337 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 339 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 340 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_42
EscapeRoom_EventScript_GoodSmeargle_NPC_41:
# 343 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
# 345 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 346 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_36:
# 324 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 325 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_37:
# 329 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 330 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30

EscapeRoom_EventScript_GoodSmeargle_NPC_42:
# 341 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_41


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 361 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 392 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 362 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 363 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 7, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 164, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 10, spAtkIv = 31, spDefIv = 31
# 385 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 386 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 387 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 388 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 389 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return


EscapeRoom_EventScript_SingleBattle1::
# 397 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 403 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 404 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 409 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 415 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 416 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 421 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 422 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro
# 427 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 433 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 434 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 438 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 440 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_6
# 473 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 474 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 476 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 435 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 442 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 443 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 444 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 25
# 447 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 450 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 453 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 456 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOXIC_ORB_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_9
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 458 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 459 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_12
EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 462 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 463 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TOXIC_ORB
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_15
EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 466 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TOXIC_ORB
# 469 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOXIC_ORB_STOLEN
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 460 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 464 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_14


EscapeRoom_EventScript_DoubleBattle1::
# 480 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 488 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 489 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 494 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 495 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 496 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 497 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 498 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 499 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 500 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 501 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 502 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 503 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 504 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 508 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 509 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 509 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 509 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 510 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 515 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 520 "data/maps/EscapeRoom/scripts.pory"
	lock
# 521 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 522 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 523 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 524 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 525 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 526 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 530 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 531 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 535 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 536 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 537 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 540 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 546 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 619 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 621 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 622 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 654 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 655 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 658 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 541 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 542 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 543 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 548 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 549 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 553 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 555 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 556 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 614 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 615 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 546 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 540 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 550 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 549 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 623 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 624 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 627 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 648 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 649 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 559 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 560 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 561 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 609 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 610 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 628 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 629 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 630 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 631 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 634 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 640 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 641 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 642 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 643 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 564 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 565 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 566 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 569 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 585 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 586 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 589 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 590 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 591 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 592 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 595 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 604 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 605 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 635 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 636 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 570 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 571 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 574 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 577 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 596 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 597 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 600 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 572 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 575 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 578 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 579 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 580 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_CreepySilentNPC::
# 663 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 667 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 671 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_HiddenPowerHintNPC::
# 675 "data/maps/EscapeRoom/scripts.pory"
	msgbox hiddenPowerHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 679 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 683 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 687 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 691 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 695 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 696 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 703 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 704 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 706 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 707 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 708 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 697 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 698 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 699 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 700 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_FindIronBall::
# 712 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 713 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 714 "data/maps/EscapeRoom/scripts.pory"
	removeobject 19
# 715 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 716 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


StartMessage::
# 722 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 726 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

EscapeRoomEndCongratz::
# 730 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 735 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 739 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 744 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "Do you have the skill to find a way?$"

Double1Puzzle_Outro::
# 752 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 757 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 761 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 765 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 769 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 774 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "Do you want to release this SMEARGLE\n"
	.string "and get your ball back?$"

SmeargleReleaseHealSecondMonMessage::
# 781 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseGetSecondMonMessage::
# 785 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 789 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleReleaseDeclinedMessage::
# 793 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay.$"

SmeargleMessagePerfect::
# 797 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\n"
	.string "GARDEVOIR."
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 806 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 814 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 818 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 822 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 826 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 831 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 841 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 848 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single1Puzzle_PostBattle::
# 852 "data/maps/EscapeRoom/scripts.pory"
	.string "...\p"
	.string "Good luck.$"

Single2Puzzle_Intro::
# 857 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 863 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 867 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 871 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide!$"

Single3Puzzle_Outro::
# 875 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 879 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I'll throw you back down in return for\n"
	.string "my item and money.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 887 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "It looks like you're softlocked.\p"
	.string "I'll throw you back down in return for\n"
	.string "my money.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 895 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 901 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 905 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 911 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 915 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 922 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I can only teach moves to very a\n"
	.string "specific POKéMON.$"

MoveTutorTradeDeclined::
# 926 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 930 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 935 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 941 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 947 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 952 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 956 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 961 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

SilentNPCMessage::
# 965 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "One quiet turn could set you free.$"

NuggetNPCmessage::
# 970 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET?$"

hiddenPowerHintNPCmessage::
# 974 "data/maps/EscapeRoom/scripts.pory"
	.string "Even copied moves can hold surprises.\n"
	.string "Sometimes they just feel... different.$"

someoneLockedUsUpNPCmessage::
# 979 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 985 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 990 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to fully solve it on your\n"
	.string "first try.$"

StopWinningNPCmessage::
# 997 "data/maps/EscapeRoom/scripts.pory"
	.string "Aren't you tired of winning?\n"
	.string "Try losing instead!$"

NewGreatBallMessage::
# 1002 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1006 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1011 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1016 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"
