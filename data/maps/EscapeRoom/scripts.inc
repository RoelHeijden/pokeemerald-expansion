EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
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


EscapeRoom_MapScript_OnTransitionScripts::
# 20 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 21 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_KeepDouble1Moved::
# 25 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 26 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 11
# 27 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 10
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 32 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 33 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 37 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 38 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 42 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 43 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 44 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 45 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 49 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 69 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 70 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 74 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 75 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 76 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 77 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 78 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 79 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 80 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 81 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 82 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 83 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 84 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 85 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 86 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 87 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 88 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 89 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 91 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 96 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 97 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 101 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 102 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 13
# 103 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 107 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 110 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 108 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 117 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 118 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 119 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 120 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 124 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 125 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 126 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 127 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 128 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 129 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 130 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 134 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 137 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 158 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 159 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 135 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 163 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 166 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 177 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 178 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 164 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_FindRareCandy::
# 182 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 183 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 184 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 185 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 186 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget2::
# 190 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 191 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 192 "data/maps/EscapeRoom/scripts.pory"
	removeobject 9
# 193 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
# 194 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 198 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 199 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 200 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 201 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 202 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindPainSplit::
# 206 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 207 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_TM_PAIN_SPLIT
# 208 "data/maps/EscapeRoom/scripts.pory"
	removeobject 13
# 209 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PAIN_SPLIT_OBTAINED
# 210 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 214 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 215 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 216 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 222 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 223 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 254 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_15
EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 262 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 263 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_24
EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 271 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 272 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 273 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 217 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 218 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 219 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 224 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_THIEF
# 225 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_10
EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 231 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_20
EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 238 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_29
EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 245 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 246 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_33
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 226 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 227 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 228 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_10:
# 225 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GOTHITA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_9
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_8

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 256 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 257 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 258 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 259 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_15:
# 255 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_14
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_13

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 233 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 234 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 235 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SHEDINJA
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_19
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_18

EscapeRoom_EventScript_GoodSmeargle_NPC_23:
# 264 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 265 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 266 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 267 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_24:
# 263 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_23
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4

EscapeRoom_EventScript_GoodSmeargle_NPC_28:
# 240 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 241 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 242 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_29:
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_28
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_27

EscapeRoom_EventScript_GoodSmeargle_NPC_32:
# 247 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButGothitaInBox
# 248 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 249 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_33:
# 246 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_32
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_4


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 278 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 343 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 279 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_HELPING_HAND
# 280 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_5
# 306 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_6
# 333 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_0
	end

EscapeRoom_EventScript_IniitializeGardevoirTrade_4:
# 337 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 338 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_1
# 339 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage
# 340 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_5:
# 281 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 0, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4

EscapeRoom_EventScript_IniitializeGardevoirTrade_6:
# 307 "data/maps/EscapeRoom/scripts.pory"
	createmon 0, 1, SPECIES_GARDEVOIR, 30, abilityNum = 0, item = ITEM_NUGGET nature = 5, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
	goto EscapeRoom_EventScript_IniitializeGardevoirTrade_4


EscapeRoom_EventScript_SingleBattle1::
# 348 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 349 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerriesAndHeal
# 355 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 356 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 361 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 367 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 368 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 373 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 374 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_PostMatchHeal
# 380 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 381 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_DoubleBattle1::
# 386 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 393 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 394 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 399 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 400 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 401 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 402 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 403 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 404 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 405 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 406 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 407 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 408 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 409 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 413 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 414 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 414 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 414 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 415 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 420 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_GetSitrusBerriesAndHeal::
# 425 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 426 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_BikeShop::
# 430 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 431 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 432 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 433 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 434 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 435 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage
# 436 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 437 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


	.align 2
# 441 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 442 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 446 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 447 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 448 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage, MSGBOX_AUTOCLOSE
# 449 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 450 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 451 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_2
# 456 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 457 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_7
EscapeRoom_EventScript_HeartscaleTutor_6:
# 488 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 489 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 492 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 452 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 453 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 458 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 459 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 460 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_10
# 483 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 484 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_7:
# 457 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_GARDEVOIR
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_10:
# 461 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_TRICK_ROOM
# 462 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
# 465 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_15
# 469 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_HeartscaleTutor_Text_0
# 470 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_13:
# 473 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 474 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 475 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirLearntDisable
# 476 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 478 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DISABLE_TAUGHT
# 479 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtDisable, MSGBOX_AUTOCLOSE
# 480 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_14:
# 463 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 0, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_15:
# 466 "data/maps/EscapeRoom/scripts.pory"
	setmonmove 1, 2, MOVE_DISABLE
	goto EscapeRoom_EventScript_HeartscaleTutor_13


EscapeRoom_EventScript_CreepySilentNPC::
# 497 "data/maps/EscapeRoom/scripts.pory"
	lock
# 498 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 499 "data/maps/EscapeRoom/scripts.pory"
	msgbox SilentNPCMessage, MSGBOX_AUTOCLOSE
# 500 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PerishExplain_NPC::
# 505 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 506 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 507 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 508 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 509 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 513 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 514 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 521 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 522 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 524 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 525 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 526 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 515 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 516 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 517 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 518 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_0:
# 333 "data/maps/EscapeRoom/scripts.pory"
	.string "something has gone wrong$"

EscapeRoom_EventScript_IniitializeGardevoirTrade_Text_1:
# 338 "data/maps/EscapeRoom/scripts.pory"
	.string "Received Gardevoir$"

EscapeRoom_EventScript_HeartscaleTutor_Text_0:
# 469 "data/maps/EscapeRoom/scripts.pory"
	.string "something went wrong.$"

StartMessage::
# 531 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 535 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

Double1Puzzle_NotEnoughMons::
# 539 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second POKéMON.$"

Double1Puzzle_Intro::
# 543 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 547 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Finalwords::
# 551 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations! You've done it.$"

Double1Puzzle_PostBattle::
# 555 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 559 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your POKéMON!$"

SmeargleMessageInitial::
# 563 "data/maps/EscapeRoom/scripts.pory"
	.string "I love SMEARGLE. Show me the perfect\n"
	.string "SMEARGLE.$"

SmeargleMessageBad::
# 567 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible. I\n"
	.string "asked for the perfect SMEARGLE.$"

SmeargleMessagePerfect::
# 571 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GOTHITA for my GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButGothitaInBox::
# 579 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty GotGOTHITAhita for my GARDEVOIR.\p"
	.string "Oh, where did it go?$"

TradeAcceptedMessage::
# 587 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Good luck!$"

TradeDeclinedMessage::
# 591 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 595 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this GOTHITA...$"

PerishNPCexplain::
# 599 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "POKéMON and PERISH SONG counts down,\l"
	.string "the POKéMON to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 603 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already? I think one of their POKéMON\l"
	.string "is hiding something.$"

Single1Puzzle_Outro::
# 607 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the final duo.$"

Single1Puzzle_PostBattle::
# 611 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 615 "data/maps/EscapeRoom/scripts.pory"
	.string "You think you better than me?$"

Single2Puzzle_Outro::
# 619 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay. I'm impressed.$"

Single2Puzzle_PostBattle::
# 623 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck getting out!$"

Single3Puzzle_Intro::
# 627 "data/maps/EscapeRoom/scripts.pory"
	.string "You can run but you can't hide.$"

Single3Puzzle_Outro::
# 631 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure if you wanted to do that.$"

Single3Puzzle_PostBattle::
# 635 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...$"

MoveTutorNoHeartScales::
# 639 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

MoveTutorStartMessage::
# 643 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move\l"
	.string "if you'd like.$"

AskTeachGardevoirDisable::
# 649 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want me to teach DISABLE to\n"
	.string "your GARDEVOIR?$"

MoveTutorNoSuitablePokemonMessage::
# 653 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, none of your POKéMON can learn\n"
	.string "the moves I teach.$"

MoveTutorTaughtDisable::
# 657 "data/maps/EscapeRoom/scripts.pory"
	.string "Good choice.$"

MoveTutorTradeDeclined::
# 661 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

GardevoirLearntDisable::
# 665 "data/maps/EscapeRoom/scripts.pory"
	.string "Gardevoir learned Disable!$"

BikeShopHelloMessage::
# 669 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, how can I help you?$"

BikeShoptGoodbyeMessage::
# 673 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

SilentNPCMessage::
# 677 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

NuggetNPCmessage::
# 681 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my nuggets?$"

missdirectNPCmessage::
# 685 "data/maps/EscapeRoom/scripts.pory"
	.string "I love a good misdirection.$"

EscapeRoomEndCongratz::
# 688 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!$"

EndEscapeRoomSignMessage::
# 692 "data/maps/EscapeRoom/scripts.pory"
	.string "You have beaten the escape room!$"
