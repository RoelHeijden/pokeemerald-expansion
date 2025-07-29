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
# 20 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_ShortcutRoute_OnResumeMapScripts::
# 26 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call CheckIfBerryJuiceObtained
# 27 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_DisableBagUse
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_SetLostItemVars
	return


EscapeRoom_ShortcutRoute_DisableBagUse::
# 33 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_ShortcutRoute_DisableBagUse_1
	return

EscapeRoom_ShortcutRoute_DisableBagUse_1:
# 34 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_ShortcutRoute_SetLostItemVars::
# 40 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_ShortcutRoute_SetLostItemVars_1
	return

EscapeRoom_ShortcutRoute_SetLostItemVars_1:
# 42 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


SetWallOnLoad::
# 49 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 50 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 51 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 52 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 53 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 54 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 55 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


CheckResetRocks::
# 60 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetSmashRock1
# 61 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetShuckleSmashRocks
	return


ResetSmashRock1::
# 67 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 67 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 68 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 72 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 69 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


ResetShuckleSmashRocks::
# 79 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, ResetShuckleSmashRocks_1
	return

ResetShuckleSmashRocks_1:
# 80 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK1
# 81 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK2
# 82 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK3
# 83 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK4
	return


CheckIfBerryJuiceObtained::
# 88 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_1
	return

CheckIfBerryJuiceObtained_1:
# 90 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 91 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_4
CheckIfBerryJuiceObtained_3:
# 94 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 95 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_7
CheckIfBerryJuiceObtained_6:
# 100 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 101 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_10
CheckIfBerryJuiceObtained_9:
# 107 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_12
	return

CheckIfBerryJuiceObtained_4:
# 92 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_3

CheckIfBerryJuiceObtained_7:
# 96 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_6

CheckIfBerryJuiceObtained_10:
# 102 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_9

CheckIfBerryJuiceObtained_12:
# 111 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 112 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 113 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 114 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 116 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 117 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 119 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, CheckIfBerryJuiceObtained_14
# 120 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8006, ITEM_JABOCA_BERRY
	goto_if_eq CheckIfBerryJuiceObtained_14
# 120 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8007, ITEM_JABOCA_BERRY
	goto_if_eq CheckIfBerryJuiceObtained_14
# 121 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_14
	return

CheckIfBerryJuiceObtained_14:
# 124 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


HikerSellAbilityCapsule::
# 135 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lock
# 136 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	faceplayer
# 137 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, HikerSellAbilityCapsule_2
# 198 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCFinalMessage, MSGBOX_AUTOCLOSE
# 199 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
HikerSellAbilityCapsule_1:
# 201 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

HikerSellAbilityCapsule_2:
# 140 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDrugs, MSGBOX_YESNO
# 141 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HikerSellAbilityCapsule_5
# 192 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDeclined, MSGBOX_AUTOCLOSE
# 193 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_5:
# 144 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkmoney 1025
# 145 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_9
# 153 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removemoney 1025
# 156 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	giveitem ITEM_ABILITY_CAPSULE
# 159 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellAcceptedMessage, MSGBOX_AUTOCLOSE
# 160 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 162 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_ABILITY_CAPSULE_BOUGHT
# 170 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 171 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 172 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 173 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 175 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 176 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 178 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkexactmoney 0
# 179 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_11
# 180 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, HikerSellAbilityCapsule_11
# 181 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8006, ITEM_BERRY_JUICE
	goto_if_eq HikerSellAbilityCapsule_11
# 181 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8007, ITEM_BERRY_JUICE
	goto_if_eq HikerSellAbilityCapsule_11
# 182 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq HikerSellAbilityCapsule_11
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_9:
# 147 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCnotEnoughMoney, MSGBOX_AUTOCLOSE
# 148 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 149 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	end

HikerSellAbilityCapsule_11:
# 184 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 185 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 186 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 187 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	goto HikerSellAbilityCapsule_1


FindDuskStoneItem::
# 205 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 206 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_DUSK_STONE
# 207 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 6
# 208 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_DUSK_STONE_OBTAINED
# 209 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


RockSmashNPCsellDrugs::
# 213 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Hey kid, wanna buy some dru- OH HEY!\p"
	.string "You're the one who smashed that rock\n"
	.string "for me, aren't you?\p"
	.string "For you I've got a special offer!\n"
	.string "An Ability Capsule for only ¥1025.\l"
	.string "What do you say?$"

RockSmashNPCsellDeclined::
# 224 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "You know where to find me.$"

RockSmashNPCnotEnoughMoney::
# 228 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Come back when you have the money.$"

RockSmashNPCsellAcceptedMessage::
# 232 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Pleasure doing business.$"

RockSmashNPCFinalMessage::
# 236 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Move along now.$"
