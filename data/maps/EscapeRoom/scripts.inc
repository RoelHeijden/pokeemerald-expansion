EscapeRoom_MapScripts::
# 3 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_UNUSED_0x40F7, 0, StartMessage
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_UNUSED_0x40F7, 1, FirstPokemon
	.2byte 0


StartMessage::
# 11 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 12 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage_Text_0, type = MSGBOX_NPC
# 13 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 1
# 14 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


FirstPokemon::
# 18 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, ITEM_SITRUS_BERRY, abilityNum = 0, nature = 5, move1 = MOVE_DISABLE, move2 = MOVE_SKILL_SWAP, move3 = MOVE_PAIN_SPLIT, move4 = MOVE_TRICK_ROOM, hpEv = 132, defEv = 252, speedEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 40 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 41 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 2
	end


EscapeRoom_EventScript_TestSign::
# 47 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 48 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TestSign_Text_0
# 49 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GetPokemon::
# 56 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 57 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_SMEARGLE, 19, ITEM_IRON_BALL, abilityNum = 0, nature = 5, move1 = MOVE_PERISH_SONG, move2 = MOVE_PROTECT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 4, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 78 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 78 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 85 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_GetPokemon_Text_1
EscapeRoom_EventScript_GetPokemon_1:
# 87 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GetPokemon_2:
# 79 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_GetPokemon_Text_0
# 81 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 82 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_UNUSED_0x020
	goto EscapeRoom_EventScript_GetPokemon_1


StartMessage_Text_0:
# 12 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

EscapeRoom_EventScript_TestSign_Text_0:
# 48 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off.$"

EscapeRoom_EventScript_GetPokemon_Text_0:
# 80 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh shit its a Smeargle.$"

EscapeRoom_EventScript_GetPokemon_Text_1:
# 85 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"
