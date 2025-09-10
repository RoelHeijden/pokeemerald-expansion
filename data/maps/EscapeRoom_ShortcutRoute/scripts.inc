EscapeRoom_ShortcutRoute_MapScripts::
# 17 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheckResetRocks
# 18 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_ShortcutRoute_OnResumeMapScripts
# 20 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_ShortcutRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 21 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 22 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_ShortcutRoute_OnResumeMapScripts::
# 28 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call CheckIfBerryJuiceObtained
# 29 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_DisableBagUse
# 30 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call EscapeRoom_ShortcutRoute_SetLostItemVars
	return


EscapeRoom_ShortcutRoute_DisableBagUse::
# 35 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_ShortcutRoute_DisableBagUse_1
	return

EscapeRoom_ShortcutRoute_DisableBagUse_1:
# 36 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_ShortcutRoute_SetLostItemVars::
# 42 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_ShortcutRoute_SetLostItemVars_1
	return

EscapeRoom_ShortcutRoute_SetLostItemVars_1:
# 44 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


SetWallOnLoad::
# 51 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, SetWallOnLoad_1
	return

SetWallOnLoad_1:
# 52 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 0, METATILE_Cave_EntranceCover, TRUE
# 53 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 0, METATILE_Cave_EntranceCover, TRUE
# 54 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 0, METATILE_Cave_EntranceCover, TRUE
# 55 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 8, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 56 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 57 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


CheckResetRocks::
# 62 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetSmashRock1
# 63 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	call ResetShuckleSmashRocks
	return


ResetSmashRock1::
# 69 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK1, ResetSmashRock1_1
# 69 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_1
	return

ResetSmashRock1_1:
# 70 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_HIDE_SMASH_ROCK2, ResetSmashRock1_5
# 74 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_HIDE_SMASH_ROCK1
	return

ResetSmashRock1_5:
# 71 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_HIDE_SMASH_ROCK1
	return


ResetShuckleSmashRocks::
# 81 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, ResetShuckleSmashRocks_1
	return

ResetShuckleSmashRocks_1:
# 82 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK1
# 83 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK2
# 84 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK3
# 85 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	clearflag FLAG_SHUCKLE_SMASH_ROCK4
	return


CheckIfBerryJuiceObtained::
# 90 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_1
	return

CheckIfBerryJuiceObtained_1:
# 92 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 93 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_4
CheckIfBerryJuiceObtained_3:
# 96 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 97 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq CheckIfBerryJuiceObtained_7
CheckIfBerryJuiceObtained_6:
# 102 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 103 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_10
CheckIfBerryJuiceObtained_9:
# 109 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_OBTAINED, CheckIfBerryJuiceObtained_12
	return

CheckIfBerryJuiceObtained_4:
# 94 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_3

CheckIfBerryJuiceObtained_7:
# 98 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
	goto CheckIfBerryJuiceObtained_6

CheckIfBerryJuiceObtained_10:
# 104 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_BERRY_JUICE_OBTAINED
# 105 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removelostitem ITEM_JABOCA_BERRY
	goto CheckIfBerryJuiceObtained_9

CheckIfBerryJuiceObtained_12:
# 113 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 114 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 115 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 116 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 118 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_JABOCA_BERRY
# 119 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 121 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, CheckIfBerryJuiceObtained_14
# 122 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8006, ITEM_JABOCA_BERRY
	goto_if_eq CheckIfBerryJuiceObtained_14
# 122 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8007, ITEM_JABOCA_BERRY
	goto_if_eq CheckIfBerryJuiceObtained_14
# 123 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq CheckIfBerryJuiceObtained_14
	return

CheckIfBerryJuiceObtained_14:
# 126 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


HikerSellAbilityCapsule::
# 137 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lock
# 138 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	faceplayer
# 139 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, HikerSellAbilityCapsule_2
# 200 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCFinalMessage, MSGBOX_AUTOCLOSE
# 201 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
HikerSellAbilityCapsule_1:
# 203 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return

HikerSellAbilityCapsule_2:
# 142 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDrugs, MSGBOX_YESNO
# 143 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HikerSellAbilityCapsule_5
# 194 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellDeclined, MSGBOX_AUTOCLOSE
# 195 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_5:
# 146 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkmoney 1025
# 147 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_9
# 155 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removemoney 1025
# 158 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	giveitem ITEM_ABILITY_CAPSULE
# 161 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCsellAcceptedMessage, MSGBOX_AUTOCLOSE
# 162 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 164 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_ABILITY_CAPSULE_BOUGHT
# 172 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 0
# 173 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 174 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkpartyitem 1
# 175 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 177 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkitem ITEM_BERRY_JUICE
# 178 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 180 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	checkexactmoney 0
# 181 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HikerSellAbilityCapsule_11
# 182 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, HikerSellAbilityCapsule_11
# 183 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8006, ITEM_BERRY_JUICE
	goto_if_eq HikerSellAbilityCapsule_11
# 183 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_0x8007, ITEM_BERRY_JUICE
	goto_if_eq HikerSellAbilityCapsule_11
# 184 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq HikerSellAbilityCapsule_11
	goto HikerSellAbilityCapsule_1

HikerSellAbilityCapsule_9:
# 149 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox RockSmashNPCnotEnoughMoney, MSGBOX_AUTOCLOSE
# 150 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 151 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	end

HikerSellAbilityCapsule_11:
# 186 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 187 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 188 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	waitmessage
# 189 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	goto HikerSellAbilityCapsule_1


FindTmTrickItem::
# 207 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 208 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_TM38
# 209 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 8
# 210 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_TM_TRICK_OBTAINED
# 211 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


FindExpCandy::
# 215 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	lockall
# 216 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	finditem ITEM_EXP_CANDY_S
# 217 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	removeobject 10
# 218 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	setflag FLAG_EXP_CANDY_OBTAINED
# 219 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	releaseall
	return


RockSmashNPCsellDrugs::
# 223 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Hey kid, wanna buy some dru- OH HEY!\p"
	.string "You're the one who smashed that rock\n"
	.string "for me, aren't you?\p"
	.string "For you I've got a special offer!\n"
	.string "An Ability Capsule for only ¥1025.\l"
	.string "What do you say?$"

RockSmashNPCsellDeclined::
# 234 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "You know where to find me.$"

RockSmashNPCnotEnoughMoney::
# 238 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Come back when you have the money.$"

RockSmashNPCsellAcceptedMessage::
# 242 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Pleasure doing business.$"

RockSmashNPCFinalMessage::
# 246 "data/maps/EscapeRoom_ShortcutRoute/scripts.pory"
	.string "Move along now.$"
