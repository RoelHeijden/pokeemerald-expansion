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
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5, EscapeRoom_MapScripts_FixCrackedGround
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
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 31 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 32 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 33 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 34 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 61 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 81 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 82 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 86 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 87 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 88 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 89 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 90 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 91 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 92 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 93 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 94 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 95 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 96 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 97 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 98 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 99 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 100 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 101 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 103 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 108 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 109 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 113 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 114 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_MACH_BIKE
# 115 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_EventScript_TestSign::
# 124 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 125 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 126 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 127 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 131 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 132 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 133 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 134 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 135 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 136 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 137 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 141 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 162 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
	return


EscapeRoom_Wild_Shedinja::
# 166 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 177 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
	return


EscapeRoom_EventScript_DoubleBattle1::
# 181 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_DoubleBattle1_2
EscapeRoom_EventScript_DoubleBattle1_1:
# 184 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostDouble1Heal
# 191 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 192 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_DoubleBattle1_2:
# 182 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_DoubleBattle1_1


EscapeRoom_EventScript_PostDouble1Heal::
# 197 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
# 198 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_Heal, MSGBOX_AUTOCLOSE
# 199 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 200 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 201 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


EscapeRoom_EventScript_FindRainDance::
# 205 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 206 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_TM_RAIN_DANCE
# 207 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 208 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RAIN_DANCE_OBTAINED
# 209 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 213 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 214 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 215 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 216 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
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
# 230 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 231 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 238 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 247 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 256 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PERISH_SONG
# 257 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 266 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 267 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 268 "data/maps/EscapeRoom/scripts.pory"
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
# 232 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 233 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 234 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 240 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 241 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 242 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 243 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 244 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 239 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 249 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 250 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 251 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 252 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 253 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 258 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageConfusedButGood
# 259 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 260 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 261 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 262 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 257 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17


EscapeRoom_EventScript_PerishExplain_NPC::
# 273 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 274 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 275 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 276 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 277 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_SingleBattle1::
# 281 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 282 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_SingleBattle1_2
EscapeRoom_EventScript_SingleBattle1_1:
# 285 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerries
# 291 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 292 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_SingleBattle1_2:
# 283 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_SingleBattle1_1


EscapeRoom_EventScript_GetSitrusBerries::
# 297 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


StartMessage::
# 305 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 309 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

SmeargleObtainedMsg::
# 313 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 317 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 321 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second Pokemon.$"

Double1Puzzle_Intro::
# 325 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 329 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 333 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 337 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your Pokemon!$"

Double1Puzzle_Heal::
# 341 "data/maps/EscapeRoom/scripts.pory"
	.string "Let us heal your Pokemon.$"

SmeargleMessageInitial::
# 345 "data/maps/EscapeRoom/scripts.pory"
	.string "I love Smeargle. Show me the perfect\n"
	.string "Smeargle.$"

SmeargleMessagePerfect::
# 349 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "Smeargle!$"

SmeargleMessageBad::
# 353 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that Smeargle looks horrible. I\n"
	.string "asked for the perfect Smeargle.$"

SmeargleMessageConfusedButGood::
# 357 "data/maps/EscapeRoom/scripts.pory"
	.string "I do not know how you managed to obtain\n"
	.string "this Smeargle already.$"

SmeargleMessageCompleted::
# 361 "data/maps/EscapeRoom/scripts.pory"
	.string "You have brightened my day. Thank you.$"

PerishNPCexplain::
# 365 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "Pokémon and Perish Song counts down,\l"
	.string "the Pokémon to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 369 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you fight against the duo already?\n"
	.string "I think one of their Pokémon is hiding\l"
	.string "something.$"

Single1Puzzle_Outro::
# 373 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the duo.$"

Single1Puzzle_PostBattle::
# 377 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"
