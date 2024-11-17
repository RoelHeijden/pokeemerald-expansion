EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScripts_PlayStartMessage
# 7 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1, EscapeRoom_MapScripts_GetFirstPokemon
# 8 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2, EscapeRoom_MapScripts_GetBadges
# 9 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3, EscapeRoom_MapScripts_SetRespawn
# 10 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4, EscapeRoom_MapScripts_GetItems
	.2byte 0


EscapeRoom_MapScripts_PlayStartMessage::
# 15 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 16 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 17 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 18 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 45 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GOTHITA, 30, item = ITEM_HEART_SCALE, abilityNum = 2, nature = 11, move1 = MOVE_THIEF, move2 = MOVE_HELPING_HAND, move3 = MOVE_NONE, move4 = MOVE_NONE, speedEv = 236, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 65 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 66 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 70 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 71 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 72 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 73 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 74 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 75 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 76 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 77 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 78 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 79 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 80 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 81 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 82 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 83 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 84 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 85 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 87 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 92 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 93 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 97 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 98 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_MACH_BIKE
# 99 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_EventScript_TestSign::
# 108 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 109 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 110 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 111 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 115 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 116 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 117 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 118 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 119 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 120 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 121 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Wild_Smeargle::
# 125 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 146 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
	return


EscapeRoom_Wild_Shedinja::
# 150 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 161 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
	return


EscapeRoom_EventScript_DoubleBattle1::
# 165 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_DoubleBattle1_2
EscapeRoom_EventScript_DoubleBattle1_1:
# 168 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostDouble1Heal
# 175 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 176 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_DoubleBattle1_2:
# 166 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_DoubleBattle1_1


EscapeRoom_EventScript_PostDouble1Heal::
# 181 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
# 182 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_Heal, MSGBOX_AUTOCLOSE
# 183 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 184 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 185 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


EscapeRoom_EventScript_FindRainDance::
# 189 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 190 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_TM_RAIN_DANCE
# 191 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 192 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RAIN_DANCE_OBTAINED
# 193 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 197 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 198 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 199 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 206 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 207 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 214 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 215 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 223 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 224 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 232 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PERISH_SONG
# 233 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 242 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 243 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 244 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 200 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 201 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 202 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 208 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 209 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 210 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 216 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 217 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 218 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 219 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 220 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 215 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 225 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 226 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 227 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 228 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 229 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 224 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 234 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageConfusedButGood
# 235 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 236 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 237 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 238 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 233 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17


EscapeRoom_EventScript_PerishExplain_NPC::
# 249 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 250 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 251 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 252 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 253 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_SingleBattle1::
# 257 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 258 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_SingleBattle1_2
EscapeRoom_EventScript_SingleBattle1_1:
# 261 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerries
# 267 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 268 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_SingleBattle1_2:
# 259 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_SingleBattle1_1


EscapeRoom_EventScript_GetSitrusBerries::
# 273 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


StartMessage::
# 280 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 284 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

SmeargleObtainedMsg::
# 288 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 292 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 296 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second Pokemon.$"

Double1Puzzle_Intro::
# 300 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 304 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 308 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 312 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your Pokemon!$"

Double1Puzzle_Heal::
# 316 "data/maps/EscapeRoom/scripts.pory"
	.string "Let us heal your Pokemon.$"

SmeargleMessageInitial::
# 320 "data/maps/EscapeRoom/scripts.pory"
	.string "I love Smeargle. Show me the perfect\n"
	.string "Smeargle.$"

SmeargleMessagePerfect::
# 324 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "Smeargle!$"

SmeargleMessageBad::
# 328 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that Smeargle looks horrible. I\n"
	.string "asked for the perfect Smeargle.$"

SmeargleMessageConfusedButGood::
# 332 "data/maps/EscapeRoom/scripts.pory"
	.string "I do not know how you managed to obtain\n"
	.string "this Smeargle already.$"

SmeargleMessageCompleted::
# 336 "data/maps/EscapeRoom/scripts.pory"
	.string "You have brightened my day. Thank you.$"

PerishNPCexplain::
# 340 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "Pokémon and Perish Song counts down,\l"
	.string "the Pokémon to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 344 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you fight against the duo already?\n"
	.string "I think one of their Pokémon is hiding\l"
	.string "something.$"

Single1Puzzle_Outro::
# 348 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the duo.$"

Single1Puzzle_PostBattle::
# 352 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"
