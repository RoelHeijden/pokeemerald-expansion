EscapeRoom_Main_MapScripts::
# 47 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 48 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 50 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 54 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 51 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_Main_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 55 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScript_GameStartScripts
# 56 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindBallAferUse
# 57 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_RETRIEVED_HELD_ITEM, 1, EscapeRoom_MapScripts_RetrievedItemMessage
# 58 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 59 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
# 60 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_DO_ERROR_MESSAGE, 1, EscapeRoom_MapScripts_DoErrorMessage
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 66 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 71 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 67 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 72 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 79 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_6
EscapeRoom_MapScript_OnResumeScripts_4:
# 89 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_10
EscapeRoom_MapScript_OnResumeScripts_9:
# 95 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_13
EscapeRoom_MapScript_OnResumeScripts_12:
# 100 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_16
EscapeRoom_MapScript_OnResumeScripts_15:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfAskPreDamage
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 80 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfPokemonCaught
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_5:
# 85 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_6:
# 84 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_5
	goto EscapeRoom_MapScript_OnResumeScripts_4

EscapeRoom_MapScript_OnResumeScripts_10:
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_13:
# 96 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_12

EscapeRoom_MapScript_OnResumeScripts_16:
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_15


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_CheckIfPokemonCaught::
# 122 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 123 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScripts_CheckIfPokemonCaught_1
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_1:
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 127 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_LEPPA_BERRY
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 131 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_LEPPA_BERRY
# 134 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 141 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 144 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 146 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_LEPPA_BERRY
# 147 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_CUSTAP_BERRY
# 150 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1000
# 153 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_LEPPA_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 155 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_LEPPA_BERRY
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 156 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
# 157 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfPokemonCaught_3
	return

EscapeRoom_MapScripts_CheckIfPokemonCaught_3:
# 160 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 1
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 166 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 167 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 174 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 175 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 178 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 168 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 176 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_CheckIfAskPreDamage::
# 186 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScripts_CheckIfAskPreDamage_2
EscapeRoom_MapScripts_CheckIfAskPreDamage_1:
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScripts_CheckIfAskPreDamage_5
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_2:
# 187 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 188 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_9
EscapeRoom_MapScripts_CheckIfAskPreDamage_8:
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_1

EscapeRoom_MapScripts_CheckIfAskPreDamage_4:
# 196 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckIfAskPreDamage_12
EscapeRoom_MapScripts_CheckIfAskPreDamage_11:
# 203 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_5:
# 195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScripts_CheckIfAskPreDamage_4
	return

EscapeRoom_MapScripts_CheckIfAskPreDamage_9:
# 189 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_8

EscapeRoom_MapScripts_CheckIfAskPreDamage_12:
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
# 201 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_FIGHT_BACKUP_CHECK
	goto EscapeRoom_MapScripts_CheckIfAskPreDamage_11


EscapeRoom_MapScripts_FindBallAferUse::
# 213 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 214 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 215 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 216 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 217 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 219 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 223 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 226 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 227 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 228 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 229 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_AskResetPredamage::
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 240 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_MapScripts_AskResetPredamage_5
EscapeRoom_MapScripts_AskResetPredamage_3:
# 263 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 264 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_12
EscapeRoom_MapScripts_AskResetPredamage_1:
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 244 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageAndWarpMessage, MSGBOX_YESNO
# 245 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_9
# 256 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 257 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 258 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_4:
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
	goto EscapeRoom_MapScripts_AskResetPredamage_3

EscapeRoom_MapScripts_AskResetPredamage_5:
# 243 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_MapScripts_AskResetPredamage_4
	goto EscapeRoom_MapScripts_AskResetPredamage_3

EscapeRoom_MapScripts_AskResetPredamage_9:
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 249 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 252 "data/maps/EscapeRoom_Main/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM_MAIN, 48, 17
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_12:
# 266 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 267 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_ZERA_FIGHT_BACKUP_CHECK, EscapeRoom_MapScripts_AskResetPredamage_14
	goto EscapeRoom_MapScripts_AskResetPredamage_1

EscapeRoom_MapScripts_AskResetPredamage_14:
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_ZERA_FIGHT_BACKUP_CHECK
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap::
# 281 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_LEPPA_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_2
EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_1:
# 285 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_5
EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_4:
# 290 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 291 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_LEPPA_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_8
EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_7:
# 294 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_10
	return

EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_2:
# 283 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_LEPPA_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_1

EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_5:
# 286 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_4

EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_8:
# 292 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_LEPPA_BERRY
	goto EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_7

EscapeRoom_MapScripts_RemoveDuplicateLeppaCustap_10:
# 295 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
	return


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 300 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 301 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScripts_DoErrorMessage::
# 305 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_DO_ERROR_MESSAGE, 0
# 306 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 307 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 308 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 309 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScript_GameStartScripts::
# 317 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 318 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 319 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 320 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 321 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 322 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 323 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 324 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 325 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 326 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 327 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 331 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 332 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 333 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 334 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 339 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_EXP_CANDY_S, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 362 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_SUNNY_DAY, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 386 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 395 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 396 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 397 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 402 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 404 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 405 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 410 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE1
# 411 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetRespawn1
	return


EscapeRoom_MapScripts_GetItems::
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_LEPPA_BERRY
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_SetRespawn1::
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 1
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 0
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	return


EscapeRoom_EventScript_SetRespawn2::
# 444 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_SetRespawn2_1
	return

EscapeRoom_EventScript_SetRespawn2_1:
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
	return


EscapeRoom_EventScript_SetRespawn3::
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 456 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 0
# 457 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 1
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE3
	return


EscapeRoom_EventScript_MainInfoSign::
# 467 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 468 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 471 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 472 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 479 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 480 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 481 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 485 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 493 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 494 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 498 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 501 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 487 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 488 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 508 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 511 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 515 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 516 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 522 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 523 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 524 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 525 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 544 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 551 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 559 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 555 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy1::
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy1_3
EscapeRoom_EventScript_AntiSoftlockGuy1_1:
# 573 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
# 576 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DONT_RETURN_MENTAL_HERB
	return

EscapeRoom_EventScript_AntiSoftlockGuy1_2:
# 571 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DONT_RETURN_MENTAL_HERB
	goto EscapeRoom_EventScript_AntiSoftlockGuy1_1

EscapeRoom_EventScript_AntiSoftlockGuy1_3:
# 570 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ROCK_SMASH_GUY_MOVED, EscapeRoom_EventScript_AntiSoftlockGuy1_2
	goto EscapeRoom_EventScript_AntiSoftlockGuy1_1


EscapeRoom_EventScript_AntiSoftlockGuy2::
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy3::
# 584 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_AntiSoftlockGuy
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 589 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 591 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_SOFTLOCK_GUY
# 594 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_2
# 605 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_3
# 610 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_4
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockOutro, MSGBOX_AUTOCLOSE
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 619 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 595 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ReturnLostItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_3:
# 606 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoUsedItems
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoOtherActions
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1


EscapeRoom_EventScript_ReturnLostItems::
# 625 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_1
# 626 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_2
# 631 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_ReturnLostItems_2
EscapeRoom_EventScript_ReturnLostItems_1:
# 638 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_BERRY_JUICE, EscapeRoom_EventScript_ReturnLostItems_5
EscapeRoom_EventScript_ReturnLostItems_4:
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RETURN_LEPPA_BERRY, EscapeRoom_EventScript_ReturnLostItems_8
EscapeRoom_EventScript_ReturnLostItems_7:
# 662 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_LEPPA_BERRY
# 663 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_11
EscapeRoom_EventScript_ReturnLostItems_10:
# 678 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_CUSTAP_BERRY
# 679 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_17
EscapeRoom_EventScript_ReturnLostItems_16:
# 686 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_MENTAL_HERB
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_24
EscapeRoom_EventScript_ReturnLostItems_22:
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	isitemlost ITEM_RING_TARGET
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_28
EscapeRoom_EventScript_ReturnLostItems_27:
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUSK_STONE_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_32
EscapeRoom_EventScript_ReturnLostItems_30:
# 711 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_37
EscapeRoom_EventScript_ReturnLostItems_35:
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_ReturnLostItems_42
EscapeRoom_EventScript_ReturnLostItems_40:
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_45
# 728 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_2, EscapeRoom_EventScript_ReturnLostItems_45
# 754 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemsReturned, MSGBOX_DEFAULT
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_2:
# 632 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE
# 633 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
# 634 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_1

EscapeRoom_EventScript_ReturnLostItems_5:
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_BERRY_JUICE
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_4

EscapeRoom_EventScript_ReturnLostItems_8:
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_LEPPA_BERRY
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_LEPPA_BERRY
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmonmove0pp SPECIES_FLORGES, MOVE_CAMOUFLAGE
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_13
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_11:
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_LEPPA_BERRY
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_LEPPA_BERRY
# 668 "data/maps/EscapeRoom_Main/scripts.pory"
	checkmonmove0pp SPECIES_FLORGES, MOVE_CAMOUFLAGE
# 669 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_19
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_13:
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_7

EscapeRoom_EventScript_ReturnLostItems_17:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_CUSTAP_BERRY
# 682 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_16

EscapeRoom_EventScript_ReturnLostItems_19:
# 670 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_10

EscapeRoom_EventScript_ReturnLostItems_23:
# 688 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 689 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 690 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_22

EscapeRoom_EventScript_ReturnLostItems_24:
# 687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_DONT_RETURN_MENTAL_HERB, EscapeRoom_EventScript_ReturnLostItems_23
	goto EscapeRoom_EventScript_ReturnLostItems_22

EscapeRoom_EventScript_ReturnLostItems_28:
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_RING_TARGET
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_1
	goto EscapeRoom_EventScript_ReturnLostItems_27

EscapeRoom_EventScript_ReturnLostItems_31:
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUSK_STONE_CONSUMED
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_DUSK_STONE
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_30

EscapeRoom_EventScript_ReturnLostItems_32:
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_31
	goto EscapeRoom_EventScript_ReturnLostItems_30

EscapeRoom_EventScript_ReturnLostItems_36:
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_35

EscapeRoom_EventScript_ReturnLostItems_37:
# 711 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_36
	goto EscapeRoom_EventScript_ReturnLostItems_35

EscapeRoom_EventScript_ReturnLostItems_41:
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_2
	goto EscapeRoom_EventScript_ReturnLostItems_40

EscapeRoom_EventScript_ReturnLostItems_42:
# 718 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_41
	goto EscapeRoom_EventScript_ReturnLostItems_40

EscapeRoom_EventScript_ReturnLostItems_45:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_RAN_FROM_TRAPINCH, EscapeRoom_EventScript_ReturnLostItems_55
EscapeRoom_EventScript_ReturnLostItems_53:
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_1, EscapeRoom_EventScript_ReturnLostItems_51
	return

EscapeRoom_EventScript_ReturnLostItems_50:
# 733 "data/maps/EscapeRoom_Main/scripts.pory"
	healpartymon SPECIES_AIPOM
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockSomeOfPartyHealed, MSGBOX_DEFAULT
# 737 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_51:
# 741 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockPartyHealed, MSGBOX_DEFAULT
# 745 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_ReturnLostItems_54:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESPAWN_SET_AT_NURSE1, 1
	goto_if_eq EscapeRoom_EventScript_ReturnLostItems_50
	goto EscapeRoom_EventScript_ReturnLostItems_53

EscapeRoom_EventScript_ReturnLostItems_55:
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER6_DEFEATED, EscapeRoom_EventScript_ReturnLostItems_54
	goto EscapeRoom_EventScript_ReturnLostItems_53


EscapeRoom_EventScript_UndoUsedItems::
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoItemToUndo, MSGBOX_AUTOCLOSE
# 763 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_EventScript_UndoOtherActions::
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_11
EscapeRoom_EventScript_UndoOtherActions_9:
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_8
EscapeRoom_EventScript_UndoOtherActions_6:
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_UndoOtherActions_5
EscapeRoom_EventScript_UndoOtherActions_4:
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionsToUndo, MSGBOX_AUTOCLOSE
# 800 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoOtherActions_1:
# 770 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoTrainer5, MSGBOX_YESNO
# 771 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_14
	return

EscapeRoom_EventScript_UndoOtherActions_2:
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFerroTrade, MSGBOX_YESNO
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 783 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_16
	return

EscapeRoom_EventScript_UndoOtherActions_3:
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockAskUndoFlorgesTrade, MSGBOX_YESNO
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoOtherActions_18
	return

EscapeRoom_EventScript_UndoOtherActions_5:
# 789 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_UndoOtherActions_3
	goto EscapeRoom_EventScript_UndoOtherActions_4

EscapeRoom_EventScript_UndoOtherActions_8:
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_UndoOtherActions_2
	goto EscapeRoom_EventScript_UndoOtherActions_6

EscapeRoom_EventScript_UndoOtherActions_11:
# 769 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ABILITY_CAPSULE_BOUGHT, EscapeRoom_EventScript_UndoOtherActions_1
	goto EscapeRoom_EventScript_UndoOtherActions_9

EscapeRoom_EventScript_UndoOtherActions_14:
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockTrainer5Undone, MSGBOX_AUTOCLOSE
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SetTrainer5Rematch
	return

EscapeRoom_EventScript_UndoOtherActions_16:
# 784 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
	return

EscapeRoom_EventScript_UndoOtherActions_18:
# 793 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
	return


EscapeRoom_EventScript_SetTrainer5Rematch::
# 806 "data/maps/EscapeRoom_Main/scripts.pory"
	removemoney 99999
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUSK_STONE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_2
EscapeRoom_EventScript_SetTrainer5Rematch_1:
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_5
EscapeRoom_EventScript_SetTrainer5Rematch_4:
# 817 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_8
EscapeRoom_EventScript_SetTrainer5Rematch_7:
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_SetTrainer5Rematch_11
EscapeRoom_EventScript_SetTrainer5Rematch_10:
# 827 "data/maps/EscapeRoom_Main/scripts.pory"
	cleartrainerflag TRAINER_CUSTOM_TRAINER5
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TRAINER5_DEFEATED
	return

EscapeRoom_EventScript_SetTrainer5Rematch_2:
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUSK_STONE_CONSUMED
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_DUSK_STONE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_1

EscapeRoom_EventScript_SetTrainer5Rematch_5:
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 815 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
	goto EscapeRoom_EventScript_SetTrainer5Rematch_4

EscapeRoom_EventScript_SetTrainer5Rematch_8:
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
	goto EscapeRoom_EventScript_SetTrainer5Rematch_7

EscapeRoom_EventScript_SetTrainer5Rematch_11:
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_BERRY_JUICE
	goto EscapeRoom_EventScript_SetTrainer5Rematch_10


EscapeRoom_EventScript_UndoFerroTrade::
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FERROTHORN
# 836 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFerrothornMessage
# 837 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FERRO_TRADE_ACCEPTED
	return


EscapeRoom_EventScript_UndoFlorgesTrade::
# 845 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 846 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_EGG
# 847 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonfrompc SPECIES_FLORGES
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	message PlayerObtainedFlorgesMessage
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 852 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 855 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_FLORGES_TRADE_ACCEPTED
	return


EscapeRoom_EventScript_LiepardNPC::
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 866 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 867 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 868 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 872 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 954 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 875 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 876 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 877 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 878 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 880 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 884 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 885 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 887 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 890 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 891 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 892 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_LIEPARD, CRY_MODE_NORMAL
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 899 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 900 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 901 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 902 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 903 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 904 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 909 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 913 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 914 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 918 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 921 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_OBTAINED
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 932 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_LiepardNPC_5
# 936 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_LiepardNPC_5
# 937 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_RETURN_ESCAPE_ROPE, EscapeRoom_EventScript_LiepardNPC_5
EscapeRoom_EventScript_LiepardNPC_4:
# 945 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 949 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
# 952 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RETURN_ESCAPE_ROPE
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_LiepardNPC_4


# 958 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 959 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 961 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 962 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 964 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 965 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 967 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 970 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 971 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 973 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, ball = ITEM_FRIEND_BALL, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_COPYCAT, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 1002 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1005 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1007 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 1008 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 1009 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1014 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 1028 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1029 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1031 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 1036 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 1040 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1041 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 1042 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1043 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 1048 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 1049 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1050 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 1053 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 1054 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RespawnChangeMessage, MSGBOX_AUTOCLOSE
# 1059 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE1, 0
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE2, 1
# 1064 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RESPAWN_SET_AT_NURSE3, 0
	return


# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 1068 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1072 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1073 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 1074 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 1076 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 1077 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 1081 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_ShopNPC::
# 1088 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1089 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1090 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 1091 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1092 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop_items
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1095 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 1098 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop_items:
# 1099 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 1100 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 1102 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 1103 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 1104 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM27
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_MoveDeleterNPC_2
# 1123 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_MOVE_DELETER
# 1126 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_5
# 1130 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_6
# 1135 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
EscapeRoom_MoveDeleterNPC_4:
# 1137 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOutOfBusiness, MSGBOX_AUTOCLOSE
# 1117 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1118 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_MoveDeleterNPC_5:
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_4

EscapeRoom_MoveDeleterNPC_6:
# 1131 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
	goto EscapeRoom_MoveDeleterNPC_4


EscapeRoom_ChooseMoveToDelete::
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 1145 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 1146 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1149 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_MOVE_DELETE_MONSLOT_BACKUP
# 1152 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EscapeRoom_ChooseMoveToDelete_2
# 1159 "data/maps/EscapeRoom_Main/scripts.pory"
	special GetNumMovesSelectedMonHas
# 1160 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_ChooseMoveToDelete_5
# 1167 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
	goto_if_eq EscapeRoom_ChooseMoveToDelete_8
# 1174 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmonmoveset VAR_0x8004
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_MOVE_DELETER_CHOSEN_SLOT
# 1178 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
# 1179 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	special MoveDeleterForgetMove
# 1183 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 1185 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1186 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterMoveDeleted, MSGBOX_AUTOCLOSE
	end

EscapeRoom_ChooseMoveToDelete_2:
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_5:
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOnlyOneMove, MSGBOX_AUTOCLOSE
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_8:
# 1168 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_RestoreMoveset::
# 1192 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 1196 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 1205 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 1206 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 1215 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_SMEARGLE
# 1226 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_11
EscapeRoom_RestoreMoveset_10:
# 1235 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_13
	return

EscapeRoom_RestoreMoveset_2:
# 1197 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1198 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1199 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 1200 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardMovesRestoredMessage, MSGBOX_DEFAULT
# 1201 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 1207 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1208 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1209 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 1210 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomMovesRestoredMessage, MSGBOX_DEFAULT
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 1217 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1218 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceMovesRestoredMessage, MSGBOX_DEFAULT
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_11:
# 1227 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 1228 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SMEARGLE_MOVE_DELETED
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SmeargleMovesRestoredMessage, MSGBOX_DEFAULT
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_10

EscapeRoom_RestoreMoveset_13:
# 1237 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 1238 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 1246 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 1247 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 1250 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_UltraBallNPC::
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 1271 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_DEFAULT
EscapeRoom_UltraBallNPC_1:
# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 1261 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 1266 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 1267 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_RockSmashNPC::
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1282 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1284 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, face_npc_up
# 1285 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1286 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1299 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 1300 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 1304 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1307 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 1311 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 1317 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 1319 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 1322 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 1323 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_MENTAL_HERB
# 1333 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1334 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1336 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1338 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MENTAL_HERB
# 1339 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 0
# 1342 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 1343 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_MoveRockSmashNPC_1
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 1344 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
# 1345 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_MoveRockSmashNPC_1
	return

EscapeRoom_MoveRockSmashNPC_1:
# 1347 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


# 1355 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 1356 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 1361 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 1362 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 1366 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1368 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuyStonesPC::
# 1374 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_OBTAINED, EscapeRoom_TryBuyStonesPC_2
# 1383 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SUN_STONE
# 1384 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_6
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_MOON_STONE
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_9
# 1397 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_DUSK_STONE
# 1398 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_TryBuyStonesPC_12
# 1404 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_no_item, MSGBOX_NPC
# 1405 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuyStonesPC_1:
# 1408 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuyStonesPC_2:
# 1378 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCPostSellMessage, MSGBOX_NPC
# 1379 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuyStonesPC_1

EscapeRoom_TryBuyStonesPC_6:
# 1385 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuySunStone
	end

EscapeRoom_TryBuyStonesPC_9:
# 1392 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyMoonStone
	end

EscapeRoom_TryBuyStonesPC_12:
# 1399 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_TryBuyStonesPC_TryBuyDuskStone
	end


EscapeRoom_TryBuyStonesPC_TryBuySunStone::
# 1412 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_SunStone, MSGBOX_YESNO
# 1415 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuySunStone_1
# 1428 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuySunStone_1:
# 1416 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_SUN_STONE
# 1417 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 1500
# 1418 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1419 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived1500
# 1420 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1421 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1422 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1424 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyMoonStone::
# 1434 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_MoonStone, MSGBOX_YESNO
# 1437 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 1451 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyMoonStone_1:
# 1438 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_MOON_STONE
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 1500
# 1440 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1441 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived1500
# 1442 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1443 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 1446 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage, MSGBOX_NPC
# 1447 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_TryBuyStonesPC_TryBuyDuskStone::
# 1456 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1457 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCInitialMessage_has_DuskStone, MSGBOX_YESNO
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuyStonesPC_TryBuyDuskStone_1
# 1468 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellDeclinedMessage, MSGBOX_NPC
# 1469 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_TryBuyStonesPC_TryBuyDuskStone_1:
# 1460 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_DUSK_STONE
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_JABOCA_BERRY
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_JABOCA_OBTAINED
# 1464 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox StonesBuyNPCSellAcceptedMessage_JabocaBerry, MSGBOX_NPC
# 1465 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return


EscapeRoom_AnnihilapeHintNPC::
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1480 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1509 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 1511 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1497 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1498 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1502 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 1483 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 1484 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1486 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1487 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 1488 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 1515 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 1519 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1520 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1521 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 1525 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage3, MSGBOX_DEFAULT
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 1538 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_DEFAULT
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_DEFAULT
# 1527 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1528 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 1529 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage2, MSGBOX_DEFAULT
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 1542 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1543 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 1546 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 1550 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 1552 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_DusknoirStoleMyMailNPC::
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1557 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DusknoirStoleMyMailMsg, MSGBOX_NPC
# 1558 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer1::
# 1565 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1566 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 1575 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 1579 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 1576 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 1591 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 1592 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 1597 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1598 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 1611 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_7
EscapeRoom_EventScript_Trainer5_6:
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 1649 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 1629 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 1626 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1

EscapeRoom_EventScript_Trainer5_7:
# 1635 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BERRY_JUICE_CONSUMED
# 1636 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUSK_STONE_CONSUMED
# 1637 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JABOCA_CONSUMED
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SAFETY_GOGGLES_CONSUMED
	goto EscapeRoom_EventScript_Trainer5_6


EscapeRoom_EventScript_Trainer6::
# 1655 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7A::
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7A, Trainer7A_Intro, Trainer7A_Outro, event_script = EscapeRoom_EventScript_Trainer7APostBattle
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7A_PostBattle, MSGBOX_AUTOCLOSE
# 1676 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer7B::
# 1681 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER7B, Trainer7B_Intro, Trainer7B_Outro, event_script = EscapeRoom_EventScript_Trainer7BPostBattle
# 1688 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer7B_PostBattle, MSGBOX_AUTOCLOSE
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer8::
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER8, Trainer8_Intro, Trainer8_Outro, event_script = EscapeRoom_EventScript_Trainer8PostBattle
# 1701 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer8_PostBattle, MSGBOX_AUTOCLOSE
# 1702 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer9::
# 1707 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer10::
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER10, Trainer10_Intro, Trainer10_Outro, event_script = EscapeRoom_EventScript_Trainer10PostBattle
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer10_PostBattle, MSGBOX_AUTOCLOSE
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer11::
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER11, Trainer11_Intro, Trainer11_Outro, event_script = EscapeRoom_EventScript_Trainer11PostBattle
# 1740 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer11_PostBattle, MSGBOX_AUTOCLOSE
# 1741 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1757 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1758 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 1767 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 1778 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 1779 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 1500
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_5
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_9
EscapeRoom_EventScript_Trainer1PostBattle_8:
# 1783 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_USED, EscapeRoom_EventScript_Trainer1PostBattle_5
EscapeRoom_EventScript_Trainer1PostBattle_4:
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 1760 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1761 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_15
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_5:
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1786 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer1PostBattle_4

EscapeRoom_EventScript_Trainer1PostBattle_9:
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_11
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_11:
# 1782 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8008, ITEM_SAFETY_GOGGLES
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_5
	goto EscapeRoom_EventScript_Trainer1PostBattle_8

EscapeRoom_EventScript_Trainer1PostBattle_15:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_USED
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 1815 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1822 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 1823 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_5
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 1825 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MARANGA_BERRY_USED, EscapeRoom_EventScript_Trainer2PostBattle_5
# 1826 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_EventScript_Trainer2PostBattle_5
EscapeRoom_EventScript_Trainer2PostBattle_4:
# 1832 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_13
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_5:
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1829 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1830 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer2PostBattle_4

EscapeRoom_EventScript_Trainer2PostBattle_13:
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MARANGA_BERRY_USED
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 1838 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1841 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_RING_TARGET
# 1844 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1845 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_2
# 1848 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_3
EscapeRoom_EventScript_Trainer3PostBattle_1:
# 1853 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1854 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 1855 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 1857 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 1858 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 1864 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 1867 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1874 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer3PostBattle_7
# 1876 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER1_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 1877 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER2_DEFEATED, EscapeRoom_EventScript_Trainer3PostBattle_7
# 1878 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_Trainer3PostBattle_7
EscapeRoom_EventScript_Trainer3PostBattle_6:
# 1884 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer3PostBattle_2:
# 1846 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 0
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_3:
# 1849 "data/maps/EscapeRoom_Main/scripts.pory"
	givepartyitem ITEM_RING_TARGET, 1
	goto EscapeRoom_EventScript_Trainer3PostBattle_1

EscapeRoom_EventScript_Trainer3PostBattle_7:
# 1880 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1881 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1882 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer3PostBattle_6


# 1888 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1890 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1891 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 1896 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 2000
# 1904 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_3
EscapeRoom_EventScript_Trainer4PostBattle_1:
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer4PostBattle_2:
# 1908 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1909 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_Trainer4PostBattle_1

EscapeRoom_EventScript_Trainer4PostBattle_3:
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_5, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer4PostBattle_2
	goto EscapeRoom_EventScript_Trainer4PostBattle_1


EscapeRoom_EventScript_Trainer5PostBattle::
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BERRY_JUICE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUSK_STONE_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_5
EscapeRoom_EventScript_Trainer5PostBattle_4:
# 1947 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JABOCA_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_11
EscapeRoom_EventScript_Trainer5PostBattle_10:
# 1959 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_SAFETY_GOGGLES_CONSUMED, EscapeRoom_EventScript_Trainer5PostBattle_19
EscapeRoom_EventScript_Trainer5PostBattle_18:
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 1924 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1925 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_8
EscapeRoom_EventScript_Trainer5PostBattle_7:
# 1928 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_16
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_5:
# 1936 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_DUSK_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_14
EscapeRoom_EventScript_Trainer5PostBattle_13:
# 1940 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1941 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_DUSK_STONE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_24
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_8:
# 1926 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_7

EscapeRoom_EventScript_Trainer5PostBattle_11:
# 1948 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1949 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_22
EscapeRoom_EventScript_Trainer5PostBattle_21:
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_JABOCA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_29
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_14:
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_13

EscapeRoom_EventScript_Trainer5PostBattle_16:
# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_19:
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 1961 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_27
EscapeRoom_EventScript_Trainer5PostBattle_26:
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_31
	goto EscapeRoom_EventScript_Trainer5PostBattle_18

EscapeRoom_EventScript_Trainer5PostBattle_22:
# 1950 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_21

EscapeRoom_EventScript_Trainer5PostBattle_24:
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_4

EscapeRoom_EventScript_Trainer5PostBattle_27:
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_Trainer5PostBattle_26

EscapeRoom_EventScript_Trainer5PostBattle_29:
# 1954 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_10

EscapeRoom_EventScript_Trainer5PostBattle_31:
# 1966 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_Trainer5PostBattle_18


EscapeRoom_EventScript_Trainer6PostBattle::
# 1976 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	removelostitem ITEM_CUSTAP_BERRY
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1983 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1984 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 1992 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1993 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1994 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 2001 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_MENTAL_HERB_SOLD_OUT
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8005
# 2013 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8005
# 2016 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_SAFETY_GOGGLES
# 2017 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 2019 "data/maps/EscapeRoom_Main/scripts.pory"
	checkexactmoney 500
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2021 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER4_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 2022 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer6PostBattle_9
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8006, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2024 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8007, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
# 2025 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 1985 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_25
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2029 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2030 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_Trainer6PostBattle_25:
# 1997 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer7APostBattle::
# 2035 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7A_DEFEATED
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer7BPostBattle::
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER7B_DEFEATED
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer8PostBattle::
# 2045 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER8_DEFEATED
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer9PostBattle::
# 2050 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer10PostBattle::
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER10_DEFEATED
# 2056 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer11PostBattle::
# 2060 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER11_DEFEATED
# 2061 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2069 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 2070 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 2092 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 2094 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 2074 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 2085 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 2086 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 2088 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 2089 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2078 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 2128 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_8
# 2179 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 2180 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER3_DEFEATED, EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 2121 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 2122 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAskRetrade, MSGBOX_YESNO
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2108 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_11
# 2115 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_8:
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_15
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FERROTHORN
# 2144 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 2145 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 2167 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 2170 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2171 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2173 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2174 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_11:
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFerroTrade
# 2111 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 2112 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_15:
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2136 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 2188 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2192 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_8
# 2247 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 2248 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 2251 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 2195 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_LIEPARD_OBTAINED, EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 2196 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAskRetrade, MSGBOX_YESNO
# 2197 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2198 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_11
# 2205 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoDeclined, MSGBOX_AUTOCLOSE
# 2206 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_8:
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_15
# 2231 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmontopc SPECIES_FLORGES
# 2234 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 2235 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 2236 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 2238 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 2239 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2241 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2242 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 2243 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_11:
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_UndoFlorgesTrade
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeUndoAccepted, MSGBOX_AUTOCLOSE
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_15:
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2226 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 2255 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2256 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2259 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 2265 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 2266 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 2292 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 2296 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 2260 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 2269 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 2270 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 2279 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 2280 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 2282 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 2283 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2284 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ByeByeDunsparce, MSGBOX_AUTOCLOSE
# 2288 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 2272 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2273 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2274 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeAipomLiepardForCacnea::
# 2300 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 2304 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeAipomLiepardForCacnea_2
# 2310 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskCacneaTrade, MSGBOX_YESNO
# 2311 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeAipomLiepardForCacnea_5
# 2369 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CacneaTradeDeclined, MSGBOX_AUTOCLOSE
# 2370 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeAipomLiepardForCacnea_1:
# 2373 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeAipomLiepardForCacnea_2:
# 2305 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CacneaTradePostTrade, MSGBOX_NPC
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeAipomLiepardForCacnea_1

EscapeRoom_EventScript_TradeAipomLiepardForCacnea_5:
# 2314 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeAipomLiepardForCacnea_9
# 2322 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 2323 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeAipomLiepardForCacnea_12
# 2332 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 2333 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_LIEPARD
# 2334 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2335 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_CACNEA, 41, abilityNum = 1, nature = 18, gender = 0, move1 = MOVE_HIDDEN_POWER, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 140, hpIv = 31, atkIv = 30, defIv = 31, speedIv = 30, spAtkIv = 31, spDefIv = 31
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2358 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AIPOM_LIEPARD_TRADE_ACCEPTED
# 2360 "data/maps/EscapeRoom_Main/scripts.pory"
	message CacneaReceivedMessage
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2362 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2363 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 2364 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox CacneaTradeAccepted, MSGBOX_AUTOCLOSE
# 2365 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeAipomLiepardForCacnea_1

EscapeRoom_EventScript_TradeAipomLiepardForCacnea_9:
# 2317 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2318 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeAipomLiepardForCacnea_12:
# 2325 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 2326 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2327 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindLiepardCollar::
# 2387 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2388 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 2389 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 2390 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 2391 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 2398 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2401 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 2412 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 2415 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 2418 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 2423 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 2438 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 2402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2403 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2404 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 2410 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 2413 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 2416 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 2419 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 2424 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2425 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 2426 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2430 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 2435 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 2431 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 2442 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2445 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 2456 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 2462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 2446 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2448 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 2454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 2457 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 2460 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 2463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 2468 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2469 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 2470 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2471 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2474 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 2479 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 2485 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2488 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 2496 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 2499 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 2502 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 2505 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 2510 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 2524 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 2489 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2490 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2491 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 2497 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 2500 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 2503 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 2506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 2511 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2512 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 2513 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2514 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2517 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 2522 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 2518 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 2528 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2531 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 2539 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 2544 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 2547 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 2550 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 2553 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 2532 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 2533 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2534 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 2540 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 2545 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 2548 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 2551 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 2559 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 2560 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 2561 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2565 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 2570 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 2566 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 2577 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 2582 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
# 2583 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 2579 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 2578 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 2580 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 2588 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2589 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 2590 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 2591 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 2592 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2593 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2594 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 2595 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 2596 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2597 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 2598 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 2600 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 2607 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2610 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 2613 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 2618 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 2641 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 2642 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 2614 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 2646 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2647 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2648 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2651 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 2655 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 2665 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2666 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 2671 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2675 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 2658 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 2659 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2661 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 2657 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 2656 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 2679 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2680 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2681 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 2687 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 2688 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 2689 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 2696 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2697 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2700 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 2691 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2692 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 2704 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2705 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2706 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2709 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 2713 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 2720 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 2721 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 2728 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 2731 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2732 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 2715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 2716 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 2723 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2725 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 2738 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2740 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2743 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 2746 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 2747 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 2748 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 2755 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2756 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2757 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2759 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2751 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 2763 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2764 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2765 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 2771 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 2772 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 2773 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 2780 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2781 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2784 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 2775 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2776 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 2788 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2789 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2790 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2793 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 2796 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 2797 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 2805 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2806 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2807 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2809 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 2800 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2801 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 2813 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2815 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 2822 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 2829 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 2841 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2842 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 2845 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 2827 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 2832 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2833 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2835 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2836 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2837 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2850 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2851 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2854 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 2858 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 2865 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 2866 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 2873 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 2876 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2877 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2879 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 2860 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 2861 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2863 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2869 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2870 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 2883 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2884 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2888 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 2892 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 2893 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2901 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2902 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 2895 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 2908 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2909 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2910 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2913 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 2916 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 2917 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 2918 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 2925 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2926 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2927 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 2920 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2921 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2934 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 2936 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2938 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2939 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2940 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2941 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2942 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2943 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2945 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 2946 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2947 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2948 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 2952 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2955 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 2975 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 2976 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 2979 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 2957 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 2958 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 2970 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 2961 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 2962 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 2958 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 2963 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 2964 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 2984 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2985 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2986 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2987 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 2988 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2989 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2990 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 2993 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2994 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 2995 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2996 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 2997 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_SWEET_SCENT
# 2998 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2999 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 3000 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 3001 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 3002 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 3003 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 3004 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 3007 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 3008 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 3009 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 3010 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 3011 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


SomethingsGoneWrongMessage::
# 3018 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that can break the game.\p"
	.string "Consider contacting Ketchupplant.$"

RespawnChangeMessage::
# 3025 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your respawn location was changed.$"

SignMessage1::
# 3030 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 3034 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 3039 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 3044 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MysteriousWallSign::
# 3051 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 3057 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "bliep bloop (TBD)$"

MoveDeleterSignMessage::
# 3061 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 3077 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 3083 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 3087 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 3091 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "A spirit makes its presence known.$"

GravestoneClick3Message::
# 3096 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 3101 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 3105 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 3109 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 3118 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 3126 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 3131 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 3136 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 3143 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 3147 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 3151 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 3156 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 3162 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 3168 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 3174 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 3181 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 3187 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 3193 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 3199 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 3206 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 3212 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 3218 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 3224 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 3231 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 3237 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 3243 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 3249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 3257 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 3261 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 3265 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 3271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 3280 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 3284 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 3291 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "Heads up, certain rollbacks will also\n"
	.string "include healing your party.\p"
	.string "What would you like to do?$"

AntiSoftlockOutro::
# 3300 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Alright, see you soon.$"

AntiSoftlockNoItemsReturned::
# 3304 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no items that can\n"
	.string "be returned.$"

AntiSoftlockPartyHealed::
# 3309 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your party Pokémon were healed.$"

AntiSoftlockSomeOfPartyHealed::
# 3313 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some of your party Pokémon got healed.$"

AntiSoftlockNoItemToUndo::
# 3317 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no item uses that\n"
	.string "can be undone.$"

AntiSoftlockNoActionsToUndo::
# 3322 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There currently are no other events\n"
	.string "that can be undone.$"

AntiSoftlockAskUndoTrainer5::
# 3327 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your previous\n"
	.string "trainer battle win?\p"
	.string "Any money earned or items lost during\n"
	.string "battle will be returned as well.$"

AntiSoftlockTrainer5Undone::
# 3334 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The battle has been undone.$"

AntiSoftlockAskUndoFerroTrade::
# 3338 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Ferrothorn?$"

AntiSoftlockAskUndoFlorgesTrade::
# 3343 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Florges?$"

AntiSoftlockAskUndoAipomTrade::
# 3348 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Would you like to undo your latest\n"
	.string "Pokémon trade and get back Aipom?$"

UltraBallQuizStart::
# 3354 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 3358 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks for playing!$"

ZeraoraHintMessage::
# 3364 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people try to catch it but no\n"
	.string "one's been able to get its HP below 50%.\p"
	.string "Will you show me your Zeraora if you do\n"
	.string "manage to capture it?\p"
	.string "I've always wanted to see one up close.$"

ZeraoraHintPostCatchMessage1::
# 3373 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!\p"
	.string "I can't believe my eyes!\n"
	.string "You've made a dream come true...\p"
	.string "Here, take this!$"

ZeraoraHintPostCatchMessage2::
# 3381 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's the least I can do.$"

ZeraoraHintPostCatchMessage3::
# 3386 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll never forget this day.$"

AnnihilapeHintNoMessage1::
# 3392 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 3396 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 3400 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.\p"
	.string "She'll always be back.$"

FourTabletsHintMessage1::
# 3410 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 3416 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to go through the menus.$"

FourTabletsHintMessage3::
# 3425 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that earthquake!?$"

DusknoirStoleMyMailMsg::
# 3432 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A Dusknoir stole my mail!\p"
	.string "To be honest, I don't really mind.\n"
	.string "It's just a bit strange.$"

StonesBuyNPCInitialMessage_no_item::
# 3441 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm obsessed with collecting rare and\n"
	.string "unusual stones.\p"
	.string "Please come to me if you ever find\n"
	.string "anything worth my attention.$"

StonesBuyNPCInitialMessage_has_SunStone::
# 3449 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Sun Stone?\p"
	.string "Would you sell it to me for ¥1500?$"

StonesBuyNPCInitialMessage_has_MoonStone::
# 3455 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Moon Stone?\p"
	.string "Would you sell it to me for ¥1500?$"

StonesBuyNPCInitialMessage_has_DuskStone::
# 3461 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Incredible...\n"
	.string "Is that a Dusk Stone?\p"
	.string "...\p"
	.string "I may have ran out of money...\p"
	.string "Would you trade it for a Jaboca Berry?$"

StonesBuyNPCSellAcceptedMessage::
# 3469 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll take good care of it.$"

StonesBuyNPCSellAcceptedMessage_JabocaBerry::
# 3473 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm sure the berry will serve you well.$"

StonesBuyNPCSellDeclinedMessage::
# 3477 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

StonesBuyNPCPostSellMessage::
# 3481 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I think I've got enough for now.$"

MoneyReceived1500::
# 3485 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥1500!$"

LiepardObtainMessage::
# 3492 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 3496 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 3500 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 3504 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 3511 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 3515 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

MartNPC_AskToShop::
# 3521 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold for\n"
	.string "the same price.$"

MartNPC_SayGoodbye::
# 3527 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 3533 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterOutOfBusiness::
# 3539 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You don't need me anymore.$"

MoveDeleterComeAgain::
# 3543 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MoveDeleterMoveDeleted::
# 3547 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s {STR_VAR_2} was removed!$"

MoveDeleterOnlyOneMove::
# 3551 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That Pokémon has only one move left.$"

AipomMovesRestoredMessage::
# 3555 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Aipom's moves were restored!$"

LiepardMovesRestoredMessage::
# 3559 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Liepard's moves were restored!$"

DunsparceMovesRestoredMessage::
# 3563 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce's moves were restored!$"

SmeargleMovesRestoredMessage::
# 3567 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Smeargle's moves were restored!$"

NoMovesRestoredMessage::
# 3571 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 3577 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 3581 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

AskResetPredamageMessage::
# 3587 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

AskResetPredamageAndWarpMessage::
# 3592 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state and\l"
	.string "return to the previous location?$"

PreDamagedStateRestoredMessage::
# 3598 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 3604 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 3609 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 3613 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 3617 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 3621 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

PlayerObtainedFerrothornMessage::
# 3625 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Ferrothorn!$"

FerroTradeAskRetrade::
# 3629 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Ferrothorn?$"

FerroTradeUndoAccepted::
# 3634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Just come back whenever you want to\n"
	.string "trade again.$"

FerroTradeUndoDeclined::
# 3639 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Works for me!$"

AskFlorgesEggTrade::
# 3644 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 3650 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 3654 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 3658 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 3662 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I sense regret?$"

PlayerObtainedFlorgesMessage::
# 3666 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Florges!$"

FlorgesTradeAskRetrade::
# 3670 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to undo our trade and get\n"
	.string "back your Florges?$"

FlorgesTradeUndoAccepted::
# 3675 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There you go.$"

FlorgesTradeUndoDeclined::
# 3679 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As you wish.$"

AskDunsparceMoneyTrade::
# 3684 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 3690 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

ByeByeDunsparce::
# 3696 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Dunsparce.$"

DunsparceTradeDeclined::
# 3700 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 3704 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

AskCacneaTrade::
# 3710 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (start trade)$"

CacneaReceivedMessage::
# 3714 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Cacnea!$"

CacneaTradeAccepted::
# 3718 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Aipom.\p"
	.string "Bye-bye Liepard.$"

CacneaTradeDeclined::
# 3723 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (trade declined)$"

CacneaTradePostTrade::
# 3727 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (post trade)$"

DoubleBattle_NotEnoughMons::
# 3734 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second Pokémon.$"

Trainer1_Intro::
# 3741 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\p"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 3747 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 3751 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 3755 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 3762 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 3766 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 3772 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 3777 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 3781 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 3787 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 3792 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 3796 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3FinalWords::
# 3800 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 3806 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ugh.. I feel exhausted already.$"

Trainer4_Outro::
# 3810 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 3814 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 3820 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 3825 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you have enough?$"

Trainer5_PostBattle::
# 3829 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_RemoveAssistMessage::
# 3833 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 3840 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They always find their way back.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 3847 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 3851 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7A_Intro::
# 3857 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer7A_Outro::
# 3861 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7A_PostBattle::
# 3865 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer7B_Intro::
# 3871 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "something something poor sight$"

Trainer7B_Outro::
# 3875 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer7B_PostBattle::
# 3879 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer8_Intro::
# 3885 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer8_Outro::
# 3889 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer8_PostBattle::
# 3893 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer9_Intro::
# 3899 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Don't get your hopes up.$"

Trainer9_Outro::
# 3903 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer9_PostBattle::
# 3907 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer10_Intro::
# 3913 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer10_Outro::
# 3917 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer10_PostBattle::
# 3921 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer11_Intro::
# 3927 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer11_Outro::
# 3931 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer11_PostBattle::
# 3935 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
