EscapeRoom_ShortcutRoute_MapScripts::
# 15 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheckResetRocks
# 16 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_ShortcutRoute_OnResumeMapScripts
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 19 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
	.2byte 0


EscapeRoom_ShortcutRoute_OnResumeMapScripts::
# 25 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call CheckIfBerryJuiceObtained
# 26 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_DisableBagUse
# 27 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_SetLostItemVars
	return


EscapeRoom_ShortcutRoute_DisableBagUse::
# 32 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_ShortcutRoute_DisableBagUse_1
	return

EscapeRoom_ShortcutRoute_DisableBagUse_1:
# 33 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_ShortcutRoute_SetLostItemVars::
# 39 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_ShortcutRoute_SetLostItemVars_1
	return

EscapeRoom_ShortcutRoute_SetLostItemVars_1:
# 41 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


SetWallOnLoad::
# 48 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 49 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 50 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 51 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 52 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 53 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 54 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


CheckResetRocks::
# 59 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetSmashRock1
# 60 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetShuckleSmashRocks
	return


ResetSmashRock1::
# 65 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 65 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 66 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 70 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 67 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


ResetShuckleSmashRocks::
# 77 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, ResetShuckleSmashRocks_1
	return

ResetShuckleSmashRocks_1:
# 78 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK1
# 79 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK2
# 80 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK3
# 81 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK4
	return


CheckIfBerryJuiceObtained::
# 86 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_1
	return

CheckIfBerryJuiceObtained_1:
# 88 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 89 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_4
CheckIfBerryJuiceObtained_3:
# 92 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 93 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_7
CheckIfBerryJuiceObtained_6:
# 98 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 99 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_9
	return

CheckIfBerryJuiceObtained_4:
# 90 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_3

CheckIfBerryJuiceObtained_7:
# 94 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_6

CheckIfBerryJuiceObtained_9:
# 100 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	return


HikerSellAbilityCapsule::
# 110 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lock
# 111 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	faceplayer
# 112 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, HikerSellAbilityCapsule_2
# 145 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCFinalMessage, MSGBOX_AUTOCLOSE
# 146 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
HikerSellAbilityCapsule_1:
# 148 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

HikerSellAbilityCapsule_2:
# 115 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDrugs, MSGBOX_YESNO
# 116 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HikerSellAbilityCapsule_5
# 139 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDeclined, MSGBOX_AUTOCLOSE
# 140 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_5:
# 119 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkmoney 525
# 120 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_9
# 129 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	giveitem ITEM_ABILITY_CAPSULE
# 132 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellAcceptedMessage, MSGBOX_AUTOCLOSE
# 133 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 135 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_ABILITY_CAPSULE_BOUGHT
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_9:
# 122 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCnotEnoughMoney, MSGBOX_AUTOCLOSE
# 123 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 124 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	end


RockSmashNPCsellDrugs::
# 151 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Hey kid, wanna buy some dru- OH HEY!\p"
	.string "You're the one who smashed that rock\n"
	.string "for me, aren't you?\p"
	.string "For you I've got a special offer!\n"
	.string "An Ability Capsule for only ¥525.\l"
	.string "What do you say?$"

RockSmashNPCsellDeclined::
# 162 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "You know where to find me.$"

RockSmashNPCnotEnoughMoney::
# 166 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Come back when you have the money.$"

RockSmashNPCsellAcceptedMessage::
# 170 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Pleasure doing business.$"

RockSmashNPCFinalMessage::
# 174 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Move along now.$"
