EscapeRoom_EggCave_MapScripts::
	.byte 0


EscapeRoom_EggCave_EventScript_FindFloatStone::
# 14 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 15 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_FLOAT_STONE
# 16 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 17 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_FLOAT_STONE_OBTAINED
# 18 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TrapinchBlocksPlayer::
# 24 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 27 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_TrapinchBlocksPlayer_2
EscapeRoom_EventScript_TrapinchBlocksPlayer_1:
# 57 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBlocksPlayer_2:
# 30 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 5, TrapinchMoveIn
# 37 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_ENCOUNTER
# 38 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 5
# 39 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 40 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmoncry
# 43 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_TrapinchBattle
# 48 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 49 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_HIDE_TRAPINCH
# 50 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 5
# 51 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 54 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_EGGCAVE_MAPSCRIPT_TRAPINCH_TRIGGER, 1
# 55 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RAN_FROM_TRAPINCH
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 60 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceLeft:
# 61 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_left
	step_end

# 64 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 65 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_right
# 65 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_right
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 69 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 72 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 75 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 80 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 80, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 4, defEv = 0, atkEv = 252, spDefEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 102 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 103 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 76 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1

