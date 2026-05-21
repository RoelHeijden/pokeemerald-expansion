EscapeRoom_ShortcutRoute_MapScripts::
# 16 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_ShortcutRoute_OnTransitionScripts
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_ShortcutRoute_OnResumeMapScripts
# 19 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 20 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 21 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_ShortcutRoute_OnTransitionScripts::
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetSmashRock1
# 29 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetShuckleSmashRocks
# 32 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_ShortcutRoute_OnTransitionScripts_2
EscapeRoom_ShortcutRoute_OnTransitionScripts_1:
# 35 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_ShortcutRoute_OnTransitionScripts_5
EscapeRoom_ShortcutRoute_OnTransitionScripts_4:
# 38 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_ShortcutRoute_OnTransitionScripts_8
EscapeRoom_ShortcutRoute_OnTransitionScripts_7:
# 41 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_ShortcutRoute_OnTransitionScripts_10
	return

EscapeRoom_ShortcutRoute_OnTransitionScripts_2:
# 33 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	goto EscapeRoom_ShortcutRoute_OnTransitionScripts_1

EscapeRoom_ShortcutRoute_OnTransitionScripts_5:
# 36 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	goto EscapeRoom_ShortcutRoute_OnTransitionScripts_4

EscapeRoom_ShortcutRoute_OnTransitionScripts_8:
# 39 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	goto EscapeRoom_ShortcutRoute_OnTransitionScripts_7

EscapeRoom_ShortcutRoute_OnTransitionScripts_10:
# 42 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	return


EscapeRoom_ShortcutRoute_OnResumeMapScripts::
# 47 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call CheckIfBerryJuiceObtained
# 48 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_DisableBagUse
# 49 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_SetLostItemVars
	return


EscapeRoom_ShortcutRoute_DisableBagUse::
# 54 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_ShortcutRoute_DisableBagUse_1
	return

EscapeRoom_ShortcutRoute_DisableBagUse_1:
# 55 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_ShortcutRoute_SetLostItemVars::
# 61 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_ShortcutRoute_SetLostItemVars_1
	return

EscapeRoom_ShortcutRoute_SetLostItemVars_1:
# 63 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


SetWallOnLoad::
# 70 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 71 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 72 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 73 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 74 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 75 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 76 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


ResetSmashRock1::
# 82 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 82 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 83 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 87 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 84 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


ResetShuckleSmashRocks::
# 94 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, ResetShuckleSmashRocks_1
# 101 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_SHUCKLE_SMASH_ROCK1
# 102 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_SHUCKLE_SMASH_ROCK2
# 103 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_SHUCKLE_SMASH_ROCK3
# 104 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_SHUCKLE_SMASH_ROCK4
	return

ResetShuckleSmashRocks_1:
# 95 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK1
# 96 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK2
# 97 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK3
# 98 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK4
	return


CheckIfBerryJuiceObtained::
# 109 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_1
	return

CheckIfBerryJuiceObtained_1:
# 111 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 112 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_4
CheckIfBerryJuiceObtained_3:
# 115 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 116 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_7
CheckIfBerryJuiceObtained_6:
# 121 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 122 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_10
CheckIfBerryJuiceObtained_9:
# 128 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_12
	return

CheckIfBerryJuiceObtained_4:
# 113 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_3

CheckIfBerryJuiceObtained_7:
# 117 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_6

CheckIfBerryJuiceObtained_10:
# 123 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
# 124 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removelostitem ITEM_IRON_BALL
	goto CheckIfBerryJuiceObtained_9

CheckIfBerryJuiceObtained_12:
# 132 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 133 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 134 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 135 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 137 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_IRON_BALL
# 138 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 140 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, CheckIfBerryJuiceObtained_14
# 141 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8006, ITEM_IRON_BALL
	goto_if_eq CheckIfBerryJuiceObtained_14
# 141 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8007, ITEM_IRON_BALL
	goto_if_eq CheckIfBerryJuiceObtained_14
# 142 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_14
	return

CheckIfBerryJuiceObtained_14:
# 145 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


HikerSellAbilityCapsule::
# 156 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lock
# 157 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	faceplayer
# 158 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, HikerSellAbilityCapsule_2
# 219 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCFinalMessage, MSGBOX_AUTOCLOSE
# 220 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
HikerSellAbilityCapsule_1:
# 222 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

HikerSellAbilityCapsule_2:
# 161 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDrugs, MSGBOX_YESNO
# 162 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HikerSellAbilityCapsule_5
# 213 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDeclined, MSGBOX_AUTOCLOSE
# 214 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_5:
# 165 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkmoney 1025
# 166 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_9
# 174 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removemoney 1025
# 177 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	giveitem ITEM_ABILITY_CAPSULE
# 180 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellAcceptedMessage, MSGBOX_AUTOCLOSE
# 181 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 183 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_ABILITY_CAPSULE_BOUGHT
# 191 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 192 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 193 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 194 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 196 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 197 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 199 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkexactmoney 0
# 200 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_11
# 201 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, HikerSellAbilityCapsule_11
# 202 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8006, ITEM_BERRY_JUICE
	goto_if_eq HikerSellAbilityCapsule_11
# 202 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8007, ITEM_BERRY_JUICE
	goto_if_eq HikerSellAbilityCapsule_11
# 203 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq HikerSellAbilityCapsule_11
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_9:
# 168 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCnotEnoughMoney, MSGBOX_AUTOCLOSE
# 169 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 170 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	end

HikerSellAbilityCapsule_11:
# 205 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 206 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 207 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 208 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	goto HikerSellAbilityCapsule_1


FindTmTrickItem::
# 226 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 227 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_TM38
# 228 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 8
# 229 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TM_TRICK_OBTAINED
# 230 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


FindExpCandy::
# 234 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 235 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_EXP_CANDY_S
# 236 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 10
# 237 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_EXP_CANDY_OBTAINED
# 238 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


RockSmashNPCsellDrugs::
# 242 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Hey kid, wanna buy some dru- OH HEY!\p"
	.string "You're the one who smashed that rock\n"
	.string "for me, aren't you?\p"
	.string "For you I've got a special offer!\n"
	.string "An Ability Capsule for only ¥1025.\l"
	.string "What do you say?$"

RockSmashNPCsellDeclined::
# 253 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "You know where to find me.$"

RockSmashNPCnotEnoughMoney::
# 257 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Come back when you have the money.$"

RockSmashNPCsellAcceptedMessage::
# 261 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Pleasure doing business.$"

RockSmashNPCFinalMessage::
# 265 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Move along now.$"
