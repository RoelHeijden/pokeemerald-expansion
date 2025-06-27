EscapeRoom_EggCave_MapScripts::
# 13 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_EggCave_OnResumeMapScripts
# 15 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


EscapeRoom_EggCave_OnResumeMapScripts::
# 22 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_DisableBagUse
# 23 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_SetLostItemVars
	return


EscapeRoom_EggCave_DisableBagUse::
# 28 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EggCave_DisableBagUse_1
	return

EscapeRoom_EggCave_DisableBagUse_1:
# 29 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EggCave_SetLostItemVars::
# 35 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_EggCave_SetLostItemVars_1
	return

EscapeRoom_EggCave_SetLostItemVars_1:
# 37 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_EventScript_TrapinchBlocksPlayer::
# 45 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 48 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_TrapinchBlocksPlayer_2
EscapeRoom_EventScript_TrapinchBlocksPlayer_1:
# 79 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBlocksPlayer_2:
# 51 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 5, TrapinchMoveIn
# 52 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 5
# 55 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceUp
# 56 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 59 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_ENCOUNTER
# 60 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 40
# 61 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmoncry
# 64 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_TrapinchBattle
# 69 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_EXIT
# 70 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 71 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_HIDE_TRAPINCH
# 72 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 5
# 73 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 76 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_EGGCAVE_MAPSCRIPT_TRAPINCH_TRIGGER, 1
# 77 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RAN_FROM_TRAPINCH
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 82 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceUp:
# 83 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
	step_end

# 86 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 87 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 88 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
# 88 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 92 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 95 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 98 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 103 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 80, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 4, defEv = 0, atkEv = 252, spDefEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 125 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 126 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 99 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1


EscapeRoom_EggCave_EventScript_FindRareCandy::
# 130 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 131 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_RARE_CANDY
# 132 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 133 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 134 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


EscapeRoom_EggCave_EventScript_Find2000Cash::
# 138 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 139 "data/maps/EscapeRoom_EggCave/scripts.pory"
	addmoney 2000
# 140 "data/maps/EscapeRoom_EggCave/scripts.pory"
	message EscapeRoom_EggCave_EventScript_Find2000Cash_Text_0
# 141 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 142 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitfanfare
# 143 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 7
# 144 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_2000_CASH_OBTAINED
# 145 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


EscapeRoom_EggCave_EventScript_Find2000Cash_Text_0:
# 140 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "{PLAYER} received ¥2.000!$"
