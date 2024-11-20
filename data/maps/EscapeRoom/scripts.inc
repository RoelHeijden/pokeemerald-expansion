EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScripts_SetHoleWarp
# 7 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScripts_PlayStartMessage
# 9 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1, EscapeRoom_MapScripts_GetFirstPokemon
# 10 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2, EscapeRoom_MapScripts_GetBadges
# 11 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3, EscapeRoom_MapScripts_SetRespawn
# 12 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4, EscapeRoom_MapScripts_GetItems
# 13 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5, EscapeRoom_MapScripts_TurnOfBagUse
# 14 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6, EscapeRoom_MapScripts_FixCrackedGround
# 15 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
	.2byte 0


EscapeRoom_MapScripts_SetHoleWarp::
# 20 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 21 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 25 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 26 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 30 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 31 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 32 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 33 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 37 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 57 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 58 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 62 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 63 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 64 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 65 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 66 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 67 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 68 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 69 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 70 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 71 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 72 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 73 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 74 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 75 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 76 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 77 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 79 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 84 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 85 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 89 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 90 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_MACH_BIKE
# 91 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 92 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 96 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 99 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 97 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 107 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 108 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 109 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 110 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 114 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 115 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 116 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 117 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 118 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 119 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 120 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 124 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 127 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 148 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 149 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 125 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 153 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 156 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 167 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 168 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 154 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_DoubleBattle1::
# 172 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostDouble1Heal
# 179 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 180 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostDouble1Heal::
# 185 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_Heal, MSGBOX_AUTOCLOSE
# 186 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 187 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 188 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


EscapeRoom_EventScript_PostSingle2Heal::
# 192 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_Heal, MSGBOX_AUTOCLOSE
# 193 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 194 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 195 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


EscapeRoom_EventScript_FindRareCandy::
# 199 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 200 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 201 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 202 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 203 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 207 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 208 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 209 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 210 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 211 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 215 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 216 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 217 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 218 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 219 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 223 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 224 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 225 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 231 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 263 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 264 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_15
EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 271 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 272 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_24
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 280 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 281 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 282 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 226 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 227 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 228 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 233 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 234 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_10
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 240 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 241 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_20
EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 247 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_29
EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 254 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_33
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 235 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 236 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 237 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_10:
# 234 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 265 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 266 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 267 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 268 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_15:
# 264 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_14
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_13

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 242 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 243 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 244 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 241 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_19
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_18

EscapeRoom_EventScript_GoodSmeargle_NPC_23:
# 273 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 274 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 275 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 276 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_24:
# 272 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_23
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_28:
# 249 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 250 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 251 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_29:
# 248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_28
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_27

EscapeRoom_EventScript_GoodSmeargle_NPC_32:
# 256 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 257 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 258 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_32
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 287 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 352 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 288 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_HELPING_HAND
# 289 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_5
# 315 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_6
# 342 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_0
	end

EscapeRoom_EventScript_IniitializeGardevoirTrade_4:
# 346 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 347 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_1
# 348 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage
# 349 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_5:
# 290 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 0, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4

EscapeRoom_EventScript_IniitializeGardevoirTrade_6:
# 316 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 1, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4


EscapeRoom_EventScript_PerishExplain_NPC::
# 357 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 358 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 359 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 360 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 361 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_SingleBattle1::
# 365 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 366 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerries
# 372 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 373 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_GetSitrusBerries::
# 378 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_SingleBattle2::
# 382 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostSingle2Heal
# 388 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 389 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 394 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 395 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro
# 400 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 401 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_0:
# 342 "data/maps/EscapeRoom/scripts.pory"
	.string "something has gone wrong$"

EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_1:
# 347 "data/maps/EscapeRoom/scripts.pory"
	.string "Received Gardevoir$"

StartMessage::
# 409 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 413 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

SmeargleObtainedMsg::
# 417 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 421 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 425 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second Pokémon.$"

Double1Puzzle_Intro::
# 429 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 433 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 437 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 441 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your Pokémon!$"

Double1Puzzle_Heal::
# 445 "data/maps/EscapeRoom/scripts.pory"
	.string "Let us heal your Pokémon.$"

SmeargleMessageInitial::
# 449 "data/maps/EscapeRoom/scripts.pory"
	.string "I love Smeargle. Show me the perfect\n"
	.string "Smeargle.$"

SmeargleMessageBad::
# 453 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that Smeargle looks horrible. I\n"
	.string "asked for the perfect Smeargle.$"

SmeargleMessagePerfect::
# 457 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "Smeargle!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty Gothita for my Gardevoir.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 465 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "Smeargle!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty Gothita for my Gardevoir.\p"
	.string "Oh, where did it go?$"

TradeAcceptedMessage::
# 473 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

TradeDeclinedMessage::
# 477 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 481 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this Gothita...$"

PerishNPCexplain::
# 485 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "Pokémon and Perish Song counts down,\l"
	.string "the Pokémon to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 489 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already? I think one of their Pokémon\l"
	.string "is hiding something.$"

Single1Puzzle_Outro::
# 493 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the final duo.$"

Single1Puzzle_PostBattle::
# 497 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 501 "data/maps/EscapeRoom/scripts.pory"
	.string "You think you better than me?$"

Single2Puzzle_Outro::
# 505 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay. I'm impressed.$"

Single2Puzzle_PostBattle::
# 509 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck getting out!$"

Single2Puzzle_Heal::
# 513 "data/maps/EscapeRoom/scripts.pory"
	.string "Let me heal your Pokémon$"

Single3Puzzle_Intro::
# 517 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 521 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure you wanted to do that.$"

Single3Puzzle_PostBattle::
# 525 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...$"
