EscapeRoom_HiddenDungeon_MapScripts::
# 8 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts
# 9 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts
# 11 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_HiddenDungeon_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 13 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 14 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
	.2byte 0


EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts::
# 21 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1
	return

EscapeRoom_HiddenDungeon_MapScript_OnTransitionScripts_1:
# 22 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectxyperm 11, 4, 8
# 23 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_RIGHT
	return


EscapeRoom_HiddenDungeon_MapScript_OnResumeScripts::
# 29 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_DisableBagUse
# 30 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_SetLostItemVars
# 31 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
# 32 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	call EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained
	return


EscapeRoom_HiddenDungeon_DisableBagUse::
# 37 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_HiddenDungeon_DisableBagUse_1
	return

EscapeRoom_HiddenDungeon_DisableBagUse_1:
# 38 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_HiddenDungeon_SetLostItemVars::
# 44 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_HiddenDungeon_SetLostItemVars_1
	return

EscapeRoom_HiddenDungeon_SetLostItemVars_1:
# 46 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	return


EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained::
# 51 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_SECRET_POWER_LEARNED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1:
# 52 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_SECRET_POWER_COMPLETED
# 53 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	clearflag FLAG_SECRET_POWER_LEARNED
	return

EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_2:
# 51 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_unset FLAG_SECRET_POWER_COMPLETED, EscapeRoom_HiddenDungeon_CheckIfSecretPowerObtained_1
	return


EscapeRoom_HiddenDungeon_DungeonGuard::
# 64 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	lockall
# 65 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	faceplayer
# 67 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	goto_if_set FLAG_DUNGEON_ENTRY_GRANTED, EscapeRoom_HiddenDungeon_DungeonGuard_2
# 74 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardIntro, MSGBOX_AUTOCLOSE
# 75 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 78 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	checkitem ITEM_CARD_KEY
# 79 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_HiddenDungeon_DungeonGuard_5
EscapeRoom_HiddenDungeon_DungeonGuard_1:
# 93 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	releaseall
	return

EscapeRoom_HiddenDungeon_DungeonGuard_2:
# 69 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardPostEntry, MSGBOX_AUTOCLOSE
# 70 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1

EscapeRoom_HiddenDungeon_DungeonGuard_5:
# 82 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	msgbox DungeonGuardShowCard, MSGBOX_AUTOCLOSE
# 83 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmessage
# 86 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	applymovement 11, GuardMoveAway
# 87 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	waitmovement 11
# 88 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	copyobjectxytoperm 11
# 90 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	setflag FLAG_DUNGEON_ENTRY_GRANTED
	goto EscapeRoom_HiddenDungeon_DungeonGuard_1


# 96 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
GuardMoveAway:
# 97 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_left
# 98 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	walk_left
# 99 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	face_right
	step_end

DungeonGuardIntro::
# 103 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "Access to this zone is restricted.\p"
	.string "Show me your entry card, or you're\n"
	.string "not getting through.$"

DungeonGuardShowCard::
# 109 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You hand over your entry card.\p"
	.string "...\p"
	.string "This doesn't look like one of our\n"
	.string "usual entry cards.\p"
	.string "But hey, looks legit enough to me!$"

DungeonGuardPostEntry::
# 117 "data/maps/EscapeRoom_HiddenDungeon/scripts.pory"
	.string "You're not a normal person are you?\p"
	.string "Don't cause any trouble$"
