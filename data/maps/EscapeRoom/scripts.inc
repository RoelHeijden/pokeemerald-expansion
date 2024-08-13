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
	.2byte 0


EscapeRoom_MapScripts_PlayStartMessage::
# 14 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 15 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage
# 16 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 17 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 23 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, ITEM_SITRUS_BERRY, abilityNum = 0, nature = 5, move1 = MOVE_DISABLE, move2 = MOVE_SKILL_SWAP, move3 = MOVE_PAIN_SPLIT, move4 = MOVE_TRICK_ROOM, hpEv = 132, defEv = 252, speedEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 45 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 46 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 50 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 51 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 52 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 53 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 54 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 55 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 56 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 57 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 58 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 59 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 60 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 61 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 62 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 63 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 64 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 65 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 67 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 72 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 73 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_EventScript_TestSign::
# 82 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 83 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 84 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 88 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 89 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 90 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 91 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 92 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 93 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GetPokemon::
# 97 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 98 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_SMEARGLE, 20, ITEM_IRON_BALL, abilityNum = 0, nature = 5, move1 = MOVE_PERISH_SONG, move2 = MOVE_PROTECT, move3 = MOVE_NONE, move4 = MOVE_NONE, defEv = 252, hpIv = 22, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 118 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 118 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 125 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoRoomMsg
EscapeRoom_EventScript_GetPokemon_1:
# 127 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GetPokemon_2:
# 119 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 120 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleObtainedMsg
# 121 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 122 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SMEARGLE_OBTAINED
	goto EscapeRoom_EventScript_GetPokemon_1


EscapeRoom_EventScript_DoubleBattle1::
# 131 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostDouble1Heal
# 138 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 139 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostDouble1Heal::
# 144 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_Heal, MSGBOX_AUTOCLOSE
# 145 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 146 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 147 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


StartMessage::
# 155 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

SignMessage1::
# 159 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off mate.$"

SmeargleObtainedMsg::
# 163 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit it's a Smeargle.$"

NoRoomMsg::
# 167 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"

Double1Puzzle_NotEnoughMons::
# 171 "data/maps/EscapeRoom/scripts.pory"
	.string "You first should get a second Pokemon.$"

Double1Puzzle_Intro::
# 175 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck have no fun.$"

Double1Puzzle_Outro::
# 179 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Double1Puzzle_PostBattle::
# 183 "data/maps/EscapeRoom/scripts.pory"
	.string "We're done now.$"

Nurse_Heal_End::
# 187 "data/maps/EscapeRoom/scripts.pory"
	.string "I healed your Pokemon!$"

Double1Puzzle_Heal::
# 191 "data/maps/EscapeRoom/scripts.pory"
	.string "Let us heal your Pokemon.$"
