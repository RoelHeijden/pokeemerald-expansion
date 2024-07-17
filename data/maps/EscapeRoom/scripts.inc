EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_UNUSED_0x40F7, 0, StartMessage
# 7 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_UNUSED_0x40F7, 1, FirstPokemon
# 8 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_UNUSED_0x40F7, 2, GetBadges
	.2byte 0


StartMessage::
# 13 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 14 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage_Text_0, type = MSGBOX_NPC
# 15 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 1
# 16 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


FirstPokemon::
# 22 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, ITEM_SITRUS_BERRY, abilityNum = 0, nature = 5, move1 = MOVE_DISABLE, move2 = MOVE_SKILL_SWAP, move3 = MOVE_PAIN_SPLIT, move4 = MOVE_TRICK_ROOM, hpEv = 132, defEv = 252, speedEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 44 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_DITTO, 40, ITEM_NONE
# 49 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 50 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 2
	return


GetBadges::
# 54 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 55 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 56 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 57 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 58 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 59 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 60 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 61 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 62 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 63 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 64 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 65 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 66 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 67 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 68 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 69 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 71 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 3
	end


EscapeRoom_EventScript_TestSign::
# 80 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 81 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TestSign_Text_0
# 82 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GetPokemon::
# 87 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 88 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_SMEARGLE, 19, ITEM_IRON_BALL, abilityNum = 0, nature = 5, move1 = MOVE_PERISH_SONG, move2 = MOVE_PROTECT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 4, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 109 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 109 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 116 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_GetPokemon_Text_1
EscapeRoom_EventScript_GetPokemon_1:
# 118 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GetPokemon_2:
# 110 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 111 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_GetPokemon_Text_0
# 112 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 113 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SMEARGLE_OBTAINED
	goto EscapeRoom_EventScript_GetPokemon_1


EscapeRoom_EventScript_DoubleBattle1::
# 122 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons
# 128 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 129 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


StartMessage_Text_0:
# 14 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

EscapeRoom_EventScript_TestSign_Text_0:
# 81 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off.$"

EscapeRoom_EventScript_GetPokemon_Text_0:
# 111 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit its a Smeargle.$"

EscapeRoom_EventScript_GetPokemon_Text_1:
# 116 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 136 "data/maps/EscapeRoom/scripts.pory"
	.string "You should get a second Pokemon first$"

Double1Puzzle_Intro::
# 140 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have fun.$"

Double1Puzzle_Outro::
# 144 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck. Well played.$"

Double1Puzzle_PostBattle::
# 148 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"
