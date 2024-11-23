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
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
	return


EscapeRoom_MapScripts_CheckAfterBattle::
# 34 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 35 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_FindGreatBallAferUse
# 36 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 40 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 41 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 42 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 47 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_FindGreatBallAferUse_2
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_1:
# 48 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 49 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_GREAT_BALL
# 50 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 51 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 52 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 53 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_FindGreatBallAferUse_2:
# 47 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_FindGreatBallAferUse_1
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 58 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 59 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 63 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 64 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 68 "data/maps/EscapeRoom/scripts.pory"
	turnobject 7, DIR_SOUTH
# 69 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_EAST
# 70 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_NORTH
# 71 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_WEST
# 72 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 73 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_EAST
# 74 "data/maps/EscapeRoom/scripts.pory"
	turnobject 18, DIR_NORTH
# 75 "data/maps/EscapeRoom/scripts.pory"
	turnobject 19, DIR_WEST
# 76 "data/maps/EscapeRoom/scripts.pory"
	turnobject 20, DIR_SOUTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 81 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 82 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 83 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 88 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 89 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 90 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 91 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 95 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_IRON_BALL, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 115 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 116 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 120 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 121 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 122 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 123 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 124 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 125 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 126 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 127 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 128 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 129 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 130 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 131 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 132 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 133 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 134 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 135 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 137 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 142 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 143 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 147 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HEART_SCALE
# 148 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 13
# 149 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 153 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 156 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 154 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 163 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 164 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 165 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 166 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 170 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 171 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 172 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 173 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 174 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 175 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 176 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 180 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 183 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 204 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 205 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 181 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 209 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 212 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 223 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 224 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 210 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_FindRareCandy::
# 228 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 229 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 230 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 231 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 232 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 236 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 237 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 238 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 239 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
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


EscapeRoom_EventScript_FindPainSplit::
# 252 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 253 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TM_PAIN_SPLIT
# 254 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 255 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PAIN_SPLIT_OBTAINED
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
# 268 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 269 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 300 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 301 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_15
EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 308 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 309 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_24
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 317 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 318 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 319 "data/maps/EscapeRoom/scripts.pory"
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

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 270 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_10
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 277 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 278 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_20
EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 284 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 285 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_29
EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 291 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 292 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_33
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 272 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 273 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 274 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_10:
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 302 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 303 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 304 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 305 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_15:
# 301 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_14
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_13

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 279 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 280 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 281 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 278 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_19
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_18

EscapeRoom_EventScript_GoodSmeargle_NPC_23:
# 310 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 311 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 312 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 313 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_24:
# 309 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_23
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_28:
# 286 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 287 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 288 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_29:
# 285 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_28
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_27

EscapeRoom_EventScript_GoodSmeargle_NPC_32:
# 293 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 294 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 295 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 292 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_32
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 324 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 403 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 326 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_HELPING_HAND
# 329 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_5
# 365 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 366 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_12
EscapeRoom_EventScript_IniitializeGardevoirTrade_11:
# 371 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 1, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
EscapeRoom_EventScript_IniitializeGardevoirTrade_4:
# 396 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 397 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage
# 398 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 399 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 400 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_5:
# 331 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 332 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_9
EscapeRoom_EventScript_IniitializeGardevoirTrade_8:
# 337 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 0, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4

EscapeRoom_EventScript_IniitializeGardevoirTrade_9:
# 333 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 334 "data/maps/EscapeRoom/scripts.pory"
	additem VAR_TEMP_1, 1
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_8

EscapeRoom_EventScript_IniitializeGardevoirTrade_12:
# 367 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 368 "data/maps/EscapeRoom/scripts.pory"
	additem VAR_TEMP_1, 1
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_11


EscapeRoom_EventScript_SingleBattle1::
# 408 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 409 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerriesAndHeal, music = FALSE
# 416 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 417 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 422 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 428 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 429 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 434 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 435 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 441 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 447 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 451 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 453 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 498 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 499 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 448 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 454 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 455 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 456 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 459 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 462 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 465 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_8
	return

EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 467 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 468 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_11
EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 471 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 472 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_14
EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 475 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TM18
# 478 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_RAIN_DANCE
# 479 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_17
EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 494 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TM_18_STOLEN
	return

EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 469 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_10

EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 473 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_13

EscapeRoom_EventScript_TeleportBackOverLedge_17:
# 480 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_19
# 486 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_20
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_19:
# 481 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 482 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 483 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 484 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 487 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 0, MOVE_THIEF
# 488 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 1, MOVE_HELPING_HAND
# 489 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_NONE
# 490 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16


EscapeRoom_EventScript_DoubleBattle1::
# 504 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 512 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 513 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 518 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 519 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 520 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 521 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 522 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 523 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 524 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 525 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 526 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 527 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 528 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 532 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 533 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 533 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 533 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 534 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 539 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_GetSitrusBerriesAndHeal::
# 544 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 545 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_BikeShop::
# 549 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 550 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 551 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 552 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 553 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 554 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_AUTOCLOSE
# 555 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 556 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


	.align 2
# 560 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 561 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 565 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 566 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 568 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 569 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_2
# 575 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 576 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_7
EscapeRoom_EventScript_HeartscaleTutor_6:
# 608 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 609 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 610 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 613 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 570 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 571 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 572 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 577 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 578 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 579 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 580 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_10
# 603 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 604 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_7:
# 576 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GARDEVOIR
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_10:
# 581 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 582 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
# 585 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_15
# 589 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_HeartscaleTutor_Text_0
# 590 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_13:
# 593 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 594 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 595 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirLearntDisable
# 596 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 598 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DISABLE_TAUGHT
# 599 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtDisable, MSGBOX_AUTOCLOSE
# 600 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_14:
# 583 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_15:
# 586 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13


EscapeRoom_EventScript_CreepySilentNPC::
# 618 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 619 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 620 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_AUTOCLOSE
# 621 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 622 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_PerishExplain_NPC::
# 627 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 628 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 629 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_AUTOCLOSE
# 630 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 631 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 636 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 637 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 638 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_AUTOCLOSE
# 639 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 640 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_itemHintNPC::
# 645 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 646 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 647 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_AUTOCLOSE
# 648 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 649 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_NuggetNPC::
# 654 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 655 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 656 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_AUTOCLOSE
# 657 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 658 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 663 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 664 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 665 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_AUTOCLOSE
# 666 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 667 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_icePuzzleHintNPC::
# 672 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 673 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 674 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_AUTOCLOSE
# 675 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 676 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_getOutOfHereNPC::
# 681 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 682 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 683 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_AUTOCLOSE
# 684 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 685 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EndEscapeRoomSign::
# 690 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 691 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 698 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 699 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 701 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 702 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 703 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 692 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 693 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 694 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 695 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_HeartscaleTutor_Text_0:
# 589 "data/maps/EscapeRoom/scripts.pory"
	.string "something went wrong.$"

StartMessage::
# 709 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 713 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 717 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 722 "data/maps/EscapeRoom/scripts.pory"
	.string "Sharing is caring. Didn't you know?\n"
	.string "It's not as painful as it seems.\p"
	.string "Everyone wins!$"

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
	.string "I asked for the perfect SMEARGLE.$"

SmeargleMessagePerfect::
# 755 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 762 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did GOTHITA go?$"

TradeAcceptedMessage::
# 770 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

GardevoirObtainedMessage::
# 774 "data/maps/EscapeRoom/scripts.pory"
	.string "You received a Gardevoir!$"

TradeDeclinedMessage::
# 778 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 782 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 787 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 796 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 803 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat that\n"
	.string "final duo.$"

Single1Puzzle_PostBattle::
# 808 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 812 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "learning battle strategy!$"

Single2Puzzle_Outro::
# 818 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 822 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 826 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 830 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 834 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you give back my money and item,\n"
	.string "I'll throw you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 841 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you give me back my money,\n"
	.string "I'll throw you back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 848 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool! Come back whenever you want to\n"
	.string "battle again.$"

NoTeleportPleaseMessage::
# 853 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorNoHeartScales::
# 857 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

MoveTutorStartMessage::
# 861 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

AskTeachGardevoirDisable::
# 867 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want me to teach DISABLE to\n"
	.string "your GARDEVOIR?$"

MoveTutorNoSuitablePokemonMessage::
# 871 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, none of your POKéMON can learn\n"
	.string "the moves I teach.$"

MoveTutorTaughtDisable::
# 875 "data/maps/EscapeRoom/scripts.pory"
	.string "Good choice.$"

MoveTutorTradeDeclined::
# 879 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

GardevoirLearntDisable::
# 883 "data/maps/EscapeRoom/scripts.pory"
	.string "Gardevoir learned Disable!$"

BikeShopHelloMessage::
# 887 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, how can I help you?$"

BikeShoptGoodbyeMessage::
# 891 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 895 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 900 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 904 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 908 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGETS?$"

itemHintNPCmessage::
# 912 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "trainer battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 918 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 924 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 929 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 935 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

NewGreatBallMessage::
# 939 "data/maps/EscapeRoom/scripts.pory"
	.string "You retrieve your Great Ball$"
