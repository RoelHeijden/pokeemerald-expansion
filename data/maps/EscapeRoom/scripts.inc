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
	.2byte 0


EscapeRoom_MapScripts_PlayStartMessage::
# 13 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 14 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 15 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 16 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 22 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, ITEM_SITRUS_BERRY, abilityNum = 0, nature = 5, move1 = MOVE_DISABLE, move2 = MOVE_SKILL_SWAP, move3 = MOVE_PAIN_SPLIT, move4 = MOVE_TRICK_ROOM, hpEv = 132, defEv = 252, speedEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 44 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 45 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 49 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 50 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 51 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 52 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 53 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 54 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 55 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 56 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 57 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 58 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 59 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 60 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 61 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 62 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 63 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 64 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 66 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_EventScript_TestSign::
# 75 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 76 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 77 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GetPokemon::
# 82 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 83 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_SMEARGLE, 19, ITEM_IRON_BALL, abilityNum = 0, nature = 5, move1 = MOVE_PERISH_SONG, move2 = MOVE_PROTECT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 4, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 104 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 104 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 111 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoRoomMsg
EscapeRoom_EventScript_GetPokemon_1:
# 113 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GetPokemon_2:
# 105 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 106 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleObtainedMsg
# 107 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 108 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SMEARGLE_OBTAINED
	goto EscapeRoom_EventScript_GetPokemon_1


EscapeRoom_EventScript_DoubleBattle1::
# 117 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons
# 123 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 124 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


StartMessage::
# 131 "data/maps/EscapeRoom/scripts.pory"
	.string "We're no strangers to love\n"
	.string "You know the rules and so do I\p"
	.string "A full commitment's what I'm\n"
	.string "thinking of\p"
	.string "You wouldn't get this from any\n"
	.string "other guy$"

SignMessage1::
# 138 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off.$"

SmeargleObtainedMsg::
# 142 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 146 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 150 "data/maps/EscapeRoom/scripts.pory"
	.string "You should get a second Pokemon first$"

Double1Puzzle_Intro::
# 154 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have fun.$"

Double1Puzzle_Outro::
# 158 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck. Well played.$"

Double1Puzzle_PostBattle::
# 162 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"
