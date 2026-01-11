EscapeRoom_EggCave_MapScripts::
# 13 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EggCave_SetWallOnLoad
# 14 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_EggCave_OnResumeMapScripts
# 16 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_EggCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 17 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 18 "data/maps/EscapeRoom_EggCave/scripts.pory"
	map_script_2 VAR_MAIN_EASTER_EGG_STEP2_COMPLETE_MSG, 1, EscapeRoom_EventScript_MainEasterEggStep2Complete
	.2byte 0


EggCave_SetWallOnLoad::
# 24 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_MAIN_EASTER_EGG_STATE, 1
	goto_if_ge EggCave_SetWallOnLoad_1
	return

EggCave_SetWallOnLoad_1:
# 25 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_EASTER_EGG_ROCK_SMACH_USED, EggCave_SetWallOnLoad_3
# 34 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setmetatile 18, 4, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

EggCave_SetWallOnLoad_3:
# 28 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setmetatile 18, 3, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
# 29 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setmetatile 18, 4, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	return


EscapeRoom_EggCave_OnResumeMapScripts::
# 41 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_DisableBagUse
# 42 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EggCave_SetLostItemVars
	return


EscapeRoom_EggCave_DisableBagUse::
# 47 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_EggCave_DisableBagUse_1
	return

EscapeRoom_EggCave_DisableBagUse_1:
# 48 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EggCave_SetLostItemVars::
# 54 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_EggCave_SetLostItemVars_1
	return

EscapeRoom_EggCave_SetLostItemVars_1:
# 56 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_EventScript_TrapinchBlocksPlayer::
# 66 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 69 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_unset FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_TrapinchBlocksPlayer_2
EscapeRoom_EventScript_TrapinchBlocksPlayer_1:
# 106 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBlocksPlayer_2:
# 72 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 5, TrapinchMoveIn
# 73 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 5
# 74 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceUp
# 75 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 78 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_ENCOUNTER
# 79 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 40
# 80 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmoncry
# 83 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_TrapinchBattle
# 88 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 89 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 90 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_HIDE_TRAPINCH
# 91 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 5
# 92 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 95 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox TrapinchWentAway, MSGBOX_AUTOCLOSE
# 96 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 99 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_EGGCAVE_MAPSCRIPT_TRAPINCH_TRIGGER, 1
# 100 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RAN_FROM_TRAPINCH
# 103 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 104 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_RescueNurse
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 109 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceUp:
# 110 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
	step_end

# 112 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 113 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 114 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
# 114 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 118 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 121 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 124 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 128 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 90, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 0, defEv = 0, atkEv = 252, spDefEv = 4, speedEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 151 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 152 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 125 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1


EscapeRoom_EventScript_RescueNurse::
# 157 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_PIN
# 158 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseFaceRight
# 159 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 160 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 161 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 162 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 163 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseToPlayer
# 164 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 167 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceLeft
# 168 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 171 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage1, MSGBOX_DEFAULT
# 172 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 175 "data/maps/EscapeRoom_EggCave/scripts.pory"
	addmoney 2000
# 176 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 177 "data/maps/EscapeRoom_EggCave/scripts.pory"
	message MoneyReceived
# 178 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 179 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitfanfare
# 180 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
# 183 "data/maps/EscapeRoom_EggCave/scripts.pory"
	partymonhasfainted
# 184 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 187 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_RescueNurse_2
EscapeRoom_EventScript_RescueNurse_1:
# 197 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 200 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage2, MSGBOX_AUTOCLOSE
# 201 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 204 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayerAside
# 205 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 208 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseAway
# 209 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 212 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_EXIT
# 213 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 5
# 214 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 7
# 215 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_NURSE_RESCUED
# 216 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
	return

EscapeRoom_EventScript_RescueNurse_2:
# 188 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessageHeal1, MSGBOX_DEFAULT
# 190 "data/maps/EscapeRoom_EggCave/scripts.pory"
	special HealPlayerParty
# 191 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_USE_ITEM
# 192 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 193 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
# 194 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
# 195 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_RescueNurse_1


# 219 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseFaceRight:
# 220 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
	step_end

# 222 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseToPlayer:
# 223 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 224 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_up
# 225 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
# 226 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 226 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
	step_end

# 228 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseAway:
# 229 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 229 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 229 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 230 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 231 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_down
	step_end

# 233 "data/maps/EscapeRoom_EggCave/scripts.pory"
MovePlayerAside:
# 234 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 235 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_up
# 236 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
	step_end

# 238 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceLeft:
# 239 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_left
	step_end

EscapeRoom_EggCave_EventScript_FindRareCandy1::
# 244 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 245 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_RARE_CANDY
# 246 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 247 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RARE_CANDY1_OBTAINED
# 248 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


TrapinchWentAway::
# 253 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "The Trapinch disappeared into the\n"
	.string "ground.$"

NurseMessage1::
# 258 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Thank you so much!\n"
	.string "That Pokémon would not let me out!\p"
	.string "I don't know what I would've done if\n"
	.string "it weren't for you.\p"
	.string "Here, take this.\n"
	.string "Call it a rescue reward!$"

NurseMessageHeal1::
# 267 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "It also looks like your Pokémon got\n"
	.string "hurt in battle.\p"
	.string "Allow me to fix that.$"

NurseMessage2::
# 273 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Take care!$"

MoneyReceived::
# 277 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "{PLAYER} received ¥2000!$"
