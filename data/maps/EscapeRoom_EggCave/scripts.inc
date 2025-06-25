EscapeRoom_EggCave_MapScripts::
# 11 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_EggCave_OnResumeMapScripts
# 13 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


EscapeRoom_EggCave_OnResumeMapScripts::
# 20 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_DisableBagUse
# 21 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_SetLostItemVars
	return


EscapeRoom_EggCave_DisableBagUse::
# 26 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EggCave_DisableBagUse_1
	return

EscapeRoom_EggCave_DisableBagUse_1:
# 27 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EggCave_SetLostItemVars::
# 33 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_EggCave_SetLostItemVars_1
	return

EscapeRoom_EggCave_SetLostItemVars_1:
# 35 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_EventScript_TrapinchBlocksPlayer::
# 43 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 46 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_TrapinchBlocksPlayer_2
EscapeRoom_EventScript_TrapinchBlocksPlayer_1:
# 76 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBlocksPlayer_2:
# 49 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 5, TrapinchMoveIn
# 50 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 5
# 53 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceUp
# 54 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 57 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_ENCOUNTER
# 58 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 40
# 59 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmoncry
# 62 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_TrapinchBattle
# 67 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 68 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_HIDE_TRAPINCH
# 69 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 5
# 70 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 73 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_EGGCAVE_MAPSCRIPT_TRAPINCH_TRIGGER, 1
# 74 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RAN_FROM_TRAPINCH
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 79 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceUp:
# 80 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
	step_end

# 83 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 84 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 85 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
# 85 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 89 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 92 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 95 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 100 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 80, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 4, defEv = 0, atkEv = 252, spDefEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 122 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 123 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 96 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1


EscapeRoom_EggCave_EventScript_FindRareCandy::
# 127 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 128 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_RARE_CANDY
# 129 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 130 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 131 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

