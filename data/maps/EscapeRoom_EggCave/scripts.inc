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
# 87 "data/maps/EscapeRoom_EggCave/scripts.pory"
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
	lockall
# 70 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 71 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_HIDE_TRAPINCH
# 72 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 5
# 73 "data/maps/EscapeRoom_EggCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 76 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox TrapinchWentAway, MSGBOX_AUTOCLOSE
# 77 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 80 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setvar VAR_EGGCAVE_MAPSCRIPT_TRAPINCH_TRIGGER, 1
# 81 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RAN_FROM_TRAPINCH
# 84 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 85 "data/maps/EscapeRoom_EggCave/scripts.pory"
	call EscapeRoom_EventScript_RescueNurse
	goto EscapeRoom_EventScript_TrapinchBlocksPlayer_1


# 91 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceUp:
# 92 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
	step_end

# 95 "data/maps/EscapeRoom_EggCave/scripts.pory"
TrapinchMoveIn:
# 96 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 97 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
# 97 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_faster_down
	step_end

EscapeRoom_EventScript_TrapinchBattle::
# 101 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 104 "data/maps/EscapeRoom_EggCave/scripts.pory"
	backupplayerparty
# 107 "data/maps/EscapeRoom_EggCave/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_TrapinchBattle_2
EscapeRoom_EventScript_TrapinchBattle_1:
# 111 "data/maps/EscapeRoom_EggCave/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_TRAPINCH, level = 90, nature = 3, abilityNum = 1, gender = 1, move1 = MOVE_EARTHQUAKE hpEv = 0, defEv = 0, atkEv = 252, spDefEv = 4, speedEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 134 "data/maps/EscapeRoom_EggCave/scripts.pory"
	dowildbattle
# 135 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TrapinchBattle_2:
# 108 "data/maps/EscapeRoom_EggCave/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_TrapinchBattle_1


EscapeRoom_EventScript_RescueNurse::
# 140 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_PIN
# 141 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseFaceRight
# 142 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 143 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 144 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 145 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 30
# 146 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseToPlayer
# 147 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 150 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceLeft
# 151 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 154 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage1, MSGBOX_AUTOCLOSE
# 155 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 158 "data/maps/EscapeRoom_EggCave/scripts.pory"
	addmoney 2000
# 159 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 160 "data/maps/EscapeRoom_EggCave/scripts.pory"
	message MoneyReceived
# 161 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 162 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitfanfare
# 163 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
# 164 "data/maps/EscapeRoom_EggCave/scripts.pory"
	closemessage
# 167 "data/maps/EscapeRoom_EggCave/scripts.pory"
	partymonhasfainted
# 168 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 171 "data/maps/EscapeRoom_EggCave/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_RescueNurse_2
EscapeRoom_EventScript_RescueNurse_1:
# 181 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 184 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessage2, MSGBOX_AUTOCLOSE
# 185 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
# 189 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayerAside
# 190 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 193 "data/maps/EscapeRoom_EggCave/scripts.pory"
	applymovement 7, MoveNurseAway
# 194 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmovement 7
# 197 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_EXIT
# 198 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 5
# 199 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 7
# 200 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_NURSE_RESCUED
# 201 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
	return

EscapeRoom_EventScript_RescueNurse_2:
# 172 "data/maps/EscapeRoom_EggCave/scripts.pory"
	msgbox NurseMessageHeal1, MSGBOX_DEFAULT
# 174 "data/maps/EscapeRoom_EggCave/scripts.pory"
	special HealPlayerParty
# 175 "data/maps/EscapeRoom_EggCave/scripts.pory"
	playse SE_USE_ITEM
# 176 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 177 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitse
# 178 "data/maps/EscapeRoom_EggCave/scripts.pory"
	delay 10
# 179 "data/maps/EscapeRoom_EggCave/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_RescueNurse_1


# 204 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseFaceRight:
# 205 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
	step_end

# 208 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseToPlayer:
# 209 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 210 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_up
# 211 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_right
# 212 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 212 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
	step_end

# 215 "data/maps/EscapeRoom_EggCave/scripts.pory"
MoveNurseAway:
# 216 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 216 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 216 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_right
# 217 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
# 218 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_fast_down
	step_end

# 221 "data/maps/EscapeRoom_EggCave/scripts.pory"
MovePlayerAside:
# 222 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_up
# 223 "data/maps/EscapeRoom_EggCave/scripts.pory"
	walk_up
# 224 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_down
	step_end

# 227 "data/maps/EscapeRoom_EggCave/scripts.pory"
PlayerFaceLeft:
# 228 "data/maps/EscapeRoom_EggCave/scripts.pory"
	face_left
	step_end

EscapeRoom_EggCave_EventScript_FindRareCandy::
# 233 "data/maps/EscapeRoom_EggCave/scripts.pory"
	lockall
# 234 "data/maps/EscapeRoom_EggCave/scripts.pory"
	finditem ITEM_RARE_CANDY
# 235 "data/maps/EscapeRoom_EggCave/scripts.pory"
	removeobject 4
# 236 "data/maps/EscapeRoom_EggCave/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 237 "data/maps/EscapeRoom_EggCave/scripts.pory"
	releaseall
	return


TrapinchWentAway::
# 242 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "The Trapinch disappeared into\n"
	.string "the ground.$"

NurseMessage1::
# 247 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Thank you so much!\n"
	.string "That Pokémon would not let me out!\p"
	.string "I don't know what I would've done if\n"
	.string "it weren't for you.\p"
	.string "Here, take this.\n"
	.string "Call it a rescue reward!$"

NurseMessageHeal1::
# 256 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "It also looks like your Pokémon got\n"
	.string "hurt in battle.\p"
	.string "Allow me to fix that.$"

NurseMessage2::
# 262 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "Take care!$"

MoneyReceived::
# 266 "data/maps/EscapeRoom_EggCave/scripts.pory"
	.string "{PLAYER} received ¥2.000!$"
