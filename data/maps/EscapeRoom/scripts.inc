EscapeRoom_MapScripts::
# 3 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_UNUSED_0x40F7, 0, StartMessage
	.2byte 0


StartMessage::
# 10 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 11 "data/maps/EscapeRoom/scripts.pory"
	msgbox StartMessage_Text_0, type = MSGBOX_NPC
# 12 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 1
# 13 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TestSign::
# 19 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 20 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TestSign_Text_0
# 21 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GetPokemon::
# 28 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 29 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_SMEARGLE, 19, ITEM_IRON_BALL, abilityNum = 0, nature = 5, move1 = MOVE_PERISH_SONG, move2 = MOVE_PROTECT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 4, defEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 51 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 51 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EscapeRoom_EventScript_GetPokemon_2
# 58 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_GetPokemon_Text_1
EscapeRoom_EventScript_GetPokemon_1:
# 60 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GetPokemon_2:
# 52 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 53 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_GetPokemon_Text_0
# 54 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 55 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_UNUSED_0x020
	goto EscapeRoom_EventScript_GetPokemon_1


StartMessage_Text_0:
# 11 "data/maps/EscapeRoom/scripts.pory"
	.string "Good luck.$"

EscapeRoom_EventScript_TestSign_Text_0:
# 20 "data/maps/EscapeRoom/scripts.pory"
	.string "Fock off.$"

EscapeRoom_EventScript_GetPokemon_Text_0:
# 53 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle Received.$"

EscapeRoom_EventScript_GetPokemon_Text_1:
# 58 "data/maps/EscapeRoom/scripts.pory"
	.string "no room.$"
