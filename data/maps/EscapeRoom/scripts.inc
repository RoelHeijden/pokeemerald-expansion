EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScripts_OnResumeScripts
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
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 23 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 24 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScripts_OnResumeScripts::
# 28 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
	end


EscapeRoom_MapScripts_SetHoleWarp::
# 39 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 40 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScript_setNPCfacing::
# 44 "data/maps/EscapeRoom/scripts.pory"
	turnobject 7, DIR_SOUTH
# 45 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_EAST
# 46 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_NORTH
# 47 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_WEST
# 48 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 49 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_EAST
# 50 "data/maps/EscapeRoom/scripts.pory"
	turnobject 18, DIR_NORTH
# 51 "data/maps/EscapeRoom/scripts.pory"
	turnobject 19, DIR_WEST
# 52 "data/maps/EscapeRoom/scripts.pory"
	turnobject 20, DIR_SOUTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 57 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 58 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 59 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 64 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 65 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 69 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 70 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 71 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 72 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 76 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_IRON_BALL, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 96 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 97 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 101 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 102 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 103 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 104 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 105 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 106 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 107 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 108 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 109 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 110 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 111 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 112 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 113 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 114 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 115 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 116 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 118 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 123 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 124 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 128 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HEART_SCALE
# 129 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 13
# 130 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 134 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 137 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 135 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 144 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 145 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 146 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 147 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 151 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 152 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 153 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 154 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 155 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 156 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 157 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 161 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 164 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 185 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 186 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 162 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 190 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 193 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 204 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 205 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 191 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_FindRareCandy::
# 209 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 210 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 211 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 212 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 213 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 217 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 218 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 219 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 220 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 221 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 225 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 226 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 227 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 228 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 229 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPainSplit::
# 233 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 234 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TM_PAIN_SPLIT
# 235 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 236 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PAIN_SPLIT_OBTAINED
# 237 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 241 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 242 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 243 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 249 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 250 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 281 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 282 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_15
EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 289 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 290 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_24
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 298 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 299 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 300 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 244 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 245 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 246 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 251 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 252 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_10
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 258 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 259 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_20
EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 265 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 266 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_29
EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 272 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 273 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_33
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 253 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 254 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 255 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_10:
# 252 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 283 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 284 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 285 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 286 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_15:
# 282 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_14
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_13

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 260 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 261 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 262 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 259 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_19
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_18

EscapeRoom_EventScript_GoodSmeargle_NPC_23:
# 291 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 292 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 293 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 294 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_24:
# 290 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_23
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_28:
# 267 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 268 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 269 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_29:
# 266 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_28
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_27

EscapeRoom_EventScript_GoodSmeargle_NPC_32:
# 274 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 275 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 276 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 273 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_32
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 305 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 384 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 307 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_HELPING_HAND
# 310 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_5
# 346 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 347 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_12
EscapeRoom_EventScript_IniitializeGardevoirTrade_11:
# 352 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 1, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
EscapeRoom_EventScript_IniitializeGardevoirTrade_4:
# 377 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 378 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage
# 379 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 380 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 381 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_5:
# 312 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 313 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_9
EscapeRoom_EventScript_IniitializeGardevoirTrade_8:
# 318 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 0, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4

EscapeRoom_EventScript_IniitializeGardevoirTrade_9:
# 314 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 315 "data/maps/EscapeRoom/scripts.pory"
	additem VAR_TEMP_1, 1
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_8

EscapeRoom_EventScript_IniitializeGardevoirTrade_12:
# 348 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 349 "data/maps/EscapeRoom/scripts.pory"
	additem VAR_TEMP_1, 1
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_11


EscapeRoom_EventScript_SingleBattle1::
# 389 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 390 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerriesAndHeal, music = FALSE
# 397 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 398 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 403 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 409 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 410 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 415 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 416 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 422 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 428 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 432 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 434 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 479 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 480 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 429 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 435 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 436 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 437 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 440 "data/maps/EscapeRoom/scripts.pory"
	removemoney 78999
# 443 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 446 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_8
	return

EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 448 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 449 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_11
EscapeRoom_EventScript_TeleportBackOverLedge_10:
# 452 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 453 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_TM18
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_14
EscapeRoom_EventScript_TeleportBackOverLedge_13:
# 456 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_TM18
# 459 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_RAIN_DANCE
# 460 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_17
EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 475 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TM_18_STOLEN
	return

EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 450 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_10

EscapeRoom_EventScript_TeleportBackOverLedge_14:
# 454 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_13

EscapeRoom_EventScript_TeleportBackOverLedge_17:
# 461 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_19
# 467 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_20
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_19:
# 462 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 463 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 464 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 465 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 468 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 0, MOVE_THIEF
# 469 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 1, MOVE_HELPING_HAND
# 470 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_NONE
# 471 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16


EscapeRoom_EventScript_DoubleBattle1::
# 485 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 493 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 494 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 499 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 500 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 501 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 502 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 503 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 504 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 505 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 506 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 507 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 508 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 509 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 513 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 514 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 514 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 514 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 515 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 520 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_GetSitrusBerriesAndHeal::
# 525 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 526 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_BikeShop::
# 530 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 531 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 532 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 533 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 534 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 535 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_AUTOCLOSE
# 536 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 537 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


	.align 2
# 541 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 542 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 546 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 547 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 549 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 550 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_2
# 556 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 557 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_7
EscapeRoom_EventScript_HeartscaleTutor_6:
# 589 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 590 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 591 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 594 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 551 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 552 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 553 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 558 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 559 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 560 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 561 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_10
# 584 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 585 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_7:
# 557 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GARDEVOIR
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_10:
# 562 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 563 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
# 566 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_15
# 570 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_HeartscaleTutor_Text_0
# 571 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_13:
# 574 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 575 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 576 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirLearntDisable
# 577 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 579 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DISABLE_TAUGHT
# 580 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtDisable, MSGBOX_AUTOCLOSE
# 581 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_14:
# 564 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_15:
# 567 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13


EscapeRoom_EventScript_CreepySilentNPC::
# 599 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 600 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 601 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_AUTOCLOSE
# 602 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 603 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_PerishExplain_NPC::
# 608 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 609 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 610 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_AUTOCLOSE
# 611 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 612 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 617 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 618 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 619 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_AUTOCLOSE
# 620 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 621 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_itemHintNPC::
# 626 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 627 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 628 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_AUTOCLOSE
# 629 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 630 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_NuggetNPC::
# 635 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 636 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 637 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_AUTOCLOSE
# 638 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 639 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 644 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 645 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 646 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_AUTOCLOSE
# 647 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 648 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_icePuzzleHintNPC::
# 653 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 654 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 655 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_AUTOCLOSE
# 656 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 657 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_getOutOfHereNPC::
# 662 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 663 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 664 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_AUTOCLOSE
# 665 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 666 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EndEscapeRoomSign::
# 671 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 672 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 679 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 680 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 682 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 683 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 684 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 673 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 674 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 675 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 676 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_HeartscaleTutor_Text_0:
# 570 "data/maps/EscapeRoom/scripts.pory"
	.string "something went wrong.$"

StartMessage::
# 690 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 694 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 698 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 703 "data/maps/EscapeRoom/scripts.pory"
	.string "Sharing is caring. Didn't you know?\n"
	.string "It's not as painful as it seems.\p"
	.string "Everyone wins!$"

Double1Puzzle_Outro::
# 709 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 714 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 718 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 722 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 726 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 731 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.$"

SmeargleMessagePerfect::
# 736 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 743 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did GOTHITA go?$"

TradeAcceptedMessage::
# 751 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

GardevoirObtainedMessage::
# 755 "data/maps/EscapeRoom/scripts.pory"
	.string "You received a Gardevoir!$"

TradeDeclinedMessage::
# 759 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 763 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 768 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 777 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 784 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat that\n"
	.string "final duo.$"

Single1Puzzle_PostBattle::
# 789 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 793 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "learning battle strategy!$"

Single2Puzzle_Outro::
# 799 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 803 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 807 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 811 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 815 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you give back my money and item,\n"
	.string "I'll throw you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 822 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you give me back my money,\n"
	.string "I'll throw you back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 829 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool! Come back whenever you want to\n"
	.string "battle again.$"

NoTeleportPleaseMessage::
# 834 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorNoHeartScales::
# 838 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

MoveTutorStartMessage::
# 842 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

AskTeachGardevoirDisable::
# 848 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want me to teach DISABLE to\n"
	.string "your GARDEVOIR?$"

MoveTutorNoSuitablePokemonMessage::
# 852 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, none of your POKéMON can learn\n"
	.string "the moves I teach.$"

MoveTutorTaughtDisable::
# 856 "data/maps/EscapeRoom/scripts.pory"
	.string "Good choice.$"

MoveTutorTradeDeclined::
# 860 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

GardevoirLearntDisable::
# 864 "data/maps/EscapeRoom/scripts.pory"
	.string "Gardevoir learned Disable!$"

BikeShopHelloMessage::
# 868 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, how can I help you?$"

BikeShoptGoodbyeMessage::
# 872 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 876 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 881 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 885 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 889 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGETS?$"

itemHintNPCmessage::
# 893 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "trainer battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 899 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 905 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 910 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 916 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"
