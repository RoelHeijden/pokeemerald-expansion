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
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4, EscapeRoom_MapScripts_GetIronBall
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


EscapeRoom_MapScripts_GetIronBall::
# 97 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_IRON_BALL
# 98 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


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
	createmon side = 1, slot = 0, species = SPECIES_SMEARGLE, level = 20, abilityNum = 0, nature = 7, move1 = MOVE_SKETCH, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 208, hpIv = 11, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 145 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
	return


EscapeRoom_Wild_Shedinja::
# 149 "data/maps/EscapeRoom/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_SHEDINJA, level = 10, item = ITEM_FLAME_ORB, move1 = MOVE_PROTECT, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE
# 160 "data/maps/EscapeRoom/scripts.pory"
	dowildbattle
	return


EscapeRoom_EventScript_DoubleBattle1::
# 164 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_DoubleBattle1_2
EscapeRoom_EventScript_DoubleBattle1_1:
# 167 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostDouble1Heal
# 174 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 175 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_DoubleBattle1_2:
# 165 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_DoubleBattle1_1


EscapeRoom_EventScript_PostDouble1Heal::
# 180 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
# 181 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_Heal, MSGBOX_AUTOCLOSE
# 182 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 183 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 184 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


EscapeRoom_EventScript_FindRainDance::
# 188 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 189 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_TM_RAIN_DANCE
# 190 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 191 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RAIN_DANCE_OBTAINED
# 192 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 196 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 197 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 198 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_PERFECT_SMEARGLE, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 205 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 206 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_5
# 213 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 214 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 222 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 223 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 231 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PERISH_SONG
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_19
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 241 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
# 242 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 243 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 199 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 200 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 201 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_5:
# 207 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 208 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 209 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 215 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 216 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 217 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 218 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 219 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 214 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 224 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect
# 225 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 226 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 227 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 228 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 223 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 233 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageConfusedButGood
# 234 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 235 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 236 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_OBTAINED_PERFECT_SMEARGLE
# 237 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_19:
# 232 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_18
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17


EscapeRoom_EventScript_PerishExplain_NPC::
# 248 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 249 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 250 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain
# 251 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 252 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_SingleBattle1::
# 256 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 257 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_SingleBattle1_2
EscapeRoom_EventScript_SingleBattle1_1:
# 260 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_GetSitrusBerries
# 266 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 267 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_SingleBattle1_2:
# 258 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_SingleBattle1_1


EscapeRoom_EventScript_GetSitrusBerries::
# 272 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 99
	return


StartMessage::
# 279 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 283 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

SmeargleObtainedMsg::
# 287 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 291 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 295 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle? You should first get a\n"
	.string "second Pokemon.$"

Double1Puzzle_Intro::
# 299 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 303 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 307 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 311 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your Pokemon!$"

Double1Puzzle_Heal::
# 315 "data/maps/EscapeRoom/scripts.pory"
	.string "Let us heal your Pokemon.$"

SmeargleMessageInitial::
# 319 "data/maps/EscapeRoom/scripts.pory"
	.string "I love Smeargle. Show me the perfect\n"
	.string "Smeargle.$"

SmeargleMessagePerfect::
# 323 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "Smeargle!$"

SmeargleMessageBad::
# 327 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that Smeargle looks horrible. I\n"
	.string "asked for the perfect Smeargle.$"

SmeargleMessageConfusedButGood::
# 331 "data/maps/EscapeRoom/scripts.pory"
	.string "I do not know how you managed to obtain\n"
	.string "this Smeargle already.$"

SmeargleMessageCompleted::
# 335 "data/maps/EscapeRoom/scripts.pory"
	.string "You have brightened my day. Thank you.$"

PerishNPCexplain::
# 339 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know? In competitive battles,\n"
	.string "if both players are down to their final\l"
	.string "Pokémon and Perish Song counts down,\l"
	.string "the Pokémon to faint last is declared\l"
	.string "the winner! Isn’t that fun?$"

Single1Puzzle_Intro::
# 343 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you fight against the duo already?\n"
	.string "I think one of their Pokémon is hiding\l"
	.string "something.$"

Single1Puzzle_Outro::
# 347 "data/maps/EscapeRoom/scripts.pory"
	.string "Here, this should help you beat the duo.$"

Single1Puzzle_PostBattle::
# 351 "data/maps/EscapeRoom/scripts.pory"
	.string "You can beat them. I believe in you!$"
