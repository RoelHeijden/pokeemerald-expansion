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
# 39 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 5, move1 = MOVE_PAIN_SPLIT, move2 = MOVE_SKILL_SWAP, move3 = MOVE_DISABLE, move4 = MOVE_TRICK_ROOM, hpEv = 132, defEv = 212, speedEv = 52, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 60 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 80 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 81 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 85 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 86 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 87 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 88 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 89 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 90 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 91 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 92 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 93 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 94 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 95 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 96 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 97 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 98 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 99 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 100 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 102 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 107 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 108 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 112 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 113 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_MACH_BIKE
# 114 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 118 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 121 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 119 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 129 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 130 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 131 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 132 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 136 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 137 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 138 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 139 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 140 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 141 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 142 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 146 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Smeargle_2
EscapeRoom_Wild_Smeargle_1:
# 149 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 170 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 172 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Smeargle_2:
# 147 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Smeargle_1


EscapeRoom_Wild_Shedinja::
# 176 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_Wild_Shedinja_2
EscapeRoom_Wild_Shedinja_1:
# 179 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 190 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
# 192 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return

EscapeRoom_Wild_Shedinja_2:
# 177 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_Wild_Shedinja_1


EscapeRoom_EventScript_DoubleBattle1::
# 196 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostDouble1Heal
# 203 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostDouble1Heal::
# 209 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
# 210 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_Heal, MSGBOX_AUTOCLOSE
# 211 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 212 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 213 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


EscapeRoom_EventScript_FindRainDance::
# 217 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 218 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_TM_RAIN_DANCE
# 219 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 220 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RAIN_DANCE_OBTAINED
# 221 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 225 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 226 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 227 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 228 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 229 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget::
# 233 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 234 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_NUGGET
# 235 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 236 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET2_OBTAINED
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
# 250 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 251 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 258 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 259 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 267 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 268 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 276 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PERISH_SONG
# 277 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 286 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 287 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 288 "data/maps/EscapeRoom/scripts.pory"
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
# 252 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 253 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 254 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 260 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 261 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 262 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 263 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 264 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 259 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 269 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 270 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 271 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 272 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 273 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 268 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 278 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageConfusedButGood
# 279 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 280 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 281 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 282 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 277 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17


EscapeRoom_EventScript_PerishExplain_NPC::
# 293 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 294 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 295 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 296 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 297 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_SingleBattle1::
# 301 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 302 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerries
# 308 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 309 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_GetSitrusBerries::
# 314 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


EscapeRoom_EventScript_SingleBattle2::
# 318 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro
# 323 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 324 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


StartMessage::
# 332 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 336 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

SmeargleObtainedMsg::
# 340 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 344 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 348 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second Pokemon.$"

Double1Puzzle_Intro::
# 352 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 356 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 360 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 364 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your Pokemon!$"

Double1Puzzle_Heal::
# 368 "data/maps/EscapeRoom/scripts.pory"
	.string "Let us heal your Pokemon.$"

SmeargleMessageInitial::
# 372 "data/maps/EscapeRoom/scripts.pory"
	.string "I love Smeargle. Show me the perfect\n"
	.string "Smeargle.$"

SmeargleMessagePerfect::
# 376 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "Smeargle!$"

SmeargleMessageBad::
# 380 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that Smeargle looks horrible. I\n"
	.string "asked for the perfect Smeargle.$"

SmeargleMessageConfusedButGood::
# 384 "data/maps/EscapeRoom/scripts.pory"
	.string "I do not know how you managed to obtain\n"
	.string "this Smeargle already.$"

SmeargleMessageCompleted::
# 388 "data/maps/EscapeRoom/scripts.pory"
	.string "You have brightened my day. Thank you.$"

PerishNPCexplain::
# 392 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "Pokémon and Perish Song counts down,\l"
	.string "the Pokémon to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 396 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you try to fight the duo at the exit\n"
	.string "already? I think one of their Pokémon\l"
	.string "is hiding something.$"

Single1Puzzle_Outro::
# 400 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the final duo.$"

Single1Puzzle_PostBattle::
# 404 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"

Single2Puzzle_Intro::
# 408 "data/maps/EscapeRoom/scripts.pory"
	.string "You think you better than me?$"

Single2Puzzle_Outro::
# 412 "data/maps/EscapeRoom/scripts.pory"
	.string "Okay. I'm impressed.$"

Single2Puzzle_PostBattle::
# 416 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck getting out!$"
