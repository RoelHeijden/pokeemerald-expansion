EscapeRoom_EggCave_MapScripts::
# 13 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EggCave_SetWallOnLoad
# 14 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_EggCave_OnResumeMapScripts
# 15 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_EggCave_OnTransitionScripts
# 17 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 19 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script_2 VAR_MAIN_EASTER_EGG_STEP2_COMPLETE_MSG, 1, EscapeRoom_EventScript_MainEasterEggStep2Complete
	.2byte 0


EggCave_SetWallOnLoad::
# 25 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 1
	goto_if_ge EggCave_SetWallOnLoad_1
	return

EggCave_SetWallOnLoad_1:
# 26 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_EASTER_EGG_ROCK_SMACH_USED, EggCave_SetWallOnLoad_3
# 35 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setmetatile 18, 4, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

EggCave_SetWallOnLoad_3:
# 29 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setmetatile 18, 3, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
# 30 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setmetatile 18, 4, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	return


EscapeRoom_EggCave_OnTransitionScripts::
# 42 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_2
EscapeRoom_EggCave_OnTransitionScripts_1:
# 45 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_5
EscapeRoom_EggCave_OnTransitionScripts_4:
# 48 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_8
EscapeRoom_EggCave_OnTransitionScripts_7:
# 51 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_11
EscapeRoom_EggCave_OnTransitionScripts_10:
# 56 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_14
EscapeRoom_EggCave_OnTransitionScripts_13:
# 59 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_17
EscapeRoom_EggCave_OnTransitionScripts_16:
# 62 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_20
EscapeRoom_EggCave_OnTransitionScripts_19:
# 65 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EggCave_OnTransitionScripts_22
	return

EscapeRoom_EggCave_OnTransitionScripts_2:
# 43 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	goto EscapeRoom_EggCave_OnTransitionScripts_1

EscapeRoom_EggCave_OnTransitionScripts_5:
# 46 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	goto EscapeRoom_EggCave_OnTransitionScripts_4

EscapeRoom_EggCave_OnTransitionScripts_8:
# 49 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	goto EscapeRoom_EggCave_OnTransitionScripts_7

EscapeRoom_EggCave_OnTransitionScripts_11:
# 52 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	goto EscapeRoom_EggCave_OnTransitionScripts_10

EscapeRoom_EggCave_OnTransitionScripts_14:
# 57 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	goto EscapeRoom_EggCave_OnTransitionScripts_13

EscapeRoom_EggCave_OnTransitionScripts_17:
# 60 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_LEFT
	goto EscapeRoom_EggCave_OnTransitionScripts_16

EscapeRoom_EggCave_OnTransitionScripts_20:
# 63 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	goto EscapeRoom_EggCave_OnTransitionScripts_19

EscapeRoom_EggCave_OnTransitionScripts_22:
# 66 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_RIGHT
	return


EscapeRoom_EggCave_OnResumeMapScripts::
# 72 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_DisableBagUse
# 73 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_SetLostItemVars
	return


EscapeRoom_EggCave_DisableBagUse::
# 78 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EggCave_DisableBagUse_1
	return

EscapeRoom_EggCave_DisableBagUse_1:
# 79 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EggCave_SetLostItemVars::
# 85 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_EggCave_SetLostItemVars_1
	return

EscapeRoom_EggCave_SetLostItemVars_1:
# 87 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_EventScript_TrapinchBlocksPlayer::
# 97 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 100 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_TrapinchBlocksPlayer_2
EscapeRoom_EventScript_TrapinchBlocksPlayer_1:
# 137 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBlocksPlayer_2:
# 103 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 5, TrapinchMoveIn
# 104 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 5
# 105 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceUp
# 106 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 109 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_ENCOUNTER
# 110 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 40
# 111 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmoncry
# 114 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_TrapinchBattle
# 119 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 120 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 121 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_HIDE_TRAPINCH
# 122 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 5
# 123 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 126 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox TrapinchWentAway, MSGBOX_AUTOCLOSE
# 127 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 130 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_EGGCAVE_MAPSCRIPT_TRAPINCH_TRIGGER, 1
# 131 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RAN_FROM_TRAPINCH
# 134 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 135 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_RescueNurse
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 140 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceUp:
# 141 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
	step_end

# 143 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 144 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 145 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
# 145 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 149 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 152 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 155 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 159 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 90, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 0, defEv = 0, atkEv = 252, spDefEv = 4, speedEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 182 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 183 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 156 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1


EscapeRoom_EventScript_RescueNurse::
# 188 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_PIN
# 189 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseFaceRight
# 190 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 191 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 192 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 193 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 194 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseToPlayer
# 195 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 198 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceLeft
# 199 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 202 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage1, MSGBOX_DEFAULT
# 203 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 206 "data/maps/EscapeRoom_EggCave/scripts.pory"
	addmoney 2000
# 207 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 208 "data/maps/EscapeRoom_EggCave/scripts.pory"
	message MoneyReceived
# 209 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 210 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitfanfare
# 211 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
# 214 "data/maps/EscapeRoom_EggCave/scripts.pory"
	partymonhasfainted
# 215 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 218 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_RescueNurse_2
EscapeRoom_EventScript_RescueNurse_1:
# 228 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 231 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage2, MSGBOX_AUTOCLOSE
# 232 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 235 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayerAside
# 236 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 239 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseAway
# 240 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 243 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_EXIT
# 244 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 5
# 245 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 7
# 246 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_NURSE_RESCUED
# 247 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
	return

EscapeRoom_EventScript_RescueNurse_2:
# 219 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessageHeal1, MSGBOX_DEFAULT
# 221 "data/maps/EscapeRoom_EggCave/scripts.pory"
	special HealPlayerParty
# 222 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_USE_ITEM
# 223 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 224 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
# 225 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
# 226 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_RescueNurse_1


# 250 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseFaceRight:
# 251 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
	step_end

# 253 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseToPlayer:
# 254 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 255 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_up
# 256 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
# 257 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 257 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
	step_end

# 259 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseAway:
# 260 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 260 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 260 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 261 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 262 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_down
	step_end

# 264 "data/maps/EscapeRoom_EggCave/scripts.pory"
MovePlayerAside:
# 265 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 266 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_up
# 267 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
	step_end

# 269 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceLeft:
# 270 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_left
	step_end

EscapeRoom_EggCave_EventScript_FindRareCandy1::
# 275 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 276 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_RARE_CANDY
# 277 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 278 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RARE_CANDY1_OBTAINED
# 279 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


TrapinchWentAway::
# 284 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "The Trapinch disappeared into the\n"
	.string "ground.$"

NurseMessage1::
# 289 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Thank you so much!\n"
	.string "That Pokémon would not let me out!\p"
	.string "I don't know what I would've done if\n"
	.string "it weren't for you.\p"
	.string "Here, take this.\n"
	.string "Call it a rescue reward!$"

NurseMessageHeal1::
# 298 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "It also looks like your Pokémon got\n"
	.string "hurt in battle.\p"
	.string "Allow me to fix that.$"

NurseMessage2::
# 304 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Take care!$"

MoneyReceived::
# 308 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "{PLAYER} received ¥2000!$"
