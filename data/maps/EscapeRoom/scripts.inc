EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScripts_SetHoleWarp
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


EscapeRoom_MapScript_setNPCfacing::
# 28 "data/maps/EscapeRoom/scripts.pory"
	turnobject 7, DIR_SOUTH
# 29 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_EAST
# 30 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_NORTH
# 31 "data/maps/EscapeRoom/scripts.pory"
	turnobject 15, DIR_WEST
# 32 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
# 33 "data/maps/EscapeRoom/scripts.pory"
	turnobject 17, DIR_EAST
# 34 "data/maps/EscapeRoom/scripts.pory"
	turnobject 18, DIR_NORTH
# 35 "data/maps/EscapeRoom/scripts.pory"
	turnobject 19, DIR_WEST
# 36 "data/maps/EscapeRoom/scripts.pory"
	turnobject 20, DIR_SOUTH
	end


EscapeRoom_MapScript_KeepDouble1Moved::
# 41 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 42 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 43 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 48 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 49 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 53 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 54 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 58 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 59 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 60 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 61 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 65 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_IRON_BALL, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 85 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 86 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 90 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 91 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 92 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 93 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 94 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 95 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 96 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 97 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 98 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 99 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 100 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 101 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 102 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 103 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 104 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 105 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 107 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 112 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 113 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 117 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HEART_SCALE
# 118 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 13
# 119 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 123 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 126 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 124 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 133 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 134 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 135 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 136 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 140 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 141 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 142 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 143 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 144 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 145 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 146 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 150 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 153 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 174 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 175 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 151 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 179 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 182 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 193 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 194 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 180 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_FindRareCandy::
# 198 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 199 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 200 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 201 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 202 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 206 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 207 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 208 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 209 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 210 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 214 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 215 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 216 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 217 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 218 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPainSplit::
# 222 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 223 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TM_PAIN_SPLIT
# 224 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 225 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PAIN_SPLIT_OBTAINED
# 226 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 230 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 231 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 232 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 238 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 270 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_15
EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 278 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 279 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_24
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 287 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 288 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 289 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 233 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 234 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 235 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 240 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 241 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_10
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 247 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_20
EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 254 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_29
EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 261 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 262 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_33
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 242 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 243 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 244 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_10:
# 241 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 272 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 273 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 274 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 275 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_15:
# 271 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_14
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_13

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 249 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 250 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 251 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_19
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_18

EscapeRoom_EventScript_GoodSmeargle_NPC_23:
# 280 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 281 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 282 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 283 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_24:
# 279 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_23
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_28:
# 256 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 257 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 258 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_29:
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_28
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_27

EscapeRoom_EventScript_GoodSmeargle_NPC_32:
# 263 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 264 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 265 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 262 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_32
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 294 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 373 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 296 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_HELPING_HAND
# 299 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_5
# 335 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 336 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_12
EscapeRoom_EventScript_IniitializeGardevoirTrade_11:
# 341 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 1, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
EscapeRoom_EventScript_IniitializeGardevoirTrade_4:
# 366 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 367 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage
# 368 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 369 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 370 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_5:
# 301 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 302 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_9
EscapeRoom_EventScript_IniitializeGardevoirTrade_8:
# 307 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 0, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4

EscapeRoom_EventScript_IniitializeGardevoirTrade_9:
# 303 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 304 "data/maps/EscapeRoom/scripts.pory"
	additem VAR_TEMP_1, 1
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_8

EscapeRoom_EventScript_IniitializeGardevoirTrade_12:
# 337 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 338 "data/maps/EscapeRoom/scripts.pory"
	additem VAR_TEMP_1, 1
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_11


EscapeRoom_EventScript_SingleBattle1::
# 378 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 379 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerriesAndHeal, music = FALSE
# 386 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 387 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 392 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 398 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 399 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 404 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 405 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 411 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_TeleportBackOverLedge::
# 417 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TM_18_STOLEN, EscapeRoom_EventScript_TeleportBackOverLedge_2
# 421 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleNotStolen, MSGBOX_YESNO
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 423 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_5
# 470 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 471 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 418 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattleStolen, MSGBOX_YESNO
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 424 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 425 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 426 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 10, 26
# 431 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_SINGLE_BATTLE3
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
# 466 "data/maps/EscapeRoom/scripts.pory"
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
# 458 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_20
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_19:
# 453 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 454 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 455 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 456 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16

EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 459 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 0, MOVE_THIEF
# 460 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 1, MOVE_HELPING_HAND
# 461 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_NONE
# 462 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 3, MOVE_NONE
	goto EscapeRoom_EventScript_TeleportBackOverLedge_16


EscapeRoom_EventScript_DoubleBattle1::
# 476 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 484 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 485 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 490 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 491 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 492 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 493 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 494 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 495 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 496 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 497 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 498 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 499 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 500 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 504 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 505 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 505 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 505 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 506 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 511 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_GetSitrusBerriesAndHeal::
# 516 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 517 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_BikeShop::
# 521 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 522 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 523 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 524 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 525 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 526 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_AUTOCLOSE
# 527 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 528 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


	.align 2
# 532 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 533 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 537 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 538 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 540 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 541 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_2
# 547 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 548 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_7
EscapeRoom_EventScript_HeartscaleTutor_6:
# 580 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 581 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 582 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 585 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 542 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 543 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 544 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 549 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 550 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 551 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 552 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_10
# 575 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 576 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_7:
# 548 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GARDEVOIR
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_10:
# 553 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 554 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
# 557 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_15
# 561 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_HeartscaleTutor_Text_0
# 562 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_13:
# 565 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 566 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 567 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirLearntDisable
# 568 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 570 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DISABLE_TAUGHT
# 571 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtDisable, MSGBOX_AUTOCLOSE
# 572 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_14:
# 555 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_15:
# 558 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13


EscapeRoom_EventScript_CreepySilentNPC::
# 590 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 591 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 592 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_AUTOCLOSE
# 593 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 594 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_PerishExplain_NPC::
# 599 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 600 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 601 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_AUTOCLOSE
# 602 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 603 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 608 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 609 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 610 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_AUTOCLOSE
# 611 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 612 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_itemHintNPC::
# 617 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 618 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 619 "data/maps/EscapeRoom/scripts.pory"
	msgbox itemHintNPCmessage, MSGBOX_AUTOCLOSE
# 620 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 621 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_NuggetNPC::
# 626 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 627 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 628 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_AUTOCLOSE
# 629 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 630 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 635 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 636 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 637 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_AUTOCLOSE
# 638 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 639 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_icePuzzleHintNPC::
# 644 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 645 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 646 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_AUTOCLOSE
# 647 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 648 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_getOutOfHereNPC::
# 653 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 654 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 655 "data/maps/EscapeRoom/scripts.pory"
	msgbox getOutOfHereNPCmessage, MSGBOX_AUTOCLOSE
# 656 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 657 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_EndEscapeRoomSign::
# 662 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 663 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 670 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 671 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 673 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 674 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 675 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 664 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 665 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 666 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 667 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_HeartscaleTutor_Text_0:
# 561 "data/maps/EscapeRoom/scripts.pory"
	.string "something went wrong.$"

StartMessage::
# 681 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SignMessage1::
# 685 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

Double1Puzzle_NotEnoughMons::
# 689 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 694 "data/maps/EscapeRoom/scripts.pory"
	.string "Sharing is caring. Didn't you know?\n"
	.string "It's not as painful as it seems.\p"
	.string "Everyone wins!$"

Double1Puzzle_Outro::
# 700 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 705 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 709 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 713 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 717 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\p"
	.string "Have you got one??$"

SmeargleMessageBad::
# 722 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.$"

SmeargleMessagePerfect::
# 727 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 734 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Oh, where did GOTHITA go?$"

TradeAcceptedMessage::
# 742 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

GardevoirObtainedMessage::
# 746 "data/maps/EscapeRoom/scripts.pory"
	.string "You received a Gardevoir!$"

TradeDeclinedMessage::
# 750 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 754 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA very\n"
	.string "much...$"

PerishNPCexplain::
# 759 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 768 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 775 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat that\n"
	.string "final duo.$"

Single1Puzzle_PostBattle::
# 780 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 784 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "learning battle strategy!$"

Single2Puzzle_Outro::
# 790 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay, you've impressed me.$"

Single2Puzzle_PostBattle::
# 794 "data/maps/EscapeRoom/scripts.pory"
	.string "You should probably get out of here.$"

Single3Puzzle_Intro::
# 798 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 802 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattleStolen::
# 806 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you give back my money and item,\n"
	.string "I'll throw you back over the ledge.\p"
	.string "Deal?$"

Single3Puzzle_PostBattleNotStolen::
# 813 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\p"
	.string "If you give me back my money,\n"
	.string "I'll throw you back over the ledge.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 820 "data/maps/EscapeRoom/scripts.pory"
	.string "Cool! Come back whenever you want to\n"
	.string "battle again.$"

NoTeleportPleaseMessage::
# 825 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorNoHeartScales::
# 829 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

MoveTutorStartMessage::
# 833 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

AskTeachGardevoirDisable::
# 839 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want me to teach DISABLE to\n"
	.string "your GARDEVOIR?$"

MoveTutorNoSuitablePokemonMessage::
# 843 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, none of your POKéMON can learn\n"
	.string "the moves I teach.$"

MoveTutorTaughtDisable::
# 847 "data/maps/EscapeRoom/scripts.pory"
	.string "Good choice.$"

MoveTutorTradeDeclined::
# 851 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

GardevoirLearntDisable::
# 855 "data/maps/EscapeRoom/scripts.pory"
	.string "Gardevoir learned Disable!$"

BikeShopHelloMessage::
# 859 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, how can I help you?$"

BikeShoptGoodbyeMessage::
# 863 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

EscapeRoomEndCongratz::
# 867 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 872 "data/maps/EscapeRoom/scripts.pory"
	.string "TBD$"

SilentNPCMessage::
# 876 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 880 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGETS?$"

itemHintNPCmessage::
# 884 "data/maps/EscapeRoom/scripts.pory"
	.string "Unfortunately, items can’t be used in\n"
	.string "trainer battles.\p"
	.string "Maybe they have their uses elsewhere.$"

someoneLockedUsUpNPCmessage::
# 890 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 896 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing right?$"

icePuzzleHintNPCmessage::
# 901 "data/maps/EscapeRoom/scripts.pory"
	.string "I heard there's an ice puzzle in the cave\n"
	.string "beneath us.\p"
	.string "Don't expect to solve it right away.$"

getOutOfHereNPCmessage::
# 907 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"
