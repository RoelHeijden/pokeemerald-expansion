EscapeRoom_AnnihilapesLair_MapScripts::
# 7 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpawnDungeonEntranceOnLoad
# 8 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts
# 10 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_AnnihilapesLair_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 12 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


SpawnDungeonEntranceOnLoad::
# 18 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, SpawnDungeonEntranceOnLoad_1
	return

SpawnDungeonEntranceOnLoad_1:
# 19 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 6, 0, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
# 20 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 5, 1, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
# 21 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 6, 1, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
# 22 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setmetatile 7, 1, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return


EscapeRoom_AnnihilapesLair_MapScript_OnResumeScripts::
# 28 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_ReturnBall
# 29 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_DisableBagUse
# 30 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_SetLostItemVars
	return


EscapeRoom_AnnihilapesLair_ReturnBall::
# 35 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_AnnihilapesLair_ReturnBall_2
	return

EscapeRoom_AnnihilapesLair_ReturnBall_1:
# 36 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_AnnihilapesLair_ReturnBall_2:
# 35 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_AnnihilapesLair_ReturnBall_1
	return


EscapeRoom_AnnihilapesLair_DisableBagUse::
# 42 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_AnnihilapesLair_DisableBagUse_1
	return

EscapeRoom_AnnihilapesLair_DisableBagUse_1:
# 43 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_AnnihilapesLair_SetLostItemVars::
# 49 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_AnnihilapesLair_SetLostItemVars_1
	return

EscapeRoom_AnnihilapesLair_SetLostItemVars_1:
# 51 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_AnnihilapesLair_FindPrimeape::
# 61 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	givemon SPECIES_PRIMEAPE, 44, ball = ITEM_TIMER_BALL, item = ITEM_MAX_REVIVE, abilityNum = 2, nature = NATURE_CALM, gender = MON_FEMALE, move1 = MOVE_RAGE_FIST, move2 = MOVE_TAUNT, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 252, defEv = 0, spDefEv = 8 hpIv = 31, atkIv = 0, defIv = 0, spAtkIv = 31, spDefIv = 31, speedIv = 10
# 87 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	healpartymon SPECIES_PRIMEAPE, reverse = TRUE
# 90 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_PRIMEAPE_OBTAINED
# 93 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_MAX_REVIVE_OBTAINED
# 96 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_FANFARE_NO_MUSIC_RESUME
# 97 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 98 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	message PrimeapeObtainMessage
# 99 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitfanfare
# 100 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 103 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox NicknameThisPokemonMessage2, MSGBOX_YESNO
# 104 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_FindPrimeape_2
EscapeRoom_AnnihilapesLair_FindPrimeape_1:
# 108 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	closemessage
	return

EscapeRoom_AnnihilapesLair_FindPrimeape_2:
# 105 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 106 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_AnnihilapesLair_FindPrimeape_1


EscapeRoom_AnnihilapesLair_PrimeapeGrave1::
# 112 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 115 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_GRAVE1_ROBBED, EscapeRoom_AnnihilapesLair_PrimeapeGrave1_2
# 122 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_main, MSGBOX_YESNO
# 123 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave1_5
EscapeRoom_AnnihilapesLair_PrimeapeGrave1_4:
# 140 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapesLair_PrimeapeGrave1_2:
# 116 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_PostScriptMessage, MSGBOX_AUTOCLOSE
# 117 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
	return

EscapeRoom_AnnihilapesLair_PrimeapeGrave1_5:
# 125 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_youSure1, MSGBOX_YESNO
# 126 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave1_7
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave1_4

EscapeRoom_AnnihilapesLair_PrimeapeGrave1_7:
# 128 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_youSure2, MSGBOX_YESNO
# 129 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave1_9
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave1_4

EscapeRoom_AnnihilapesLair_PrimeapeGrave1_9:
# 131 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_youSure3, MSGBOX_YESNO
# 132 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave1_11
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave1_4

EscapeRoom_AnnihilapesLair_PrimeapeGrave1_11:
# 134 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_PrimeapeGrave_DigGrave
# 135 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_GRAVE1_ROBBED
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave1_4


EscapeRoom_AnnihilapesLair_PrimeapeGrave2::
# 144 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	lockall
# 147 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_GRAVE1_ROBBED, EscapeRoom_AnnihilapesLair_PrimeapeGrave2_2
# 154 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	goto_if_set FLAG_GRAVE2_ROBBED, EscapeRoom_AnnihilapesLair_PrimeapeGrave2_5
# 161 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_main, MSGBOX_YESNO
# 162 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave2_8
EscapeRoom_AnnihilapesLair_PrimeapeGrave2_7:
# 185 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapesLair_PrimeapeGrave2_2:
# 148 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_PostScriptMessage, MSGBOX_AUTOCLOSE
# 149 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
	return

EscapeRoom_AnnihilapesLair_PrimeapeGrave2_5:
# 155 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_PostDigNothingMessage, MSGBOX_AUTOCLOSE
# 156 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
	return

EscapeRoom_AnnihilapesLair_PrimeapeGrave2_8:
# 164 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_youSure1, MSGBOX_YESNO
# 165 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave2_10
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave2_7

EscapeRoom_AnnihilapesLair_PrimeapeGrave2_10:
# 167 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_youSure2, MSGBOX_YESNO
# 168 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave2_12
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave2_7

EscapeRoom_AnnihilapesLair_PrimeapeGrave2_12:
# 170 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_youSure3, MSGBOX_YESNO
# 171 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_AnnihilapesLair_PrimeapeGrave2_14
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave2_7

EscapeRoom_AnnihilapesLair_PrimeapeGrave2_14:
# 174 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_DigTheGrave2, MSGBOX_DEFAULT
# 175 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 178 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_FindNothingMessage, MSGBOX_AUTOCLOSE
# 179 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 180 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	setflag FLAG_GRAVE2_ROBBED
	goto EscapeRoom_AnnihilapesLair_PrimeapeGrave2_7


EscapeRoom_AnnihilapesLair_PrimeapeGrave_DigGrave::
# 190 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	fadeoutbgm 0
# 191 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 20
# 194 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_DigTheGrave, MSGBOX_AUTOCLOSE
# 195 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 198 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	playse SE_PIN
# 199 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 200 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 201 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 50
# 204 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_PrimeapeGrave_ApeRoar
# 205 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 20
# 208 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	call EscapeRoom_AnnihilapesLair_FindPrimeape
# 211 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 10
# 212 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	msgbox PrimeapeGrave_PostDigMessage, MSGBOX_AUTOCLOSE
# 213 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmessage
# 215 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_AnnihilapesLair_PrimeapeGrave_ApeRoar::
# 219 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 220 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 221 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 10
# 222 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 223 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 10
# 224 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 225 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	delay 10
# 226 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 229 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	waitmoncry
	return


PrimeapeGrave_main::
# 237 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "It's an old grave...\p"
	.string "Do you want to dig up the grave in\n"
	.string "in search for treasure?$"

PrimeapeGrave_youSure1::
# 244 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "Are you sure about this?$"

PrimeapeGrave_youSure2::
# 248 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "Do you really want to rob a grave?$"

PrimeapeGrave_youSure3::
# 252 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "Are you REALLY sure?$"

PrimeapeGrave_DigTheGrave::
# 256 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "You carefully dig through the soil...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "...$"

PrimeapeGrave_DigTheGrave2::
# 265 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "You carefully dig through the soil...\p"
	.string "...$"

PrimeapeGrave_FindNothingMessage::
# 270 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "You find nothing but dirt.$"

PrimeapeGrave_PostDigNothingMessage::
# 274 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "It's an old grave...$"

PrimeapeGrave_PostDigMessage::
# 278 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "I'm never doing this again.$"

PrimeapeGrave_PostScriptMessage::
# 282 "data/maps/EscapeRoom_AnnihilapesLair/scripts.pory"
	.string "Some things are better left buried.$"
