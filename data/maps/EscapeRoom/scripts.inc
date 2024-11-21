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
	additem ITEM_NUGGET, 13
# 91 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 95 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 98 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 96 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 105 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 106 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 107 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 108 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 112 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 113 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 114 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 115 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 116 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 117 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 118 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 122 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 125 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 146 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 147 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 123 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 151 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 154 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 165 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 166 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 152 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_DoubleBattle1::
# 170 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 177 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 178 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 184 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_FindRareCandy::
# 189 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 190 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 191 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 192 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 193 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 197 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 198 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 199 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 200 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 201 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 205 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 206 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 207 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 208 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 209 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPainSplit::
# 213 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 214 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_TM_PAIN_SPLIT
# 215 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 216 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PAIN_SPLIT_OBTAINED
# 217 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 221 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 222 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 223 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 229 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 230 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 261 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 262 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_15
EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 269 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 270 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_24
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 278 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 279 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 280 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 224 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 225 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 226 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 231 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_10
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 238 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_20
EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 245 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 246 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_29
EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 252 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 253 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_33
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 233 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 234 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 235 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_10:
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 263 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 264 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 265 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 266 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_15:
# 262 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_14
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_13

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 240 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 241 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 242 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_19
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_18

EscapeRoom_EventScript_GoodSmeargle_NPC_23:
# 271 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 272 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 273 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 274 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_24:
# 270 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_23
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_28:
# 247 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 248 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 249 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_29:
# 246 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_28
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_27

EscapeRoom_EventScript_GoodSmeargle_NPC_32:
# 254 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 255 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 256 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 253 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_32
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 285 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 350 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 286 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_HELPING_HAND
# 287 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_5
# 313 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_6
# 340 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_0
	end

EscapeRoom_EventScript_IniitializeGardevoirTrade_4:
# 344 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 345 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_1
# 346 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage
# 347 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_5:
# 288 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 0, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4

EscapeRoom_EventScript_IniitializeGardevoirTrade_6:
# 314 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 1, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4


EscapeRoom_EventScript_SingleBattle1::
# 355 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 356 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerriesAndHeal
# 362 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 363 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_GetSitrusBerriesAndHeal::
# 368 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 369 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_SingleBattle2::
# 373 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 379 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 380 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 385 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 386 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 392 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 393 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_BikeShop::
# 398 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 399 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 400 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 401 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 402 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 403 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage
# 404 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 405 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


	.align 2
# 409 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 410 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 414 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 415 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 416 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage, MSGBOX_AUTOCLOSE
# 417 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 418 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 419 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_2
# 424 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 425 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_7
EscapeRoom_EventScript_HeartscaleTutor_6:
# 456 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 457 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 460 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 420 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 421 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 426 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 427 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 428 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_10
# 451 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 452 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_7:
# 425 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GARDEVOIR
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_10:
# 429 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 430 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
# 433 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_15
# 437 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_HeartscaleTutor_Text_0
# 438 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_13:
# 441 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 442 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 443 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirLearntDisable
# 444 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 446 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DISABLE_TAUGHT
# 447 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtDisable, MSGBOX_AUTOCLOSE
# 448 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_14:
# 431 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_15:
# 434 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13


EscapeRoom_EventScript_CreepySilentNPC::
# 465 "data/maps/EscapeRoom/scripts.pory"
	lock
# 466 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 467 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_AUTOCLOSE
# 468 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PerishExplain_NPC::
# 473 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 474 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 475 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 476 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 477 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_0:
# 340 "data/maps/EscapeRoom/scripts.pory"
	.string "something has gone wrong$"

EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_1:
# 345 "data/maps/EscapeRoom/scripts.pory"
	.string "Received Gardevoir$"

EscapeRoom_EventScript_HeartscaleTutor_Text_0:
# 437 "data/maps/EscapeRoom/scripts.pory"
	.string "something went wrong.$"

StartMessage::
# 483 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 487 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

Double1Puzzle_NotEnoughMons::
# 491 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second POKéMON.$"

Double1Puzzle_Intro::
# 495 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 499 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 503 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 507 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your POKéMON!$"

SmeargleMessageInitial::
# 511 "data/maps/EscapeRoom/scripts.pory"
	.string "I love SMEARGLE. Show me the perfect\n"
	.string "SMEARGLE.$"

SmeargleMessageBad::
# 515 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible. I\n"
	.string "asked for the perfect SMEARGLE.$"

SmeargleMessagePerfect::
# 519 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 527 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GotGOTHITAhita for my GARDEVOIR.\p"
	.string "Oh, where did it go?$"

TradeAcceptedMessage::
# 535 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

TradeDeclinedMessage::
# 539 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 543 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA...$"

PerishNPCexplain::
# 547 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "POKéMON and PERISH SONG counts down,\l"
	.string "the POKéMON to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 551 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already? I think one of their POKéMON\l"
	.string "is hiding something.$"

Single1Puzzle_Outro::
# 555 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the final duo.$"

Single1Puzzle_PostBattle::
# 559 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 563 "data/maps/EscapeRoom/scripts.pory"
	.string "You think you better than me?$"

Single2Puzzle_Outro::
# 567 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay. I'm impressed.$"

Single2Puzzle_PostBattle::
# 571 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck getting out!$"

Single3Puzzle_Intro::
# 575 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 579 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure if you wanted to do that.$"

Single3Puzzle_PostBattle::
# 583 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...$"

MoveTutorNoHeartScales::
# 587 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

MoveTutorStartMessage::
# 591 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move\l"
	.string "if you'd like.$"

AskTeachGardevoirDisable::
# 597 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want me to teach DISABLE to\n"
	.string "your GARDEVOIR?$"

MoveTutorNoSuitablePokemonMessage::
# 601 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, none of your POKéMON can learn\n"
	.string "the moves I teach.$"

MoveTutorTaughtDisable::
# 605 "data/maps/EscapeRoom/scripts.pory"
	.string "Good choice.$"

MoveTutorTradeDeclined::
# 609 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

GardevoirLearntDisable::
# 613 "data/maps/EscapeRoom/scripts.pory"
	.string "Gardevoir learned Disable!$"

SilentNPCMessage::
# 617 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

BikeShopHelloMessage::
# 621 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, how can I help you?$"

BikeShoptGoodbyeMessage::
# 625 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"
