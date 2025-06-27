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
# 47 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 50 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_TrapinchBlocksPlayer_2
EscapeRoom_EventScript_TrapinchBlocksPlayer_1:
# 83 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBlocksPlayer_2:
# 53 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 5, TrapinchMoveIn
# 54 "data/maps/EscapeRoom_EggCave/scripts.pory"
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
# 80 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 81 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_RescueNurse
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 87 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceUp:
# 88 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
	step_end

# 91 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 92 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 93 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
# 93 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 97 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 100 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 103 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 107 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 90, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 0, defEv = 0, atkEv = 252, spDefEv = 4, speedEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 130 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 131 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 104 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1


EscapeRoom_EventScript_RescueNurse::
# 136 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_PIN
# 137 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 138 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 139 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 140 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseToPlayer
# 141 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 144 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceLeft
# 145 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 148 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage1, MSGBOX_AUTOCLOSE
# 149 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 152 "data/maps/EscapeRoom_EggCave/scripts.pory"
	addmoney 2000
# 153 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 154 "data/maps/EscapeRoom_EggCave/scripts.pory"
	message MoneyReceived
# 155 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 156 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitfanfare
# 157 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 15
# 158 "data/maps/EscapeRoom_EggCave/scripts.pory"
	closemessage
# 159 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 5
# 162 "data/maps/EscapeRoom_EggCave/scripts.pory"
	partymonhasfainted
# 163 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 164 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_RescueNurse_2
EscapeRoom_EventScript_RescueNurse_1:
# 174 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 177 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage2, MSGBOX_AUTOCLOSE
# 178 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 181 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayerAside
# 182 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 185 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseAway
# 186 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 189 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_EXIT
# 190 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 5
# 191 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 7
# 192 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_NURSE_RESCUED
# 193 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
	return

EscapeRoom_EventScript_RescueNurse_2:
# 166 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessageHeal1, MSGBOX_AUTOCLOSE
# 167 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 169 "data/maps/EscapeRoom_EggCave/scripts.pory"
	special HealPlayerParty
# 170 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_USE_ITEM
# 171 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
# 172 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
	goto EscapeRoom_EventScript_RescueNurse_1


# 196 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseToPlayer:
# 197 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 198 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_up
# 199 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
# 200 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
	step_end

# 203 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseAway:
# 204 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 204 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 204 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 205 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 206 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_down
	step_end

# 209 "data/maps/EscapeRoom_EggCave/scripts.pory"
MovePlayerAside:
# 210 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 211 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_up
# 212 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
	step_end

# 215 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceLeft:
# 216 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_left
	step_end

EscapeRoom_EggCave_EventScript_FindRareCandy::
# 221 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 222 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_RARE_CANDY
# 223 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 224 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 225 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


NurseMessage1::
# 240 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Thank you so much!\p"
	.string "That Trapinch would not let me out.\p"
	.string "I don't know what I would've done if it\n"
	.string "weren't for you!\p"
	.string "Here, take this.\n"
	.string "Call it a rescue reward!$"

NurseMessageHeal1::
# 249 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Let me fix you up as well.$"

NurseMessage2::
# 253 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Take care!$"

MoneyReceived::
# 257 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "{PLAYER} received ¥2.000!$"
